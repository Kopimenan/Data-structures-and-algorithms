#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
   int left=2*root+1;
   int right=2*root+2;
   int max=root; // choosing root as the maximum value's index
     
   if(left<n && arr[left]>arr[max]){
   		max=left;
   }
   if(right<n && arr[right]>arr[max]){
   		max=right;
   }
   
   if(max!=root){//checking whether root need to be changed
		swap(arr[root],arr[max]);
		
		heapify(arr,n,max);
   }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n / 2 - 1; i >= 0; i--){
   		heapify(arr, n, i);
   }
        
  
   // extracting elements from heap one by one
   for (int i = n - 1; i >= 0; i--) {
   	// move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
	
	int n;
   	cout << "Enter the size of the array: ";
   	cin >> n;

	int heap_arr[n];
	cout << "Enter " << n << " elements for the array:\n";
	for(int i=0; i<n; i++) {
       cin >> heap_arr[i];
   }	
   
   //cout<<"Input array"<<endl;
   //displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}