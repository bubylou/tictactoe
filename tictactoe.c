#include <stdio.h>

char board[3][3] = {' ',' ',' ',
                    ' ',' ',' ',
                    ' ',' ',' '};

char winner(void)
{
    int i;

    for(i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
            return board[i][0];

        if(board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return board[0][i];

        if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return board[0][0];

        if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return board[0][2];
    }

    return ' ';

}

int draw(int row, int column)
{
    printf("   0  1  2\n0 [%c][%c][%c]\n1 [%c][%c][%c]\n2 [%c][%c][%c]\n",
            board[0][0], board[0][1], board[0][2],
            board[1][0], board[1][1], board[1][2],
            board[2][0], board[2][1], board[2][2]);

    return 0;
}

int move(int player)
{
    int row, column;

    draw(row, column);
    printf("Please select a coordinate to place your %c (Row Column):\n", (player == 1) ? 'X' : 'O');
    scanf("%i %i", &row, &column);

    if (board[row][column] != ' ') {
        printf("\nYou cannot place that there. Try again.\n");
        scanf("%i %i", &row, &column);
    }

    board[row][column] = (player == 1) ? 'X' : 'O';

    return row, column;
}

int main(int argc, const char *argv[])
{
    int i, row, column;
    int player = 0;

    for (i = 0; i < 9 && winner() == ' '; i++) {
        player = i % 2 + 1;

        move(player);
    }
    
    if (winner() != ' ') {
        draw(row, column);
        printf("%c Wins!!\n", winner());
    } else {
        draw(row, column);
        printf("Tie.\n");
    }


    return 0;
}
