
#include <iostream>
using namespace std;

/*
* Functoin to search an item in an array in sequential sort
* Parameter needed is the array, the number of elemet in the array (n)
* The item to be searched
* Return the index of the element in the array if it is present or -1

*/
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
 
/*
  Function SeqSearch called from the main program
  Offer the possibility to the user to define the number of element in the array  
*/
int SeqSearch(void)
{
    writeTitle("Welcome to sequential search ");
    int n;
    string choice;
    int target;
    cout <<"\t \t \t \t Enter the number of Element in the table\n";
    cin >>n;
     // Check the value from the user is an integer
    while(cin.fail())                                    
    {
      cout <<"The value you enter is not correct \n";
      cin.clear();
      cin.ignore(256,'\n');
      cin >> n;
    }
    int arr[n];                                         
    do
    {
        writeChoice("1","Create the table");
        writeChoice("2","Exit");
        cin >>choice;
        if(choice=="1")   //Creation of the table in 
        {
            cout <<"\t \t \t \t Enter the "<<n<<" value  of the table: \n";
            for (int i = 0; i < n; ++i)
            {
                int value;
                cin >> value;
                while(cin.fail())     //Check the value from the user is an integer                                  
                  {
                    cout <<"The value you enter is not correct \n";
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> value;
                  }
                arr[i]=value;
           
            }
            cout <<"Now enter the value to search in the table \n";          //Now look for the element
            cin >>target;
            int result = search(arr, n, target);
                (result == -1)
                ? cout << "\t\t\t\t\t Element is not present in array \n"
                : cout << "\t\t\t\t\t Element is present at index " << result <<"\n";
        }

    } while (choice!="2");
 
    return 0;  
        
}
