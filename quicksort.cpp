// Quicksort -- in progress

#include <iostream>
using namespace std;

void quicksort(int array[], int startSize, int endSize);
//void partition()...

int main()
{
   const int arraySize = 10;
   int array[arraySize] = {37, 3, 12, 65, 1, 89, 42, 22, 9, 17};
  
   // call quicksort function
   quicksort(array, arraySize);

   
}
 
/*
 sort the first element
 sort the first element of the left subarray, sort the first element of the right subarray
 sort the first element of the left subarray of the left subarray, sort the first element of the right subarray of the right subarray
  
 * */

   // 1. partitioning step -- sort the first element
   void quicksort(int a[], int start, int end)
   {
   
      
      // 2. recursive step -- perform step 1 (partitioning step)  on each subarray.
      // partition will feed subarrays into quicksort f.
      partition(int a[start], &start)
         



   }

   void partition(...)
   {
      // from right to left
      for(int i=end; i < start; i--)
      {
         if(i < start)  // when number less than start number is hit, swap them
         {
            // swap
            int hold1 = array[i];   // int hold = 17;
            array[i] = array[start];   // array[9] = 37;
            array[start] = hold1;   // array[start] = 17;
         }
      }
      // from left to right
      for(int j = start + number of numbers at the beginning you skip; j >= end; j++)
      {
         if(j > array[start])  // when number more than my number is hit, swap them
         {
            // swap
            int hold2 = array[j];
            array[j] = array[start];
            array[start] = hold2;
         }
      }


   }
