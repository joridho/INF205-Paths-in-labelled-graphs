run: comparing-paths
	cd directed-graph && make
	./comparing-paths directed-graph/results.dat

comparing-paths: comparing-paths.o
	g++ -g3 -std=c++17 -o comparing-paths *.o

%.o: %.cpp
	g++ -g3 -c -std=c++17 -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f *.o *.zip comparing-paths
	cd directed-graph && make clean
	