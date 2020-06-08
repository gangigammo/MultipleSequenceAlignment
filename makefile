run:
	rm main
	g++ -std=c++17 -o main main.cpp Blossum62.cpp pairDP.cpp StarMethod.cpp
	./main

main:
	g++ -std=c++17 -o main main.cpp Blossum62.cpp pairDP.cpp StarMethod.cpp
	./main