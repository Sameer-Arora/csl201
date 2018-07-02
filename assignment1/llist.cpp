
#include <iostream>
#include <string>
#include "car.h"

using namespace std;

template <class T > class node;

template <class T >        //template class linked list for each type of node.
class llist                        
{
	public:
		llist();                  //constructor for linked list class.         
      ~llist();	                   //destructor for linked list class.         
		void add(const T& da);       
		void remov(const T& da ) ;     
		node<T>* search ( const T& da )const;    // to search for element.
		void print()const ;                 //to print list.
      const T& iterator(int st)const;      //to iterate linked list class.
			
	private:
		node<T>* head; 				//private to provide robustness.
};

template <class T > class node{           //template classs node for each type of node.

			public:
				node():next(NULL)                //member iniializtion of next member to NULL.
				{}
            
				~node(){
				}
            T& getval(){                   //to get reference to node's val.
               return val;
            }
            
			private:                            //private to provide robustness.
				T val;
				node<T>* next;

			friend class llist<T>;         //to provide full access to llist class by declaring it a friend.
				
			};





template <class T>
llist<T>::llist():head(NULL){}

template <class T> 
      llist<T>::~llist() {
         node<T>* cur=head;
         node<T>* temp;
         while(cur!=NULL){
            temp=cur;
            cur=cur->next;
            delete temp;
         }
      }
template <class T> 
const T& llist<T>::iterator(int st)const{
   static node<T>* cur;                      //declared static so it remains in memory even if function returns.
   if(st==0)cur=head;                       //to see if start is from head or subsequent call.
   else  cur=cur->next;
   if(cur!=NULL) {  return cur->val; }
   else  {
      T* null=new T("null");
      return *null;                          //a dummy obj to check if list is exhausted.
   }
}


template <class T> 
void llist<T>::add( const T& da ){
   	if(search(da)!=NULL){                                    
   			cout<<"ERROR::-elements alredy in list:  "<<da<<endl; return;}       //checking if ele already in list.
   	if(head!=NULL ){
   			node<T>* cur=head;
            node<T>* pre1=NULL;                                   //the previous link where to insert.
      
         while(cur!=NULL && cur->val > da ){                       //inserting the ele in a sorted manner.
               
               if(pre1==NULL)pre1=head;
               else pre1=pre1->next;
               cur=cur->next;
         }
            if(pre1!=NULL){
               node<T>* temp=new node<T>;
               temp->val=da;
               temp->next=pre1->next;
               pre1->next=temp;
            
            
            } else{
               node<T>* temp=new node<T>;
               temp->val=da;
               temp->next=head;
               head=temp;
               
            }


   		}else{
   			node<T>* temp =new node<T>;
   			temp->val=da;
   			head=temp;
   		}
   
   }       

template <class T> 
   void llist <T> :: remov (const T& da ){
   		node<T>* cur=head, *prev=NULL;

   		while(cur!=NULL){
   			if(cur->val==da){
   				break;
   			}
   			cur=cur->next;
   			if(prev==NULL) prev=head;
   			else  prev=prev->next;
   		}
   		if(cur==NULL) {
   			cout<< "ERROR::-elements not in list:   "<<da<<endl;return;}
   		if(prev!=NULL ){
   			node<T>* te=prev->next;
   			prev->next=prev->next->next;
   			te->~node();
   		}else{
   			node<T>* te=head;
   			head=head->next;
   			te->~node();
   		}
         cout<<"SUCESSFULLY REMOVED\n";
   		return;
   }

template <class T> 
   node<T>* llist <T>::search( const T& da )const{                    //return node* to searched elements .NULL is returned if ele not found.
   		node<T>* cur=head;
   		while(cur !=NULL){
   			if(cur->val==da){
   				return cur;
   			}
   			cur=cur->next;
   		}
   		return NULL;
   }   

template <class T> 
   void llist<T>::print  ( )const{         //to print the list.
   	node<T>* cur=head;
   	while(cur!=NULL){
   		cout  << cur->val<<" -> \n";
   		cur=cur->next;
   	}
   	cout<<endl;
   	return;
   }

template <>                        //used template specialization for car class as no to insert in sorted manner.Same functions are used except the add. 
class llist<car>
{
   public:
      llist():head(NULL){}
      llist(node<car>* hh):head(hh){}
      ~llist(){}   
      void add(const car& da){ if(search(da)!=NULL){
         cout<<"ERROR::-elements alredy in list:  "<<da<<endl; return;}
            if(head!=NULL ){
                 node<car>* temp =new node<car>;
                  temp->val=da;
                  temp->next=head;
                  head=temp;

              }else{
                  node<car>* temp =new node<car>;
                  temp->val=da;
                  head=temp;
               }
 }       

      void remov (const car& da ){
         node<car>* cur=head, *prev=NULL;

         while(cur!=NULL){
            if(cur->val==da){
               break;
            }
            cur=cur->next;
            if(prev==NULL) prev=head;
            else  prev=prev->next;
         }
         if(cur==NULL) {
            cout<< "ERROR::-elements not in list:   "<<da<<endl;return;}
         if(prev!=NULL ){
            node<car>* te=prev->next;
            prev->next=prev->next->next;
            te->~node();
         }else{
            node<car>* te=head;
            head=head->next;
            te->~node();
         }

         cout<<"SUCESSFULLY REMOVED\n";
         return;
      }
      
   node<car>* search( const car& da )const{  
         node<car>* cur=head;
         while(cur !=NULL){
            if(cur->val==da){
               return cur;
            }
            cur=cur->next;
         }
         return NULL;
   }   
   void print  ( )const{
      node<car>* cur=head;
      while(cur!=NULL){
         cout  << cur->val<<" -> \n";
         cur=cur->next;
      }
      cout<<endl;
      return;
   }

   const car& iterator(int st)const{
   static node<car>* cur;
   if(st==0)cur=head;
   else  cur=cur->next;
   if(cur!=NULL) {  return cur->val; }
   else  {
      cout<<" List is exhausted";
      car* null=new car("null");

      return *null;
   }
}
         
   private:
      node<car>* head;             
};                                                                                         