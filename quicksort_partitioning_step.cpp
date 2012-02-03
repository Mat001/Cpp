/* this program puts its first element into a position where all elements on the left of that element are less than the element and all the right elements are greater.
 * This is a 'partitioning step' of the (recursive) quicksort algorithm
 * (Next step will be to implement recursion to apply this partitioning step to all left and right sub-arrays. We will end up with a sorted array.)
 * This program also demonstrates reading-in integer data from a file ('data.txt')
 */

#include <iostream>
#include <fstream>
using namespace std;

const int arraySize = 42; // 42 elements in the input file
int array[arraySize] = {};

// global variables
int start = 0;
int end = arraySize-1;
int temp1=0;
int temp2=0;

int main() // **********************  MAIN  ******************************
{
   // read-in 'data.txt' file into array 'array'
   int x = 0;
   ifstream readIn("data.txt", ios::in);
   while(readIn >> array[x])
      x++;

   // variables local to main
   int first = array[0];
   int terminate;
   bool flag = 1;
   int final=1;
  
   // display information 
   cout << "In this program, the first element of the array (" << first << ") " << "will be put in its final position.\n\n"; 
   // print original array
   cout << "Original: \n";
   for(int i=0; i<=arraySize-1; i++)
      cout << array[i] << ' ';
   cout << endl;

   
   while(flag)    // flag will be false when the first element stops changing position (stabilizes at the final location) -- loop will stop
   {
      // from right to left
      for(int i = end; i >= 0; i--)
      {
         if(array[i] <= array[start])  // when number less than start number is hit, swap them
         {
            // swap
            int hold1 = array[i];   // int hold = 12;
            array[i] = array[start];   // array[7] = 37;
            array[start] = hold1;   // array[start] = 12;
            temp1 = i;  // = 7
            break;
         }
      }

      
      // from left to right
      for(int j = start; j <= arraySize; j++)
      {
         if(array[j] >= array[temp1])  // when number greater than my number is hit, swap them
         {
            // swap
            int hold2 = array[j];   // int hold2 = 89;
            array[j] = array[temp1];   // array[4] = 37;
            array[temp1] = hold2;    // array[temp1] = 89;
            temp2 = j;  // = 4
            break;
         }
      }
      
      // termination when sunbscript and terminate don't differ
      for(int i=0; i <= arraySize-1; i++)
         if(array[i] == first)
            if(i - terminate == 0)
               flag = 0;

         
      for(int i=0; i<=arraySize-1; i++)
         if(array[i] == first)
            terminate = i;

      end = temp1;
      start = temp2;
   }
   // print final array -- sorted first element
   cout << "\nSorted:\n";
   for(int i=0; i<=arraySize-1; i++)
   {
      cout << array[i] << ' ';
      if(array[i] == first)   // this gives final subscript of the first element's final position -- for the displayed information
         final = i+1;   // add 1 to start counting from 1, not 0 in the comment below
   }
   cout << "\n\n" << first << " (array above) is now placed at " << final << "th position.\n";
   cout << "Left of " << first << " all values are less than " << first << "." <<
   "\nRight of " << first << " all values are greater than " << first << "." << endl;
}  // ***************************  END MAIN  *****************************
 



