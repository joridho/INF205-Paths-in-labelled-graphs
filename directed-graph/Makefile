run: run-graph
	./run-graph 1000 10 kb.dat query.dat 1

run-graph: graph.o query.o run-graph.o graph-benchmark.o
	g++ -g3 -std=c++17 -o run-graph *.o

%.o: %.cpp
	g++ -g3 -c -std=c++17 -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f *.o *.zip run-graph
