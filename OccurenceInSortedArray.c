#include <stdio.h>
//
// Find first and last occurence of an element in the sorted array which has duplicates
//

//
// Binary Search
//

int find(int *arr, int low, int high, int key) {
  
  int mid;
  
  mid = ( low + high) / 2;
  
  if ( arr[mid] == key) {
   
    return mid;
 
  } else {
   
    if (( key < arr[mid] ) && ( key > arr[low])) {
    
     return find(arr, low, mid-1, key);
     
   } else if (( key > arr[mid]) && ( key < arr[high])){
      
      return find( arr, mid+1, high, key); 
   }
  
  }
   return -1;
}

//
// Traverse only around the found element
//
void findOccurence ( int *arr , int low, int high ,int key ) {
  
  int index = find (arr, low, high, key);
 
  int firstOccurence = -1,lastOccurence = -1;
  
  if ( index != -1) {
      int temp = index;
 
      if ( arr[temp] == arr[temp-1] ) {
        while (( arr[temp] == key) && ( temp >= 0) ) {
          temp--;  
        }
        temp++;

      } 

      firstOccurence = temp;

       if ( arr[temp] == arr[temp +1] ) {
        while (( arr[temp] == key) && ( temp < 7) ) {
          temp++;  
        }
        temp--;

      } 
      lastOccurence = temp;
  }
  printf ( "\nFirst = %d Last = %d",firstOccurence,lastOccurence);
}


int main() {
  
  int arr[]= { 1,2,4,4,4,5,6};
  findOccurence(arr,0,6,7);
  
  
}
