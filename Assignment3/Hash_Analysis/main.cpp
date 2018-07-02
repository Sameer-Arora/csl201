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
	cout<<"\tName_Map:- Number of collisons\n\n";
	nm.print();
	cout<<endl;

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

	cout<<"\tNumber_Map:- Number of collisons\n\n";
	num.print();
	ofstream fout;
	fout.open("2016csb1058_output.txt");
	nm.write(fout);
	num.write(fout);

	fin.close();
	finn.close();
	fout.close();

	return 0;
}