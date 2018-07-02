#include  <iostream>
#include <cstring>
#include "bus.h"
using namespace std;

ostream& operator<< (ostream& str, const bus& a){        //used operator overloading to print the details of a bus by same cout.
	return str<<"bus - name: "<< a.name<<"   color: "<<  a.color<<"  no_gears: "<< a.no_gears<<"  mileage:"<< a.mileage<<"  topspeed:"<< a.topspeed<<"  no_seats:"<<a.no_seats;
}


bus::bus(){                //default constructor.
	mileage = 15;
	topspeed= 80;
	no_gears =6;
	no_seats=100;
	stat=0;
}

bus::bus(string na){           //overloaded constructor.
	name=na;
	mileage = 15;
	topspeed= 80;
	no_gears =6;
	no_seats=100;
	stat=0;
}


bus::bus(string na,string c,int m,int t,int n,int ns){         //overloaded constructor.
 	mileage= m;
 	topspeed=t;
 	no_gears=n;
 	color=c;
 	name=na;
    no_seats=ns;
    stat=0;
 }

 bus::~bus(){}


void bus::book(){                          //function for booking a vehicle.
	if(stat!=0){                            //checking if vehicle is already booked or not.
		cout<< this->name <<"bus is already booked:sorry!\n";
	}else{
		stat=1;
		                                      //giving details of booked vehicle.
		cout <<"bus - name: "<< this->name<<"   color: "<<  this->color<<"  no_gears: "<< this->no_gears<<"  mileage:"<< this->mileage<<"  topspeed:"<< this->topspeed<<"  no_seats:"<<this->no_seats<<"  bus is successfully booked!!\n";
	}
}

 void bus::unbook(){                     //function for unbooking a vehicle.
	if(stat==0){                          //checking if vehicle is already booked or not.
		cout<< this->name <<"bus is not booked:sorry!\n";
	}else{
		stat=0;
		                                    //giving details of booked vehicle.
		cout <<"bus - name: "<< this->name<<"   color: "<<  this->color<<"  no_gears: "<< this->no_gears<<"  mileage:"<< this->mileage<<"  topspeed:"<< this->topspeed<<"  no_seats:"<<this->no_seats<<" bus is successfully unbooked!!\n";
	}
}

int bus::getno_seats()const{
	return  no_seats;                    //function to get the no of seats in the bus.
}
		
