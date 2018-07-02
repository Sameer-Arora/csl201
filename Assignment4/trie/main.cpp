#include <iostream>
#include <fstream>
#include "trie.h"
#include <locale>         // std::locale, std::tolower
#include <cstdio>
#include <cstring>
  
using namespace std;

int main(){
	Trie t;
	std::locale loc;
/*
	t.insert("ss",34);
	t.insert("aachman",9849489137);	
	t.insert("sst",34);
	t.insert("sster",34);
	t.insert("tss",34);
	t.search("s");
	t.search("ta");
	t.search("ts");
	t.search("sst");
	*/

	ifstream fin;
	fin.open("name_number.txt",ios::in);
	string name;
	long long int num;
	
	fin>>name>>num;
	for (int i=0; i<name.length(); ++i)
	   	name[i]=tolower(name[i],loc);
 	t.insert(name,num);
	//t.print_trie();
	while(!fin.eof()){
		fin>>name>>num;
		for (int i=0; i<name.length(); ++i)
		   	name[i]=tolower(name[i],loc);
	 		
		t.insert(name,num);
	//t.print_trie();
	
 	}
 	int n;
 	while(1){
 		cout<<"Please​ ​ enter​ ​ full/partial​ ​ contact​ ​ name​:-\n";
 		cin>>name;
 		for (int i=0; i<name.length(); ++i)
		   	name[i]=tolower(name[i],loc);
 		t.search(name);
 		cout<<"Do you want to exit press 0 :\n";
 		cin>>n;
 		if(n==0)break;

 	}
}