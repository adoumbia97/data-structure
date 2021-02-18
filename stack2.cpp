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
   
  int capacity;
  int *arr;
  int top;
  int count;
  
   
 public: //public variables--------------
   
   ~StackType(){}; //destructor
   
   // Stack initialization
   StackType(int size);
      void MakeEmpty();
      bool IsEmpty();
      bool IsFull();
      void Push(int item);
      void Pop();
      void Display();

     int Peek();
     int NbElements();
     
     
     
     int size();
   

  
 };




 StackType::StackType(int size){ //clas constructure
    arr=new int(size);
     
     capacity = size;
     top = -1;
     count = 0;
     
     
   }
   
   
   //remove the stack top--------------------  
   
   void StackType::Pop(){
     if(IsEmpty()){
       cout<<"\nThe stack is empty. '\n";
       exit(EXIT_FAILURE);
     }
     cout<<"\nRemoving "<<arr[top]<<"\n";
     top--; 
     count--;
   }
   
   //add an item--------------------  
   
   void StackType::Push(int item){
     if(IsFull()){
       cout<<"\nThe stack is full. '\n";

     }
     else{
      cout<<item<<" Inserted\n";
      ++top;
      arr[top] = item;
      count++;

     }
       
     
     
   }
   
   //make empty the stack--------------------  
   
   void StackType::MakeEmpty(){
     top = -1;
   };
   
   //return top element --------------------  
   
   int StackType::Peek(){
     if(IsEmpty()){
       cout<<"\nThe stack is empty.\n";
       exit(EXIT_FAILURE);
     }
     cout<<"\nThe stack top is : ";
     return arr[top];
     
   }
   
   // The number of elements in the stack---------------
   
   int StackType::NbElements(){
     return top+1;
   }
   
   //stack size--------------------  
   
   int StackType::size(){
     return capacity;
   }
   
   //Display the stack--------------------   
   
   void StackType::Display(){
     cout << "\nThe Stack size is " <<size()<< " and the items actually inside are "  <<NbElements()<< " :\n"; 
     if(top>=0){
       for ( int i=0; i <=top; i++)
         cout << "\n " << i << "\t" <<arr[i] <<"\n";
       
       
     }
   };
   //check if the stack is empty--------------------  
   
   bool StackType::IsEmpty(){
     return (top == -1);
   }
   //check if the stack is full
   
   bool StackType::IsFull(){
     return (top == capacity-1);
   }


 
 void Stack(){
   
   //Home Menu-----------------------------------
   
   cout<<"\n-----------------------------------------";
   cout<<"\n|    DOUMBIA Crespin Welcomes you to the Stack function     |";
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