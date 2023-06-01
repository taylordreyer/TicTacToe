#include <stdio.h>

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

// Function prototypes
int checkwin();
void board();

int main()
{
    int player = 1, choice, i;
    char mark;

    do
    {
        board(); // Display the game board

        player = (player % 2) ? 1 : 2; // Alternate between players 1 and 2
        printf("Player %d, enter a number: ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O'; // Assign the mark (X or O) to the current player

        // Validate the user's move
        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice)
            square[choice] = mark; // Update the game board with the player's mark
        else
        {
            printf("Invalid move. ");
            player--;
            continue;
        }

        i = checkwin(); // Check if there is a winner or draw
        player++;
    } while (i == -1);

    board(); // Display the final game board

    // Print the result
    if (i == 1)
        printf("==> Player %d wins!\n", --player);
    else
        printf("==> Game draw.\n");

    return 0;
}

// Function to check if there is a winner or draw
int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
             square[4] != '4' && square[5] != '5' && square[6] != '6' &&
             square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}

// Function to display the game board
void board()
{
    system("cls"); // Clear the console screen
    printf("\n\n\tTic Tac Toe\n\n");
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);
    printf("     |     |     \n\n");
}
