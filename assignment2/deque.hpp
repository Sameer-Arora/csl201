#ifndef DEQUE_HPP
#define  DEQUE_HPP

#include <iostream>
//#include "cStack.hpp"
using namespace std;

template <typename E>  
class Deque{				// deque as doubly linked list
  public:
    Deque();				// constructor
    int size() const;				// number of items in the deque
    bool empty() const;				// is the deque empty?
    const E& g_front() const; // the first element
    const E& g_back() const;	// the last element
    void insertFront(const E& e);		// insert new first element
    void insertBack(const E& e);		// insert new last element
    void removeFront();	// remove first element
    void removeBack();	// remove last element
  
  private:
    E* front;
    E* back;
    cStack<E> que;
  };


template <typename E>  
 Deque<E>::Deque(){ 
    front=NULL;
    back=NULL; 
 }

                
template <typename E>  
int  Deque<E>::size()const{
    if(empty())     return 0;
    if(front==back)                   return 1;
    else if(front <back){
        return que.redsize()+que.bluesize();
    }
    else if(front > back ){
        return ( front-back )+1;
    }
}
        
              

template <typename E>  
bool Deque<E>::empty() const{
    return (front ==NULL && back== NULL);
}     

template <typename E>  
const E& Deque<E>::g_front() const{
    if(empty())  cout<<"Deque is empty.\n";
    else  return *front;
}

template <typename E>  
const E& Deque<E>::g_back() const{
    if(empty())  cout<<"Deque is empty.\n";
    else  return *back;

}      

template <typename E>  
void Deque<E>::insertFront(const E& e){
    if(empty()){
        que.redpush(e);
        front=que.stack_red_top;
        back=front;
    }
    else{
        if( front+1==back ){
            cout<<"Deque Is full.\n"; return;
        }
        else if(front < back) {
            que.redpush(e);
            front=que.stack_red_top;
        }
        else{
            if(front==que.stack_arr_end){
                que.redpush(e);
                front=que.stack_red_top;
            }
            else{
                front++;
                *front=e;
            }
        }
    }
}
 
template <typename E>  
void Deque<E>::insertBack(const E& e){
 if(empty()){
        que.bluepush(e);
        back=que.stack_blue_top;
        front=back;
      }
    else{
        if( front+1==back ){
            cout<<"Deque Is full.\n"; return;
        }
        else if(front < back) {
            que.bluepush(e);
            back=que.stack_blue_top;
        }
        else{
            if(back==que.stack_arr_st){
                que.bluepush(e);
                back=que.stack_blue_top;
            }
            else{
                back--;
                *back=e;
            }
        }
    }   
} 
  
template <typename E>  
void Deque<E>::removeFront(){
    if( empty() ) { cout<<"Deque is empty.\n"; return; }
    else{
        if(front < back){
            if(front==que.stack_arr_st){
                que.redpop();
                front=que.stack_arr_end;
            }else{
                que.redpop();
                front=que.stack_red_top;
            }
        }
        else if(front == back){
            front=NULL;
            back=NULL;
        }
        else {
            front--;           
        }
    }
}

template <typename E>  
void Deque<E>::removeBack(){
    if( empty() ) { cout<<"Deque is empty.\n"; return; }
    else{
        if(front < back){
            if( back==que.stack_arr_end ){
                que.bluepop();
                back=que.stack_arr_st;
            }else{
                que.bluepop();
                back=que.stack_blue_top;
            }
        }
        else if(front == back){
            front=NULL;
            back=NULL;
        }
        else {
            back++;           
        }
    }   
}


#endif