run: main
	cd directed-graph && make
	./main directed-graph/results.dat

main: main.o comparing-paths.o
	g++ -g3 -std=c++17 -o main *.o

%.o: %.cpp
	g++ -g3 -c -std=c++17 -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f *.o *.zip main
	cd directed-graph && make clean
