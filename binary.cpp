#include <bits/stdc++.h> 
using namespace std; 

int bsearh(int d, int f, int arr[], int target)
{
	bool find =false;
	int res;
	int i;
	int m;
	res=d-1;
	while(!find)
	{
		int sum=d+f;
		m= sum / 2;
		if(arr[m]==target)
		{
			res=m;
			find=true;
		}
		else if(target<arr[m]){f=m-1;}
		else{d=m+1;}
	}
	return res;

}




int * sort(int arr[], int n)
{
  //array declaration

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


int BinarySearch(void)
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
            int* arri=sort(arr, n);
            int result = bsearh(0,n-1, arri, target);
                (result == -1)
                ? cout << "\t\t\t\t\t Element is not present in array \n"
                : cout << "\t\t\t\t\t Element is present at index " << result <<"\n";
            

        }

        /* code */
    } while (choice!="2");

        
    return 0;
}