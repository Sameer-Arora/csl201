#ifndef BUS_H
#define BUS_H

 #include "car.h"                   //include the base class.

 class bus : public car{             //inheriting from the base class car.
 private:
 	int no_seats;                      //additonal members of class.
 	
 public:
 	bus();                           //constructor
 	bus(string na);           // overloaded constructor
 	bus(string na,string c,int m,int t,int n,int ns);   // overloaded constructor
 	~bus();                         // destructor
 	void book();
 	void unbook();
 	int getno_seats()const;

 bool operator== (bus b){                //used operator overloading to compare two buses by same operator.
	return (this->name == b.name);
} 

bool operator > (bus b){                //used operator overloading to compare two buses on basis of no of seats  by same operator.
	return (this->no_seats > b.no_seats);
} 

friend ostream& operator<< (ostream& str, const bus& a);     //friend function.
 };

#endif
