#include <bits/stdc++.h>
using namespace std;

//vertical order traversal of binary tree.
typedef struct node
 {
 	int data;
 	node *left=NULL,*right=NULL;
 }node ; 

void insert_node(node *head,int val){
	node *curr=head;
	if(curr==NULL) return;
	if(val > curr->data ){
		if(curr->right ==NULL){
			node* temp=new node;
			temp->data=val;
			curr->right=temp;
		}else{
			insert_node(curr->right,val);
		}
	}else{
		if(curr->left ==NULL){
			node* temp=new node;
			temp->data=val;
			curr->left=temp;
		}else{
			insert_node(curr->left,val);
		}
	}
}

 node* form_tree( int *arr,int size){
 	int i=0,j;
 	node* head=new node;
 	head->data=arr[0];
 	node* curr=head;
 	for(i=1;i<size;i++){
 		insert_node(head,arr[i]);
 	}
 	return head;
 }

void print_inoder_tree(node* head){
	node* curr=head;
	//cout<<"tr";
	if(curr==NULL) return;
	
	print_inoder_tree(curr->left);
	cout<<curr->data<<"\t";
	print_inoder_tree(curr->right);

}
typedef struct dnode
{
	int data;
	dnode *next=NULL,*prev=NULL;
}dnode;


void hash(node* head,dnode** map,int hd,int size){
	node* curr=head;
	//cout<<"hhe"<<endl;
	if(curr==NULL) return;
	if( map[hd+size-1]==NULL){
		dnode* temp=new dnode;
		temp->data=curr->data;
		map[hd+size-1]=temp;
	} else{
		dnode* temp=new dnode;
		temp->data=curr->data;
		temp->next=map[hd+size-1];
		map[hd+size-1]->prev=temp;
		map[hd+size-1]=temp;
	}
	hash(curr->left,map,hd-1,size);
	hash(curr->right,map,hd+1,size);
	
}
void print_reverse(dnode* he){
	if(he==NULL)return;
	print_reverse(he->next);
	cout<< he->data<<" ";
} 
void print_vertical(dnode** map,int map_size){
	for(int i=0;i<map_size;i++){
		if(map[i]==NULL)  continue;
		else {
			//cout<<"e"<<endl;
		print_reverse(map[i]);
		cout<<endl;
			}
	}
}
 int main(){
 	int arr[]={7,8,96,5,6,53,52,2,1,0};
 	node* head=form_tree(arr,10);
 	print_inoder_tree(head);
 	cout<<endl;
 	dnode* map[19];    //map of size 2n-1.
 	for(int i=0;i<19;i++)
 		map[i]=NULL;
 	hash(head,map,0,10);
 	print_vertical(map,19);
 }