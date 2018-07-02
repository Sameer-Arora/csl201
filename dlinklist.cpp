#include<iostream>
#include"my.h"
using namespace std;




template<class Data >dlinklist::dlinklist()
		:head(NULL),tail(NULL)
		{}
		
template<class Data >dlinklist::~dlinklist(){
		
		}
		
template<class Data >bool dlinklist::empty() const{
			return head==NULL;
		}
		
template<class Data >const Data& dlinklist::front() const{
			if( !empty() ) return head->data;
			else return ;
		}
		
template<class Data >const Data& dlinklist::back() const{
			if( !empty() )  return tail->data;
		}
		
template<class Data >void dlinklist::addfront ( const Data& e ){
			dnode* temp= new <Data> dnode;
			temp->data=e;
			temp->next=head;
			head->prev= temp;
			head=temp;
		}
		
template<class Data >void dlinklist::removefront (){
			dnode* temp= head;
			head=head->next;
			temp-> ~dnode();
					}
		
template<class Data >void dlinklist::addback ( const Data& e ){
			dnode* temp= new <Data> dnode;
			temp->data=e;
			temp->prev=tail;
			tail->next= temp;
			tail=temp;
		}
		
template<class Data >void dlinklist::removeback (){
			dnode* temp= tail ;
			tail=tail->prev ;
			temp-> ~dnode();
			
		}
		
		
	