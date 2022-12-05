run: threading-paths
	@clear 
	./threading-paths

threading-paths: threading-paths.o
	g++ -g3 -std=c++17 -o threading-paths *.o

%.o: %.cpp
	g++ -g3 -c -std=c++17 -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f *.o *.zip threading-paths
