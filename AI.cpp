#include <iostream>
    using std::cout;
    using std::endl;
    using std::cin;
    using std::streamsize;
#include <limits>
    using std::numeric_limits;
#include <string>
    using std::string;
#include <chrono>
#include <thread>
    
#include "functions.h"

//colors
//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
//http://www.cplusplus.com/forum/unices/36461/

//cs(); .. cs (creascreen does not actually clear the screen, adds tons of space.)
// actually methods to clear the screen can be danger inducing, quick look only.

int main()
{
    int column = -1;
	bool move = false;
    string board[SIX][SEVEN]; // can store up to  6 * 7, or 42 element
    bool won = false;
    string garbage = "";
    char playAgain = 'n';
    create(board);
    
    cout << "\n\nHere are the current \"RULES\""
         << "\n\t1. Once a column is full, you cannot choose it."
         << "\n\t2. If the board is full and no one has won, it is a stalemate.\n\n";
    
    do{
        cout << "\nEnter any character and press enter to continue.  ";
        cin >> garbage;
        cout << endl;
        display(board);
        cout << "\nPlease enter a number between 1 to 7 (0 is end) to indicate column\n";
    }while(garbage == "");
    
    do{
        while((column != 0 && (column <= SEVEN || column >= 1)) && won == false)
        {
            if(won != true){
        		do{
        			move = false;
                    cout << "\033[2;91mColumn(Red): \033[0m";
                    if((cin >> column) && (column >= 1 && column <= 7)){
                        move = addR(board, column-1);
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }while(move == false);
        		
        		display(board);
                won = winCase(board);
                if(won == true){
                    cout << "\n\033[2;91mRed Won!\033[0m" << endl;
                }
                if(checkStaleMate(board)){
                    cout << "\nYou have reached a stalemate" << endl;
                    won = true;
                }
            }
            if(won != true){
        		do{
                    move = false;
        			cout << "\033[2;94mColumn(Blue): \033[0m";
        			if((cin >> column) && (column >= 1 && column <= SEVEN)){
                        move = addB(board, column-1);
                    }
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        		}while(move == false);
        		
                display(board);
                won = winCase(board);
                if(won == true){
                    cout << "\n\033[2;94mBlue Won!\033[0m" << endl;
                }
                if(checkStaleMate(board)){
                    cout << "\nYou have reached a stalemate" << endl;
                    won = true;
                }
            }
        }
        cout << "\nWould you like to play again? (y or n) ";
        cin >> playAgain;
        if(playAgain == 'y'){
            won = false;
            create(board);
            cs();
            cs2();
            display(board);
            cout << "\nPlease enter a number between 1 to 7 (0 is end) to indicate column\n\n";
        }
    }while(playAgain == 'y');
    
    cout << "\n\n";

    return 0;

}