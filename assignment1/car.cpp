#include<iostream>
#include<cstring>
#include "car.h"
using namespace std;



ostream& operator<< (ostream& str, const car& a){          //used operator overloading to print the details of a car by same cout.
	return str<<"Car - name: "<< a.name<<"   color: "<<  a.color<<"  no_gears: "<< a.no_gears<<"  mileage:"<< a.mileage<<"  topspeed:"<< a.topspeed;

}
 car::car():mileage(25),topspeed(100),no_gears(5),stat(0){}            // constructor.

car::car(string na):mileage(25),topspeed(100),no_gears(5),stat(0){                  //overloaded constructor.   
	name=na;
} 
 car::car(string na,string c,int m,int t,int n){                     //overloaded constructor.
 	mileage= m;
 	topspeed=t;
 	no_gears=n;
 	color=c;
 	name=na;
 	stat=0;
 }

 car::~car(){}



void car::book(){                                      //function for booking a vehicle.
	if(stat!=0){                                       //checking if vehicle is already booked or not.

		cout<< this->name <<"car is already booked:sorry!\n";
	}else{
		stat=1;
		                                                //giving details of booked vehicle.
		cout <<"Car - name: "<< this->name<<"   color: "<<  this->color<<"  no_gears: "<< this->no_gears<<"  mileage:"<< this->mileage<<"  topspeed:"<< this->topspeed<< " car is successfully booked!!\n";
	}

}

void car::unbook(){                                    //function for unbooking a vehicle.
	if (stat==0){                                       //checking if vehicle is already booked or not.
		cout<< this->name <<"car is not booked:sorry!\n";
	}else{
		stat=0;                                              //giving details of unbooked vehicle.
		cout << "Car - name: "<< this->name<<"   color: "<<  this->color<<"  no_gears: "<< this->no_gears<<"  mileage:"<< this->mileage<<"  topspeed:"<< this->topspeed<<" car is successfully unbooked!!\n";
	}
}
