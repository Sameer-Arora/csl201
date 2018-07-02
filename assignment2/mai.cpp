#include "cStack.hpp"
#include "deque1.hpp"
#include "heap.hpp"
#include <iostream>

using namespace std;

int main(){
    cout<<"CSTACK\n";
    cStack<int> st(8);
    cout<<"capacity "<<st.get_capacity()<<endl;
    cout<<st.redsize()<<endl ;
    cout<<st.redempty()<<endl;
    cout<<st.redtop() <<endl ;
    st.redpush(10);
    st.redpush(5);
    st.redpush(14);
    st.redpush(16);  
    cout<<st.redtop()<<endl;
    cout<<st.blueempty()<<endl;
    cout<<st.bluetop()  <<endl;
     cout<<st.redsize()<<endl;
    cout<<st.bluesize() <<endl;
    st.bluepush(10);
    st.bluepush(5);
    st.bluepush(14);
    st.bluepush(11);
    st.bluepush(12);
    st.bluepush(16);
    st.bluepush(14);

    st.bluepop(); 
    cout<<st.bluetop()<<endl;
    st.bluepop(); 
    cout<<st.bluetop()<<endl;
    st.bluepop(); 
    cout<<st.bluetop()<<endl;
    st.bluepop(); 
    cout<<st.bluetop()<<endl;

    cout<<"DEQUE\n";
    Deque<int> de;
    cout<<de.size()<<endl;   
    cout<<de.empty() <<endl;
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.insertFront(4);       
    de.insertBack(10);
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl ; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    de.removeBack();
    de.insertFront(14);       
    de.insertBack(103);
    de.insertFront(54);       
    de.insertBack(15);
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();

    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();
    cout<<"font "<<de.front()<<endl;
    cout<<"back "<<de.back()<<endl; 
    de.removeFront();
    
    Heap<int, Comp<int> >d;
    cout<<"HEAP\n";
    cout<<d.size()<<endl;   
    cout<<d.isEmpty() <<endl;
    cout<<"min "<<d.min()<<endl; 
    d.insert(4);       
    d.insert(10);
    cout<<"min "<<d.min()<<endl; 
    d.insert(14);       
    d.insert(103);
    d.insert(54);       
    d.insert(15);
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    d.insert(5);
    cout<<"min "<<d.min()<<endl;
    d.insert(3);
    cout<<"min "<<d.min()<<endl;
    d.insert(30);
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    int arr[]={5,465,75,75,33,54,2,54,43,53};
    Heap<int, Comp<int> >d1;
    cout<<"HEAP2\n";
    d1.buildHeap(arr,10);
    d1.insert(5);
    d1.insert(465);
    d1.insert(75);
    d1.insert(75);
    d1.insert(33);
    d1.insert(54);
    d1.insert(2);
    d1.insert(54);
    
    cout<<d1.size()<<endl;   
    cout<<d1.isEmpty() <<endl;
    cout<<"min "<<d1.min()<<endl;
    cout<<"mergeHeaps :\n"; 
    d.mergeHeaps(d1);
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    d.insert(5);
    cout<<"min "<<d.min()<<endl;
    d.insert(3);
    cout<<"min "<<d.min()<<endl;
    d.insert(30);
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    cout<<"min "<<d.min()<<endl;
    
    return 0;
}