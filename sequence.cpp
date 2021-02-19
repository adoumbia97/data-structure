
// C++ code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
 
#include <iostream>
using namespace std;
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
// Driver code
int SeqSearch(void)
{
    cout <<"\t \t \t \t ----------- --------------------\n" ;
    cout <<"\t \t \t \t "<< "Welcome to sequential search \n" ;
    cout <<"\t \t \t \t ----------- --------------------\n" ;
    
    int n;
    string choice;
    int target;
    cout <<"\t \t \t \t Enter the number of Element in the table\n";
    cin >>n;
    int arr[n];
    do
    {
        cout <<"\t \t \t \t \n 1 - Create the table \n";
        cout <<"\t \t \t \t \n  2 - Exit \n";
        cin >>choice;

        if(choice=="1")   //Creation of the table in 
        {
            cout <<"\t \t \t \t Enter the "<<n<<" value  of the table: \n";
            for (int i = 0; i < n; ++i)
            {
                int value;
                cin >> value;
                arr[i]=value;
                /* code */
            }
            //Now look for the element
            cout <<"Now enter the value to search in the table \n";
            cin >>target;
            int result = search(arr, n, target);
                (result == -1)
                ? cout << "\t\t\t\t\t Element is not present in array \n"
                : cout << "\t\t\t\t\t Element is present at index " << result <<"\n";
            

        }

        /* code */
    } while (choice!="2");

        
    return 0;
            

    // Function call
    
        
}
