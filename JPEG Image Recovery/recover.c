#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    // Accept single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open memory card
    FILE *card = fopen(argv[1], "rb");
    if (card == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    // Create a buffer for a data block
    uint8_t buffer[BLOCKSIZE];
    int imageCount = 0;
    char filename[32];
    FILE *img = NULL;

    // Repeat until end of card:
    while (1)
    {
        // Read 512 bytes into buffer
        size_t bytesRead = fread(buffer, 1, BLOCKSIZE, card);

        // check end of file
        if (bytesRead == 0)
        {
            break;
        }

        // If start of new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If not first JPEG, close existing file
            if (img != NULL)
            {
                fclose(img);
            }

            // Create new JPEG file
            sprintf(filename, "%03i.jpg", imageCount++);
            img = fopen(filename, "wb");
            fwrite(buffer, BLOCKSIZE, 1, img);
        }

        // Else: currently writing to JPEG file
        else if (img != NULL)
        {
            // If already found JPEG: keep writing
            fwrite(buffer, BLOCKSIZE, 1, img);
        }
    }

    // Close remaining files
    if (img != NULL)
    {
        fclose(img);
    }

    fclose(card);

    return 0;
}
