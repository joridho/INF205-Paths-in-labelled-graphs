g++ -g3 -std=c++17 -o graph-benchmark *.o

run: run-graph
	./graph-benchmark 100 4 kb.dat query.dat
	./run-graph kb.dat query.dat

run-graph: graph.o query.o run-graph.o
	g++ -g3 -std=c++17 -o run-graph *.o

%.o: %.cpp
	g++ -g3 -c -std=c++17 -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f *.o *.zip run-graph
	rm -f *.o *.zip comparing-paths
