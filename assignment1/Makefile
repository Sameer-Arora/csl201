default:ass1

ass1:r.o  car.o  truck.o bus.o 
	g++ r.o  car.o truck.o bus.o -o ass1

r.o: r.cpp llist.cpp
	g++ -c r.cpp -o r.o

car.o:car.cpp	
	g++ -c car.cpp -o car.o

truck.o:truck.cpp	car.o
	g++ -c truck.cpp -o truck.o

bus.o:bus.cpp	car.o
	g++ -c bus.cpp -o bus.o
	
clean:
	rm  r.o  car.o truck.o bus.o