#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include "name_map.hpp"
#include "number_map.hpp"

using namespace std;

int main()
{
	Name_Map <string,string> nm(2531);
	//cout<<nm.empty()<<endl;
	int i,p=0;
	ifstream fin;
	fin.open("names.txt");
	string name,mean; 
	fin>>name;  //cout<<name<<" ";
	
	fin.ignore();        
	fin.clear();
	getline(fin,mean); //cout<<mean <<endl;
	nm.put(name,mean); //cout<<name<<endl;	
	
	while(!fin.eof())
	{
		fin>>name;  //cout<<name<<endl;
		fin.ignore();        
		fin.clear();
		getline(fin,mean);
		nm.put(name,mean);  	
	//	nm.print();
	} 

	long long int number;
	int balance;
	Number_Map <long long int,int> num(743);
	//cout<<num.empty()<<endl;
	ifstream finn;
	finn.open("numbers.txt");
	finn>>number;  //cout<<name<<" ";
	
	finn.ignore();        
	finn.clear();
	finn>>balance; //cout<<mean <<endl;
	num.put(number,balance); //cout<<name<<endl;	
	
	while(!finn.eof())
	{
		finn>>number;  //cout<<name<<endl;
		finn.ignore();        
		finn.clear();
		finn>>balance;
		num.put(number,balance); //cout<<name<<endl;	
				//nm.print();
	}
	//cout<<num.size()<<endl;
	//num.print();
	ofstream fout;
	fout.open("2016csb1058_output.txt");
	nm.write(fout);
	num.write(fout);

	int choice=0;
	string val;
	while(1){	
		cout<<"Please enter:- \n 1) to​ ​know​ balance​ ​of​​ a ​phone ​number​\n 2) ​to​ know​​ meaning​ ​of​ ​a​ name\n 0) to exit \n";
		cin>>choice;
		switch(choice){
			case 1: cout<<"Enter the (int) phone number:\n";
					cin>>number;
					cout<<"Balance of phone="<<number<< " is "<<num.find(number)<<endl;
					break;

			case 2:  cout<<"Enter the name:\n";
					cin>>name;
					cout<<"Meaning of name="<<name<< " is "<<nm.find(name)<<endl;
					break;
			case 0: break;
			default: cout<<"Please enter correct choice\n:";break;
		}
		if(choice==0)break;
		cout<<"Do you wish to continue:0) to quit any other integer to continue.\n";
		cin>>choice;
		if(choice==0)break;
	}
	fin.close();
	finn.close();
	fout.close();

	return 0;
}