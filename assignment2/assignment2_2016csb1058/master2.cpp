#include "cStack.hpp"
#include "deque.hpp"
#include <fstream>
#include <cstdlib>


using namespace std;


void checkdeque();



int main (){

		cout<<"Checking for deque template with 4 cases "<<endl;
		checkdeque();


	return 0;
}



void checkdeque(){

	Deque<int> q;
	int i = 0 ;

	for(i = 0; i< 50;i++)
	{
		q.insertFront(i);
		q.insertBack(i);

	}
	//cout<< "size of queue" << q.size() <<endl;
	if (q.size() == 100)
		cout<<"Passed"<<endl;
	else
		cout<<"Fail"<<endl;
 // case 2 deltion 
	while(!q.empty())
	{
		//cout<<"front element "<<q.front()<<endl;
		//cout<<"back element "<<q.back()<<endl;
		q.removeFront();	// remove first element
        q.removeBack();
	}
	//cout<<"size of queue" << q.size()<<endl;
	
	if (q.size() == 0)
		cout<<"Passed"<<endl;
	else
		cout<<"Fail"<<endl;
//cas 3 mixed  insertion and deltion  
	int flag = 1;
	for(i = 0; i< 50;i++)
	{
		q.insertFront(i);
		q.insertBack(i);

	}
	while(!q.empty())
	{

		// cout<<"front element "<<q.front()<<endl;
		// cout<<"back element "<<q.back()<<endl;
		q.removeFront();	// remove first element
        q.removeBack();

        if(flag ==1){
			for(i = 0; i< 50;i++)
			{
				q.insertFront(i);
				q.insertBack(i);
			}
			flag = 0;
			if (q.size() > 100)
				cout<<"Passed"<<endl;
			else
				cout<<"Fail"<<endl;

		}
	}
	//cout<<"size of queue" << q.size()<<endl;
	if (q.size() == 00)
		cout<<"Passed"<<endl;
	else
		cout<<"Fail"<<endl;


}

