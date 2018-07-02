#include <iostream>
#include <string>
#include <fstream>
#include "car.h"
#include "bus.h"
#include "truck.h"
#include "llist.cpp"
using namespace std;

int main(){
	llist < car > l_c ;    //linked list for cars. 
	int nog,mil,ts;       //variables for storing the input and calling constructors.
	string na,col;

	ifstream fc;             //for file input car.txt
	fc.open("car.txt");
	fc >>na >>col>>mil>> ts>> nog ;
	while(!fc.eof()){           //checking for EOF
	car c(na,col,mil,ts,nog);
	l_c.add(c);
	fc >>na >>col>>mil>> ts>> nog ;
	}
	

 	llist < truck > l_t ;   //linked list for trucks.
	int lkg,ll;


	ifstream ft;           //for file input truck.txt
	ft.open("truck.txt");
	ft >>na >>col>>mil>> ts>> nog>>lkg>>ll ;

	while(!ft.eof()){        //checking for EOF
	truck t(na,col,mil,ts,nog,lkg,ll);
	l_t.add(t);
	ft >>na >>col>>mil>> ts>> nog>>lkg>>ll  ;
	}
	
	
	llist < bus > l_b ;   //linked list for buses.
	int ns;

	ifstream fb;             //for file input bus.txt

	fb.open("bus.txt");
	fb >>na >>col>>mil>> ts>> nog>>ns ;

	while(!fb.eof()){               //checking for EOF
	bus b(na,col,mil,ts,nog,ns);
	l_b.add(b);
	fb >>na >>col>>mil>> ts>> nog>>ns  ;
	}

	int st,sc;         //flags to check the availabilty of vehicles .
	truck t;
	truck nt("null");    //objects for support functionality.
	bus b;
	bus nb("null");
	car c;
	car nc("null");
	int choi=1,veh;  
	
    while(choi!=0){
    cout<<"Welcome to vehicle management system:Enter your choice\n 1-Add a new vehicle\n 2-remove a vehicle\n 3-Book a vehicle\n 4-Unbook a vehicle\n 5-Details of vehicle\n 6-No of trucks for watermelon \n 7-No of buses/cars for accomodation\n 0-Quit\n";
	cin>>choi;
	if(cin.bad()){              //to clear the input buffer.
		cin.clear();
		cin.ignore(); 
	}
	switch(choi){
		case 1:cout<<"Enter your choice:\n 1-Truck 2-Bus 3-Car\n";
				cin>>veh;
				if(veh==1) {
					cout<< "Enter the details:NAME COLOR MILEAGE TOPSPEED NO_GEARS LOAD_CAP_KG LOADCAP_LIT\n";
					cin>>na>>col>>mil>>ts>>nog>>lkg>>ll;
					truck t(na,col,mil,ts,nog,lkg,ll);
					l_t.add(t);
				    cout<<"SUCESSFULLY ADDED\n";
   
					}

				else if(veh==2) {
					cout<< "Enter the details:NAME COLOR MILEAGE TOPSPEED NO_GEARS NO_SEATS\n";
					cin>>na>>col>>mil>>ts>>nog>>ns;
					bus b(na,col,mil,ts,nog,ns);
					l_b.add(b);
					cout<<"SUCESSFULLY ADDED\n";
   
					}

				else if(veh==3) {
					cout<< "Enter the details:NAME COLOR MILEAGE TOPSPEED NO_GEARS \n";
					cin>>na>>col>>mil>>ts>>nog;
					car c(na,col,mil,ts,nog);
					l_c.add(c);
					cout<<"SUCESSFULLY ADDED\n";
   					}else{
						cout<<"Wrong choice!\n\n";
						break;
					}cout<<endl;
					cout<<"Do you want to continue! 1-CONTINUE 0- QUIT\n";
					cin>> choi;
					break;	

		case 2:cout<<"Enter your choice:\n 1-Truck 2-Bus 3-Car\n";
				cin>>veh;
				if(veh==1) {
					cout<"Enter the NAME \n";
					cin>>na;
					truck t(na);
					l_t.remov(t);
					}	
				else if(veh==2) {
					cout<< "Enter the NAME \n";
					cin>>na;
					bus b(na);
					l_b.remov(b);
					}	

				else if(veh==3) {
					cout<< "Enter the NAME \n";
					cin>>na;
					car c(na);
					l_c.remov(c);
				}
				else{
						cout<<"Wrong choice!\n\n";
						break;
					}cout<<endl;
					cout<<"Do you want to continue! 1-CONTINUE 0- QUIT\n";
					cin>> choi;
					break;

		case 3:cout<<"Enter your choice:\n 1-Truck 2-Bus 3-Car\n";
				cin>>veh;
				if(veh==1) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<truck>* t_poi=l_t.search(na);                  //checking wether vehicle is in the list or not.
					if(t_poi!=NULL)   (t_poi->getval()).book();
					
					else cout<<"Vehicle not in the list.\n";
				}	
				else if(veh==2) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<bus>* b_poi=l_b.search(na);                   //checking wether vehicle is in the list or not.
					if(b_poi!=NULL)   (b_poi->getval()).book();
					
					else cout<<"Vehicle not in the list.\n";
					}	

				else if(veh==3) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<car>* c_poi=l_c.search(na);                  //checking wether vehicle is in the list or not.
					if(c_poi!=NULL) (c_poi->getval()).book();
					else cout<<"Vehicle not in the list.\n";
				}
				else{
						cout<<"Wrong choice!\n\n";
						break;
					}cout<<endl;
					cout<<"Do you want to continue! 1-CONTINUE 0- QUIT\n";
					cin>> choi;
					break;
	case 4:cout<<"Enter your choice:\n 1-Truck 2-Bus 3-Car\n";
				cin>>veh;
				if(veh==1) {
					cout<< "Enter the NAME \n";
					cin>>na;
			        node<truck>* t_poi=l_t.search(na);               //checking wether vehicle is in the list or not.
					if(t_poi!=NULL)   (t_poi->getval()).unbook();
					
					else cout<<"Vehicle not in the list.\n";
				}	
				else if(veh==2) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<bus>* b_poi=l_b.search(na);                 //checking wether vehicle is in the list or not.
					if(b_poi!=NULL)   (b_poi->getval()).unbook();
					
					else cout<<"Vehicle not in the list.\n";
					}	

				else if(veh==3) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<car>* c_poi=l_c.search(na);                     //checking wether vehicle is in the list or not.
					if(c_poi!=NULL) (c_poi->getval()).unbook();
					else cout<<"Vehicle not in the list.\n";
				}
				else{
						cout<<"Wrong choice!\n\n";
						break;
					}cout<<endl;
					cout<<"Do you want to continue! 1-CONTINUE 0- QUIT\n";
					cin>> choi;
					break;
		case 5:cout<<"Enter your choice:\n 1-Truck 2-Bus 3-Car\n";
				cin>>veh;
				if(veh==1) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<truck>* t_poi=l_t.search(na) ;             //checking wether vehicle is in the list or not.
					if(t_poi!=NULL)   cout<<(t_poi->getval())<<endl;
					
					else cout<<"Vehicle not in the list.\n";
				}	
				 else if(veh==2) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<bus>* b_poi=l_b.search(na);                //checking wether vehicle is in the list or not.
					if(b_poi!=NULL)   cout<<b_poi->getval()<<endl;
					
					else cout<<"Vehicle not in the list.\n";
					}	

				else if(veh==3) {
					cout<< "Enter the NAME \n";
					cin>>na;
					node<car>* c_poi=l_c.search(na);                 //checking wether vehicle is in the list or not.
					if(c_poi!=NULL) cout<<c_poi->getval()<<endl;
					else cout<<"Vehicle not in the list.\n";
				}
				else{
						cout<<"Wrong choice!\n\n";
						break;
					}	cout<<endl;
					cout<<"Do you want to continue! 1-CONTINUE 0- QUIT\n";
					cin>> choi;
					break;

		case 6:   long long int wat,req;
					st=0;            //watermelon capacity= 30l.
					cout<< "Enter the No of watermelons(any natural no 1 and above): \n";
					cin>>wat;
					t=l_t.iterator(st++);             //to iterate the truck list.
					req=0;
					cout<<"You need \n";
					while(req < wat*30){
						if(t==nt){                                         //to check if truck list is empty or not.
							cout<<req<<"is the max limit .WE DONT HAVE ENOUGH TRUCKS!SORRY\n";
							break;
						}
						cout<<t<< endl;
						req+=t.getload_cap();
						t=l_t.iterator(st);
						
					}cout<<endl;
					cout<<"Do you want to continue! 1-CONTINUE 0- QUIT\n";
					cin>> choi;
					break;
				
			
		case 7:   long long int persons;
					st=0,sc=0;
					cout<< "Enter the No of persons(any natural no 1 and above): \n";
					cin>>persons;
					req=0;
					cout<<"You need \n";
					while(req < persons){
						
						b=l_b.iterator(st);                          //to iterate the bus list.                  
						if(b==nb){                                   //to check if bus list is empty or not.
							
							c=l_c.iterator(sc++);                     //to iterate the car list.
							if(c==nc){                                     //to check if car list is empty or not.
								cout<<req<<"is the max limit .WE DONT HAVE ENOUGH BUSES/CARS!SORRY\n";
								break;
									}
							else{
								cout<<c<< endl;
								req+=5;
							}
										
						}else{
						cout<<b<< endl;
						req+=b.getno_seats();
										}					}

					cout<<endl;
					cout<<"Do you want to continue! 1-CONTINUE 0- QUIT\n";
					cin>>choi;
					break;
		case 0:choi=0; break;

		default: cout<<"Please choose the correct option!\n\n"; break;		
			}				

		}
	return 1;
}


