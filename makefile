build:
	g++ -std=c++17 -Wall -O2 pagerank.cpp -o pagerank.exe

run: build
	./pagerank.exe
	rm -f pagerank.exe

run_tests: build run_test1 run_test2 run_test3 run_test4
	rm -f pagerank.exe

run_test1: build
	./pagerank.exe ./testing/test1.txt 1

run_test2: build
	./pagerank.exe ./testing/test2.txt 2
	
run_test3: build
	./pagerank.exe ./testing/test3.txt 3
	
run_test4: build
	./pagerank.exe ./testing/test4.txt 4
	
	