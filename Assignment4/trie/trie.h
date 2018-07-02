#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <string>
#include <queue>
using namespace std;
//implement the compressed tries

class trie_node
{
	public:
		trie_node(){
			is_end_word=false;
			size=0;
			for(int i=0;i<26;i++){
				child[i]=NULL;		
			}
		}
		
	private:
		trie_node* child[26];
		bool is_end_word;
		string data;
		long long int p_num;
		int size;
		string parent;
		
	friend class Trie;
};

class Trie
{
	public:
		Trie(){
			root=new trie_node;
		
		}
		void insert(string s,long long int p_nm);
		void remove(string s);
		void search(string s);
		void print(trie_node* r); 
		void print_trie(); 
		void swap(trie_node* r,trie_node* s,int j);

	private:
		trie_node* root;

};


void Trie::swap(trie_node* r,trie_node* s,int j){
	for(int i=0;i<26;i++){
		if(i!=j)
		{
			s->child[i]=r->child[i];
			r->child[i]=NULL;
		}
	}
}

void Trie::insert(string s,long long int p_nm){
	trie_node* curr=root;
	int i=s[0]-'a';  //cout<<"i "<<i<<endl;
	int count=0;
	int j;
	bool extens=true;
	while(curr->child[i]!=NULL ){
		curr=curr->child[i];
		for(j=0; j< curr->data.size() ;j++){
			if( count >= s.size()) { goto pr;}
			//cout<<curr->data;
			if(s[count]!=curr->data[j] ){
					extens=false;
					goto pr;
			}
			count++;
			//cout<<"co "<<count<<endl;

		}
		curr->size++;
		i=s[count]-'a'; //cout<<"i "<<i<<endl;
	}
	pr:

	if( extens && curr->child[i]==NULL ){  //case1
		curr->child[i]=new trie_node;
		string par=curr->parent+curr->data;
		curr=curr->child[i];
		curr->data=s.substr(count,s.size()-count);  //cout<<"c->da "<<curr->data<<endl;
		curr->p_num=p_nm;  //cout<<"c->n "<<curr->p_num<<endl;
		curr->is_end_word=true;   	  //cout<<"c->end "<<curr->is_end_word<<endl;
		curr->parent=par;
		curr->size++;
	}
	else if(extens && curr->child[i]!=NULL ){      //case2
		curr=curr->child[i];
		curr->p_num=p_nm;  //cout<<"c->n "<<curr->p_num<<endl;
		curr->is_end_word=true;  //cout<<"c->end "<<curr->is_end_word<<endl;
		curr->size++;
	}
	else{               //case3
		string r;
		string r1;

		int i1=s[count]-'a'; // cout<<"i "<<i<<endl;
		i=curr->data[j]-'a'; //cout<<"i1 "<<i1<<endl;
		
		r=curr->data.substr(j,curr->data.size());    //string in lower nodes.
		r1=s.substr(count,s.size()-count);                  //string of new insertion.
		curr->data=curr->data.substr(0,j);//cout<<"c->da "<<curr->data<<endl;
		bool is_end_par=curr->is_end_word;
		int par_size=curr->size;
		curr->is_end_word=false;   //cout<<"c->end "<<curr->is_end_word<<endl;
		curr->size++;
		long long int p=curr->p_num;
		curr->child[i]=new trie_node;
		swap(curr,curr->child[i],i);
		
		curr->child[i1]=new trie_node;
		
		trie_node* curr1=curr->child[i1];
		string par=curr->parent+curr->data;

		curr=curr->child[i];
		curr->data=r;  //cout<<"c2->da "<<curr->data<<endl;
		curr->p_num=p; //cout<<"c2->n "<<curr->p_num<<endl;
		curr->is_end_word=is_end_par;  //cout<<"c2->end "<<curr->is_end_word<<endl;
		curr->parent=par;
		curr->size=par_size;

		//add the old cildren also

		curr1->data=r1;  //cout<<"c1->da "<<curr1->data<<endl;
		curr1->p_num=p_nm;  //cout<<"c1->n "<<curr1->p_num<<endl;
		curr1->is_end_word=true;  //cout<<"c1->end "<<curr->is_end_word<<endl;
		curr1->parent=par;
		curr1->size++;

	}
}


void Trie::print(trie_node* r) {
	if(r==NULL) return;
	queue<trie_node*> q;
	q.push(r);
	int i=0;
	cout<<"Total "<<r->size<<" matches found of which best 5 are\n";
	while(!q.empty()){
		//cout<<"3\n";
		int size=q.size();
		
		while(size--){
			trie_node* temp=q.front();
			//cout<<"tem "<<temp->data<<endl;
			//cout<<"tem "<<temp->is_end_word<<endl;

			if( i>=5 ) return;
			if(temp->is_end_word==true){
				cout<<(temp->parent+temp->data)<<","<<temp->p_num<<endl;
				i++;
				}
			q.pop();
			for(int j=0;j<26;j++){
				if (temp->child[j]!=NULL)  { 
					q.push(temp->child[j]);
				}

			}			
		}
	}
}

void Trie::print_trie() {
	queue<trie_node*> q;
	q.push(root);
	int i=0;
	string res;
	while(!q.empty()){
		int size=q.size();
		
		while(size--){
			trie_node* temp=q.front();
			cout<<(temp->parent+temp->data)<<","<<temp->p_num<<"\t";
			q.pop();
			for(int i=0;i<26;i++){
				if (temp->child[i]!=NULL)  { 
					temp->child[i]->parent=temp->parent+temp->data;
					q.push(temp->child[i]);
				}

			}			
		}
		cout<<endl;
	}
}

void Trie::search(string s){
	trie_node* curr=root;
	int i=s[0]-'a';
	int count=0;
	bool found=false;
	while(curr->child[i]!=NULL ){
		curr=curr->child[i];
		for(int j=0; j< curr->data.size() ;j++){

			if(s[count++]!=curr->data[j] ){
					cout<<"Contact not found\n";
					return;
			}
			if( count >= s.size()) { found=true; goto pr; }
		
		}
		i=s[count]-'a';
	}
	pr:
	if(found==true)
		print(curr);
	else
		cout<<"Contact not found\n";
			
	return ;

}


#endif