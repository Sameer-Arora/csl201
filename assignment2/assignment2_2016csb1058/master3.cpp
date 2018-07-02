#include "heap.hpp"
#include <fstream>
#include <cstdlib>


using namespace std;


void checkheap();

class Student{
public:
	Student(){}
	Student(string n, string b, double g){
		name=n;
		branch=b;
		grade=g;
	}
	string name;
	string branch;
	double grade;

};



class Less{
public:
	bool operator()(Student &a, Student &b){ return a.grade<b.grade; }
};

int main (){

		cout<<"checking for heap template with 3 cases"<<endl;
		checkheap();
	

	return 0;
}




void checkheap(){
	fstream input;
	string line;

	input.open("records.txt",ios::in);
	if (!input) {
    cerr << "Unable to open file records.txt";
    exit(1);   // call system to stop
    }
	
	int count ;
	input>>count;
	//cout<<" Original number of records present in records.txt "<<count<<endl;




	float min_grade = 10.0,temp;
	Heap<Student,Less> h;
	for(int i = 0 ; i < count;i++){
		Student *s= new Student;
		input>>s->name>>s->branch>>s->grade;
		temp = (float)s->grade;
		if(min_grade > temp)
			min_grade = temp;
		// cout<<temp<<endl;
		h.insert(*s);
	}
	//case 1 size should equal to total records
	//cout<<"tree size"<<h.size()<<endl;

	if (h.size() == count)
		cout<<"Passed"<<endl;
	else
		cout<<"Fail"<<endl;



	// case 2 check min should come as root node

	if(min_grade ==((float)(h.min().grade )))
		cout<<"Passed"<<endl;
	else
		cout<<"Fail"<<endl;
	

	//case 3 for merging two heap
	int counter=0;
	Heap<Student, Less> h1;
	h1.insert(Student("Heap2_chamu","Dept",1));
	h1.insert(Student("Heap2_somu","Dept", 5));
	h1.insert(Student("Heap2_ramu","Dept", 2));

	h.mergeHeaps(h1);
	/*
	//cout<<"start after merge"<<endl;
	while(!(h.isEmpty())){
		counter++;
		//cout<<"Lowest Now is "<<h.min().name<<endl;	
		h.removeMin();
	}

	if(counter > count )
		cout<<"Passed"<<endl;
	else
		cout<<"Fail"<<endl;	*/

	return;
}