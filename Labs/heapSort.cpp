#include <iostream>
using namespace std;

// swapping function
void swap(int* a, int* b) {
   int temp = *a;
   *a = *b;
   *b = temp;
}
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int largest = root;
   int leftNode = 2*root + 1;
   int rightNode = 2*root + 2;

   // check whether value of left node is greater than the value of parent
   if ((leftNode < n) && (arr[leftNode] > arr[largest])) {
      largest = leftNode;
   }
   // check whether value of right node is greater than the value of parent
   if ((rightNode < n) && (arr[rightNode] > arr[largest])) {
      largest = rightNode;
   }
   // when found a larger value than parent, then swap the values & recursively call heapify for that node
   if (largest != root) {
      swap(&arr[root], &arr[largest]);
      heapify(arr, n, largest);
   }   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   // hear (n/2)-1 is the smallest parent node
   for (int i=(n/2)-1; i>-1; i--) {
      heapify(arr, n, i);
   }

   // extracting elements from heap one by one
   for (int i=n-1; i>-1; i--) {
      swap(&arr[0], &arr[i]);
      // move the largest value to end of array & agin call heapify for that node 
      heapify(arr, i, 0);
   }  
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i) {
      cout << arr[i] << " ";
   }
   cout << "\n";
      
}
  
// main program
int main() {
   
   cout << "Enter the no.of values :";
   int n; // no of elements
   cin >> n;

   // initialize empty array
   cout << "Enter the space separated integers6 :";
   int heap_arr[n];
   //  
   for (int i=0; i<n; i++) {
      cin >> heap_arr[i];
   }
/*
   int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
*/
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "\nSorted array"<<endl;
   displayArray(heap_arr, n);
}