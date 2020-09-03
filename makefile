all: Teleposter

Teleposter: main.o Task.o Dispetcher.o Network.o additional.o 
	g++ -o "teleposter" main.o Task.o Dispetcher.o Network.o additional.o   -lcurl 

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Task.o: Task.cpp
	g++ -c Task.cpp -std=c++11
	
Dispetcher.o: Dispetcher.cpp
	g++ -c Dispetcher.cpp -std=c++11



Network.o: Network.cpp
	g++ -c Network.cpp -std=c++11
	
additional.o: additional.cpp
	g++ -c additional.cpp -std=c++11
	
clean:
	rm -rf *.o teleposter
 
