# INF205 Paths in labelled graphs
## Programming project in INF205 Resource-efficient programming at NMBU

The point of the project is to take in a labelled graph *g* and two sequences *p* and *q* of edge labels and check if there exist a path *p* and a path *q* that contains the same start node and end node. 


### Run the full program
To run the full program you go into the [src](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src)-folder and type *make* in the terminal. 

First the makefile will go into the [directed-graph](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src/directed-graph)-folder and runs the [makefile](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/directed-graph/Makefile) for this directory. This makefile will run [run-graph.cpp](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/directed-graph/run-graph.cpp) which contains code from run-graph.h graph.h, query.h and graph-benchmark.h

After the [makefile](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/directed-graph/Makefile) from [directed-graph](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src/directed-graph) is ran, the [makefile](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/Makefile) in [src](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src) will run the [main.cpp](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/main.cpp) which contains functions form comparing-paths.h. 


### Benchmark run-time
The run-time has been tested on [run-graph.cpp](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/directed-graph/run-graph.cpp) and [directed-graph](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src/directed-graph). 

The run-time for run-graph.cpp is tested in [time-run-graph.cpp](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/directed-graph/time-run-graph.cpp) in [src/directed-graph](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src/directed-graph). The time is written to [TimeRunGraph.dat](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/results/TimeRunGraph.dat) in [src/results](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src/results). 

The run-time for [comparing-paths.cpp](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/comparing-paths.cpp) is tested in [time-comparing-paths.cpp](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/time-comparing-paths.cpp) in [src](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src). The time is written to [TimeComparingPaths1.dat](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/results/TimeComparingGraph1.dat) and [TimeComparingPaths2.dat](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/results/TimeComparingGraph2.dat) in [src/results](https://github.com/joridho/INF205-Paths-in-labelled-graphs/tree/main/src/results). 


### Plot time 
The results of benchmarking the run-time is read by [plot_timing_inf205.py](https://github.com/joridho/INF205-Paths-in-labelled-graphs/blob/main/src/results/plot_timing_inf205.py). The mean of the time is calculated and then plotted. 