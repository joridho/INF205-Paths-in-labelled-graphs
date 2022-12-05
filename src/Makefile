run: time-comparing-paths
	./time-comparing-paths

time-comparing-paths: time-comparing-paths.o comparing-paths.o 
	g++ -g3 -std=c++17 -o time-comparing-paths *.o

%.o: %.cpp
	g++ -g3 -c -std=c++17 -o $@ $<

clean:
	@echo "Cleaning up..."
	rm -f *.o *.zip time-comparing-paths
	cd directed-graph && make clean