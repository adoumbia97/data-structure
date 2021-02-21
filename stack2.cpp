#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;



//########################################################
//#                Programme                         #
//########################################################

 
//Creation of the class Stactype for creating stack
 class StackType{
   
//Local variables of the class stack:

  int capacity; //Size of the array which implements the stack
  int *arr;     //Array which implements the stack
  int top;      //To identify the top of the stack
  int count;    // To count the number of the inside the stack
  
   
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


 /*

  * Constructor of the class Stacktype
  * The parameter size is the size of the array which implements the object
  * At initial, the number of element in the table representant by the variable count=0
  * The top of the stack is -1 at initial

 */

 StackType::StackType(int size){ 
    arr=new int(size);  
    top = -1;           
    capacity=size; 
     
     
   }
   
   
   /*   
        Method Pop which removes element from the top of the stack
        At each remove, the value of top decreases in 1
        The number of the element in the stack(count) decreases in 1
        it uses the function writeInformation and writeResult from the file write
   */
   
   void StackType::Pop(){
     if(IsEmpty()){
       writeInformation("Error !!!","The Stack is Empty");   
     }
     else
     {

      writeResult("Removing",arr[top], "Removed");
      top--; 
      
     }
       
   }
   
    /*   
        Method Push to insert element into the stack
        The parameter needed is the item to add in the stack:Integer
        At each insertion, the top and the number of element in the stack increases in 1
        it uses the function writeInformation and writeInsertionfrom the file write
   */
   
   void StackType::Push(int item){
     if(IsFull()){
      writeInformation("Error !!!","The Stack is full"); 

     }
     else{
      writeInsertion(item);
      ++top;
      arr[top] = item;
   

     }
     
   }
   
   /*   
        Method Pop which rmakes the stack empy
        No parameter needed
        after empytying the stack initialise the value of top and count

   */
   void StackType::MakeEmpty(){
     top = -1;
     writeInformation("","Stack  Emptied"); 
   };
   
  /*
    Method Peek: Return the value value top of the stack :Integer
    No need of parameter
  */
   
   int StackType::Peek(){
     if(IsEmpty()){
      
       writeInformation("Error !!!","The Stack is Empty"); 
     }
     writeResult("The top is : ", arr[top],"");
      
     return arr[top];
     
   }
   
   /*
    Method NbElemennts: Return the number of element in the stack : Integer
    No need of parameter
  */
   
   int StackType::NbElements(){
     return top+1;
   }
   

   
   /*
    Method size: Return the zise of the array which implements the stack : Integer
    No need of parameter
  */
   int StackType::size(){
     return capacity;
   }
   
   /*
    Method Display: Print in the screen the elements inside the stack
    It first checks if the stack is empty or not
    No need of parameter
    it uses the functions writeResult and writeInformation from the file write
  */
   
   void StackType::Display(){
    if(!IsEmpty())
    {
      writeResult("The size of the stackt is : ", size(),"The items actually inside are : ", NbElements());
      if(top>=0){
        cout <<"\n\t\t\t\t\t\t\t\t" << "Indices " << "\t" <<"Values" <<"\n";
         for ( int i=0; i <=top; i++)
        cout <<"\n\t\t\t\t\t\t\t\t  " << i << "\t\t  " <<arr[i] <<"\n";
         
       }
      cout<<"\n\t\t\t\t\t\t\t---------------------------------------- \n";
    }
    else{
      writeInformation("Error !!!","The Stack is Empty");
    }
      
     
   };

   /*
    Method IsEmpty: Checks either the stack is empty or not
    No need of parameter
    Retunr boolean 
  */ 
   
   bool StackType::IsEmpty(){
     return (top == -1);
   }
   //check if the stack is full
   
   bool StackType::IsFull(){
     return (top == capacity-1);
   }



  /*
    Procedure Stack: Which is called in the main program
    Ask the use the size of the stack: Size of the array
    Ask either to implements randomly or not
    Menu of the stack for the manipulation of the stack
  */
 
 void Stack(){
  //Declaration of variables
    char option = '+'; 
    int size = 0;
    string randomly;
   

    writeTitle("Welcome to stack secion");
    cout <<"\nEnter the stack size :\n";
    cin >> size; 
    StackType s(size);
    cout<<"\n------------------------\n";

    // Implements the stack randomly or not
    cout<<"Do you want to fill it randomly? Y/N \n";
    cin >>randomly;
    if(randomly=="Y" || randomly=="y")
      {
        for (int i = 0; i < size; ++i)
        {
          s.Push(rand() % 100);
        }
      }
   
   // Menu of the stack
   
   while (option != 's' && option!='S'){      //Display the menu untill the user enters "S" or "s"
     cout<<("\nSelect a stack operation :\n");
     cout<<"\n------------------------";
     cout<<"\n1 : Insert a new item.\n ";
     cout<<"\n2 : Get the stack top.\n ";
     cout<<"\n3 : Remove the stack top.\n ";
     cout<<"\n4 : Empty the stack .\n ";
     cout<<"\n5 : Test wether the stack is empty or not.\n ";
     cout<<"\n6 : Test wether the stack is full or not.\n ";
     cout<<"\n7 : Display the stack content.\n ";
     cout<<"\nS : Stop.\n ";
     cout<<"\nEnter an option.\n ";
     cin>> option;//this will let the user select one option.---------------

     
     //Treatement of the option chosen by the user --------------------  ------
     
     switch(option){
     
           
         case '1' :  //option Insert a new item
         {
           int item;
           cout<<"\nEnter an item :\n";
           cin >> item;
           s.Push(item); break;
         }
           
           
         case '2': {  //option Get the stack top

           cout<<s.Peek()<<"\n";break;
         }
           
            
           
         case '3': {  //option Remove the stack top------- 
           s.Pop(); 
           break;
         }
           
           
         case '4' : //option Empty the stack------------
         {
          s.MakeEmpty();
          break;
         
         }
           
           
         case '5' : //option Test wether the stack is empty or not------------
         {
          if(s.IsEmpty())
           writeInformation("","The Stack is Empty"); 
          else writeInformation("","The Stack is not Empty"); break;
         }
           
           
           
         case '6' :     //option Test wether the stack is full or not------------
         {
          if(s.IsFull())
            writeInformation("","The Stack is full"); 
          else writeInformation("","The Stack is  not full"); ; break;
         }
           
           
           
         case '7' : {s.Display(); break;} //option Dispaly the stack content------------
     
         }
       
     } 
     
   
 }