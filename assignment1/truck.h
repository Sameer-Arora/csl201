#ifndef  TRUCK_H
#define TRUCK_H

#include "car.h"                             //include the base class.

class truck : public car{               //inheriting from the base class car.
 private:
 	int lo_cap_kg;                        //additonal members of class.
 	int lo_cap_l;
 	
 public:
 	truck();                           //constructor
 	truck(string na);                            // overloaded constructor
 	truck(string na,string c,int m,int t,int n,int lkg,int ll);       // overloaded constructor
 	~truck();                                        // destructor
 	void book();
 	void unbook();
 	int getload_cap()const;
 	
 bool operator== (truck b){          //used operator overloading to compare two trucks by same operator.
	return (this->name == b.name);
} 

bool operator > (truck b){          //used operator overloading to compare two trucks on basis of no of seats  by same operator.
	return (this->lo_cap_l > b.lo_cap_l);
}
friend ostream& operator<< (ostream& str, const truck& a);           //friend function.
 
 };

#endif