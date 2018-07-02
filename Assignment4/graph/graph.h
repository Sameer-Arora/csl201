#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <map>

using namespace std;
//implement the graph nodes and edges.

class g_edge;
class g_node
{
	public:
		g_node(string c,int d){
			course=c;
			visited=false;
			in_recursion_stack=false;
			duration=d;
			size=duration;
		}
		
	private:
		string course;     //nodes name denoting course.
		int duration;     //duration of the course.
		vector<g_edge*> list; //list of edges for each vertex
		g_node** pnode;  //pointer to the original graph nodes.
		bool visited;
		bool in_recursion_stack;
		int size;

	friend class g_edge;
	friend class graph;
};

class g_edge
{
	public:
		g_edge(g_node *st,g_node *en){
		//cout<<"edge"<<endl;
		start=st;  // cout<<st->course<<"  "<<st->duration<<endl;

		end=en; //cout<<en->course<<"  "<<en->duration<<endl;

	}
	
	private:
		g_node* start;  //list of vetrex joined by edge. 
		g_node* end;  //list of vetrex joined by edge. 
		g_edge** list_s;  //list of 
		g_edge** list_e;  //list of 
		g_edge** pedge;  //pointer to the original graph edges.
	
	friend class graph;

};

class graph
{
	public:
		graph(){}
		void add_edge(g_node* n1,g_node* n2);
		void add_node(string name,int d);
		g_node* find_node(string s);
		int longest_path();
		bool check_cycle(g_node* n);
		vector<g_node*> adj_node_d(g_node* n1);
		vector<g_node*> adj_node_r(g_node* n1);        
		void topo_sort(g_node* n);	
		void path(g_node* n1,string& s);

	private:

		map <string,g_node*> nodes;
		vector <g_edge*> edges;


};

g_node* graph::find_node(string s){
	return nodes.find(s)->second;
	//return &(* nodes.find(s)->second);
}


void graph::add_edge(g_node* n1,g_node* n2){  //c
	g_edge* temp=new g_edge(n1,n2);
	temp->pedge=&temp;              
	n1->list.push_back(temp); 
	int size=n1->list.size();
	temp->list_s=&(n1->list[size-1]);
	n2->list.push_back(temp);
	size=n2->list.size();
	temp->list_e=&(n2->list[size-1]);
	edges.push_back(temp);

}

void graph::add_node(string name,int d){
	g_node* temp=new g_node(name,d);
	temp->pnode=&temp;    //cout<<temp->course<<"  "<<temp->duration<<endl;
	nodes.insert(make_pair(name,temp));  //cout<<temp<<" "<<*temp<<endl;
}

vector<g_node*> graph::adj_node_d(g_node* n1){        
	vector<g_node*> res;
	std::vector<g_edge*>::iterator i;
	//cout<<"n "<<n1->course<<endl;
	//cout<<" a";
	for(i=n1->list.begin();i!=n1->list.end();i++){
		if( (*i)->start==n1 ){
			//cout<<" "<<(*i)->end->course;
			res.push_back((*i)->end);
		}
	}
	//cout<<endl;

	return res;
}

vector<g_node*> graph::adj_node_r(g_node* n1){        
	vector<g_node*> res;
	std::vector<g_edge*>::iterator i;
	//cout<<"n "<<n1->course<<endl;
	//cout<<" a";
	for(i=n1->list.begin();i!=n1->list.end();i++){
		if((*i)->end==n1 ){
			//cout<<" "<<(*i)->start->course;
			res.push_back((*i)->start);
		}
	}
	//cout<<endl;
	return res;
}

void graph::topo_sort(g_node* n){
	n->visited=false;
	vector<g_node*>::iterator i;
	vector<g_node*> v=adj_node_d(n);

	for(i=v.begin();i!=v.end();i++){
		if((*i)->visited){
			//cout<<"n "<< (*i)->course<<endl;

			(*i)->size+=n->size;   
			//cout<<"s "<< (*i)->size<<endl;
		}
		else{
			//cout<<"n "<< (*i)->course<<endl;

			if((*i)->size < (n->size + (*i)->duration) ){
				(*i)->size=(n->size + (*i)->duration);
				//cout<<"s "<< (*i)->size<<endl;

			}
		}
		topo_sort (*i);

	}
}

bool graph::check_cycle(g_node* n){
	n->visited=true;
	n->in_recursion_stack=true;
	vector<g_node*>::iterator i;
	vector<g_node*> v=adj_node_d(n);

	for(i=v.begin();i!=v.end();i++){
		//cout<<(*i)->course<<endl;
		if(!(*i)->visited && check_cycle((*i)) ){
			return true;
		}
		else{
			if((*i)->in_recursion_stack)
				return true;
		}
	}
	n->in_recursion_stack=false;
	return false;
}

void graph::path(g_node* n1, string& s ){
	n1->visited=true;
	//cout<<n1->course<<" -> ";
	s= n1->course +" -> " +s ;
	vector<g_node*>::iterator i;
	vector<g_node*>::iterator lng;
	vector<g_node*> v=adj_node_r(n1);
	int max=0;
	lng=v.end();
	for(i=v.begin();i!=v.end();i++){
		//cout<<(*i)->course<<endl;
		if(!(*i)->visited ){
			if(max < (*i)->size ){
				lng=i;
				max=(*i)->size ;
			}
		}
	}
	if(lng!=v.end())	
		path(*lng,s);
}

int graph::longest_path(){
	std::map<string,g_node*>::iterator i;
	std::vector<g_edge*>::iterator j;
	
	bool check=check_cycle(&(*nodes.begin()->second));
	if(check){
		cout<<"Not​ a ​DAG\n";
	}
	else{
		topo_sort ( &(*nodes.begin()->second));
	}
	string s;
	path(&(*nodes.rbegin()->second),s );
	s="Longest path is "+s;
	cout<<s<<endl;
	return  nodes.rbegin()->second->size;
}

#endif