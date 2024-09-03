#include <iostream>
#include <windows.h>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int row, column;
bool draw = false;

void display_board() {
    system("cls");
    cout << "\tT i c k   C r o s s   G a m e\n\n";

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0x0C); 
    cout << "\t  Player[X]\n";
    SetConsoleTextAttribute(hConsole, 0x0E);
    cout << "\t  Player[O]\n";
    SetConsoleTextAttribute(hConsole, 0x07); 
    SetConsoleTextAttribute(hConsole, 0x0B); 
    cout << "\t\t     |     |      \n";
    cout << "\t\t   " << board[0][0] << " |   " << board[0][1] << " |   " << board[0][2] << "  \n";
    cout << "\t\t__|_|___\n";
    cout << "\t\t     |     |      \n";
    cout << "\t\t   " << board[1][0] << " |   " << board[1][1] << " |   " << board[1][2] << "  \n";
    cout << "\t\t__|_|___\n";
    cout << "\t\t     |     |      \n";
    cout << "\t\t   " << board[2][0] << " |   " << board[2][1] << " |   " << board[2][2] << "  \n";
    cout << "\t\t     |     |      \n";
    SetConsoleTextAttribute(hConsole, 0x07);
}

void player_turn() {
    int choice;
    if (turn == 'X') {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 0x0C); 
        cout << "\n";
        cout << "Player1[X] Turn : ";
        SetConsoleTextAttribute(hConsole, 0x07); 
    } else if (turn == 'O') {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 0x0E); 
        cout << "\n";
        cout << "Player2[O] Turn : ";
        SetConsoleTextAttribute(hConsole, 0x07); 
    }
    cin >> choice;
    switch (choice) {
        case 1: row = 0, column = 0; break;
        case 2: row = 0, column = 1; break;
        case 3: row = 0, column = 2; break;
        case 4: row = 1, column = 0; break;
        case 5: row = 1, column = 1; break;
        case 6: row = 1, column = 2; break;
        case 7: row = 2, column = 0; break;
        case 8: row = 2, column = 1; break;
        case 9: row = 2, column = 2; break;
        default:
            cout << "invalid number" << endl;
            break;
    }
    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'X';
        turn = 'O';
    } else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = 'O';
        turn = 'X';
    } else {
        cout << "Box Already Filled!\n Please Try Again!\n" << endl;
        player_turn();
    }
    display_board();
}

bool Game_Over() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && (board[i][0] == 'X' || board[i][0] == 'O'))
            return false;
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && (board[0][i] == 'X' || board[0][i] == 'O'))
            return false; 
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && (board[0][0] == 'X' || board[0][0] == 'O'))
        return false; 

    if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && (board[0][2] == 'X' || board[0][2] == 'O'))
        return false; 

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true; 
        }
    }
    draw = true;
    return false; 
}

int main() {
    while (Game_Over()) {
        display_board();
        player_turn();
        Game_Over();
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 0x0E); 
    if (turn == 'X' && draw == false) {
        cout << "Player2 [O] wins!!!!\n Congratulation!!\n";
    } else if (turn == 'O' && draw == false) {
        cout << "Player1 [X] wins!!!!\nCongratulation!!\n";
    } else {
        cout << "GAME DRAW!!!\n";
    }
    SetConsoleTextAttribute(hConsole, 0x07);
  
      system("pause");
    return 0;
}
