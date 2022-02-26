FindMax.out : FindMax.o RunFind.o  
	g++ -ansi -Wall -g -o FindMax.out FindMax.o RunFind.o  

FindMax.o : FindMax.cpp FindMax.h 
	g++ -ansi -Wall -g -c FindMax.cpp

RunFind.o : RunFind.cpp RunFind.h CPUTimer.h FindMax.h 
	g++ -ansi -Wall -g -c RunFind.cpp

clean : 
	rm -f FindMax.out FindMax.o  RunFind.o   
