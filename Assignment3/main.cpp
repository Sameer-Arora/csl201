#include <iostream>
#include <fstream>
#include "mavl1.hpp"

using namespace std;

int main(){
	MAVLTree tree;
	ifstream f;
	int k;
	string s;
	f.open("entries.txt");
	f >> k >>s;
	//tree.insert(k,s);
	while(!f.eof()){
		
		tree.insert(k,s);
	//	tree.print();
		f>>k>>s;
	//	cout<<endl;
	}
	int choice=0;
	string val;
	int key=0,place;
	while(1){	
		cout<<"Please enter:- \n 1) to insert\n 2) to delete by key\n 3) to get the place of a key\n 4) to delete by place of​ ​ key\n 5) find value of key\n 6) for Tree size\n 0) to exit \n";
		cin>>choice;
		switch(choice){
			case 1: cout<<"Enter the (int)key and (string)value to insert :\n";
					cin>>key>>val;
					tree.insert(key,val);
					break;

			case 2:  cout<<"Enter the (int)key to delete :\n";
					cin>>key;
					tree.remove(key);
					break;
			case 3:  cout<<"Enter the (int)key to get place :\n";
					cin>>key;
					cout<<"Place:-"<<tree.get_place(key)<<endl;
					break;
			case 4:  cout<<"Enter the place to delete :\n";
					cin>>place;
					tree.delete_by_place(place);
					break;
			case 5: cout<<"Enter the (int)key to find:\n";
					cin>>key;
					cout<<"value of key is "<<tree.search(key)<<endl;
					break;
			case 6: cout<<"Size:- "<<tree.size()<<endl;
					break;
			case 0: break;
			default: cout<<"Please enter correct choice\n:";break;
		}
		if(choice==0)break;
		cout<<"Do you wish to continue:0) to quit any other integer to continue.\n";
		cin>>choice;
		if(choice==0)break;
	}
	
}