#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

const int SIZE = 10; // when using functions array size needs to be declared outside main

int precondition();
int inputNewMovePlayer1();
int inputNewMovePlayer2();
void displ(const int f[][SIZE]); 
int testForWin();
void displayTheWinner();


int field[SIZE][SIZE]={0};

int row1, col1, row2, col2;
int counter = 0;
int victory;

int main()
{
   precondition();
   srand(time(0));

   while (counter < 64) // ensures the game stops when all fields are full, in case there is no winner
   {

      inputNewMovePlayer1();
      displ(field);
      cout << endl;
      victory = testForWin();
      if (victory  > 0)
      {
         displayTheWinner();
         break;
      }

      inputNewMovePlayer2();
      displ(field);
      cout << endl;
      victory = testForWin();
      if (victory  > 0)
      {
         displayTheWinner();
         break;
      }

      counter++;
   } // end while

   return 0;
}



//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//       FUNCTIONS
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Precondition for the borders around the display board
int precondition()
{
   // this three initalizations enable conditionals field[row1+/-1][col1] == 0 and field[row2+/-1][col2] == 0 to work properly
   for(int i=0; i<SIZE; i++)
      field[i][0]=3;
   for(int i=0; i<SIZE; i++)
      field[i][9]=5;
   for(int i=1; i<SIZE; i++)
      field[9][i]=4;
}

// PLayer 1 enters a new move-----------------------------------------------------------------------------
int inputNewMovePlayer1()
{
      cout << "Player 1: ";
      row1 = 1+rand() % 9;
      col1 = 1+rand() % 9;
      
      //cin >> row1;
      //cin.ignore(); // skip comma
      //cin >> col1;

      if(field[row1][col1] == 0 && field[row1-1][col1] == 0 && field[row1+1][col1] != 0 && (row1 >= 1 && row1 <= 8 && col1 >= 1 && col1 <= 8))
         field[row1][col1] = 1;
      else if(field[row1][col1] != 0 || field[row1-1][col1] != 0 || field[row1+1][col1] == 0 || row1 < 1)
      {
         while(field[row1][col1] != 0 || field[row1-1][col1] != 0 || field[row1+1][col1] == 0 || row1 < 1)
         {
            cout << "Player 1, repeat:" << endl;
            
            //cin >> row1;
            //cin.ignore(); // skip comma
            //cin >> col1;
            
         row1 = 1+rand() % 9;
         col1 = 1+rand() % 9;
         }
         field[row1][col1] = 1;
      }

      else if(row1 < 1 || row1 > 8 || col1 < 1 || col1 > 8)
      {
         while(row1 < 1 || row1 > 8 || col1 < 1 || col1 > 8)
         {
            cout << "Player 1, repeat:" << endl;
            
            //cin >> row1;   // enter a row then comma then a column
            //cin.ignore(); // skip comma
            //cin >> col1;
            
         row1 = 1+rand() % 9;
         col1 = 1+rand() % 9;
         }
         field[row1][col1] = 1;
      }
      cout << endl;

return 0;
}

// PLayer 2 enteres a new move --------------------------------------------------------------------------------
int inputNewMovePlayer2()
{
      cout << "Player 2: ";
      row2 = 1+rand() % 9;
      col2 = 1+rand() % 9;
      
      //cin >> row2;
      //cin.ignore(); // skip comma
      //cin >> col2;
      

      if(field[row2][col2] == 0 && field[row2-1][col2] == 0 && field[row2+1][col2] != 0 && (row2 >= 1 && row2 <= 8 && col2 >= 1 && col2 <= 8))
         field[row2][col2] = 2;
      else if(field[row2][col2] != 0 || field[row2-1][col2] != 0 || field[row2+1][col2] == 0 || row2 < 1)
      {
         while(field[row2][col2] != 0 || field[row2-1][col2] != 0 || field[row2+1][col2] == 0 || row2 < 1)
         {
            cout << "Player 2, repeat:" << endl;
         row2 = 1+rand() % 9;
         col2 = 1+rand() % 9;

            //cin >> row2;
            //cin.ignore(); // skip comma
            //cin >> col2;
         }
         field[row2][col2] = 2;
      }

      else if(row2 < 1 || row2 > 8 || col2 < 1 || col2 > 8)
      {
         while(row2 < 1 || row2 > 8 || col2 < 1 || col2 > 8)
         {
            cout << "Player 2, repeat:" << endl;
            row2 = 1+rand() % 9;
            col2 = 1+rand() % 9;

            //cin >> row2;
            //cin.ignore(); // skip comma
            //cin >> col2;
         }
         field[row2][col2] = 2;
      }
      cout << endl;
}


// function display field----------------------------------------------------------------------------------------
void displ(const int f[][SIZE])
{
   // column counter
   cout << "    ";
   for(int i=1; i<SIZE-1; i++)
      cout << i << ' ';
   cout << '\n' << endl;

   // field / table
   for(int display1=1; display1 < SIZE-1; display1++)
   {
      cout << display1 << "   ";  // line counter
      for(int display2=1; display2 < SIZE-1; display2++)
      {
         if(f[display1][display2] == 0)
            cout << "-" << ' ';
         else
            cout << f[display1][display2] << ' ';
      }
      cout << endl; 
   }
}
      

// test for the winner in all directions (player 1 and player 2)---------------------------------------------------
int testForWin()
{
     for (int i=0; i<SIZE; i++) // columns
     {
       for (int j=0; j<SIZE; j++) // rows
       {
         // vertical victory test
         if (field[j][i] == 1 && field[j][i+1] == 1 && field[j][i+2] == 1 && field[j][i+3] == 1)
            return 1;

         if (field[j][i] == 2 && field[j][i+1] == 2 && field[j][i+2] == 2 && field[j][i+3] == 2)
            return 2;

         // horizontal victory test
         if (field[j][i] == 1 && field[j+1][i] == 1 && field[j+2][i] == 1 && field[j+3][i] == 1)
            return 1;

         if (field[j][i] == 2 && field[j+1][i] == 2 && field[j+2][i] == 2 && field[j+3][i] == 2)
           return 2;

         // diagonal victory test (left to right)
         if(field[j][i] == 1 && field[j+1][i+1] == 1 && field[j+2][i+2] == 1 && field[j+3][i+3] == 1)
            return 1;

         if(field[j][i] == 2 && field[j+1][i+1] == 2 && field[j+2][i+2] == 2 && field[j+3][i+3] == 2)
           return 2;

         // diagonal victory test (right to left)
         if(field[j][i] == 1 && field[j-1][i+1] == 1 && field[j-2][i+2] == 1 && field[j-3][i+3] == 1)
            return 1;

         if(field[j][i] == 2 && field[j-1][i+1] == 2 && field[j-2][i+2] == 2 && field[j-3][i+3] == 2)
            return 2;
       }
     }
}

// display the winner-------------------------------------------------------------------------------------
void displayTheWinner()
{
   cout << "Player " << victory << " wins!" << endl;   // change for either player
}
