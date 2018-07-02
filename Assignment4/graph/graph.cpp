#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include "graph.h"
using namespace std;



int main(){
	graph g;/*
	g.add_node("C1",12);
	g.add_node("C2",10);
	g.add_node("C3",11);

	g.add_edge(g.find_node("C1"),g.find_node("C2"));
	g.add_edge(g.find_node("C2"),g.find_node("C3"));
	g.add_edge(g.find_node("C1"),g.find_node("C3"));
	g.adj_node_d(g.find_node("C1"));
	g.adj_node_d(g.find_node("C2"));
	g.adj_node_d(g.find_node("C3"));
	g.adj_node_r(g.find_node("C1"));
	g.adj_node_r(g.find_node("C2"));
	g.adj_node_r(g.find_node("C3"));
	cout<<g.check_cycle(g.find_node("C1"))<<endl;
	cout<<g.check_cycle(g.find_node("C2"))<<endl;
	cout<<g.check_cycle(g.find_node("C3"))<<endl;

*/
	ifstream fin;
	fin.open("courses.txt",ios::in);
	string name;
	int num;
	fin>>name>>num;
	g.add_node(name,num);

	while(!fin.eof()){
		fin>>name>>num;
		g.add_node(name,num);
 	}
	fin.close();

	fin.open("dependencies.txt",ios::in);
	string name1;
	fin>>name>>name1;
	g.add_edge( g.find_node(name),g.find_node(name1));

	while(!fin.eof()){
		fin>>name>>name1;
		g.add_edge( g.find_node(name), g.find_node(name1));
	}
	cout<<"​Longest​ ​ duration​ ​ is​ ​"<<g.longest_path()<<"​ months."<<endl;
	
	return 0;
}