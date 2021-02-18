#include <bits/stdc++.h>
 
using namespace std;
#define MAX 2


class Queue
{
   int rear;
   int front;
   int n;
   int a[MAX];
public:
   
   Queue(){rear=-1; front=-1; n=100;};
   void Insert(int itemToAdd);
   void Delete();
   void Display();
   
};



void Queue:: Insert(int itemToAdd) {
   if (rear == n - 1)
   {
     cout<<"Queue Overflow"<<endl; 
   }
   
   else {
      if (front == - 1)
      
         front = 0;
         rear++;
         a[rear] = itemToAdd;
         cout<<"Insert the element in queue : "<<endl;
      
         
   }
}
void Queue:: Delete() {
   if (front == - 1 || front > rear) {
      cout<<"Queue Underflow ";
      return ;
   } else {
      cout<<"Element deleted from queue is : "<< a[front] <<endl;
      front++;;
   }
}
void Queue:: Display() {
   if (front == - 1)
   cout<<"Queue is empty"<<endl;
   else {
      cout<<"Queue elements are : ";
      for (int i = front; i <= rear; i++)
      cout<<a[i]<<" ";
         cout<<endl;
   }
}



int queueManager() {
   class Queue q;
   int ch;
   cout<<"1) Insert element to queue"<<endl;
   cout<<"2) Delete element from queue"<<endl;
   cout<<"3) Display all the elements of queue"<<endl;
   cout<<"4) Exit"<<endl;

   do {
      cout<<"Enter your choice : "<<endl;
      cin >>ch;
      switch (ch) {
         case 1:
            int valueToAdd; 
            cout<<"Enter the value you want to insert in the queue \n";
            cin >> valueToAdd;
            q.Insert(valueToAdd);
            break;
         case 2: q.Delete();
         break;
         case 3: q.Display();
         break;
         case 4: cout<<"Exit"<<endl;
         break;
         default: cout<<"Invalid choice"<<endl;
      }
   } while(ch!=4);




   
   return 0;
}