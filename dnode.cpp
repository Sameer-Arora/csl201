#include<iostream>
#include"my.h"
using namespace std;
 
// Data type user defined. 

template<class Data >
class dnode{
	public:
		 template<class Data > dnode(Data da)
		:data(da),next(NULL),prev(NULL)
		{}
		
		~dnode(){
		}
		
	private:
		Data data;
		dnode* next;
		dnode* prev;
		
	friend class dlinklist;	

};
