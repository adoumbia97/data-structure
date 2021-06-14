#include<iostream>
#include <cstring>
#define MAX_DATA_SIZE 1000

using namespace std;

//The following function computes the sum of the first n numbers : 1+2+3+.......+n
//Returns the sum of the first n numbers
int sum_of_numbers(int n) {
 int s=0;
 for (int i=1; i<=n; i++)
	s=s+i;
 return s;
}

void sum() {
 //read a number n and compute the sum of the first n numbers using the function sum_of_numbers(n)
 int n;
 cout <<  "Enter a number : ";
 cin >> n;
 cout <<  "The sum of the first " << n << " numbers is : " << sum_of_numbers(n) << "\n";//function call
}

// The following section implements List .................................................
class ListType {
 public:     //everything inside public can be accessed in the main function
    ListType(int n) { //constructor for the class ListType to allocate memory
    	MAX_ITEMS = n;  //takes the maximum number of items
    	nbItems = 0;    //takes the number of items
    };

    void MakeEmpty(){ //a function that empties the list and it has no return type
    	nbItems = 0;
    };

    bool IsEmpty() const { // a function that checks to see if the list is empty
 	return (nbItems == 0);
    };

    bool IsFull() const { // a function that checks to see if the list is full
 	return (nbItems == MAX_ITEMS-1);
    };

    void FindNode(int searchItem) { //a function that finds an item in the list
 	int i = 0;
	while (!((items[i]==searchItem)||(i>nbItems)))
 		i++;
	if (i>nbItems) 
		cout << "\nThe item : " << searchItem << " is not found !\n";
	else 	cout << "\nThe item : " << searchItem << " is found at position " << i << "\n";
    };

    void InsertNode(int position, int newItem) { //a function that insert a item into the list
 	if (!(nbItems == MAX_ITEMS)) {
 	 for (int i=nbItems; i>position; i--)
	  items[i] = items[i-1];
	 items[position] = newItem;
	 nbItems++;
	}
    };

    void DeleteNode(int position) { //a function that deletes an item from the list
 	if (!(nbItems == 0)) {
 	 for (int i=position; i<nbItems; i++)
	  items[i] = items[i+1];
	 items[MAX_ITEMS-1] = 0;
	 nbItems--;
	}
    };

    void Display() {  //a function that displays the content of the list
	cout << "\nContent of the List : \n";
 	for (int i=0; i<nbItems; i++)
 		cout << "\n " << i << "\t" << items[i];
	cout << "\n";
    };

    void RandomNodes() { //a function that fills the list with random numbers 
  	for(int i=0; i<MAX_ITEMS; i++) items[i]=rand()%100+1;
	nbItems = MAX_ITEMS;
    };
    ~ListType() { } //destructor for the constructor ListType which deallocate the memory

 private: //things in the private class can't be accessed in the main function of the program
    int MAX_ITEMS, nbItems;
    int items[MAX_DATA_SIZE];
};

// The following section implements Stack .................................................
class StackType {
 public:     //everything inside public can be accessed in the main function
    StackType(int n) { //constructor for the class StackType to allocate memory
    	STACK_CAPACITY = n;  //takes the maximum number of items
    	myTop = -1;    //point to top of stack and -1 means the stack is empty
    };

    void MakeEmpty(){ //a function that empties the stack and it has no return type
    	myTop = -1;
    };

    bool IsEmpty() const { // a function that checks to see if the stack is empty
 	return (myTop == -1);
    };

    bool IsFull() const { // a function that checks to see if the stack is full
 	return (myTop == STACK_CAPACITY-1);
    };

    int top() const { //a function that finds an item in the stack and this is normally the top value
 	if ( !IsEmpty() )
	return (items[myTop]);
	else
	{
	cout << "*** Stack is empty -- returning garbage value ***\n";
		int garbage; return garbage;
	}
    };

    void push(int newItem) { //a function that insert a item into the stack
 	if (myTop < STACK_CAPACITY-1) 
	{
		++myTop;
		items[myTop]=newItem;
	}
	else
	{
	cout <<
	"*** Stack full -- can't add new value ***\n"
	"Must increase value of STACK_CAPACITY in Stack\n";
	exit(0);
 	}	 
    };

    void pop() { //a function that deletes an item from the stack
 	if ( !IsEmpty() )
	myTop--;
	else
	cout << "*** Stack is empty -- can't remove a value ***\n";
    };

    void Display() {  //a function that displays the content of the stack
	cout << "\nContent of the Stack : \n";
 	for (int i=myTop; i>=0; i--)
 		cout << "\n " << i << "\t" << items[i];
	cout << "\n";
    };

    void RandomElements() { //a function that fills the stack with random numbers 
  	for(int i=0; i<STACK_CAPACITY; i++) items[i]=rand()%100+1;
	myTop = STACK_CAPACITY-1;
    };
    ~StackType() { } //destructor for the constructor StackType to deallocate the memory

 private: //things in the private class can't be accessed in the main function of the program
    int STACK_CAPACITY, myTop;
    int items[MAX_DATA_SIZE];
};

// The following section implements Queue .................................................
class Circular_Queue
{
    private:
        int *cqueue_arr;
        int front, rear;
	int QUEUE_CAPACITY;
    public:
        Circular_Queue(int n)
        {
            cqueue_arr = new int [MAX_DATA_SIZE];
            rear = front = -1;
	    QUEUE_CAPACITY =n;
        }
        //Insert into Circular Queue
        void enqueue(int item)
        {
            if ((front == 0 && rear == QUEUE_CAPACITY-1) || (front == rear+1))
            {
                cout<<"Queue Overflow \n";
                return;
            }
            if (front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                if (rear == QUEUE_CAPACITY - 1)
                    rear = 0;
                else
                    rear = rear + 1;
            }
            cqueue_arr[rear] = item ;
        }
        //Delete from Circular Queue
        int dequeue()
        {
            if (front==-1)
            {
                cout<<"Queue Underflow.\n";
                return cqueue_arr[front++];
            }
            cout<<"Element deleted from queue is : "<<cqueue_arr[front]<<endl;
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                if (front == QUEUE_CAPACITY - 1)
                    front = 0;
                else
                    front = front + 1;
            }
            return 0;
        }
        //Display Circular Queue
        void display()
        {
            int front_pos = front, rear_pos = rear;
            if (front==-1)
            {
                cout<<"Queue is empty\n";
                return;
            }
            cout<<"Queue elements :\n";
            if (front_pos <= rear_pos)
            {
                while (front_pos <= rear_pos)
                {
                    cout << "\n" << front_pos << "   " <<cqueue_arr[front_pos];
                    front_pos++;
                }
            }
            else
            {
                while (front_pos <= QUEUE_CAPACITY - 1)
                {
                    cout << "\n" << front_pos << "   " <<cqueue_arr[front_pos];
                    front_pos++;
                }
                front_pos = 0;
                while (front_pos <= rear_pos)
                {
                    cout << "\n" << front_pos << "   " <<cqueue_arr[front_pos];
                    front_pos++;
                }
            }
            cout<<endl;
        }
	bool IsEmpty() { // a function that checks to see if the queue is empty
 	if(front>rear){ 
        return true; 
    }
	else{ 
        return false;
    } 
    }

	bool IsFull()  { // a function that checks to see if the queue is full
 	return ((rear+1)%QUEUE_CAPACITY==front);
    }
	int myfront()  { //a function that finds an item in the queue and this is normally the top value
 	if ( !IsEmpty() )
	return (cqueue_arr[front]);
	else
	{
	cout << "*** Queue is empty -- returning garbage value ***\n";
		int garbage; return garbage;
	}
	}
	int myback()  { //a function that finds an item in the queue and this is normally the top value
 	if ( !IsEmpty() )
	return (cqueue_arr[rear]);
	else
	{
	cout << "*** Queue is empty -- returning garbage value ***\n";
		int garbage; return garbage;
	}
    }
	void MakeEmpty(){ //a function that empties the queue and it has no return type
    	while(!IsEmpty())
	{
		dequeue();
    }
}
};

// The following section implements Selection Sort .................................................

void swap(int *xp, int *yp) 
{ 
	int temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min_idx; 

	// One by one move boundary of unsorted subarray 
	for (i = 0; i < n-1; i++) 
	{ 
		// Find the minimum element in unsorted array 
		min_idx = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min_idx]) 
			min_idx = j; 

		// Swap the found minimum element with the first element 
		swap(&arr[min_idx], &arr[i]); 
	} 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// The following section implements Merge Sort .................................................
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 

	/* create temp arrays */
	int L[n1], R[n2]; 

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1+ j]; 

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2) 
	{ 
		if (L[i] <= R[j]) 
		{ 
			arr[k] = L[i]; 
			i++; 
		} 
		else
		{ 
			arr[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	/* Copy the remaining elements of L[], if there 
	are any */
	while (i < n1) 
	{ 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	/* Copy the remaining elements of R[], if there 
	are any */
	while (j < n2) 
	{ 
		arr[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

/* l is for left index and r is right index of the 
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
	if (l < r) 
	{ 
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l+(r-l)/2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m+1, r); 

		merge(arr, l, m, r); 
	} 
}
/* UTILITY FUNCTIONS */
/* Function to print an array */
void displayArray(int A[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout << A[i] << " "; 
	cout << endl; 
} 
// The following section implements Linear Search .................................................
class LS
{
    public:
        void LinearSearch(int arr[], int value, int i, int n)
        {   int found = 0;
            for (i = 0; i < n ; i++)
            {
                if (value == arr[i] )
                {
                   found = 1;
                    break;
                }
            }
            if (found == 1)
            {
                cout<<"Element is present in the array at position   "<<i+1;
            }
            else
            {
                cout<<"Element is not present in the array.";
            }
        }
};
// The following section implements Binary Search .................................................
 class BS
    {
    public:
        /*
         * Binary Search function
         */
        void BinarySearch(int array[], int keynum, int num)
        {
            int low = 0;
            int high = num;
            int mid;
        do
        {
            mid = (low + high) / 2;
            if (keynum < array[mid])
            {
                high = mid - 1;
            }
       	else if (keynum > array[mid])
            {
                low = mid + 1;
            }
    	}
    	while (keynum != array[mid] && low <= high);
            if (keynum == array[mid])
            {
                cout<<"SEARCH SUCCESSFUL \n";
		cout<<"Element is present in the array ";
            }
            else
            {
                cout<<"SEARCH FAILED \n";
		cout<<"Element is not present in the array.";
            }
        }
    };

// The following section implements Tree Traversals (Preorder, Postorder and Inorder) .................................................
struct node
    {
        int a;
        struct node *left;
        struct node *right;
    };
    void generate(struct node **, int);
    void infix(struct node *);
    void postfix(struct node *);
    void prefix(struct node *);
    void supprimer(struct node **);

//-----------------------------------------------------------------------------------------------------------------------------
//Main program begins here ....................................
int main() {
 char choice = '+'; //a variable takes input for the type of program to be run
 char option = '+'; //a variable takes input for the type of operation to be performed in the list 
 while (!((choice == 'e')||(choice == 'e'))) {//displays a list of program that can be run
	cout << "\nSelect an option : ";
	cout << "\nn : Sum of numbers";
	cout << "\nl : List";
	cout << "\ns : Stack";
	cout << "\nq : Queue";
	cout << "\np : Selection Sort";
	cout << "\nr : Merge Sort";
	cout << "\nt : Linear Search";
	cout << "\nm : Binary Search";
	cout << "\nw : Tree Traversals";
	cout << "\ne : Exit";
	cout << "\nEnter your choice : ";
	cin >> choice; 
	choice = toupper(choice);
	if (choice == 'N') sum();//function call to run the sum of the first n numbers
	else if (choice == 'L') {
	       int size = 0;	//List operations ..................
	       cout << "\nEnter the size of the list : ";
	       cin >> size; 
	       ListType list(size);
	       while (!(option == '0')) {
		cout << "\nSelect a List operation : ";
		cout << "\n1 : Create a list";
		cout << "\n2 : Insert a new item";
		cout << "\n3 : Delete an item";
		cout << "\n4 : Find an item";
		cout << "\n5 : Empty the list";
		cout << "\n6 : Test whether the list is empty";
		cout << "\n7 : Test whether the list is full";
		cout << "\n8 : Fill the list randomly";
		cout << "\n9 : Display the content of the list";
		cout << "\n0 : Stop";
		cout << "\nEnter option : ";
		cin >> option; 
		switch (option) {
		 case '1': {ListType list(size); cout << "List created.Empty? "  << boolalpha << list.IsEmpty();break;}//Displays that a list is created
		 case '2': {
		       int position, item;
		       cout << "\nEnter a position and an item : ";
		       cin >> position >> item;
		       list.InsertNode(position, item);//function call to insert an item into the list
		       break;
		 }
		 case '3': {
		       int position;
		       cout << "\nEnter the position of the item to delete : ";
		       cin >> position;
		       list.DeleteNode(position);//function call to delete an item from the list
		       break;
		 }
		 case '4': {
		       int item;
		       cout << "\nEnter the item to find : ";
		       cin >> item;
		       list.FindNode(item);//function call to find an item in the list
		       break;
		 }
		 case '5': {list.MakeEmpty(); cout << "\nThe list is emptied\n"; break;}//function call to empty the list
		 case '6': {if (list.IsEmpty()) cout << "\nThe list is empty\n"; else cout << "\nThe list is not empty\n"; break;}//function call to check if list is empty
		 case '7': {if (list.IsFull()) cout << "\nThe list is full\n"; else cout << "\nThe list is not full\n"; break;}//function call to check if list is full
		 case '8': {list.RandomNodes(); break;}//function call to fill list with random numbers
		 case '9': {list.Display(); break;}//function call to display the content of the list
		 default:;
        	}
	       }
	}
	else if (choice == 'S'){
	int size = 0;	//Stack operations ..................
	       cout << "\nEnter the size of the Stack : ";
	       cin >> size; 
	       StackType stack(size);
	while (!(option == '0')) {
		cout << "\nSelect a Stack operation : ";
		cout << "\n1 : Create a Stack";
		cout << "\n2 : Push a new item into the Stack";
		cout << "\n3 : Pop an item from the Stack";
		cout << "\n4 : Find an item in the Stack";
		cout << "\n5 : Empty the Stack";
		cout << "\n6 : Test whether the Stack is empty";
		cout << "\n7 : Test whether the Stack is full";
		cout << "\n8 : Fill the Stack randomly";
		cout << "\n9 : Display the content of the Stack";
		cout << "\n0 : Stop";
		cout << "\nEnter option : ";
		cin >> option; 
		switch (option) {
		 case '1': {StackType stack(size); cout << "Stack created.Empty? "  << boolalpha << stack.IsEmpty(); break;}//Displays that a stack is created
		 case '2': {
		       int item;
		       cout << "\nEnter an item into stack : ";
		       cin >>  item;
		       stack.push(item);//function call to insert an item into the stack
		       break;
		 }
		 case '3': {
		       stack.pop();//function call to delete an item from the stack
		       break;
		 }
		 case '4': {
		       cout << "\nTop Value of Stack : " << stack.top();//function call to find an item in the stack
		       break;
		 }
		 case '5': {stack.MakeEmpty(); cout << "\nThe stack is emptied\n"; break;}//function call to empty the stack
		 case '6': {if (stack.IsEmpty()) cout << stack.IsEmpty() << "\nThe stack is empty\n" ; else cout << stack.IsEmpty() << "\nThe stack is not empty\n" ; break;}//function call to check if stack is empty
		 case '7': {if (stack.IsFull()) cout << stack.IsFull() << "\nThe stack is full\n" ; else cout << stack.IsFull() << "\nThe stack is not full\n" ; break;}//function call to check if stack is full
		 case '8': {stack.RandomElements(); break;}//function call to fill stack with random numbers
		 case '9': {stack.Display(); break;}//function call to display the content of the stack
		 default:;
        	}
	       }
	}

	else if (choice == 'Q'){
int choice, item;
	int size = 0;	//Queue operations ..................
		cout << "Enter 1 if you want to create a queue\n"; 
		cin >> choice;
	       if (choice==1){
		cout << "Queue created.Empty?\n ";
	       cout << "\nEnter the size of the Queue : ";
	       cin >> size; 
	       Circular_Queue cq(size);
    do
    {
	cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
	cout<<"\n2.Enqueue a new item into the Queue\n";
        cout<<"3.Dequeue an item from the Queue\n";
        cout<<"4.Display the content of the Queue\n";
	cout<<"5.Test whether the Queue is empty\n";
	cout<<"6.Test whether the Queue is full\n";
	cout<<"7.Find an item in the Queue\n";
	cout<<"8.Empty the Queue\n";
        cout<<"0.Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 2:
            cout<<"Input the element for insertion in queue : ";
            cin>>item;	
            cq.enqueue(item);
	    break;
	case 3:
            cq.dequeue();
	    break;
        case 4:
            cq.display();
	    break;
	case 5:
		if (cq.IsEmpty()) cout << cq.IsEmpty() << "\nThe queue is empty\n" ; else cout << cq.IsEmpty() << "\nThe queue is not empty\n" ; break;//function call to check if queue is empty
	case 6: if (cq.IsFull()) cout << cq.IsFull() << "\nThe queue is full\n" ; else cout << cq.IsFull() << "\nThe queue is not full\n" ; break;//function call to check if queue is full
	case 7: 
		       cout << "\nFront Value of Queue : " << cq.myfront();//function call to find an item in the queue
			cout << "\nBack Value of Queue : " << cq.myback();//function call to find an item in the queue
		       break;
	case 8: cq.MakeEmpty(); cout << "\nThe queue is emptied\n";break;//function call to empty the content of the queue
	case 0:
	    break;
	default:
	    cout<<"Wrong choice\n";
	}//End of switch
    }
    while(choice != 0);
	}
else
	cout<<"Wrong choice\n";
}
		else if (choice == 'P'){//Selection Sort operations ..................
int n;
int arr[n];	
cout << "enter the number of elements to be sorted : ";
cin >> n;
cout<<"Enter the numbers to be sorted : "<<endl;
for(int i=0; i<n; i++)
{
cin>>arr[i];
}
 
cout<<"Orignal entered numbers : "<<endl;
 
for(int j=0; j<n; j++)
{
cout<<arr[j];
cout<<endl;
} 
cout << "Therefore the unsorted elements are : ";
	printArray(arr, n); 
	selectionSort(arr, n); 
	cout << "Sorted array: \n";
	for(int l=0; l<n; l++)
	{
	cout<<arr[l];
	cout<<endl;
	}  
cout << "Therefore the sorted elements are : ";
	 printArray(arr, n); 
	}
	else if (choice == 'R'){//Merge Sort operations ..................
	int arr_size;
int arr[arr_size];	
cout << "enter the number of elements to be sorted : ";
cin >> arr_size;
cout<<"Enter the numbers to be sorted : "<<endl;
for(int i=0; i<arr_size; i++)
{
cin>>arr[i];
}
 
cout<<"Given array is : \n";
 
for(int j=0; j<arr_size; j++)
{
cout<<arr[j];
cout<<endl;
} 
        cout << "Therefore the unsorted elements are : ";
	displayArray(arr, arr_size); 
	mergeSort(arr, 0, arr_size - 1); 
	cout << "\nSorted array is : \n";
	for(int l=0; l<arr_size; l++)
	{
	cout<<arr[l];
	cout<<endl;
	}  
cout << "Therefore the sorted elements are : ";
	 displayArray(arr, arr_size); 
	}
	else if (choice == 'T'){//Linear Search operations ..................
	int num;
        int i,  keynum, found = 0;
        cout<<"Enter the number of elements   ";
        cin>>num;
        int array[num];
        cout<<"Enter the elements one by one \n";
        for (i = 0; i < num; i++)
        {
            cin>> array[i];
        }
        cout<<"Enter the element to be searched   ";
        cin>>keynum;
        /*  Linear search begins */
        LS l1;
        l1.LinearSearch(array,keynum,i,num);
	}
	else if (choice == 'M'){//Binary Search operations ..................
	int i, j, num, temp, keynum;
        int low, mid, high;
        cout<<"Enter the number of elements \n";
        cin>>num;
	int array[num];
        cout<<"Enter the elements one by one \n";
        for (i = 0; i < num; i++)
        {
            cin>>array[i];
        }
        /*
         * Bubble sort
         */
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < (num - i - 1); j++)
            {
                if (array[j] > array[j + 1])
                {
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
            }
        }
        cout<<"Enter the element to be searched \n";
        cin>>keynum;
        // Binary searching begins
        BS b1;
        b1.BinarySearch(array, keynum, num);

	}
	else if (choice == 'W'){//Tree Traversal operations ..................
	struct node *head = NULL;
        int choix = 0, num, flag = 0, key;
        do
        {
            cout << "\nEnter your choice:\n1. Insert\n2. Traverse via infix(Inorder)\n3.Traverse via prefix(Preorder)\n4. Traverse via postfix(Postorder)\n5. Exit\nChoice: ";
            cin >> choix;
            switch(choix)
            {
            case 1: 
                cout << "Enter element to insert: ";
                cin >> num;
                generate(&head, num);
                break;
            case 2: 
                infix(head);
                break;
            case 3: 
                prefix(head);
                break;
            case 4: 
                postfix(head);
                break;
            case 5: 
                supprimer(&head);
                cout << "Memory Cleared\nPROGRAM TERMINATED\n";
                break;
            default: cout << "Not a valid input, try again\n";
            }
        } while (choix != 5);

	}
	 else if (choice == 'E') exit(0);	//stack or list program stops or exit when e is entered
 }
 return 0;//the main function has a return type integer so returns 0
}
// The following section implements Tree Traversals (Preorder, Postorder and Inorder) .................................................
void generate(struct node **head, int num)
    {
        struct node *temp = *head, *prev = *head;
        if (*head == NULL)
        {
            *head = (struct node *)malloc(sizeof(struct node));
            (*head)->a = num;
            (*head)->left = (*head)->right = NULL;
        }
        else
        {
            while (temp != NULL)
            {
                if (num > temp->a)
                {
                    prev = temp;
                    temp = temp->right;
                }
                else
                {
                    prev = temp;
                    temp = temp->left;
                }
            }
            temp = (struct node *)malloc(sizeof(struct node));
            temp->a = num;
            if (num >= prev->a)
            {
                prev->right = temp;
            }
            else
            {
                prev->left = temp;
            }
        }
    }
    void infix(struct node *head)
    {
        if (head)
        {
            infix(head->left);
            cout << " " << head->a;
            infix(head->right);
        }
    }     
    void prefix(struct node *head)
    {
        if (head)
        {
            cout << " " << head->a;
            prefix(head->left);
            prefix(head->right);
        }
    }
    void postfix(struct node *head)
    {
        if (head)
        {
            postfix(head->left);
            postfix(head->right);
            cout << " " << head->a;
        }
    }
    void supprimer(struct node **head)
    {
        if (*head != NULL)
        {
            if ((*head)->left)
            {
                supprimer(&(*head)->left);
            }
            if ((*head)->right)
            {
                supprimer(&(*head)->right);
            }
            free(*head);
        }
    }
