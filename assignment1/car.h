#ifndef CAR_H
#define  CAR_H

#include  <iostream>
#include <cstring>
using namespace std;
class car
 {                                               //members of the class declared protected so to give access to derived classes.
 protected:                     
 	int mileage;
 	int topspeed;
 	int no_gears;
 	string color; 
 	string name;
 	bool stat;
 public:
 	car();                                //constructor
 	car(string na);                          // overloaded constructor
 	car(string na,string c,int m,int t,int n);       // overloaded constructor
 	~car();                                        // destructor
 	virtual void book();                     //virtual funtions used to have different functions for the derived class.
	virtual void unbook();
	
 bool operator== (car b){                //used operator overloading to compare two cars by same operator.
	return (this->name == b.name);
	} 
 friend ostream& operator<< (ostream& str, const car& a);          //friend function.
 
 };

#endif