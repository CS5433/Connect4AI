#ifndef AI_H
#define AI_H

#include "functions.h"

vector<int> optionsList;
/*Holds random chance for AI to choose vertical
 *Would have to be passed through multiple functions
 *Easier to keep it as a global
 */
bool boost = true;
const int FOUR = 4;

int placement(int min, int max)
{                                                 
   return rand() % max + min; // min = 0 and max = 7 is 0 - 6....
}

void blockRed(string board[SIX][SEVEN], int chosen, int& rRow, int& rCount)
{
   //cout << "\ncheckBoard\n";
   //update option list with possible places to choose from for ai.
   int pkForward = FOUR;
   int pkBackward = FOUR;
   int pkHorizon = FOUR;
   int pkVertical = FOUR;
   bool check = false;
   string piece = RED;
   int rowCheck, columnCheck, count = 0;
   
   for(int row = 0; row < SIX; ++row)
   {
      for(int column = 0; column < SEVEN; column++)
      {
         rowCheck = row;
         columnCheck = column;
         count = 0;
         do{//Bottom Left to Top Right diagonal like forward slash
            for(int i = 0; i < FOUR && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
            {
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
            if(pkForward > (FOUR - count)){
               pkForward = FOUR - count;
               //cout << "\n" << piece << " win\n";
            }else{
               check = true;
            }
         }while(pkForward != 0 && check == false);
         rowCheck = row;
         columnCheck = column;
         count = 0;
         if(pkBackward != 0){
            do{//Top Right to Bottom Left diagonal like back slash
               for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
               {
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
               if(pkBackward > (FOUR - count)){
                  pkBackward = FOUR - count;
                  //cout << "\n" << piece << " 2 win\n";
               }else{
                  check = true;
               }
            }while(pkBackward != 0 && check == false);
         }
         rowCheck = row;
         columnCheck = column;
         count = 0;
         if(pkHorizon != 0){
            do{//Horizontal
               for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
               {
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
               if(pkHorizon > (FOUR - count) && (columnCheck < 6 && board[rowCheck][columnCheck] == piece)){
                  pkHorizon = FOUR - count;
                  //cout << "\n" << piece << " 3 win\n";
               }else{
                  check = true;
               }
            }while(pkHorizon != 0 && check == false);
         }
         rowCheck = row;
         columnCheck = column;
         count = 0;
         if(pkVertical != 0)
         {
            do{//Vertical
               for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
               {
                  if(board[rowCheck][columnCheck] == piece)
                  {
                     count++;
                     rowCheck--;
                     //cout << "\n" << count << "\n" << rowCheck << "\n" << columnCheck << endl;
                  }else{
                     i = 5;
                  }
               }
               if(pkVertical > (FOUR - count) && board[rowCheck][columnCheck] == piece){
                  pkVertical = FOUR - count;
                  //cout << "\n" << piece << " 4 win\n";
               }else{
                  check = true;
               }
            }while(pkVertical != 0 && check == false);
         }
      }
   }
   
   
   
   //cout << "\npkForward: " << pkForward
   //     << "\npkBackward: " << pkBackward
   //     << "\npkHorizon: " << pkHorizon
   //     << "\npkVertical: " << pkVertical;
   
   if(rCount > pkForward)
   {
      rCount = pkForward;
   }
   if(rCount > pkBackward)
   {
      rCount = pkBackward;
   }
   if(rCount > pkHorizon)
   {
      rCount = pkHorizon;
   }
   if(rCount > pkVertical)
   {
      rCount = pkVertical;
   }
   
   int findRow = 0;
   string spot = "";
   bool found = false;
   while(found == false && findRow < 6){
      findRow++;
      spot = board[findRow][chosen];
      //cout << "\n\nspot: " << spot;
      if(spot != "\033[0;37m0\033[0m")
      {
         found = true;
         //cout << "\nFindRow Loop: " << findRow;
      }
   }
   
   findRow--;
   rRow = findRow;
   //cout << "\nfindRow = " << findRow << endl;
}

void defense(string board[SIX][SEVEN], int chosen, int rRow)
{
   optionsList.clear();
   if(rRow+1 <= 5 && board[rRow+1][chosen] == RED)
   {
      optionsList.push_back(chosen);
   }
   if(rRow+1 <= 5 && chosen > 0 && chosen < 6 && board[rRow+1][chosen-1] == RED
      && board[rRow][chosen+1] != ZERO)
   {
      optionsList.push_back(chosen+1);
   }
   if(rRow+1 <= 5 && chosen > 0 && chosen < 6 && board[rRow+1][chosen+1] == RED
      && board[rRow][chosen-1] != ZERO)
   {
      optionsList.push_back(chosen-1);
   }
   if(rRow-1 >= 5 && rRow+2 <= 5 && chosen > 0 && chosen < 6
      && board[rRow-1][chosen-1] == RED
      && board[rRow+1][chosen+1] == ZERO)
   {
      if(rRow+2 > 5 || (board[rRow+2][chosen-1] != ZERO))
      {
         optionsList.push_back(chosen-1);
      }
   }
   if(rRow-1 >= 5 && rRow+1 <= 5 && chosen > 0 && chosen < 6
      && board[rRow-1][chosen+1] == RED
      && board[rRow+1][chosen-1] == ZERO)
   {
      if(rRow+2 > 5 || (board[rRow+2][chosen-1] != ZERO))
      {
         optionsList.push_back(chosen-1);
      }
   }
   
   //cout << "\nmaking list: ";
   //for(int i : optionsList)
   //{
   //   cout << i+1 << " ";
   //}
}

int moveChoice(string board[SIX][SEVEN], int chosen)
{
   int rCount = 4;
   int rRow;
   int chance = 0;
   blockRed(board, chosen, rRow, rCount);
   vector<int> place;
   //cout << "\nrCount :" << rCount;
   if(rCount >= 2)
   {
      //cout << "\nno defense\n";
      int min = 0;
      int max = optionsList.size();
      if(max != 0)
      {
         chance = rand() % max + min; // min = 0 and max = 7 is 0 - 6....
      }
   }
   else
   {
      defense(board, chosen, rRow);
      //cout << "\ndefense\n";
      int min = 0;
      int max = optionsList.size();
      if(max != 0)
      {
         chance = rand() % max + min; // min = 0 and max = 7 is 0 - 6....
      }
   }
   return chance;
}

void checkBoard(string board[SIX][SEVEN], int chosen, int& bCount)
{
   //cout << "\ncheckBoard\n";
   //update option list with possible places to choose from for ai.
   int pkLeft = FOUR;
   bool check = false;
   string piece = BLUE;
   int rowCheck, columnCheck, count = 0;
   
   for(int row = 0; row < SIX; ++row)
   {
      for(int column = 0; column < SEVEN; column++)
      {
         rowCheck = row;
         columnCheck = column;
         count = 0;
         do{
            for(int i = 0; i < FOUR && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
            {
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
            if(pkLeft > (FOUR - count)){
               pkLeft = FOUR - count;
               //cout << "\n" << piece << " win\n";
            }else{
               check = true;
            }
         }while(pkLeft != 0 && check == false);
         rowCheck = row;
         columnCheck = column;
         count = 0;
         if(pkLeft != 0){
            do{
               for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
               {
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
               if(pkLeft > (FOUR - count)){
                  pkLeft = FOUR - count;
                  //cout << "\n" << piece << " 2 win\n";
               }else{
                  check = true;
               }
            }while(pkLeft != 0 && check == false);
         }
         rowCheck = row;
         columnCheck = column;
         count = 0;
         if(pkLeft != 0){
            do{
               for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
               {
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
               if(pkLeft > (FOUR - count)){
                  pkLeft = FOUR - count;
                  //cout << "\n" << piece << " 3 win\n";
               }else{
                  check = true;
               }
            }while(pkLeft != 0 && check == false);
         }
         rowCheck = row;
         columnCheck = column;
         count = 0;
         if(pkLeft != 0)
         {
            do{
               for(int i = 0; i < 4 && rowCheck >= 0 && columnCheck >= 0 && rowCheck < SIX && columnCheck < SEVEN; i++)
               {
                  if(board[rowCheck][columnCheck] == piece)
                  {
                     count++;
                     rowCheck--;
                     //cout << "\n" << count << "\n" << rowCheck << "\n" << columnCheck << endl;
                  }else{
                     i = 5;
                  }
               }
               if(pkLeft > (FOUR - count)){
                  pkLeft = FOUR - count;
                  //cout << "\n" << piece << " 4 win\n";
               }else{
                  check = true;
               }
            }while(pkLeft != 0 && check == false);
         }
      }
   }
   
   //cout << "\nbCount = " << bCount;
   //cout << "\npkLeft = " << pkLeft;
   
   bCount = pkLeft;
   
   int findRow = 0;
   string spot;
   do{
      spot = board[findRow][chosen];
      findRow++;
   }while(spot != BLUE);
   
   findRow--;
   //cout << "\nfindRow = " << findRow << endl;
   //cout << "\nmaking list: ";
   optionsList.clear();
   //Top
   if(board[findRow-1][chosen] == ZERO && (findRow-1) >= 0 && chosen >= 0 && (findRow-1) < SIX && chosen < SEVEN)
   {
      optionsList.push_back(chosen);
   }
   else
   {
      boost = false;
   }
   //Top Right
   if(board[findRow-1][chosen+1] == ZERO && (findRow-1) >= 0 && (chosen+1) >= 0 && (findRow-1) < SIX && (chosen+1) < SEVEN)
   {
      optionsList.push_back(chosen+1);
   }
   //Top Left
   if(board[findRow-1][chosen-1] == ZERO && (findRow-1) >= 0 && (chosen-1) >= 0 && (findRow-1) < SIX && (chosen-1) < SEVEN)
   {
      optionsList.push_back(chosen-1);
   }
   //Bottom Right
   if(board[findRow+1][chosen+1] == ZERO && (findRow+1) >= 0 && (chosen+1) >= 0 && (findRow+1) < SIX && (chosen+1) < SEVEN)
   {
      optionsList.push_back(chosen+1);
   }
   //Bottom Left
   if(board[findRow+1][chosen-1] == ZERO && (findRow+1) >= 0 && (chosen-1) >= 0 && (findRow+1) < SIX && (chosen-1) < SEVEN)
   {
      optionsList.push_back(chosen-1);
   }
   //Right
   if(board[findRow][chosen+1] == ZERO && (findRow) >= 0 && (chosen+1) >= 0 && (findRow) < SIX && (chosen+1) < SEVEN)
   {
      optionsList.push_back(chosen+1);
   }
   //Left
   if(board[findRow][chosen-1] == ZERO && (findRow) >= 0 && (chosen-1) >= 0 && (findRow) < SIX && (chosen-1) < SEVEN)
   {
      optionsList.push_back(chosen-1);
   }
   
   //for(int i : optionsList)
   //{
   //   cout << i+1 << " ";
   //}
}


bool hB(string board[SIX][SEVEN], int &bCount, int& column, const int& rColumn)
{
   bool moved = false;
   int min = 0;
   int max = 7;
   int temp;
   //int prevCol = column;
   //cout << "\nhB\n";
   /*if(bCount != 4){
      checkBoard(board, column, bCount);
   }*/
   if(bCount == 4)
   {
      column = placement(min, max);
      moved = addB(board, column);
      //cout << "\n\n" << column+1 << "\n\n";
      bCount--;
   }
   else if(bCount == 3)
   {
      checkBoard(board, column, bCount);
      //cout << "\nmaking choice: ";
      //temp = moveChoice(column, bCount, prevCol);
      temp = moveChoice(board, rColumn);
      column = optionsList[temp];
      moved = addB(board, column);
      //optionsList.clear();
      //cout << column+1 << "\n\n\n";
   }
   else if(bCount == 2)
   {
      checkBoard(board, column, bCount);
      //cout << "\nmaking choice: ";
      //temp = moveChoice(column, bCount, prevCol);
      temp = moveChoice(board, rColumn);
      column = optionsList[temp];
      moved = addB(board, column);
      //optionsList.clear();
      //cout << column+1 << "\n\n";
   }
   else if(bCount == 1)
   {
      checkBoard(board, column, bCount);
      //cout << "\nmaking choice: ";
      //temp = moveChoice(column, bCount, prevCol);
      temp = moveChoice(board, rColumn);
      column = optionsList[temp];
      moved = addB(board, column);
      //optionsList.clear();
      //cout << column+1 << "\n\n";
   }
   return moved;
}





//////////////////////////////////////////////////////////////////////////////
/*
int moveChoice(int column, const int& bCount, const int& prevCol)
{
   vector<int>::iterator it;
   int up = rand()% 101 + 0;
   string horizon = "";
   bool boost = false;
   if(up <= 15 && bCount == 4)
   {
      boost = true;
   }
   cout << "\nhorizon: " << horizon << "\nboost: " << boost << "\n\n";
   if(column >= 4 && column <= 6 && boost == false)
   {
      for(it = optionsList.begin(); it != optionsList.end(); ++it)
      {
         if((*it) >= column)
         {
            optionsList.erase(it);
         }
      }
   }
   else if(column >= 0 && column <= 3 && boost == false)
   {
      for(it = optionsList.begin(); it != optionsList.end(); ++it)
      {
         if((*it) <= column)
         {
            optionsList.erase(it);
         }
      }
   }
   else if(boost == true)
   {
      for(it = optionsList.begin(); it != optionsList.end(); ++it)
      {
         cout << "\nUp: " << (*it) << " ";
         if((*it) != column)
         {
            optionsList.erase(it);
         }
      }
   }
   
   int min = 0;
   int max = optionsList.size();
   int chance = 0;
   if(max != 0){
      chance = rand() % max + min; // min = 0 and max = 7 is 0 - 6...
   }
   else
   {
      cout << "\nNo available moves!\n";
   }
   return chance;
}*/

#endif