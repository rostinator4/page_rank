build:
	g++ -std=c++17 -Wall -O2 pagerank.cpp -o pagerank.exe

run: build
	./pagerank.exe
	rm -f pagerank.exe
	