#include <iostream>
using namespace std;
#define MAX 5
 
//Declaration of Stack
class Stack
{
    private:
        int top;
        int ele[MAX];
    public:
             Stack();
        int     isFull();
        int     isEmpty();
        void    push(int item);
        int     pop(int *item);
        void    printallstak();
        void printelt(int item);

}; 
 
//Initialization of stack
Stack:: Stack()
{
    top = -1;
    
}
 
//Check stack is full or not
int Stack:: isFull()
{
    int full = 0;
 
    if( top == MAX-1 )
        full = 1;
 
    return full; 
}
 
//Check stack is empty or not
int Stack:: isEmpty()
{
    int empty = 0;
 
    if( top == -1 )
        empty = 1;
 
    return empty;
}
 
//Insert item into stack
void Stack:: push( int item )
{
    if( isFull() )
    {
        cout<<"\nStack Overflow";
        return;
    }
 
    top++;
    ele[top] = item;
 
    cout<<"\nInserted item : "<< item;  
}
 
//Delete item from stack
int Stack:: pop( int *item )
{
    if( isEmpty() )
    {
        cout<<"\nStack Underflow";
        return -1;
    }
 
    *item = ele[top--];
    return 0;
}
//Print element
void Stack:: printelt(int item)
{
    cout << ele[item] +"\n";
}

void Stack:: printallstak()
{
    for (int i = 0; i < top; ++i)
    {
        /* code */
        cout << "Voici les elements" << ele[top] << "\n";
    }

}


void stackManage()
{
    Stack s=Stack();
    bool insideStak;
    insideStak=true;
    int choice;
    do
    {
        cout << "New program of stack \n" ;
            cout << "1- Create new stack \n";
            cout << "2- Insert in the stack \n";
            cout << "3- Remove from the stack \n";
            cout << "4- Afficher le stack \n";
            cout << "5- Check if the stack is full \n";
            cin >> choice;

            switch(choice)
            {
                case 2:
                int itemToAdd;
                    cout <<"Enter the item you want to add to the stack \n";
                    cin >> itemToAdd;
                    s.push(itemToAdd);
                    break;
                case 4:
                  s.printallstak();
                break;
            }
          
       
    }while(insideStak=true);
   


}
 

    /*

    int item = 0;
 
    Stack s = Stack();
 
    s.push( 10 );
    s.push( 20 );
    s.push( 30 );
    s.push( 40 );
    s.push( 50 );
    s.push( 60 );
 
 
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
    if( s.pop(&item) == 0 )
        cout<<"\nDeleted item : "<< item;
 
    cout<< endl;
    */
 
