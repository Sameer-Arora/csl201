
#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
using namespace std;

//TNode as node of the tree.
//LNode as nodes of the linked list.
template <typename E, typename C> class Heap;

template<typename E>
class Comp {                //Sample comparator used for testing the Heap structure.
            public:
                Comp(){}
                bool operator()(E e1,E e2){
                
                }    
         };


template<> 
class Comp<int> {            //Sample comparator template specified for testing the Heap structure with integers.
            public:
                Comp(){}
                bool operator()(int e1,int e2){
                    return (e1<e2);
                }    
         };

template <typename E,typename C >
class TNode{                         //TNode class to present the nodes in our Heap data structure.
    public:
        TNode():parent(NULL),left(NULL),right(NULL){}    //initialinzing its pointers to NULL.
        /*const int& get_val(){                                
            return this->val;
        }*/
      private:
        TNode<E,C>* parent;
        TNode<E,C>* left;
        TNode<E,C>* right;
        E val;
        
      friend class Heap<E,C>;            //declaring the friend class Heap to use this nodes private members.
};

template <typename E, typename C>			// element and comparator
  class Heap {					       // priority-queue interface
  public:
    Heap(); //Constructor
    int size() const;					// number of elements
    bool isEmpty() const;				// is the queue empty?
    void insert(const E& e);				// insert element
    const E& min() const;		// minimum element
    void removeMin();			// remove minimum
    void mergeHeaps(Heap H); //MODIFIED function to merge the two Heaps 
    void buildHeap(E A[], int size);	//Function to build the Heap afresh from the list passed.
    E* traverse()const;        //One function to do the inorder traversal and store its elements in returned list.
    int isleft(TNode<E,C>* n);        //utility function for checking if the node is a left or right child.
    void swap(TNode<E,C>* n1,TNode<E,C>* n2);         //utility function for swapping the node's value.
    //TNode<E,C>* form_tree(E A[],TNode<E,C>* r,int size,int st);
    void form_tree(E A[],TNode<E,C>* r,int size,int st); //utility function for forming the tree in buildHeap.
    //void postorder(TNode<E,C>* r );       //utility  function used for deleting the previous Heap in buildHeap.
    void inorder(TNode<E,C>* r ,E* list,int size)const;    //utility  function used in the traversal.
    void null(TNode<E,C>* n);
  private:
    C  isLess;                       //Comparator object to compare the two E class objects.
    TNode<E,C>* root;
    TNode<E,C>* last;
    int h_size;                  //stores the Heap size.
  };

template <typename E,typename C>  
 Heap<E,C>::Heap(){ 
    root=NULL;
    last=NULL;
    h_size=0;
 }
/*
template <typename E,typename C>  
void Heap<E,C>::postorder(TNode<E,C>* r ){
    if(r==NULL)return;
    postorder(r->left);
    postorder(r->right);
    ////cout<<"delete "<<r->val<<endl;
    delete r;  
    return;
}*/

template <typename E,typename C>  
int  Heap<E,C>::size()const{
    if(isEmpty())     return 0;
    ////cout<<"size "<<h_size<<endl;
    return h_size;
}
        
template <typename E,typename C>  
bool Heap<E,C>::isEmpty() const{                    //if the Heap are empty.
    return  ( root==NULL );
}     

template <typename E,typename C>  
int Heap<E,C>::isleft( TNode<E,C>* n ) {
    if(n->parent==NULL) { 
        return 0; }          //check if node is root or not.
    else {
        return (n==n->parent->left);
    }
}

template <typename E,typename C>  
void Heap<E,C>::null( TNode<E,C>* n ) {
     n=NULL;
    }

template <typename E,typename C>  
E* Heap<E,C>::traverse( )const{
    E* list=new E[h_size];        //allocating memory for storing the list os E objects.
    //cout<<"inorder\n";
    inorder(root,list,h_size);            
    //cout<<endl;
    return list;
}

template <typename E,typename C>  
void Heap<E,C>::inorder(TNode<E,C>* r ,E* list,int size)const{
    static int i=0;                          
    if(r==NULL)return;
    inorder(r->left,list,size);
    list[i++]=r->val;  //cout<<" "<<r->val;
    if(i==size) i=0;                       //updating the value of i again to zero for next inorder traversal.
    inorder(r->right,list,size);
    return;
}

template <typename E,typename C>  
void Heap<E,C>::swap( TNode<E,C>* n1,TNode<E,C>* n2 ) {    //swap just swaps the values of two tree nodes.
        E r;
        r=n1->val;
        n1->val=n2->val;
        n2->val=r;
        //cout<<"swap: "<<r<<" "<<n1->val<<endl;
        return;
    }

template <typename E,typename C>  
const E& Heap<E,C>::min()const {
    if(isEmpty()) { cout<<"ERR:-Heap is empty. Random value:";  }    //check if deque is empty or not.
    else {
        return root->val;
        
    }
}      

template <typename E,typename C>  
void Heap<E,C>::insert( const E& e) {
    if(isEmpty()) { TNode<E,C>* temp=new TNode<E,C>; temp->val=e;  last=temp; root=temp;  }          //check if Heap is empty or not.
    else {
        /////-------------INSERTING THE NODE AT LEAF 1) FINDING THE LEAF .-------///////
        int fl=0;
        TNode<E,C>* cur=last;
        
        while( !isleft(cur) ){        //going up untill find a left child or root .
            if( cur->parent==NULL ){           //checking if the rooot is reached.
                while(cur->left!=NULL){
                    cur=cur->left;
                }
                TNode<E,C>* temp=new TNode<E,C>;  //add a new node to the leftmost of the tree if root is reached. 
                temp->val=e;       
                cur->left=temp;
                temp->parent=cur;
                last=temp;  //cout<<"last: "<<last->val<<endl;

                fl=1;                     //upadating a flag to check if element is inserted or not.             
                break;
            }

          cur=cur->parent;
        }
    if(fl==0){
            cur=cur->parent;           //if left child was found then insert at its right sibling leftmost.
            if(cur->right!=NULL){              //if right sibling is there.
                cur=cur->right;
                while(cur->left!=NULL){
                    cur=cur->left;
                }
                    TNode<E,C>* temp=new TNode<E,C>;  //add a new node to the leftmost of the tree if root is reached. 
                    temp->val=e; 
                    cur->left=temp;
                    temp->parent =cur;
                    last=temp;  //cout<<"last: "<<last->val<<endl;


        }else{            
                TNode<E,C>* temp=new TNode<E,C>;      //add a new node to the right sibling of the tree. 
                temp->val=e;   //cout<<"val: "<<e<<endl;
                cur->right=temp;
                temp->parent =cur;
                last=temp;//cout<<"last: "<<last->val<<endl;

        }

      }
      ////-----------UP HEAP BUBBLING-------------//////
      cur=last;
    
      while(cur->parent!=NULL && isLess(cur->val ,cur->parent->val) ){ //to check uptill the root if heap property is voilated or not.
        swap(cur,cur->parent);
        cur=cur->parent;
      }  
    }
   //cout<<" upd last: "<<last->val<<endl;
   h_size++;                            //updating heap size after every insert.
  
}


template <typename E,typename C>  
void Heap<E,C>::removeMin(){ 
    if( isEmpty() ) { cout<<"ERR:-Heap is empty cannot remove minimum.\n"; return; } //if deque is empty .
    else{     
        TNode<E,C>* cur=last;
        /////////------------DELETING THE LAST NODE AND UPDATING THE LAST NODE--------////////
        if(root==last){
            delete last;
            root=NULL;
            last=NULL;
            h_size--;
            return;
            }
        swap(last,root);
        int fl=0;
        
        while( isleft(cur) || cur->parent==NULL ){//going up untill we find a right child or root then update last to left siblings rightmost. 
            
        if(cur->parent==NULL){              //checking if the rooot is reached.
                while(cur->right!=NULL){
                    cur=cur->right;                  //going to root's rightmost leaf as the new last.
                }
                last->parent->left=NULL;
                delete last;                //deleting the previous last to avoid memory leak.
                last=cur;      //cout<<"last: "<<last->val<<endl;
                fl=1;
                break;
            }
        cur=cur->parent;
        }
        if(fl==0){
            cur=cur->parent->left;    //every right child will have a left sibling in a Heap going to its rightmost leaf. 
            while(cur->right !=NULL ){
                cur=cur->right;
            }
            (isleft(last))? last->parent->left=NULL:last->parent->right=NULL;//deleting the link of parent and last before deleting.
            delete last;                    //deleting the previous last to avoid memory leak.
            last=cur;  //cout<<"last: "<<last->val<<endl;

        }
        ////////---------DOWN HEAP BUBBLING-----------////////  
        cur=root;
        while( (cur->left!= NULL && cur->right!=NULL) ){  //going down uptill leaf is reached.
            if(cur->right==NULL){                           //if node has no right child.
                if(isLess(cur->left->val,cur->val)){
                    swap(cur,cur->left);
                    cur=cur->left;                 //updated the cur to its left child. 
                }else break;
            }else {
                if(isLess(cur->right->val,cur->val)|| isLess(cur->left->val,cur->val) ){
                   if( isLess(cur->left->val,cur->right->val) ){ //updating the cur to smaller child.
                        swap(cur,cur->left) ; 
                        cur= cur->left;            
                    }else{
                        swap(cur,cur->right);
                        cur=cur->right ;
                    }
                }else break;

            }
        }

        
    }
    //cout<<" upd last: "<<last->val<<endl;
    h_size--;           //updating the size of the Heap.   
}


template <typename E,typename C>  
void Heap<E,C>::buildHeap(E A[], int size){          
        int j;
        if(size==0) return; //check on the size.
        for(int i=size-1;i>=0;i--){          //doing bottom-up heap construction in the array itself.
            j=i;
            //cout<<"j "<<j<<" "<<A[j]<<endl;
            while( 2*j+1 < size ){                //in array the index of left child is 2*i+1 and right child 2*(i+1). 

                if ( isLess(A[2*j+1],A[j]) || ( 2*(j+1)<size && isLess(A[(j+1)*2],A[j]) ) ){
                         
                         //cout<<"e\n";
                         E r=A[j];
                        if(2*(j+1)<size){ 
                             if(isLess(A[2*j+1],A[2*(j+1)]) ){
                                 A[j]=A[2*j+1]; 
                                 A[2*j+1]=r;   //cout<<"swaped1 "<<r<<" "<<A[j]<<endl;
                                 j=2*j+1; 
                             }else {
                                 A[j]=A[2*(j+1)]; 
                                 A[2*(j+1)]=r; //cout<<"swaped2 "<<r<<" "<<A[j]<<endl;
                                 j=2*(j+1);
                             }
                        }
                        else{
                            A[j]=A[2*j+1]; 
                             A[2*j+1]=r;   //cout<<"swaped3 "<<r<<" "<<A[j]<<endl;
                             j=2*j+1; 
                        } 
                     }
                     else break;
            }
            //cout<<"j "<<j<<endl;
        }
       
        h_size=0;
        
        for(int i=0;i<size;i++){          //doing bottom-up heap construction in the array itself.
           // cout<<" "<<A[i]<<endl;
        }       //removing the previous Heap if a new Heap is built.*/
        null(root);     
        //root=form_tree(A,NULL,size,0);
        if(root==NULL)root=new TNode<E,C>;
        root->val=A[0];
        h_size++;
        form_tree(A,root,size,0);
        return;                                                      
        
}

template <typename E,typename C>  
void Heap<E,C>::form_tree(E A[],TNode<E,C>* r,int size,int st){
    if( 2*st+1 > size-1 ) return;
    //cout<<"st "<<st<<endl;
    if(2*(st+1) < size ){
        TNode<E,C>* temp1=new TNode<E,C>;
        TNode<E,C>* temp2=new TNode<E,C>;
        temp1->val=A[2*st+1];     //cout<<"temp->val "<<temp1->val<<endl;
        h_size++;                           //updating the size of the Heap.
        r->left=temp1;
        temp1->parent=r;
        temp2->val=A[2*(st+1)];   //cout<<"temp->val "<<temp2->val<<endl;
        h_size++;                          //updating the size of the Heap.
        r->right=temp2;
        temp2->parent=r;
        form_tree(A,temp1,size,2*st+1);
        form_tree(A,temp2,size,2*(st+1) );
        if(2*(st+1) == size-1) { last=temp2;  }
        
    }else{
        TNode<E,C>* temp1=new TNode<E,C>;
        temp1->val=A[2*st+1];      //cout<<"temp->val "<<temp1->val<<endl;
        h_size++;                        //updating the size of the Heap.
        r->left=temp1;
        temp1->parent=r;
        if(2*st+1 == size-1) { last=temp1;  }

          }

} /*     

template <typename E,typename C>  
TNode<E,C>* Heap<E,C>::form_tree(E A[],TNode<E,C>* par,int size,int st){
    if( st > size-1 ) return NULL;
    cout<<"st "<<st<<endl;
    TNode<E,C>* temp1=new TNode<E,C>; //cout<<"33\n";
    temp1->val=A[st];     //cout<<"temp->val "<<temp1->val<<endl;
    h_size++;                                      //updating the size of the Heap.
    temp1->left=form_tree(A,temp1,size,2*st+1);
    temp1->right=form_tree(A,temp1,size,2*(st+1) );
    temp1->parent=par;
    return temp1;

}  */    

template <typename E,typename C>  
void Heap<E,C>::mergeHeaps( Heap H ){          
    E* B=H.traverse();
    E* A=this->traverse();
    E* F=new E[H.size()+this->size()-1];
    //cout<<"F "<<endl;
    int i;                               
    for (i = 0; i < H.size()+this->size(); ++i)
    {   if(i<H.size()){
            F[i]=B[i];  ////cout<<" "<<F[i]; 
        }
        else {
            F[i]=A[i-H.size()]; // //cout<<" "<<F[i];
        }
    }                                                
    buildHeap(F,this->size()+H.size());

    return;
}

#endif