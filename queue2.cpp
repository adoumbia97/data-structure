
//########################################################
//#                Queue function                         #
//########################################################
#include <bits/stdc++.h>
 
using namespace std;
#define MAX 2

class QueueType{ // class declaration
  
  
  int number_of_elements;
  int arr[MAX_DATA_SIZE];


  int rear;
  int front;
  int a[MAX];
  int counter;
  
public: //public variables
  
  ~QueueType(){}; //destructor
  
  QueueType(int size);
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  void Enqueue(int elt);
  void Dequeue();
  void Display();
  int Peek();
  int NbElements();
  int Size();
  void result(string result);
  
  
  
  
  
  
};


QueueType::QueueType(int size){ //class constructor
    number_of_elements = size;
    rear = -1;
    front = -1;
    counter = 0;
    
  }
  
  //remove the queue front--------------------  
  
  void QueueType::Dequeue(){

     if(IsEmpty()){
      cout<<"\n \t \t \t \t ################### The queue is empty. \t ###################\\n";
    }
    else
    {
      cout<<"\n \t \t \t \t \t Removing "<<arr[front]<<"\n";

      cout<<"\n \t \t \t \t \t Element deleted from queue is : "<< arr[front] <<endl;
      front++;
      counter--;
    }
      
    
    
  }
  
  // Insert an element at the rear of the queue---------------------------------
  
  void QueueType::Enqueue(int elt){
    if(IsFull()){
      cout<<"\n \t \t \t \t ###################  The queue is full. ###################\n";
    }
    else if (front == -1) //If the queue is empty
    {
      cout<<"\n \t \t \t \t ###################   Element inserted : "<< elt << "\t ###################\n";
      front =  0;
      rear = 0 ; 
      arr[rear] = elt;
      counter++;
    }
   
    else
    {
    cout<<"\n \t \t \t \t ###################   Element inserted : "<< elt << "\t ###################\n";
    rear= rear + 1;
    arr[rear] = elt;
    counter++;
    }
    
  }
  
  //make empty the queue---------------------------------
  
  void QueueType::MakeEmpty(){
    front = rear=-1;
    counter = - 1;
    cout<<"\n \t \t \t \t ###################  Queue emptied. \t ###################\n";
  };
  
  //return front element---------------------------------
  
  int QueueType::Peek(){
    if(IsEmpty()){
      cout<<"\nThe queue is empty.\n";
      exit(EXIT_FAILURE);
    }
    return arr[front];
    
  }
  
  //The number of elements in the  queue.---------------------------------
  
  int QueueType::NbElements(){
    return counter+1;
  }
  
  //queue size---------------------------------
  
  int QueueType::Size(){
    return number_of_elements;
  }

  void QueueType::Display(){
      if(IsEmpty()){
        cout<<" \n \t \t \t \t ################### Queue is empty ###################\n";
      }
      else{
         cout<<"\n \t \t \t \t ################### Queue elements are : \t ###################\n";
         for (int i = front; i <= rear; i++)
         cout<<arr[i]<<"\t";
         cout<<endl;
      }

  
    
  };
  
  //check if the queue is empty---------------------------------
  
  bool QueueType::IsEmpty(){
    return (front == - 1 || front > rear);

  }
  
  //check if the queue is full---------------------------------
  
  bool QueueType::IsFull(){
    return ( counter == number_of_elements);
  }



 
// calling the QueueType using the void method ------------------------

void Queue(){
  
  //Home Menu-------------------------------------------------------
  
  cout<<"\n-----------------------------------------";
  cout<<"\n|     Welcome to the Queue function of fofvi    |\n";
  cout<<"\n-----------------------------------------";
  cout<<"\n ";
  char option = '+'; //character declaration
  int size = 0; //queue size initialization
  cout <<"\nEnter the queue size :\n";
  cin >> size; // this will allow the user to choose the size of the queue
  QueueType q(size); //create a queue with the size chosen by the user
  cout<<"\n------------------------\n";
// Queue operations defintions --------------------------------------
  while (option != 's'){
    cout<<("\n \t \tSelect a queue operation :\n");
    cout<<"\n------------------------";
    cout<<"\n \t \t1 : Create a queue.\n ";
    cout<<"\n\t \t2 : Insert a new element at the rear of the queue.\n ";
    cout<<"\n\t \t3 : Get the front of the queue.\n ";
    cout<<"\n\t \t4 : Delete an element from the front of the queue.\n ";
    cout<<"\n\t \t5 : MakeEmpty the queue .\n ";
    cout<<"\n\t \t6 : Test wether the queue is empty.\n ";
    cout<<"\n\t \t7 : Test wether the queue is full.\n ";
    cout<<"\n\t \t8 : Print all the elements of the queue.\n ";
    cout<<"\n\t \tS : Stop.\n ";
    cout<<"\n\t \tEnter an option.\n ";
    cin>> option; // this will allow the user to choose an option
    
    //option implementation -----------------------------------
    
    switch(option){
    
    //option create a queue
    
    case '1' : { 
      cout <<"\nEnter the queue size :\n";
      cin >> size; // this will allow the user to choose the size of the queue
      QueueType q(size); //create a queue with the size chosen by the user

      cout<<"\n \t \t \t \t ###################  Queue created.\t ################### \n";break;}
      
      //option Insert a new element
      
    case '2' : {
      int elt;
      string wantToinsert="y";
      do
      {
        cout<<"\nEnter an elt :\n";
        cin >> elt;
        q.Enqueue(elt);
        cout <<"Do you want to insert again? \n";
        cin >>wantToinsert;
        if(wantToinsert=="n"){wantToinsert="n";} 
        /* code */
      } while (wantToinsert=="y");
        
      break;}
      //option Get the queue front
      
    case '3': {
      cout<<"\n \t \t \t \t ################### The front of the Queue is : "<<q.Peek()<<"\t ################### \n";break;
    }
      
      //option Remove the queue front
      
    case '4': {
      q.Dequeue();
      break; 
    }
      
      //option Empty the queue
      
    case '5' : {q.MakeEmpty(); break;}
      
      //option Test wether the queue is empty or not.
      
    case '6' : 
    {
      if(q.IsEmpty()){cout<<"\n \t \t \t \t ################### The queue is empty. \t ################### \n"; }
      
      else{cout<<"\n \t \t \t \t ###################  The queue is not empty.\t ################### \n";}  
      break;
    }
      
      //option Test wether the queue is full or not.
      
    case '7' : {if(q.IsFull())
      cout<<"\n \t \t \t \t ###################  The queue is full.\t ################### \n";
    else cout<<"\n \t \t \t \t ###################  The queue is not full.\t ################### \n"; break;}
      
      // Print all the elements of the queue
      
    case '8' : { 
      q.Display();break;}
      
      // option stop
      
    s:;
    }
      
    } 
    
}



