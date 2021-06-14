
//########################################################
//#                Section of Queue                        #
//########################################################
#include <bits/stdc++.h>
 
using namespace std;
#define MAX_DATA_SIZE 1000

//Creation of the class Queutype for creating Queue
class QueueType{ 
  //Local variables
  int max_element_of_queue;
  int arr[MAX_DATA_SIZE];
  int rear;
  int front;
  int counter;
  
public: //public variables
  
  ~QueueType(){}; //destructor
  
  QueueType(int size);
  void MakeEmpty();
  bool IsEmpty();
  bool IsFull();
  void Enqueue(int elt);
  void Dequeue();
  void DisplayQueue();
  int Peek();
  int NbElements();
  int Size();
  void result(string result);
  
};

/*

  * Constructor of the class QueueType
  * The parameter size is the Maimu of the number of the element in the Queue
  * At initial, the rear and the front ot the queue are : -1; and the number of element is : 0

 */
QueueType::QueueType(int size){
    max_element_of_queue = size;
    rear = -1;
    front = -1;
    counter = 0;
    
  }
  
   /*   
        Method Dequeue which removes element from the Queue :
        At each remove, the value of front increases in 1 and the number of element decreases in 1
        The number of the element in the stack(count) decreases in 1
        it uses the function writeInformation and writeResult from the file write
   */
  
  void QueueType::Dequeue(){

     if(IsEmpty()){
      writeInformation("Error !!!","The Queue is Empty");
    }
    else
    {
      writeResult("Removing",arr[front], "Removed");
      front++;
      counter--;
    }
      
    
    
  }
  
   /*   
        Method Endqueue to insert element into the Queue
        The parameter needed is the element to add in the Queue:Integer
        if the Queue is empty : The variables front, rear = 0, and the number of element increases(counter) in 1 
        iF the Queue in not empty : Only the variable rear and he number of element increases(counter)  increases in 1 after the insertion if the Queu is not empty
        it uses the function writeInformation and writeInsertion from the file write
   */

  void QueueType::Enqueue(int elt){
    if(IsFull()){
      writeInformation("Error !!!","The Stack is full"); 
    }
    else if (front == -1) //If the queue is empty
    {
      writeInsertion(elt);
      front =  0;
      rear = 0 ; 
      arr[rear] = elt;
      counter++;
    }
   
    else
    {
    writeInsertion(elt);
    rear= rear + 1;
    arr[rear] = elt;
    counter++;
    }
    
  }
  
  /*
    Method MakeEmpty will remove every element in the Queue
    Initialise the variable front, rearm and counter at their initial values
    Return nothing and no need of parameter

  */
  
  void QueueType::MakeEmpty(){
    front = rear=-1;
    counter = 0;
    writeInformation("","Queue Emptied"); 
  }
  
  /*
    Method Peek: Return the value of the front of the Queue :Integer
    No need of parameter
  */
  
  int QueueType::Peek(){
    if(IsEmpty()){
      writeInformation("Error !!!","The Queue is Empty"); 
    }
    else{
       writeResult("The front is : ", arr[front],"");
      
    }
    return arr[front];
  }
  
  /*
    Method NbElements: Return the number of element in the Queue : Integer
    No need of parameter
  */
   
  
  int QueueType::NbElements(){
    return counter;
  }
  
  /*
    Method size: Return the size of the maximum of the elements of the Queue : Integer
    No need of parameter
  */
  
  int QueueType::Size(){
    return max_element_of_queue;
  }

   /*
    Method Display: Print in the screen the elements inside the stack
    It first checks if the stack is empty or not
    No need of parameter
    it uses the functions writeResult and writeInformation from the file write
  */

  void QueueType::DisplayQueue()
  {
      if(IsEmpty()){
        writeInformation("Error !!!","The QueueType is Empty");
      }
      else{
        writeResult("The size of the Queue is : ", Size(),"The items actually inside are : ", NbElements());
         for (int i = front; i <= rear; i++)
          cout <<"\n\t\t\t\t\t\t\t\t\t  " <<arr[i] <<"\n";
      }

      cout<<"\n\t\t\t\t\t\t\t---------------------------------------- \n";

  
    
  };
  
  /*
    Method IsEmpty: Checks either the Queue is empty or not
    No need of parameter
    Return boolean 
  */ 
  
  bool QueueType::IsEmpty(){
    return (front == - 1 || front > rear);

  }
  
  /*
    Method IsFull: Checks either the Queue is full or not
    No need of parameter
    Return boolean 
  */ 
  
  bool QueueType::IsFull(){
    return ( counter == max_element_of_queue);
  }



 

 /*
    Procedure Queue: Which is called in the main program
    Ask the use the size of the stack: Size of the array
    Ask either to implements randomly or not
    Menu of the stack for the manipulation of the stack
  */
void Queue(){
  
    //Declaration of variables
    char option = '+'; 
    int size = 0; 
    string randomly;


    writeTitle("Welcome to Queue secion");
    cout <<"\nEnter the queue size :\n";
    cin >> size; 

    // Check the value from the user is an integer and not more than the size of the array of implementation
    while(cin.fail() || size>MAX_DATA_SIZE)                                    
    {
      cout <<"The value you enter is not either an inter or > 1000 correct \n";
      cin.clear();
      cin.ignore(256,'\n');
      cin >> size;
    }

  
    //Creation of the Queue with a size from the user
    QueueType q(size);
    cout<<"\n------------------------\n";



    // Implements the stack randomly or not
    cout<<"Do you want to fill it randomly? Y/N \n";
    cin >>randomly;
    if(randomly=="Y" || randomly=="y")
    {
      for (int i = 0; i < size; ++i)
      {
        q.Enqueue(rand() % 100);
        /* code */
      }
    }
    else{
      for (int i = 0; i < size; ++i)
      {
        int value;
        cout <<"Enter the elements \n";
        cin >> value;

        q.Enqueue(value);
        /* code */
      }
    }
// Menus options of the Queue --------------------------------------
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

    
    case '1' : {                //option create a new queue which calls the function Queue(Recursive)
      Queue();break;}

      
    case '2' : {                //option Insert a new element
      int elt;
      cout<<"\nEnter an elt :\n";
      cin >> elt;
      q.Enqueue(elt);
       
      break;}
      
      
    case '3': {                 //option Get the front value of the Queue
      q.Peek();
      break;
    }
  
      
    case '4': {                //option Remove from the Queue
      q.Dequeue();
      break; 
    }
      
    case '5' : {q.MakeEmpty(); break;}      //option Empty the queue
      
      
    case '6' :                              //Tester either the Queue is empty or not     
    {
      if(q.IsEmpty()){writeInformation("","The Queue is Empty"); }
      
      else{writeInformation("","The Stack is not Empty");}  
      break;
    }
      
      
    case '7' :                               //Test either the Queue is full or not
    {
      if(q.IsFull())
      writeInformation("","The Queue is full");
      else writeInformation("","The Queue is not full");
      break;
    }
      
      
    case '8' : {                               // Print all the elements of the queue
      q.DisplayQueue();break;}                       
      
    }
      
    } 
    
}



