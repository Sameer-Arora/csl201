#ifndef CSTACK_HPP
#define  CSTACK_HPP

#include <iostream>

using namespace std;

template <typename E> class Deque;

  template <typename E>
  class cStack {      // an interface for a stack
  public:
    cStack(int cap =100 );    // constructor from capacity
    int redsize() const;    // number of items in stack
    bool redempty() const;    // is the stack empty?
    const E& redtop()const;            // the top element
    void redpush(const E& e);     // push x onto the stack
    void redpop();            // remove the top element
    int bluesize() const;               // number of items in stack
    bool blueempty() const;             // is the stack empty?
    const E& bluetop() const;           // the top element
    void bluepush(const E& e);          // push x onto the stack
    void bluepop();                     // remove the top element 
    const E& get_arr_end()const;           //gives the array end .
    const E& get_arr_start()const;           //gives the array start.
    const int& get_capacity()const;           //gives the stack's capacity. 
private:
    int CAPACITY;
    E *stack_arr_st;
    E *stack_red_top;
    E *stack_blue_top;
    E *stack_arr_end;

    

 };

template <typename E>
cStack<E>::cStack(int cap){
  stack_arr_st=new E[cap];
  stack_arr_end=stack_arr_st+(cap-1);
  stack_red_top=NULL;
  stack_blue_top=NULL;
  CAPACITY=cap;
}

template <typename E>
int cStack<E>::redsize()const{
    if(redempty()) return 0;
    else  return (stack_red_top- stack_arr_st )+1 ;
}

template <typename E>
bool cStack<E>::redempty()const{
    return (stack_red_top==NULL)? true:false; 
}

template <typename E>
const E& cStack<E>::redtop()const{
  if(redempty()){ 
  cout<<"RED Stack is empty no top .Random value:";
   }       
  else return *stack_red_top;
}            

template <typename E>
void cStack<E>::redpush(const E& e){
  if(redsize()+bluesize() >= CAPACITY ){ cout<<"Stack is full\n"; return;}
  if(stack_red_top==NULL)  stack_red_top=stack_arr_st;
  else                     stack_red_top++;
  *stack_red_top=e;
} 

template <typename E>
void cStack<E>::redpop(){
  if(redempty()) {  "RED Stack is empty no element to remove.\n"; return; }
  if(stack_red_top==stack_arr_st)  stack_red_top=NULL;
  else                             stack_red_top--;                       
}       

template <typename E>
int cStack<E>::bluesize() const{
    if(blueempty()) return 0;
    else  return ( stack_arr_end - stack_blue_top )+1 ;

} 

template <typename E>
bool cStack<E>::blueempty() const{
    return (stack_blue_top==NULL)? true:false;
}       

template <typename E>
const E& cStack<E>::bluetop() const{
  if(blueempty()){ cout<<"BLUE Stack is empty no top .Random value:";  }         
  else return *stack_blue_top;
}     

template <typename E>
void cStack<E>::bluepush(const E& e){
  if(redsize()+bluesize() >= CAPACITY ){ cout<<"Stack is full\n"; return;}
  if(stack_blue_top==NULL)  stack_blue_top=stack_arr_end;
  else                     stack_blue_top--;
  *stack_blue_top=e;
}         

template <typename E>
void cStack<E>::bluepop(){
  if(blueempty()) {  cout<<"BLUE Stack is empty no element to remove.\n"; return; }
  if(stack_blue_top==stack_arr_end)  stack_blue_top=NULL;
  else                             stack_blue_top++;                       
} 

template <typename E>
const E& cStack<E>::get_arr_start()const{
  return   *stack_arr_st;                       
} 


template <typename E>
const E& cStack<E>::get_arr_end()const{
  return   *stack_arr_end;                       
} 


template <typename E>
const int& cStack<E>::get_capacity()const{
  return  CAPACITY ;                       
} 

#endif