
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

file1 = "/Users/joridholmen/INF205/INF205-Paths-in-labelled-graphs/timing/TimeRunGraph.dat"
file2 = "/Users/joridholmen/INF205/INF205-Paths-in-labelled-graphs/timing/TimeComparingGraph1.dat"
file3 = "/Users/joridholmen/INF205/INF205-Paths-in-labelled-graphs/timing/TimeComparingGraph2.dat"


data = list(open(file1))


h = 0
for line in data:
    if line == '\n':
        h += 1


df = []
i = 0
for k in range(0,h):
    e = []
    while data[i] != '\n':
        try:
            e.append(float(data[i]))
        except:
            e.append(data[i])
        i += 1
    i += 1
    df.append(e)


def PlotBenchmark(time, x_axis):
    plots = np.array(time[1:])
    plt.plot(x_axis, np.log(plots))
    plt.title(time[0])
    plt.ylabel('Logarithmic time scale')

PlotBenchmark(df[0],[10, 100, 1000, 10000])
 
        


        




