# INF205 Paths in labelled graphs
## Programming project in INF205 Resource-efficient programming at NMBU
The point of the project is to take in a labelled graph *g* and two sequences *p* and *q* of edge labels and check if there exist a path *p* and a path *q* that contains the same start node and end node. 

## The code 

### src
The folder containing the whole directory

##### main.cpp
You run this code and it will run the most important file for comparing the paths. Running Makefile in src-folder is better. 

##### comparing-paths.cpp
Compares the paths that is read from results.dat 

##### time-comparing-paths.cpp
Measures the run time for comparing-paths.cpp
nevn hvordan den funker og hva som blir tatt tid på 

#### results 
Folder containing all the different results 
- Results with different amounts of paths found from 2^4 to 2^13
- Results with different amount of equal paths found: 0%, 25%, 50%, 75% and 100%
- plot-timing.py - code for plotting the results 
- 6 different plots saved as png 
- 5 different .dat-files with the time it took to benchmark-testing 
- kbt.dat and queryt.dat which contains data used to benchmark run-graph.cpp

#### directed-graph
Folder containing the code for creating the graph and finding valid paths to use in comparing-paths

##### graph-benchmark.cpp

##### query.cpp

##### graph.cpp

##### run-graph.cpp
run-graph.cpp 

##### time-run-graph.cpp


#### threading_pkg 

##### src

###### threading-paths.cpp


## How does it work and how to use it


## Performance 



## Concurrency 


## Further work 


