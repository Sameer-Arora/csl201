#ifndef DEQUE_HPP
#define  DEQUE_HPP

#include <iostream>

using namespace std;

template <typename E>  
class Deque{				// deque as doubly linked list
  public:
    Deque(int cap=100);				// constructor
   // Deque(int cap);
    int size() const;				// number of items in the deque
    bool empty() const;				// is the deque empty?
    const E& front() ; // the first element
    const E& back() ;	// the last element
    void insertFront(const E& e);		// insert new first element
    void insertBack(const E& e);		// insert new last element
    void removeFront();	// remove first element
    void removeBack();	// remove last element
  
  private:
    cStack<E>* que;                       //complimentary cStack for increasing the effeciency.
    cStack<E>* complimentry;              //complimentary cStack for increasing the effeciency.
    void move_half_back( int size );   //utility function for moving half of the stack from front to back.
    void move_half_front( int size );   //utility function for moving half of the stack from back to front.
};


template <typename E>  
 Deque<E>::Deque(int cap){ 
    que=new cStack<E>(cap);
    complimentry=new cStack<E>(cap);
 }

                
template <typename E>  
int  Deque<E>::size()const{
    if(empty())     return 0;
    return que->redsize()+que->bluesize();         //deque size = redstack size + bluestack size 
}
        
              

template <typename E>  
bool Deque<E>::empty() const{                    //if both the stacks are empty then the deque is also empty.
    return  ( que->blueempty() && que->redempty() );
}     

template <typename E>  
const E& Deque<E>::front() {
    if(empty()) { cout<<"Deque is empty. Random value:"; }          //check if deque is empty or not.
    else  if(que->redempty()) { 
            move_half_front(que->bluesize());          //moving the half of the deque to front side.
            return que->redtop();
        }   
    else return que->redtop();              //normal case.
}

template <typename E>  
const E& Deque<E>::back() {
    if(empty()) { cout<<"Deque is empty. Random value:";   }    //check if deque is empty or not.
    else  if(que->blueempty()) {
        move_half_back(que->redsize());   //moving the half of the deque to back side.
        return que->bluetop();
    }   
    else return que->bluetop();              //normal case.

}      


template <typename E>  
void Deque<E>::insertFront(const E& e){
        if(  que->redsize()+que->bluesize()==que->get_capacity() ){
            cout<<"Deque Is full.\n"; return;
        }
        else {
            que->redpush(e);
                                    // front=que->stack_red_top;
        }
    
}
 
template <typename E>  
void Deque<E>::insertBack(const E& e){

        if(  que->redsize()+que->bluesize()==que->get_capacity()  ){
            cout<<"Deque Is full.\n"; return;
        }
        else{                     
            que->bluepush(e);                // back=que->stack_blue_top;
       }
       
} 
  
template <typename E>  
void Deque<E>::removeFront(){
    if( empty() ) { cout<<"Deque is empty cannot remove front.\n"; return; } //if deque is empty .
    else{                                               
            if(que->redempty()){                         //the case when front is at the blue stack's bottom or cstack's array end.
                move_half_front(que->bluesize());          //moving the half of the deque to front side.
                que->redpop();
            } else{
                que->redpop();                   //normal case.
            } 
        }
    }


template <typename E>  
void Deque<E>::removeBack(){
    if( empty() ) { cout<<"Deque is empty cannot remove back.\n"; return; }  //if deque is empty .
    else{ 
        if(que->blueempty()){                    //the case when back is at the red stack's bottom or cstack's array start.
                move_half_back(que->redsize());   //moving the half of the deque to back side.
                que->bluepop();
            } else{
                que->bluepop();    //normal case.
            }
    }   
}

template <typename E>  
void Deque<E>::move_half_front( int size ){          //moves half of the blue stack into the red stack.
    
    E ele;
    for(int i=0;i<size;i++){
        if(i < size/2 ){
            ele=que->bluetop();
            que->bluepop(); 
            complimentry->bluepush(ele);      //using complimentry cStack to temporarily store the half of the blue stack.
            
        }else{
            ele=que->bluetop();
            que->bluepop(); 
            que->redpush(ele);
        }
    }
    while(!complimentry->blueempty()){     //restoring back the elements in original deque.
        ele=complimentry->bluetop();
        que->bluepush(ele);
        complimentry->bluepop();
    }
    return;
}

template <typename E>  
void Deque<E>::move_half_back( int size ){          //moves half of the red stack into the blue stack.
 
    E ele;
    for(int i=0;i<size;i++){
        if(i < size/2 ){
            ele=que->redtop();
            que->redpop(); 
            complimentry->bluepush(ele);      //using complimentry cStack to temporarily store the half of the red stack.
            
        }else{
            ele=que->redtop();
            que->redpop(); 
            que->bluepush(ele);
        }
    }
    while(!complimentry->blueempty()){     //restoring back the elements in original deque.
        ele=complimentry->bluetop();
        que->redpush(ele);
        complimentry->bluepop();
    }
    return;
}

#endif