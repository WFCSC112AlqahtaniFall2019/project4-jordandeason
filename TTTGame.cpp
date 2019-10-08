/* Class: TicTacToe
 * Author: Jordan Deason
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include "time.h"
using namespace std;

int main() {

    //declaring of object of class type TicTacToe
    TicTacToe game;

    //declaring of variables
    int row;
    int col;
    int players;

    //to ensure different random number generated each time
    srand(time(NULL));

    //ask player for # players; can only be 1 or 2
    while (true) {
        cout << "Number of players?" << endl;
        cin >> players;
         if (players != 1 && players != 2){//there cannot be more than 1 or two players
            cout << "Invalid number of players. Must enter either 1 or 2." << endl;
         }
         else {
            break;
     }
    }

    game.initializeBoard(); //initializes board
    game.printBoard(); //prints board

    //one player game. playing against computer
    if (players == 1){
        int beginner;
        beginner = rand()% 2; // randomly assigns whether computer or user goes first
        if (beginner == 1) {
            game.changePlayer();
        }
        while(!game.isBoardFull() && !game.checkForWin()){
            if (game.getCurrentPlayerNumber() == 1) {
                cout << "Player: " << game.getCurrentPlayerNumber() << endl;
                cout << "Guess the row:" << endl;
                cin >> row;
                cout << "Guess the column:" << endl;
                cin >> col;
                if (row > 3 || col > 3 || row < 1 || col < 1) {// if col or row guess is out of range there is an error
                    cout << "Row and column must be between 1 and 3." << endl;
                }
                else if(!game.placeMark(row - 1, col - 1)) {//in the case that a user or computer guesses a spot already marked
                    cout << "Spot has already been taken." << endl;
                }
                else {
                    game.placeMark(row - 1, col - 1);
                    game.printBoard();
                    game.changePlayer();
                }
            }
            else {
                cout << "Player: " << game.getCurrentPlayerNumber() << endl;
                cout << "Guess the row:" << endl; //computer "guesses" row
                row = rand()% 3 + 1;
                cout << row << endl;
                cout << "Guess the column:" << endl; //computer "guesses" col
                col = rand()% 3 + 1;
                cout << col << endl;
                game.placeMark(row - 1, col - 1);
                game.printBoard();
                game.changePlayer();
            }
        }
    }

    //two player game
    if (players == 2) {
    while (!game.isBoardFull() && !game.checkForWin()) { //neither condition can be true for game to continue
        cout << "Player: " << game.getCurrentPlayerNumber() << endl;
        cout << "Guess the row:" << endl;
        cin >> row;
        cout << "Guess the column:" << endl;
        cin >> col;
        if (row > 3 || col > 3 || row < 1 || col < 1) { // if col or row guess is out of range there is an error
            cout << "Row and column must be between 1 and 3." << endl;
        }
        else if(!game.placeMark(row - 1, col - 1)) {//in the case that a user or computer guesses a spot already marked
            cout << "Spot has already been taken." << endl;
        }
        else {
            game.placeMark(row - 1, col - 1);
            game.printBoard();
            game.changePlayer();
        }
    }
}

    //if board is full
    if(game.isBoardFull()) {
        cout << "Board is full. Tie game." << endl;
    }

    if(game.checkForWin()) {
        game.changePlayer(); // necessary because player switches before checking for win
        cout << "Player " << game.getCurrentPlayerNumber() << " is the winner." << endl;
    }

    return 0;
}