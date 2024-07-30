# Project: JPEG Recovery

This project focuses on recovering JPEG images from a raw memory card image. It demonstrates my ability to handle file I/O operations, buffer management, and the implementation of fundamental C programming concepts.

- **Project Description**

    The JPEG Recovery program is designed to search through a raw memory card file to find and recover JPEG images. The program reads the memory card file in 512-byte blocks and identifies the start of JPEG files by checking for specific header patterns. Once a new JPEG is found, it creates a new file and continues to write the subsequent blocks until the next JPEG header is detected.


- **Features:**

	- File Handling: Opens the memory card file and reads its contents in fixed-size blocks.
	- JPEG Detection: Identifies the beginning of a new JPEG file by checking the standard JPEG header bytes.
	- Dynamic File Creation: Creates new JPEG files dynamically as they are discovered and writes the corresponding data blocks to them.
	- Memory Management: Manages buffer operations efficiently to ensure smooth file reading and writing processes.
	- Error Handling: Includes basic error handling for file operations, ensuring robust performance even when encountering issues such as file access errors.

This project showcases my ability to work with low-level file operations, use buffers for efficient data handling, and implement logical structures to achieve the desired functionality. It highlights my proficiency in C programming and my understanding of file system interactions.