#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;

void drawBoard() {
    cout << "Tic-Tac-Toe Game\n";
    cout << "Player 1: X  Player 2: O\n\n";
    cout << "     |     |     \n";
    for (int i = 0; i < 3; i++) {
        cout << "  " << board[i][0] << "  |  " << board[i][1] << "  |  " << board[i][2] << "  \n";
        if (i < 2) cout << "_____|_____|_____\n     |     |     \n";
    }
    cout << "     |     |     \n\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    }
    return false;
}

int winner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swapPlayerAndMarker() {
    if (current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';
    current_player = (current_player == 1) ? 2 : 1;
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;
    drawBoard();

    int player_won;
    for (int i = 0; i < 9; i++) {
        cout << "Player " << current_player << "'s turn. Enter slot (1-9): ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            i--; // Repeat the turn for invalid input
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try a different slot.\n";
            i--; // Repeat the turn for occupied slot
            continue;
        }

        drawBoard();
        player_won = winner();

        if (player_won != 0) {
            cout << "Player " << player_won << " wins!\n";
            return;
        }
        
        swapPlayerAndMarker();
    }

    cout << "It's a tie!\n";
}

int main() {
    game();
    return 0;
}
