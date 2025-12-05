#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class TicTacToe {
private:
    vector<char> board;
    char currentPlayer;

public:
    TicTacToe() : board(9, ' '), currentPlayer('X') {
        srand(time(0));
    }

    void displayBoard() {
        cout << "\n";
        for (int i = 0; i < 9; i += 3) {
            cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
            if (i < 6) cout << "---|---|---\n";
        }
        cout << "\n";
    }

    bool makeMove(int pos) {
        if (pos < 0 || pos > 8 || board[pos] != ' ') return false;
        board[pos] = currentPlayer;
        return true;
    }

    bool checkWin() {
        int wins[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
        for (auto& win : wins) {
            if (board[win[0]] == currentPlayer &&
                board[win[1]] == currentPlayer &&
                board[win[2]] == currentPlayer) {
                return true;
            }
        }
        return false;
    }

    bool isBoardFull() {
        for (char c : board) {
            if (c == ' ') return false;
        }
        return true;
    }

    void computerMove() {
        vector<int> available;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') available.push_back(i);
        }
        if (!available.empty()) {
            int move = available[rand() % available.size()];
            board[move] = currentPlayer;
            cout << "Komputer wybral pole: " << move << "\n";
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void play() {
        cout << "=== KOLKO I KRZYZYK ===\n";
        cout << "Pola numerowane od 0 do 8\n";

        while (true) {
            displayBoard();

            if (currentPlayer == 'X') {
                cout << "Twoj ruch (0-8): ";
                int move;
                cin >> move;
                if (!makeMove(move)) {
                    cout << "Nieprawidlowy ruch!\n";
                    continue;
                }
            } else {
                computerMove();
            }

            if (checkWin()) {
                displayBoard();
                cout << "Gracz " << currentPlayer << " wygral!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "Remis!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}