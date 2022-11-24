run: timing_algorithm
	@echo "\n"
	./timing_algorithm

timing_algorithm: timing_algorithm.o ../directed-graph/graph-benchmark.o ../directed-graph/run-graph.o
	g++ -g3 -std=c++17 -o timing_algorithm *.o

%.o: %.cpp
	g++ -g3 -c -std=c++17 -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f *.o *.zip timing_algorithm