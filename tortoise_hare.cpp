// ex. 8.12 tortoise and hare race
// the point of using pass by reference with pointer arguments in this example is to directly modify values in main()
//#include <iostream>
//#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// function prototypes
void startAnnouncement();
void clockTick(float);
void moveTortoise(int * const);
void moveHare(int * const);
void printRace(const int * const, const int * const);
void printWinner(const int *const, const int *const);

const int end = 70;  // global variable

int main()  // ******************* MAIN ***********************
{
   int tortoise = 1;
   int hare = 1;
   int speed = 1;

   srand(time(0));
  
   cout << "Choose speed of the race (1-slow, 15-fast): ";
   cin >> speed;
   cout << endl;

   startAnnouncement();    // print announcement for the start of the run 
   
   
   while( tortoise < end && hare < end) // ********** LOOP ****************
   {
      clockTick(speed);      // clockTick creates one second delay.
      
      moveTortoise(&tortoise);
      moveHare(&hare);

      printRace(&tortoise, &hare);   // display the moving letters
      printWinner(&tortoise, &hare);   // display the winner    

   } // ************************  END LOOP  *****************************

return 0;
}  // ****************** END MAIN *********************



void startAnnouncement()
{ cout << "BANG !!!!!\n" << "AND THEY'RE OFF !!!!!\n\n"; }


void moveTortoise(int *const tortoisePtr)
{
   int randomT = 1 + rand() % 10;

   if(1 <= randomT &&  randomT <= 5)
      *tortoisePtr = *tortoisePtr + 3;
   else if(6 <= randomT && randomT <= 7)
      *tortoisePtr = *tortoisePtr - 6;
   else //if(8 <= randomT && randomT <= 10)
      *tortoisePtr = *tortoisePtr + 1;

   if(*tortoisePtr < 1)
      *tortoisePtr = 1;
}


void moveHare(int *const harePtr)
{
   int randomH = 1 + rand() % 10;

   if(1 <= randomH && randomH <= 2)        
      *harePtr = *harePtr;       // sleep -- do nothing, retain previous position
   else if(3 <= randomH && randomH <= 4)
      *harePtr = *harePtr + 9;
   else if(randomH == 5)
      *harePtr = *harePtr - 12;
   else if(6 <= randomH && randomH <= 8)
      *harePtr = *harePtr + 1;   // small hop -- move hare 1 square to the right
   else //if(9 <= randomH && randomH <= 10)
      *harePtr = *harePtr - 2;   // small slip -- move hare 2 squares to the left

   if(*harePtr < 1)
      *harePtr = 1;
}


void clockTick(float s)
{
   clock_t second;      // generate a variable 'second' that holds 1 second
   second = clock() + (1/s)*CLOCKS_PER_SEC;      // change step if you want a different delay (floats also allowed)
   while(clock() < second) {};   // empty loop
}


void printRace(const int *const tPtr, const int *const hPtr)
{
   if ( *tPtr == *hPtr ) 
      cout << setw( *tPtr ) << "OUCH!!!";      
   else if ( *hPtr < *tPtr ) 
      cout << setw( *hPtr ) << "H" << setw( *tPtr - *hPtr ) << "T";
   else
      cout << setw( *tPtr ) << "T" << setw( *hPtr - *tPtr ) << "H";
   cout << '\n';  
   /* Alternative display -- with an array instead of 'setw':

   const int size = 70;
   int array[size]={0};

   for(int i=0; i<size+12; i++)    // added 1 to arraySize is cosmetic for the line
   {
      if(array[i] == 0) cout << "_";
      if(i == t)  cout << 'T';
      if(i == h)  cout << 'H';
   }
   cout << endl;
  */
}

void printWinner(const int *const tPtr, const int *const hPtr)
{
   if( *hPtr >= end && *tPtr < end )
      cout << "Hare wins. Yach.\n";
   if( *tPtr >= end && *hPtr < end )
      cout << "TORTOISE WINS!!! YAY!!!\n";
   if( *tPtr >= end && *hPtr >= end )
      cout << "A tie, but TORTOISE WINS!!! YAY!!!\n";
}
