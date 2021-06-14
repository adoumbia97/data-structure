#include <iostream>
using namespace std;

void merge(int *,int, int , int );              //Declartion of the procedure merge

/*
* Procedure merge_sort
* Parameter needed : array to be merged, the lowest and highest value in the array

*/
void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}


/*
*   Procedure merge to merge  
*   Parameter needed is : array, lowest and highest value in the array and the middle value
*/ 
void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}


/*
    Procedure Merge: Which is called in the main program
    Ask the user the number of the elements to sort
    Sort the elemens using  merge_sort 
    Print the sorted arrat at the screen
    return 0
  */
int Merge()
{
     writeTitle("Welcome to Merging sort");
    
    int myarray[30], num;
    cout<<"Enter number of elements to be sorted: \n";
    cin>>num;
    cout<<"Enter "<<num<<" elements to be sorted:";
    for (int i = 0; i < num; i++) { cin>>myarray[i];
    }
    merge_sort(myarray, 0, num-1);
    cout<<"Sorted array\n";
    for (int i = 0; i < num; i++)
    {
        cout<<myarray[i]<<"\t";
    }
    return 0;
}