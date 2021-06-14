#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#include <boost/algorithm/string.hpp>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>



#include "write.cpp"
#include "stack2.cpp"
#include "queue2.cpp"
#include "sort.cpp"
#include "merge.cpp"
#include "sequence.cpp"
#include "binary.cpp"
#include "treeTraversal.cpp"
#include "graph.h"



//#####################################################################################
//#                                      Software : Data Structure                                #
//												Version 1.0.0
//#####################################################################################

int main(){
  //variable declaration---------------------
  char choice = '+';
  char option = '+';
  //General menu content--------------------
  writeTitle("Welcome to the program : Data Structure v1.0.0", "by Abdramane DOUMBIA");
  while(!((choice == 'e') || (choice == 'e'))){
  cout<<"\nSelect one of the menus below\n";
    cout<<"\n-------------------------------";
    writeChoice("S","Stack");
    writeChoice("Q","Queue");
    writeChoice("D","Selection Sort");
    writeChoice("M","Merging Sort");
    writeChoice("R","Sequential Search");
    writeChoice("B","Binary Search");
    writeChoice("T","Tree Traversal");
    writeChoice("G","Graph  Traversal");
    writeChoice("E","Exit");
    cout<<"\nEnter your choice : ";
    cin>>choice; //Get the choice of the user 					
    choice= toupper(choice);	//Put the choice of the user in a uppercase to avoid writing mistake

    if(choice == 'S') Stack();	//Traitement of the choice of the user by calling the appopriate function
    else if(choice == 'Q') Queue();
    else if(choice == 'D') Sort();
    else if(choice == 'M') Merge();
    else if(choice == 'R') SeqSearch();
    else if(choice == 'B') BinarySearch();
    else if(choice == 'T') TreeOrder();
    else if(choice == 'G') Graph();
    else if(choice == 'E') exit(0);
   
}
  return 0;
}
