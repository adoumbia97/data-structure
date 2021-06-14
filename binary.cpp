#include <bits/stdc++.h> 
using namespace std; 

/*
  Funcion bsearch : Search an item in an array 
  Parameter needed: the lowest(d), highest(f) in the arrary, array and the item to be searched
  Return the item the index of the element found using Binary Search
*/
int bsearh(int d, int f, int arr[], int target)
{
	bool find =false;
  bool leave =false;                //Check either to leeave or not the loop
	int res;
	int i;
	int m;
  int sum;
	res=d-1;
	while(!find && !leave)
	{
		sum=d+f;
		m= sum / 2;
		if(arr[m]==target)
		{
			res=m;
			find=true;
		}
		else if(target<arr[m]){f=m-1;}
		else{d=m+1;}

    if(m==d || m==f){leave=true;}
	}


  if(find){return res;}
  else{return -1;}


}



/* Function to sort an array
* Parameters needed: array, the number of element contained in the arrat
  Return the sorted array
*/
int * sort(int arr[], int n)
{
  //Local variables declaration
  int i,j;
  int temp;

  //sorting - ASCENDING ORDER
  for(i=0;i<n;i++)
  {   
    for(j=i+1;j<n;j++)
    {
      if(arr[i]>arr[j])
      {
        temp  =arr[i];
        arr[i]=arr[j];           

        arr[j]=temp;
      }
    }
  }
  
  //print sorted array elements
  cout<<"Sorted (Ascending Order) Array elements:"<<endl;
  for(i=0;i<n;i++)
    cout<<arr[i]<<"\t";
  cout<<endl; 
  
  
  return arr;
  
}
/*
  Function BInary search called from the main program
  Offer the possibility to the user to define the number of element in the array and the filling
  Sort the array(sort) before applying the binary search(bsearch)
*/

int BinarySearch(void)
{
    writeTitle("Welcome to Binary Search  section");
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
        writeChoice("1","Create the table");
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
                /* code */
            }
            //Now look for the element
            cout <<"Now enter the value to search in the table \n";
            cin >>target;
            int* arri=sort(arr, n);               
            int result = bsearh(0,n-1, arri, target);
                (result == -1)
                ? cout << "\t\t\t\t\t Element is not present in array \n"
                : cout << "\t\t\t\t\t Element is present at index " << result <<"\n";
            

        }

        
    } while (choice!="2");

        
    return 0;
}