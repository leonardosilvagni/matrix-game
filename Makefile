all:
	g++ -std=c++11 main.cpp -o program.out
	./program.out
header:
	g++ test.cpp -o header.out
	./header.out
clean:
	rm program.out
