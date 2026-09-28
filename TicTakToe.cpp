#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void drawBoard() {
    cout << "\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n\n";
}

bool checkWin(char player) {
    int wins[8][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};
    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == player && board[wins[i][1]] == player && board[wins[i][2]] == player) {
            return true;
        }
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') return false;
    }
    return true;
}

int main() {
    srand(time(0));
    int slot;
    bool playerTurn = true;

    while (true) {
        drawBoard();
        
        if (playerTurn) {
            cout << "Enter your move (1-9): ";
            cin >> slot;
            slot--;

            if (slot < 0 || slot > 8 || board[slot] == 'X' || board[slot] == 'O') {
                cout << "Invalid move. Try again.\n";
                continue;
            }
            board[slot] = 'X';
            
            if (checkWin('X')) {
                drawBoard();
                cout << "You win!\n";
                break;
            }
        } else {
            do {
                slot = rand() % 9;
            } while (board[slot] == 'X' || board[slot] == 'O');
            
            cout << "Computer chose slot " << slot + 1 << "\n";
            board[slot] = 'O';

            if (checkWin('O')) {
                drawBoard();
                cout << "Computer wins!\n";
                break;
            }
        }

        if (isDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            break;
        }

        playerTurn = !playerTurn;
    }

    return 0;
}