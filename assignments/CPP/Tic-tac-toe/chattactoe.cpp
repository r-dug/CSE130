#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <utility>
#include <limits>

using namespace std;


class Player {
    private:
        string name;
        string role;
        char X_O;
    public:
        // Accessor funcitons
        string getName();
        string getRole();
        char getX_O();
        // Mutator functions
        void setName(string);
        void setRole(string);
        void setX_O(char);
        // Constructor functions
        Player();
        Player(string, char);
};

void Player :: setName(string name) {
    this->name = name;
}
void Player :: setRole(string role) {
    this->role = role;
}
void Player :: setX_O(char X_O) {
    this->X_O = X_O;
}
string Player :: getName() {
    return this->name;
}
string Player :: getRole() {
    return this->role;
}
char Player :: getX_O() {
    return this->X_O;
}
Player :: Player() {
    this->name = "name";
    this->X_O = 'X';
}
Player :: Player(string name, char X_O) {
    this->name = name;
    this->X_O = X_O;
}

void assignPlayers(vector<Player>& players) {
    srand(time(NULL));
    int random_number = rand() % 21;
    int player_choice;
    string player_name;

    cout << "Enter your player name: ";
    cin >> player_name;
    
    cout << "Pick a number between 0 and 20. If you guess my number, you can go first: ";
    cin >> player_choice;

    if (random_number == player_choice) {
        players[0].setName(player_name);
        players[0].setRole("HUMAN");
        players[0].setX_O('X');
        players[1].setName("COMPUTER");
        players[1].setRole("COMPUTER");
        players[1].setX_O('O');
    } else {
        players[1].setName(player_name);
        players[1].setRole("HUMAN");
        players[1].setX_O('X');
        players[0].setName("COMPUTER");
        players[0].setRole("COMPUTER");
        players[0].setX_O('O');
    }
    cout << "Player 1:\n" << players[0].getName() << "\nPlayer 2:\n" << players[1].getName() << endl;
}


class TicTacToe {
    private:
        vector<vector<vector<char>>> boards;
        int currentPlayer = 0;

        bool checkWin() {
            
            // Check same board wins
            for(int h = 0; h < 3; ++h) {
                // rows
                for(int i = 0; i < 3; ++i) {
                    if(boards[h][i][0] != ' ' && boards[h][i][0] == boards[h][i][1] && boards[h][i][1] == boards[h][i][2]) {
                        return true;
                    }
                }
                // columns
                for(int i = 0; i < 3; ++i) {
                    if(boards[h][0][i] == boards[h][1][i] && boards[h][1][i] == boards[h][2][i] && boards[h][0][i] != ' ') {
                        return true;
                    }
                }
                // diagonals 
                if(boards[h][0][0] == boards[h][1][1] && boards[h][1][1] == boards[h][2][2] && boards[h][0][0] != ' ') {
                    return true;
                }
                if(boards[h][0][2] == boards[h][1][1] && boards[h][1][1] == boards[h][2][0] && boards[h][0][2] != ' ') {
                    return true;
                }
            }
            // check inter-board wins
            for(int i = 0; i < 3; ++i) {
                for(int j = 0; j < 3; ++j){
                    if(boards[0][i][j] == boards[1][i][j] && boards[1][i][j] == boards[2][i][j] && boards[0][i][j] != ' '){
                        return true;
                    }
                }
            }
            // Diagonal wins between boards for top left corner
            if(boards[0][0][0] == boards[1][0][1] && boards[1][0][1] == boards[2][0][2] && boards[0][0][0] != ' '){
                return true;
            }
            if(boards[0][0][0] == boards[1][1][1] && boards[1][1][1] == boards[2][2][2] && boards[0][0][0] != ' '){
                return true;
            }
            if(boards[0][0][0] == boards[1][1][0] && boards[1][1][0] == boards[2][2][0] && boards[0][0][0] != ' '){
                return true;
            }
            // Diagonal wins between boards for top right corner
            if(boards[0][0][2] == boards[1][0][1] && boards[1][0][1] == boards[2][0][0] && boards[0][0][2] != ' '){
                return true;
            }
            if(boards[0][0][2] == boards[1][1][1] && boards[1][1][1] == boards[2][2][2] && boards[0][0][2] != ' '){
                return true;
            }
            if(boards[0][0][2] == boards[1][1][0] && boards[1][1][0] == boards[2][2][0] && boards[0][0][2] != ' '){
                return true;
            }
            // Diagonal wins between boards for bottom left corner
            if(boards[0][2][0] == boards[1][2][1] && boards[1][2][1] == boards[2][2][2] && boards[0][2][0] != ' '){
                return true;
            }
            if(boards[0][2][0] == boards[1][1][1] && boards[1][1][1] == boards[2][1][2] && boards[0][2][0] != ' '){
                return true;
            }
            if(boards[0][2][0] == boards[1][1][0] && boards[1][1][0] == boards[2][1][0] && boards[0][2][0] != ' '){
                return true;
            }
            // Diagonal wins between boards for bottom right corner
            if(boards[0][2][2] == boards[1][2][1] && boards[1][2][1] == boards[2][2][0] && boards[0][2][2] != ' '){
                return true;
            }
            if(boards[0][2][2] == boards[1][1][1] && boards[1][1][1] == boards[2][1][0] && boards[0][2][2] != ' '){
                return true;
            }
            if(boards[0][2][2] == boards[1][1][0] && boards[1][1][0] == boards[2][1][0] && boards[0][2][2] != ' '){
                return true;
            }
        
            return false;
        }

        bool checkDraw() {
            for(int h = 0; h < 3; h++) {
                for(int i = 0; i < 3; ++i) {
                    for(int j = 0; j < 3; ++j) {
                        if(boards[h][i][j] == ' ') {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

        void printBoards(vector<Player>& players) {
            cout << "current player: " << players[currentPlayer].getName() << endl; 
            for(int h = 0; h < 3; h++){
                cout << "Board " << h+1 << endl;
                cout << "   1 2 3";
                for(int i = 0; i < 3; ++i) {
                    cout << "\n  +-+-+-+\n";
                    switch(i)
                    {
                        case 0:
                            cout << "1 ";
                            break;

                        case 1:
                            cout << "2 ";
                            break;

                        case 2:
                            cout << "3 ";
                    }
                    for(int j = 0; j < 3; ++j) {
                        cout << "|" << boards[h][i][j];
                        if (j == 2) cout << "|";
                    }
                    if(i == 2) cout << "\n  +-+-+-+\n";
                }
                cout << "\n";
            }
        }

        void switchPlayer() {
            currentPlayer = (currentPlayer == 0) ? 1 : 0;
        }
    public:
    TicTacToe() : boards(3, vector<vector<char>>(3, vector<char>(3, ' '))), currentPlayer(0) {}

    void playGame(vector<Player>& players) {
        system("clear");
        int x, y, z;
        bool gameover = false;
        
        while(!gameover) {
            printBoards(players);
            if (players[currentPlayer].getRole() == "HUMAN"){
                cout << players[currentPlayer].getName() << ", enter which space you would like to place your move\n(format: board row column)\n(ex: '3 1 2' == top middle of board three): ";
                if (!(cin >> x >> y >> z)) {
                    // Not an integer, clear the error state and ignore the rest of the line
                    std::cin.clear();
                    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    system("clear");
                    cout << "Invalid input. Please enter an integer.\n";
                    continue;}
            } else {
                x = rand() % 3;
                y = rand() % 3;
                z = rand() % 3;
            }
            
            if (x < 1 || x > 3 || y < 1 || y > 3 || z < 1 || z > 3) {
                system("clear");
                cout << "Number out of range. Please try again.\n";
                continue;
            } else if(boards[x-1][y-1][z-1] != ' ') {
                system("clear");
                if (players[currentPlayer].getRole() == "HUMAN"){
                    cout << "Space occupied, try again.\n";
                }
                continue;
            }

            system("clear");

            boards[x-1][y-1][z-1] = players[currentPlayer].getX_O();

            if(checkWin()) {
                printBoards(players);
                cout << players[currentPlayer].getName() << " wins!\n";
                gameover = true;
            } else if(checkDraw()) {
                printBoards(players);
                cout << "The game is a draw!\n";
                gameover = true;
            } else {
                switchPlayer();
            }
        }
    }
};

int main() {
    const int num_players = 2;
    vector<Player> players(num_players); 
    assignPlayers(players);
    TicTacToe game;
    game.playGame(players);
    return 0;
}
