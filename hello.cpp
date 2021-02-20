#include <bits/stdc++.h>
#include "stack2.cpp"
#include "queue2.cpp"
#include "sort.cpp"
#include "merge.cpp"
#include "sequence.cpp"
#include "binary.cpp"
#include "inorder.cpp"
using namespace std;
#include <cstring>


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
    cout<<"\n D : Selection Sort ";
    cout<<"\n M : Selection Merge ";
    cout<<"\n R : Sequential Search ";
    cout<<"\n B : Binary Search ";
    cout<<"\n T : Tree Traversal ";
    
    
    cout<<"\nEnter your choice : ";
    cin>>choice;
    choice= toupper(choice);
    if(choice == 'S') Stack();
    else if(choice == 'Q') Queue();
    else if(choice == 'D') Sort();
    else if(choice == 'M') Merge();
    else if(choice == 'R') SeqSearch();
    else if(choice == 'B') BinarySearch();
    else if(choice == 'T') TreeOrder();
    else if(choice == 'E') exit(0);
   
    
 //   return 0;
    
   // }
}
  return 0;
}
