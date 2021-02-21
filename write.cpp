#include<iostream>
using namespace std;
#include <cstring>

void writeTitle(string title, string infos="")
{
  cout<<"\n\t\t\t\t\t---------------------------------------- ";
  cout<<"\n\t\t\t\t\t---------------------------------------- ";
  cout<<"\n";
  cout <<"\n\t\t\t\t\t|  "<<  title<< "    |";
  cout <<"\n";
  cout <<"\n\t\t\t\t\t\t  "<<  infos<< "    ";
  cout<<"\n\t\t\t\t\t---------------------------------------- ";
  cout<<"\n\t\t\t\t\t---------------------------------------- ";
  cout<<"\n ";
}

void writeChoice(string sign, string label)
{
	cout<<"\n\t\t " <<sign<<" : "<< label<<"\n";
}

void writeInformation(string title, string message)
{

	  cout<<"\n\t\t\t\t\t\t\t---------------------------------------- \n";
	  cout <<"\n\t\t\t\t\t\t\t\t  "<<  title<< "    \n";
	  cout <<"\n\t\t\t\t\t\t\t\t  "<<  message<< "    \n";
	  cout<<"\n\t\t\t\t\t\t\t---------------------------------------- \n";
	 

	
	 
}

void writeResult(string title, int titleAdd, string message, int messageAdd=0)
{

	  cout<<"\n\t\t\t\t\t\t\t---------------------------------------- \n";
	  cout<<"\n\t\t\t\t\t\t\t\t"<<  title<< " " <<titleAdd <<"    \n";
	  if(messageAdd!=0)
	  	{
	  		cout <<"\n\t\t\t\t\t\t\t\t "<<  message<< " "<< messageAdd <<"   \n";
		}
	  else
	  	{
	  		cout <<"\n\t\t\t\t\t\t\t\t "<<  message <<"   \n";
		}
	  
	  cout<<"\n\t\t\t\t\t\t\t---------------------------------------- \n";
	 
}

void writeInsertion(int item)
{
	cout <<"\n\t\t\t\t\t\t\t  Inserted : "<<  item << "    \n";
}