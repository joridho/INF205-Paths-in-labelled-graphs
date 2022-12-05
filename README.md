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
Folder containing the code for creating the graph and finding valid paths to use in comparing-paths.

##### graph-benchmark.cpp
- Creates a graph which is written into file $kb.dat$ and the partitions p and , which are written into $query.dat$ file.

##### query.cpp

##### graph.cpp
- 

##### run-graph.cpp
- Implements the files kb.dat and query.dat to find the paths in the graph. 
- Shows the paths in results.dat file. 


##### time-run-graph.cpp
- Implements graph-benchmark.cpp and run-graph.cpp
- Tests the efficiency of the file run-graph.cpp

#### threading_pkg 
- Package containing the necessary files for message-passing concurrency with ROS

##### src
- The folder containing the whole directory with threading

###### threading-paths.cpp
- Compares the paths that is read from results.dat files, but implements message-passing concurrency with ROS. 


## How does it work and how to use it


## Performance 



## Concurrency 
- step by step without ROS
-  
- step by step using ROS
-   run "catkin_make" in "catkin_ws" folder
-   copy threading-paths and threading-paths.o from catkin_ws/devel/bin/ into threading_pkg/src folder 
-   uncomment for ROS concurrency in threading-paths.cpp 
-   uncomment for printing out results to terminal
-   uncomment if you only want to run compare_paths without testing efficiency


## Further work 


