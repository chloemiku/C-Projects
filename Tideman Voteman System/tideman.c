#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool isPathExist(int i, int j);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        printf("\n");
        record_preferences(ranks);
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    
    for (int rankIndex = 0; rankIndex < candidate_count; rankIndex++)
    {
        if (strcmp(name, candidates[rankIndex]) == 0)
        {
            ranks[rank] = rankIndex;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    
    int swapCounter = -1;
    do
    {
        swapCounter = 0;
        for (int pairIndex = 0; pairIndex < pair_count; pairIndex++)
        {
            int vote1 = preferences[pairs[pairIndex].winner][pairs[pairIndex].loser];
            int vote2 = preferences[pairs[pairIndex + 1].winner][pairs[pairIndex + 1].loser];

            if (vote1 < vote2)
            {
                pair temp = pairs[pairIndex];
                pairs[pairIndex] = pairs[pairIndex + 1];
                pairs[pairIndex + 1] = temp;

                swapCounter++;
            }
        }
    }
    while (swapCounter != 0);

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    
    for (int pairIndex = 0; pairIndex < pair_count; pairIndex++)
    {
        int winner = pairs[pairIndex].winner;
        int loser = pairs[pairIndex].loser;

        if (!isPathExist(loser, winner))
        {
            locked[winner][loser] = true;
        }
        else
        {
            continue;
        }
    }
    return;
}

bool isPathExist(int i, int j)
{
    if (locked[i][j])
        return true;

    for (int candidateIndex = 0; candidateIndex < candidate_count; candidateIndex++)
    {
        if (locked[i][candidateIndex] && isPathExist(candidateIndex, j))
            return true;
    }
    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // the winners are not pointed = locked matrix is not true in the column of winner
    for (int col = 0; col < candidate_count; col++)
    {
        bool is_winner = true;

        for (int row = 0; row < candidate_count; row++)
        {
            if (locked[row][col])
            {
                is_winner = false;
                break;
            }
        }

        if (is_winner)
        {
            printf("%s\n", candidates[col]);
            return;
        }
    }

    return;
}
