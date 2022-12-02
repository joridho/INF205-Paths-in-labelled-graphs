# INF205 Paths in labelled graphs
## Programming project in INF205 Resource-efficient programming at NMBU

The point of the project is to take in a labelled graph g and two sequences p and q of edge labels and check if there exist a path p and a path q that contains the same start node and end node. 


## Run the full program
To run the full program you go into the src-folder and type make in the terminal. 

First the makefile will go into the directed-graph-folder and runs the makefile for this directory. This makefile will run run-graph.cpp which contains code from run-graph.h graph.h, query.h and graph-benchmark.h

After the makefile from directed-graph is ran, the makefile in src will run the main.cpp which contains functions form comparing-paths.h. 


## Benchmark run-time
The run-time has been tested on run-graph.cpp and comparing-paths.cpp. 

The run-time for run-graph.cpp is tested in time-run-graph.cpp in src/directed-graph. The time is written to TimeRunGraph.dat in src/results. 

The run-time for comparing-paths.cpp is tested in time-comparing-paths.cpp in src/directed-graph. The time is written to TimeComparingPaths1.dat and TimeComparingPaths1.dat in src/results. 


## Plot time 
The results of benchmarking the run-time is read by plot_timing_inf205.py. The mean of the time is calculated and then plotted. 