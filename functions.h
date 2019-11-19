#ifndef FUNCTIONS_H
#define FUNCTIONS_H

///////////////////////////////////////////////////////////////////////////////

//string ZERO = "\033[0;30m0\033[0m";
const string ZERO = "\033[0;37m0\033[0m";
const string RED = "\033[2;91mR\033[0m";
const string BLUE = "\033[2;94mB\033[0m";
const string STAR = "\033[2;35m*\033[0m";
const int SIX = 6;
const int SEVEN = 7;

///////////////////////////////////////////////////////////////////////////////

void create(string board[SIX][SEVEN])
{
    for(int i = 0; i < SIX; i++)
    {
        for(int j = 0; j < SEVEN; j++)
        {
            board[i][j] = ZERO;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

void star(){for (int i = 0; i < 70; i++) {cout << STAR;}}

///////////////////////////////////////////////////////////////////////////////

void column()
{
    cout << "\t\t ";
    
    for(int i = 1; i < 8; i++)
    {   cout << "\033[2;92m";
        cout << " " << i << " ";
        cout << "\033[0m";
    }
    cout << "\n";
    
}

///////////////////////////////////////////////////////////////////////////////

void display(string board[SIX][SEVEN])
{
    int count = 0;
    int z = 7;
       
    for(int i = 0; i < SIX; i++) 
    {
        z = z - 1;
        
       for (int j = 0; j < SEVEN; j++) 
       {
           if(count == 0)
           {
                cout << "\033[2;92m";
                cout << "\t\t" << z;
                cout << "\033[0m";
           }
           
           cout << " " << board[i][j] << " ";
           count++;
           
           if(count == 7)
           {
               cout << "\n";
               count = 0;
           }
       } 
    }
    column();
    cout << endl;
    star();
    cout << "\n\n";
}

///////////////////////////////////////////////////////////////////////////////

string red(){ return RED;}

///////////////////////////////////////////////////////////////////////////////

string blue(){ return BLUE;}

///////////////////////////////////////////////////////////////////////////////
// Note about cs (clear screen) - simply adds tons of space, does not actually
void cs(){ cout << string( 100, '\n' );} // clear the screen.

//different function for same reason. cs doesn't look great.
void cs2(){
    cout << endl << endl;
    star();
    cout << "\n\nResetting the Board!\n\n";
    star();
    cout << endl << endl;
    std::chrono::seconds dura(5);
    std::this_thread::sleep_for(dura);
}

///////////////////////////////////////////////////////////////////////////////

bool addR(string board[SIX][SEVEN], int column)
{   
    bool row = false;
    for(int i = 0; i < SIX; i++)
    {
        if(board[5 - i][column] == ZERO)
        {
            board[5 - i][column] = red();
            row = true;
            i = 10;
        }
    }
    return row;
}

///////////////////////////////////////////////////////////////////////////////

bool addB(string board[SIX][SEVEN], int column)
{   
    bool row = false;
    for(int i = 0; i < SIX; i++)
    {
        if(board[5 - i][column] == ZERO)
        {
            board[5 - i][column] = blue();
            row = true;
            i = 10;
        }
    }
    return row;
}

///////////////////////////////////////////////////////////////////////////////

bool checkStaleMate(string board[SIX][SEVEN]){
    bool stalemate = true;
    for(int i = 0; i < SIX; i++)
    {
        for(int j = 0; j < SEVEN; j++)
        {
            if(board[i][j] == ZERO)
            {
                stalemate = false;
            }
        }
    }
    return stalemate;
}

///////////////////////////////////////////////////////////////////////////////

bool winCase(string board[SIX][SEVEN]){
    bool win = false;
    bool check = false;
    string piece = ZERO;
    int rowCheck, columnCheck, count = 0;
    
    for(int k = 0; k < 2; ++k){
        if(k == 0){
            piece = RED;
        }else{
            piece = BLUE;
        }
        for(int row = 0; row < SIX; ++row){
            for(int column = 0; column < SEVEN; column++){
                rowCheck = row;
                columnCheck = column;
                count = 0;
                do{
                    for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++){
                        if(board[rowCheck][columnCheck] == piece)
                        {
                            count++;
                            rowCheck--;
                            columnCheck++;
                            //cout << "\n" << count << "\n" << rowCheck << "\n" << columnCheck << endl;
                        }else{
                            i = 5;
                        }
                    }
                    if(count == 4){
                        win = true;
                        //cout << "\n" << piece << " win\n";
                    }else{
                        check = true;
                    }
                }while(win == false && check == false);
                rowCheck = row;
                columnCheck = column;
                count = 0;
                if(win == false){
                    do{
                        for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++){
                            if(board[rowCheck][columnCheck] == piece)
                            {
                                count++;
                                rowCheck++;
                                columnCheck++;
                                //cout << "\n" << count << "\n" << rowCheck << "\n" << columnCheck << endl;
                            }else{
                                i = 5;
                            }
                        }
                        if(count == 4){
                            win = true;
                            //cout << "\n" << piece << " 2 win\n";
                        }else{
                            check = true;
                        }
                    }while(win == false && check == false);
                }
                rowCheck = row;
                columnCheck = column;
                count = 0;
                if(win == false){
                    do{
                        for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++){
                            if(board[rowCheck][columnCheck] == piece)
                            {
                                //cout << "\n" << count << "\n" << rowCheck << "\n" << columnCheck << endl;
                                count++;
                                columnCheck--;
                                //cout << "\n" << count << "\n" << rowCheck << "\n" << columnCheck << endl;
                            }else{
                                i = 5;
                            }
                        }
                        if(count == 4){
                            win = true;
                            //cout << "\n" << piece << " 3 win\n";
                        }else{
                            check = true;
                        }
                    }while(win == false && check == false);
                }
                rowCheck = row;
                columnCheck = column;
                count = 0;
                if(win == false){
                    do{
                        for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++){
                            if(board[rowCheck][columnCheck] == piece)
                            {
                                count++;
                                rowCheck--;
                                //cout << "\n" << count << "\n" << rowCheck << "\n" << columnCheck << endl;
                            }else{
                                i = 5;
                            }
                        }
                        if(count == 4){
                            win = true;
                            //cout << "\n" << piece << " 4 win\n";
                        }else{
                            check = true;
                        }
                    }while(win == false && check == false);
                }
            }
        }
    }    
    return win;
}

///////////////////////////////////////////////////////////////////////////////








///////////////////////////////////////////////////////////////////////////////

#endif