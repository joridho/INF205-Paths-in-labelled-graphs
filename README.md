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
This code we have not written ourselves. This code writes out a graph to kb.dat which looks like this, and two queries to query.dat, which looks like this. 


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


### Run time for run-graph.cpp with different amount of nodes in the graph 
First the time run time was tested for run-graph.cpp with different amount of nodes in the graph in every plot, and each plot had different query size was. 
The run time appears to be linear with run time O(n), and the slope increases slightly when the query size increases. 

<img src="/src/results/plot-run-graph1.png">

### Run time for run-graph.cpp with different query sizes
Second the time run time was tested for run-graph.cpp with different query size in every plot, and each plot had different amount of nodes in the graph. 
There can not be a query size that is longer than the amount of nodes in the graph. Therefore each plot has more and more points in accordance with the graph size. 
The run time seems to be exponential O(n^2), and it takes longer with a bigger graph. 

<img src="/src/results/plot-run-graph2.png">


### Run time for comparing the paths with different amounts of paths found 
The run time for comparing the paths with different amounts of paths found was tested with and without threading. 
The run time is linear O(n). 
When there is a small amount of paths found the code with threading is slower, but when there is a large amount of paths found the code is slightly faster, but barely noticeable. If we tested on larger numbers we would probably be able to see a bigger difference. This could be something for further work. 

<img src="/src/results/plot-compare-paths1.png"> 
<img src="/src/results/plot-compare-paths-thread1.png">

### Run time for comparing the paths with different amounts of equal paths found 
The run time for comparing the paths with different amounts of equal paths found was tested with and without threading. 
Without threading the run-time seems to be exponential (O(n^2)), but linear (O(n)) with threading. 
The code is noticeably faster with threading. 

<img src="/src/results/plot-compare-paths2.png"> 
<img src="/src/results/plot-compare-paths-thread2.png">

## Concurrency 


## Further work 


