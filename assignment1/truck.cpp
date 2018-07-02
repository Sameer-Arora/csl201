#include  <iostream>
#include <cstring>
#include "truck.h"
using namespace std;


 

ostream& operator<< (ostream& str, const truck& a){       //used operator overloading to print the details of a truck by same cout.
	return str<<"truck - name: "<< a.name<<"   color: "<<  a.color<<"  no_gears: "<< a.no_gears<<"  mileage:"<< a.mileage<<"  topspeed:"<< a.topspeed<<"  lo_cap_kg:"<<a.lo_cap_kg<<"  lo_cap_l:"<<a.lo_cap_l;
}


truck::truck(){                                                            // constructor.
	mileage = 15;
	topspeed= 80;
	no_gears =6;
	lo_cap_l = 2300;
	lo_cap_kg = 5600;
	stat=0;
}

truck::truck(string na){                                                   //overloaded constructor.
	name=na;
	mileage = 15;
	topspeed= 80;
	no_gears =6;
	lo_cap_l = 2300;
	lo_cap_kg = 5600;
	stat=0;
}


truck::truck(string na,string c,int m,int t,int n,int lkg,int ll){              //overloaded constructor.
 	mileage= m;
 	topspeed=t;
 	no_gears=n;
 	color=c;
 	name=na;
 	lo_cap_kg=lkg;
 	lo_cap_l=ll;
 	stat=0;
 }

 truck::~truck(){}


void truck::book(){                                         //function to book a vehicle.
	if(stat!=0){                                            //checking if vehicle is already booked or not.

		cout<< this->name <<"truck is already booked:sorry!\n";
	}else{
		stat=1;
	                                                       //giving details of booked vehicle.
		cout <<"truck - name: "<< this->name<<"   color: "<<  this->color<<"  no_gears: "<< this->no_gears<<"  mileage:"<< this->mileage<<"  topspeed:"<< this->topspeed<<"  lo_cap_kg:"<<this->lo_cap_kg<<"  lo_cap_l:"<<this->lo_cap_l<< " truck is successfully booked!!\n";
	}

}

void truck::unbook(){                                              //function to unbook a vehicle.
	if(stat==0){                                                    //checking if vehicle is already booked or not.
		cout<< this->name <<"truck is not booked:sorry!\n";
	}else{
		stat=0;
	                                                      //giving details of unbooked vehicle.
		cout <<"truck - name: "<< this->name<<"   color: "<<  this->color<<"  no_gears: "<< this->no_gears<<"  mileage:"<< this->mileage<<"  topspeed:"<< this->topspeed<<"  lo_cap_kg:"<<this->lo_cap_kg<<"  lo_cap_l:"<<this->lo_cap_l<< " truck is successfully unbooked!!\n";
	}
}
 
int truck::getload_cap()const{                             //function to get the no of seats in the bus.
		return lo_cap_l;
	}