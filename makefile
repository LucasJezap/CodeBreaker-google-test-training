CC = g++ -ggdb -Iinclude
T = -lgtest -pthread

compile:
	$(CC) src/*.cpp $(T) -o codebreaker

all:
	./codebreaker 2

tests:
	./codebreaker 0

play:
	./codebreaker 1

clean:
	rm codebreaker