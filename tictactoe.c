#include <stdio.h>

char board[3][3] = {'1','2','3',
                    '4','5','6',
                    '7','8','9'};

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

    return '0';

}

void draw(void)
{
    printf("\n");
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
    printf("+---+---+---+\n");
    printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
    printf("+---+---+---+\n");
}

int move(int player)
{
    int row, column, number;

    draw();
    printf("Select a number to place your %c on: ", (player == 1) ? 'X' : 'O');
    scanf("%i", &number);
    row = --number / 3;
    column = number % 3;

    if (board[row][column] == 'X' || board[row][column] == 'Y') {
        printf("You cannot place that there. Try again: ");
        scanf("%i", &number);
        row = --number / 3;
        column = number % 3;
    }

    board[row][column] = (player == 1) ? 'X' : 'O';

    return row, column;
}

int main(int argc, const char *argv[])
{
    int i, row, column;
    int player = 0;

    for (i = 0; i < 9 && winner() == '0'; i++) {
        player = i % 2 + 1;
        move(player);
    }
    
    if (winner() != '0') {
        draw();
        printf("%c Wins!!\n", winner());
    } else {
        draw();
        printf("Tie.\n");
    }

    return 0;
}
