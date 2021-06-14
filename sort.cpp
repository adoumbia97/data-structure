#include<iostream>
 
using namespace std;
#define MAX 1000

/*
    Declaration of the procedure Sort called from the main program
    No paramater for the procedure
    The maximum of the array which will contain the element to be sorted is fixed to : MAX : 1000
    The user has the possibility to fill the array randomly after chossing the number of element to be sorted
    It print at the end the sorted array at the screen
*/
 
void Sort()
{
    //Declaration of variables
    string randomly;
    int i,j,n,loc,temp,min,a[MAX];      //Maximum of array which contains the value is limited
    
    // Implementation of the stack randomly or not
    writeTitle("Welcome to Selection sort secion");
    cout<<"Enter the number of elements you want to sort";
    cin>>n;
 
    // Implementation of the stack randomly or not
    cout << "Do you want to fill it randomly? Y/N \n";
    cin >>randomly;
    if(randomly=="Y" || randomly=="y")
    {
        for (int i = 0; i < n; ++i)
        {
          a[i]=rand() % 100;
        }
    }

    else
    {
        cout<<"\nEnter the elements\n";
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
    }

 
    //Sort the array in Selection sort       
 
    for(i=0;i<n-1;i++)
    {
        min=a[i];
        loc=i;
        for(j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                loc=j;
            }
        }
 
        temp=a[i];
        a[i]=a[loc];
        a[loc]=temp;
    }
 

    //Print the sorted array
    cout<<"\nSorted list is as follows\n";
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
 
}