#include<iostream>
#include<cstring>
#include<cstdlib>
#define MAX_DATA_SIZE 1000
#define SIZE 10

using namespace std;



//########################################################
//#                Stack function                         #
//########################################################

 

 class StackType{
   
   
   int top;
   int count;
  
   
 public: //public variables--------------
   
   ~StackType(){}; //destructor
   
   // Stack initialization
   StackType(int size){ //clas constructure
     
     capacity = size;
     top = -1;
     count = 0;
     
     
   }
   
   
   //remove the stack top--------------------  
   
   void Pop(){
     if(IsEmpty()){
       cout<<"\nThe stack is empty. '\n";
       exit(EXIT_FAILURE);
     }
     cout<<"\nRemoving "<<arr[top]<<"\n";
     top--; 
     count--;
   }
   
   //add an item--------------------  
   
   void Push(int item){
     if(IsFull()){
       cout<<"\nThe stack is full. '\n";
       exit(EXIT_FAILURE);
     }
     cout<<item<<" Inserted\n";
     ++top;
     arr[top] = item;
     count++;
     
     
   }
   
   //make empty the stack--------------------  
   
   void MakeEmpty(){
     top = -1;
   };
   
   //return top element --------------------  
   
   int Peek(){
     if(IsEmpty()){
       cout<<"\nThe stack is empty.\n";
       exit(EXIT_FAILURE);
     }
     cout<<"\nThe stack top is : ";
     return arr[top];
     
   }
   
   // The number of elements in the stack---------------
   
   int NbElements(){
     return count;
   }
   
   //stack size--------------------  
   
   int size(){
     return capacity;
   }
   
   //Display the stack--------------------   
   
   void Display(){
     cout << "\nThe Stack size is " <<size()<< " and the items actually inside are "  <<NbElements()<< " :\n"; 
     if(top>=0){
       for ( int i=0; i <=top; i++)
         cout << "\n " << i << "\t" <<arr[i] <<"\n";
       
       
     }
   };
   //check if the stack is empty--------------------  
   
   bool IsEmpty(){
     return (top == -1);
   }
   //check if the stack is full
   
   bool IsFull(){
     return (top == capacity-1);
   }
   
 private : 
   int capacity;
   int arr[MAX_DATA_SIZE];
 };
 
 void Stack(){
   
   //Home Menu-----------------------------------
   
   cout<<"\n-----------------------------------------";
   cout<<"\n|    MOUTO Crespin Welcomes you to the Stack function     |";
   cout<<"\n-----------------------------------------";
   cout<<"\n ";
   char option = '+'; //character declaration  
   int size = 0; // stack size initialization
   cout <<"\nEnter the stack size :\n";
   cin >> size; //this will let the user enter the stack size-------- 
   StackType s(size); //create a stack with the typed size
   cout<<"\n------------------------";
   
   // Menu options----------
   
   while (option != 's'){ 
     cout<<("\nSelect a stack operation :\n");
     cout<<"\n------------------------";
     cout<<"\n1 : Create a stack.\n ";
     cout<<"\n2 : Insert a new item.\n ";
     cout<<"\n3 : Get the stack top.\n ";
     cout<<"\n4 : Remove the stack top.\n ";
     cout<<"\n5 : Empty the stack .\n ";
     cout<<"\n6 : Test wether the stack is empty or not.\n ";
     cout<<"\n7 : Test wether the stack is full or not.\n ";
     cout<<"\n8 : Display the stack content.\n ";
     cout<<"\nS : Stop.\n ";
     cout<<"\nEnter an option.\n ";
     cin>> option;//this will let the user select one option.---------------
     
     //option implementation --------------------  ------
     
     switch(option){
     
     //option create a stack
     
     case '1' : { int  s(size);
       cout<<"\n Stack created.\n";break;}
       
       //option Insert a new item
       
     case '2' : {
       int item;
       cout<<"\nEnter an item :\n";
       cin >> item;
       s.Push(item); break;}
       
       //option Get the stack top---------
       
     case '3': {
       cout<<s.Peek()<<"\n";break;
     }
       
       //option Remove the stack top-------  
       
     case '4': {
       s.Pop(); 
       cout<<"\nTop removed.\n";break;
     }
       
       //option Empty the stack------------
       
     case '5' : {s.MakeEmpty(); 
       cout<<"\nStack emptied.\n"; break;}
       
       //option Test wether the stack is empty or not------------
       
     case '6' : {if(s.IsEmpty())
       cout<<"\nThe stack is empty.\n";
     else cout<<"\nThe stack is not empty.\n"; break;}
       
       //option Test wether the stack is full or not------------
       
     case '7' : {if(s.IsFull())
       cout<<"\nThe stack is full.\n";
     else cout<<"\nThe stack is not full.\n"; break;}
       
       //option Dispaly the stack content------------
       
     case '8' : {s.Display(); break;
     
     //option stop
     
     s:;
     }
       
     } 
     
   }
 }



//########################################################
//#                Queue function                         #
//########################################################

class QueueType{ // class declaration
  
  
  int P1;
  int Pn;
  int i;
  
public: //public variables
  
  ~QueueType(){}; //destructor
  
  
  // queue initialization--------------------  
  
  QueueType(int size){ //class constructor
    number_of_elements = size;
    P1 = -1;
    Pn = -1;
    i = 0;
    
  }
  
  //remove the queue front--------------------  
  
  void Dequeue(){
    if(IsEmpty()){
      cout<<"\nThe queue is empty. '\n";
      exit(EXIT_FAILURE);
    }
    cout<<"\nRemoving "<<arr[P1]<<"\n";
    
    if(P1 == Pn)
    {
      P1 = -1;
      Pn = -1;
    }
    else {if (P1 == number_of_elements - 1)
      P1 = 0;
    
    }
    
    
    P1++;
    i--;
    
  }
  
  // Insert an element at the rear of the queue---------------------------------
  
  void Enqueue(int elt){
    if(IsFull()){
      cout<<"\nThe queue is full. '\n";
      exit(EXIT_FAILURE);
    }
    else if (P1 == -1)
    {
      cout<<elt<<" Inserted\n";
      P1 =  0;
      Pn = 0 ; 
      arr[Pn] = elt;
    }
    else if(Pn == number_of_elements-1 && P1 != 0)
    {
      cout<<elt<<" Inserted\n";
      Pn = 0;
      arr[Pn] = elt;
    }
    else 
      cout<<elt<<" Inserted\n";
    Pn = Pn + 1;
    arr[Pn] = elt;
    i++;
  }
  
  //make empty the queue---------------------------------
  
  void MakeEmpty(){
    P1 = Pn=-1;
    i = - 1;
  };
  
  //return front element---------------------------------
  
  int Peek(){
    if(IsEmpty()){
      cout<<"\nThe queue is empty.\n";
      exit(EXIT_FAILURE);
    }
    return arr[P1];
    
  }
  
  //The number of elements in the  queue.---------------------------------
  
  int NbElements(){
    return i+1;
  }
  
  //queue size---------------------------------
  
  int Size(){
    return number_of_elements;
  }
  void Display(){
    if(IsEmpty()){
      cout<<"\nThe queue is empty\n";
    }
    cout << "\nThe Queue size is " <<Size()<< " but the items actually inside are "  <<NbElements()<< " :\n"; 
    if(Pn >= P1){
      for (int i=P1; i <= Pn; i++)
        cout << "\n " << i << "\t" << arr[i] <<"\n";
      
    }
    else
    {
      for(int i=P1; i < number_of_elements - 1; i++)
        cout << "\n " << i << "\t" << arr[i] <<"\n";  
      
      for(int i = 0; i <= Pn; i++)
        cout << "\n " << i << "\t" << arr[i] <<"\n";  
    }
    
  };
  
  //check if the queue is empty---------------------------------
  
  bool IsEmpty(){
    return P1==-1;
  }
  
  //check if the queue is full---------------------------------
  
  bool IsFull(){
    return ((Pn == number_of_elements-1 && P1 == 0) || (P1 == (Pn + 1) % (number_of_elements-1)));
  }
private :
  int number_of_elements;
  int arr[MAX_DATA_SIZE];
  
};
 
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
    cout<<("\nSelect a queue operation :\n");
    cout<<"\n------------------------";
    cout<<"\n1 : Create a queue.\n ";
    cout<<"\n2 : Insert a new element at the rear of the queue.\n ";
    cout<<"\n3 : Get the front of the queue.\n ";
    cout<<"\n4 : Delete an element from the front of the queue.\n ";
    cout<<"\n5 : MakeEmpty the queue .\n ";
    cout<<"\n6 : Test wether the queue is empty.\n ";
    cout<<"\n7 : Test wether the queue is full.\n ";
    cout<<"\n8 : Print all the elements of the queue.\n ";
    cout<<"\nS : Stop.\n ";
    cout<<"\nEnter an option.\n ";
    cin>> option; // this will allow the user to choose an option
    
    //option implementation -----------------------------------
    
    switch(option){
    
    //option create a queue
    
    case '1' : { QueueType q(size);
      cout<<"\n Queue created.\n";break;}
      
      //option Insert a new element
      
    case '2' : {
      int elt;
      cout<<"\nEnter an elt :\n";
      cin >> elt;
      q.Enqueue(elt); break;}
      
      //option Get the queue front
      
    case '3': {
      cout<<"\nThe queue P1 is : "<<q.Peek()<<"\n";break;
    }
      
      //option Remove the queue front
      
    case '4': {
      q.Dequeue(); 
      cout<<"\nP1 removed.\n";break;
    }
      
      //option Empty the queue
      
    case '5' : {q.MakeEmpty(); 
      cout<<"\nQueue emptied.\n"; break;}
      
      //option Test wether the queue is empty or not.
      
    case '6' : {if(q.IsEmpty())
      cout<<"\nThe queue is empty.\n";
    else cout<<"\nThe queue is not empty.\n"; break;}
      
      //option Test wether the queue is full or not.
      
    case '7' : {if(q.IsFull())
      cout<<"\nThe queue is full.\n";
    else cout<<"\nThe queue is not full.\n"; break;}
      
      // Print all the elements of the queue
      
    case '8' : { 
      q.Display();break;}
      
      // option stop
      
    s:;
    }
      
    } 
    
}



//#####################################################################################
//#                                      Main program                                 #
//#####################################################################################

int main(){
  //variable declaration---------------------
  char choice = '+';
  char option = '+';
  //General menu content--------------------
  cout<<"\n---------------------------------------- ";
  cout <<"\n| Fofovi Crespin MOUTO welcomes you to execute his program ?        |";
  cout<<"\n---------------------------------------- ";
  cout<<"\n ";
  while(!((choice == 'e') || (choice == 'e'))){
  cout<<"\nSelect one of the menus below\n";
    cout<<"\n-------------------------------";
    cout<<"\n S : Stack ";
    cout<<"\n Q : Queue ";
    
    cout<<"\nEnter your choice : ";
    cin>>choice;
    choice= toupper(choice);
    if(choice == 'S') Stack();
    else if(choice == 'Q') Queue();
    else if(choice == 'E') exit(0);
    
 //   return 0;
    
   // }
}
  return 0;
}
