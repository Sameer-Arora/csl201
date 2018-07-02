#ifndef  MAVL_HPP
#define MAVL_HPP 

#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

class avl_node
{
	public:
		avl_node() :size(1),height(0),order(0),left(NULL),right(NULL),parent(NULL){}
		~avl_node(){}
	private:
		int data;					//key for each node
		string str;						//vlaue of each node
		int height;
		int size;                 // useful for the other position tree.
		avl_node* left;
		avl_node* right;
		avl_node* parent;
		int order;                //useful for getting the get place.
	 friend class MAVLTree;
};

class MAVLTree{

    public:
        MAVLTree();  //Initialize the ADT	
     	int size() const;	// number of elements
    	bool isEmpty() const;	// is the tree empty?
		void insert(const int k, string s);//insert key k,s into the tree
	  	void remove(const int k);//remove k from the tree, if exists
	   	string search(const int k)const;//search for key k in the tree
		void delete_by_place(int i); //Delete from the entry at the  ith place (as determined by the order of insertion)
	    int get_place(int k)const;//Return the place (which is determined by the order of insertion), if x does not exist, return -1 
	    void print();     //utility function for level order traversal.

	private:
		int t_size;
		int t2_size;                          //T2 tree saves elements in order of their insertions.
		avl_node* root;
		avl_node* root2;
		void left_rotate(avl_node* n);  //utiltiy function for the hieght balancing of the tree.
		void right_rotate(avl_node* n);  //utiltiy function for the hieght balancing of the tree.
		void check_avl(avl_node* n,stack<avl_node*> sta);  //utiltiy function for the checking of hieght balancing of the tree.
		void check_avl_del( avl_node* n );  //utiltiy function for the checking of hieght balancing of the tree.
		void balance(stack<avl_node*> sta); //utiltiy function for the hieght balancing of the tree.
		void balance_del(avl_node* n,bool* b); //utiltiy function for the hieght balancing of the tree.
		void swap(avl_node* n1 ,avl_node* n2);       //utility function
		
};

MAVLTree::MAVLTree(){
	t_size=0;
	t2_size=0;
	root2=NULL;
	root=NULL;
}

int MAVLTree::size()const{
	return t_size;
}

bool MAVLTree::isEmpty() const{
	return (root==NULL);
}

void MAVLTree::print(){
	queue<avl_node*> q;
	if(isEmpty()) return;
	cout<<"Tree 1"<<endl;
	q.push(root);
	while(!q.empty()){
		int size=q.size();
		while(size--){
			avl_node* temp=q.front();
			cout<<temp->data<<","<<temp->str<<"," <<temp->order;
			q.pop();
			if (temp->left!=NULL)  q.push(temp->left);
			if (temp->right!=NULL)  q.push(temp->right);
			
			cout<<"\t";
		}
		cout<<endl;
	}

	cout<<"Tree 2"<<endl;
	q.push(root2);
	while(!q.empty()){
		int size=q.size();
		while(size--){
			avl_node* temp=q.front();
			cout<<temp->data<<","<<temp->size<<"," <<temp->order;
			q.pop();
			if (temp->left!=NULL)  q.push(temp->left);
			if (temp->right!=NULL)  q.push(temp->right);
			
			cout<<"\t";
		}
		cout<<endl;
	}
}

void MAVLTree::check_avl(avl_node* n, stack<avl_node*> sta ){//stack storing the nodes visited till the first imbalance occurs.
	sta.push(n);           //cout<<sta.top()->data<<" "<<sta.top()->str<<" "<<sta.top()->size<<"\n";
	if(n->parent==NULL) {  return; }       
	n=n->parent;
	int left_h=(n->left==NULL)?-1:n->left->height;
	int right_h=(n->right==NULL)?-1:n->right->height;
	if(abs(left_h-right_h)>1 ) { sta.push(n); balance(sta); return; }  //imbalance condition
	else{
		(n->height)++;        //incrementing the hieghts of nodes.
		check_avl(n,sta);
	}
}

void MAVLTree::check_avl_del(avl_node* n){
	if(n==NULL) {  return; }
	//cout<<" n "<<n->data<<endl;
		
	int left_h=(n->left==NULL)?-1:n->left->height;
	int right_h=(n->right==NULL)?-1:n->right->height;
	bool rebalance;
	if(abs(left_h-right_h)>1 ) {                   //height property chechk
		//cout<<" n "<<n->data<<endl;
		balance_del(n,&rebalance);
		if(rebalance)              							//coditional check again if hieght is reduced.
			check_avl_del(n->parent->parent); 
	}
	else{
		if(left_h==right_h){
			(n->height)--;                 //cout<<n->data<<" "<<n->height<<"\n";
			check_avl_del(n->parent);
		
		}
		else{
			return;
		}
	}
}

void MAVLTree::swap(avl_node* n1,avl_node* n2){
		int kk=n1->data;
		n1->data= n2->data;
		n2->data=kk;

		string ss= n1->str;
		n1->str=n2->str;
		n2->str=ss;

		int ord=n1->order;
		n1->order=n2->order;
		n2->order=ord;
}

void MAVLTree::left_rotate(avl_node* n){
	//print(); cout<<endl;
	avl_node* v=n;							
	avl_node* u=n->right;                   
	u->parent=v->parent;
	if(u->parent==NULL) {
		if(u->str=="") root2=u;
		else root=u;
	}
	else{
		if(v->parent->left==v){ v->parent->left=u;}
		else                   v->parent->right=u;	
	}				
	v->parent=u;							
	avl_node* temp=u->left;	 				
	u->left=v;								
	v->right = temp;							
	if(temp!=NULL) temp->parent=v;

	/////  rebalancing the sizes of the nodes  
	(u->size)+=(1+((v->left==NULL)?0:v->left->size) );   //cout<<"  u size "<<u->data<<" "<<u->size<<endl;
	(v->size)-=(1+((u->right==NULL)?0:u->right->size) ); //cout<<" v size "<<v->data<<" "<<v->size<<endl;
	//print();	 cout<<endl;		
}

void MAVLTree::right_rotate(avl_node* n){

	avl_node* v=n;							
	avl_node* u=n->left;                    
	u->parent=v->parent;
	if(u->parent==NULL){
		if(u->str=="") root2=u;
		else root=u;
	} 
	else{
		if(v->parent->left==v){ v->parent->left=u;}
		else                   v->parent->right=u;	
	}
	v->parent=u;							
	avl_node* temp=new avl_node;			
	temp=u->right;							
	u->right=v;								
	v->left=temp;								
	if(temp!=NULL) temp->parent=v;	


	/////  rebalancing the sizes of the nodes  
	u->size+=(1+((v->right==NULL)?0:v->right->size ) );  // cout<<" u size "<<u->data<<" "<<u->size<<endl;
	v->size-=(1+((u->left==NULL)?0:u->left->size) );	// cout<<" v size "<<v->data<<" "<<v->size<<endl;
	
}
void MAVLTree::balance_del(avl_node* n ,bool* rebalance){
	avl_node* z=n;      // cout<<" z "<<z->data<<endl;
		
	
	int left_h=(n->left==NULL)?-1:n->left->height;
	int right_h=(n->right==NULL)?-1:n->right->height;

	avl_node* y=(left_h >right_h )?n->left : n->right; // cout<<" y "<<y->data<<endl;
		

	left_h=(y->left==NULL)?-1:y->left->height;
	right_h=(y->right==NULL)?-1:y->right->height;
	bool inc=((left_h <= right_h)?true:false );    //if y's right child is of same height of x then the disbalance occurs;

	avl_node* x;
	if(left_h >right_h ){
		x=y->left;	
	}
	else if( right_h > left_h ){
		x=y->right;
	}
	else{
		x=(z->left==y)? y->left:y->right;
	}                                             // cout<<" x "<<x->data<<endl;
		

	int old_height=z->height;
	int new_height;
	if(z->left==y){
		if(y->left==x){
			right_rotate(z); 
			if(inc){
				(y->height)++;
				(z->height)--;
			}else{
				(z->height)-=2;
			}
			new_height=y->height;
		}
		else{
			left_rotate(y);
			right_rotate(z);
				(z->height)-=2;
				(y->height)--;
				(x->height)++;

			new_height=x->height;
		}
	}
	else{
		if(y->right==x){
			left_rotate(z);
			inc=((left_h >= right_h)?true:false );
			if(inc){
				(y->height)++;
				(z->height)--;
			}else{
				(z->height)-=2;
			}
			new_height=y->height;
		}
		else{
			right_rotate(y);
			left_rotate(z);

				(z->height)-=2;
				(y->height)--;
				(x->height)++;
			new_height=x->height;
		}
	}
	*rebalance=(new_height<old_height)?true:false;

}
void MAVLTree::balance(stack<avl_node*> sta){
	//print();
	avl_node* z=sta.top();// cout<<sta.top()->data<<" "<<sta.top()->str<<" "<<sta.top()->size<<"\n";
	sta.pop();
	avl_node* y=sta.top(); //cout<<sta.top()->data<<" "<<sta.top()->str<<" "<<sta.top()->size<<"\n";
	sta.pop();
	avl_node* x=sta.top(); //cout<<sta.top()->data<<" "<<sta.top()->str<<" "<<sta.top()->size<<"\n";

	if(z->left==y){
		if(y->left==x){
			right_rotate(z);
			(z->height)--;
		}
		else{
			left_rotate(y);
			right_rotate(z);
			(x->height)++;
			(y->height)--;
			(z->height)--;
		}
	}
	else{
		if(y->right==x){
			left_rotate(z);
			(z->height)--;

		}
		else{
			right_rotate(y);
			left_rotate(z);
			(x->height)++;
			(y->height)--;
			(z->height)--;
		}
	}
	//print();
}

void MAVLTree::insert(const int k, string s){
	if(root==NULL){
		avl_node* temp=new avl_node;
		temp->data=k;
		temp->str=s;
		root=temp;
		t_size++;
		temp->order=1;
		avl_node* temp2=new avl_node;
		temp2->data=k;
		root2=temp2;
		t2_size++;
		temp2->order=1;
	}
	else{
		///// adding the node in T1/////
		avl_node* curr=root;
		avl_node* prev= NULL;
		while( curr!=NULL ){
			if(curr->data < k )     { prev=(prev==NULL)?root:curr; curr=curr->right; }  
			else if(curr->data > k ){ prev=(prev==NULL)?root:curr; curr=curr->left; }
			else                    {  curr->str=s; return; }                  //if key is already in the tree
			}
		avl_node* temp=new avl_node;
		temp->data=k;
		temp->str=s;
		if (prev->data < k )  { prev->right=temp;  temp->parent=prev;  }
		else 				  { prev->left=temp;   temp->parent=prev;  }
		
		///// adding the node in T2 /////
		curr=root2;
		prev= NULL;
		int ord =0;
		while( curr!=NULL ){
			prev=(prev==NULL)?root2:curr;
			(curr->size)++;
			curr=curr->right;
		}
		avl_node* temp2=new avl_node;
		temp2->data=k;
		prev->right=temp2;
		temp2->parent=prev;
		ord =( prev->order +1); //cout<<"n "<<temp2->data<< " ord "<<ord<<endl;


		////    adding the links between the trees by using the order  ////
		temp2->order=ord;
		temp->order=ord; 
						
		///// re-balancing the trees and  updating the hieght and sizes ///////////
		stack<avl_node*> sta;
		stack<avl_node*> sta2;
		
		check_avl(temp,sta);
		check_avl(temp2,sta2);

		while(!sta.empty()){
			sta.pop();
		}

		while(!sta2.empty()){
			sta2.pop();
		}
		t2_size++;
		t_size++;
	}
}



string MAVLTree::search(const int k)const{
	avl_node* curr=root;
	avl_node* prev= NULL;
		while( curr!=NULL ){
			if(curr->data < k )     { prev=(prev==NULL)?root:curr; curr=curr->right; }  
			else if(curr->data > k ){ prev=(prev==NULL)?root:curr; curr=curr->left; }
			else                    {  return curr->str ; }                  //if key is already in the tree
			}
		return "KEY NOT PRESENT IN THE AVL TREE.\n";		
}

void MAVLTree::remove(const int k){
	avl_node* curr=root;
	avl_node* prev= NULL;
		while( curr!=NULL ){
			if(curr->data < k )     { prev=(prev==NULL)?root:curr; curr=curr->right; }  
			else if(curr->data > k ){ prev=(prev==NULL)?root:curr; curr=curr->left; }
			else                    { break; }                  //if key is already in the tree
			}
		if(curr==NULL) { cout<<"KEY NOT PRESENT IN THE AVL TREE CANNOT DELETE.\n";  return ;}
		
	///// Removing the node from the tree T1 and T2. /////
	
	avl_node* curr2=root2;  
	avl_node* prev2=NULL;
	int ord;
	
	if(curr->left ==NULL && curr->right == NULL){ 
		ord=curr->order;     // cout<<"n "<<curr->data<< " ord "<<ord<<endl;
		if(curr->parent==NULL) {      delete curr;  root=NULL; t_size--; t2_size--; }
			
		else if(curr->parent->left ==curr)
			{  curr->parent->left=NULL; delete curr;  t_size--; }  
		else
		    {  curr->parent->right=NULL; delete curr; t_size--; }  
	}

	else if(curr->left!=NULL && curr->right != NULL ){
		avl_node* pre=curr->left;                  //pre is the predesscor of the node to be deleted .
		while(pre->right!=NULL){
			pre=pre->right;
		}
		swap(curr,pre);
		//case 1: if the predeccesor is left child parent.
		if(pre->left!=NULL){
			swap(pre,pre->left);
			pre=pre->left;
		}
		ord=pre->order; //cout<<"n "<<pre->data<< " ord "<<ord<<endl;

		prev=pre->parent;
		if( prev->left ==pre )
			{  prev->left=NULL; delete pre;  t_size--; t2_size--; }  
		else
		    {  prev->right=NULL; delete pre; t_size--; t2_size--; }  
		
	}	 

	else{	
		if(curr->left!=NULL){

			swap(curr,curr->left);
			
			prev=curr;
			curr=curr->left;
			ord=curr->order;  //cout<<"n "<<curr->data<< " ord "<<ord<<endl;
				if(curr->parent->left ==curr)
					{  curr->parent->left=NULL; delete curr;  t_size--; t2_size--;}  
				else
			    	{  curr->parent->right=NULL; delete curr; t_size--; t2_size--;} 

			}
		else{
			swap(curr,curr->right);
			prev=curr;
			curr=curr->right;
			ord=curr->order; // cout<<"n "<<curr->data<< " ord "<<ord<<endl;
			
				if(curr->parent->left ==curr)
					{  curr->parent->left=NULL; delete curr;  t_size--; t2_size--; }  
				else
			    	{  curr->parent->right=NULL; delete curr; t_size--; t2_size--; } 

		}	
	}
	
	while( curr2!=NULL ){
		if(curr2->order < ord )     { prev2=(prev2==NULL)?root2:curr2; curr2=curr2->right; }  
		else if(curr2->order > ord ){ prev2=(prev2==NULL)?root2:curr2; curr2=curr2->left; }
		else                    { break; }                  //if key is already in the tree
	}  
//	cout<<"n "<<curr2->data<<endl;

	//////  deleting the node in T2   /////
	if(curr2->left ==NULL && curr2->right == NULL){ 
		if(curr2->parent==NULL) {      delete curr2; root2=NULL; t2_size--; return; }
			
		if(curr2->parent->left ==curr2)
			{  curr2->parent->left=NULL; delete curr2;  t2_size--; }  
		else
		    {  curr2->parent->right=NULL; delete curr2; t2_size--; }  
	}

	else if(curr2->left!=NULL && curr2->right != NULL ){
		avl_node* pre=curr2->left;                  //pre is the predesscor of the node to be deleted .
		while(pre->right!=NULL){
			pre=pre->right;
		}
		swap(curr2,pre);
		//case 1: if the predecccesor is left child parent.
		if(pre->left!=NULL){
			swap(pre,pre->left);
			pre=pre->left;
		}
		prev2=pre->parent;
		if( prev2->left ==pre )
			{  prev2->left=NULL; delete pre;  t_size--; }  
		else
		    {  prev2->right=NULL; delete pre; t_size--; }  
		
	}	 

	else{	
		if(curr2->left!=NULL){
			swap(curr2,curr2->left);
			prev2=curr2;
			curr2=curr2->left;
				if(curr2->parent->left ==curr2)
					{  curr2->parent->left=NULL; delete curr2;  t2_size--; }  
				else
			    	{  curr2->parent->right=NULL; delete curr2; t2_size--; } 

			}
		else{
			swap(curr2,curr2->right);
			prev2=curr2;
			curr2=curr2->right;
				if(curr2->parent->left ==curr2)
					{  curr2->parent->left=NULL; delete curr2;  t_size--; }  
				else
			    	{  curr2->parent->right=NULL; delete curr2; t_size--; } 

		}	
	}
	//cout<<"p "<<prev2->data<<endl;

	////  Updating the sizes in T2    ///
	avl_node* temp3=prev2;
	while(temp3!=NULL){
		(temp3->size)--;
		temp3=temp3->parent;
	}

	///// Rebalancing of the trees T1 and T2.  ///////
	check_avl_del(prev);
	check_avl_del(prev2);
	
}

int MAVLTree::get_place(int k)const{                  
	avl_node* curr=root;                   //searching in the node in T1.
	int place=0;
		while( curr!=NULL ){
			//cout<<curr->data<<endl;

			if(curr->data < k )     { 
				curr=curr->right;  
			}
			else if(curr->data > k ){ 
				curr=curr->left; 
			}
			else{  
				break;
			}                
		}	
		if(curr==NULL){
			cout<<"INDEX OUT OF RANGE.\n";	
			return -1;	
		}

	avl_node* curr2=root2;             //searching in the T2 for the node by using order as the key.
	int ord=curr->order;
		
		while( curr2!=NULL ){
			//cout<<curr2->data<<endl;

			if(curr2->order < ord )     { 
				place+=( ( (curr2->left==NULL)?0:curr2->left->size ) +1); 
				curr2=curr2->right;  
			}
			else if(curr2->order > ord ){ 
				curr2=curr2->left; 
			}
			else{  
				place+=( ( (curr2->left==NULL)?0:curr2->left->size ) +1); 
				return place; 
			}                  
		}	
		
			//cout<<curr->data<<endl;	
}

void MAVLTree::delete_by_place(int i){
	avl_node* curr=root2;
	if( isEmpty() || curr->size < i || i<=0 ) {  cout<<"Position is out of bound not enough keys.\n"; return; }
	int pl=0;                                   //place to delete
	while(curr!=NULL){
		pl+=( ( (curr->left==NULL)?0:curr->left->size ) +1); 
		if( i <  pl ){
			curr=curr->left;
		}else if(i == pl ){
			remove(curr->data);
			return;

		}else{
			i=i-(pl);
			curr=curr->right;
		}

	}
		
}

#endif