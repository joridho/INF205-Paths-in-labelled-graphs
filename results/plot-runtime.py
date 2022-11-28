#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

file1 = "../directed-graph/TimeRunGraph.dat"
file2 = "../TimeComparingGraph1.dat"
file3 = "../TimeComparingGraph2.dat"

data1 = list(open(file1))

h = 0
for line in data1:
    if line == '\n':
        h += 1

df = []
i = 0
for k in range(0,h):
    e = []
    while data1[i] != '\n':
        try:
            e.append(float(data1[i]))
        except:
            e.append(data1[i])
        i += 1
    i += 1
    df.append(e)

data2 = list(open(file2))
data3 = list(open(file3))

plot3 = []
for i in data2:
    try:
        plot3.append(float(i))
    except:
        plot3.append(i)
plot4 = []
for i in data3:
    try:
        plot4.append(float(i))
    except:
        plot4.append(i)
        
#%% plot 1

plot1 = df[0:7]
fig, axs = plt.subplots(2, 4, figsize=(12, 6.5))
axs = axs.ravel()
y_label = 'Run-time in log scale [seconds]'
x_label = 'Number of nodes in the graph'
fig.text(0.001, 0.5, y_label, va='center', rotation='vertical')
fig.text(0.45, 0.01, x_label, va='center')
plt.tight_layout()
fig.delaxes(axs[7])

for ax in axs:
    ax.tick_params(axis='both', rotation=10, labelsize=7)
    ax.set_ylim([-10,0])
    ax.grid()

for i in range(0,7):
    plots = np.array(plot1[i][1:])
    axs[i].plot([10, 100, 1000, 10000], np.log(plots), 
                linestyle = '--', linewidth=1, marker='o')
    axs[i].set_title(label=f'Query size {plot1[i][0][-2]}', fontsize=8)
    
    

#%% plot 2
plot2 = df[7:]
fig, axs = plt.subplots(2, 3, figsize=(12, 6.5))
axs = axs.ravel()
y_label = 'Run-time in log scale [seconds]'
x_label = 'Query length'
fig.text(0.001, 0.5, y_label, va='center', rotation='vertical')
fig.text(0.45, 0.01, x_label, va='center')
plt.tight_layout()

for ax in axs:
    ax.tick_params(axis='both', rotation=10, labelsize=7)
    ax.set_ylim([-9,1])
    ax.set_xlim([-1000,11000])
    ax.grid()

nodes = [10, 100, 1000, 10000, 100000]
for i in range(0,5):
    plots = np.array(plot2[i][1:])
    axs[i].plot(nodes[0:len(plots)], np.log(plots), 
                linestyle = '--', linewidth=1, marker='o')
    axs[i].set_title(label=f'Graph with {nodes[i]} nodes', fontsize=8)

plots = np.array(plot2[-1][4:])
axs[-1].plot(nodes[3:], np.log(plots), 
            linestyle = '--', linewidth=1, marker='o')
axs[-1].set_title(label=f'Graph with {nodes[i]} nodes', fontsize=8)
axs[-1].set_xlim([9000,110000])
        


#%% plot 3

plt.figure()
plots = np.array(plot3[1:])
plt.grid()
x_axis = [10, 100, 1000, 10000]
plt.plot(x_axis, np.log(plots), linestyle = '--', linewidth=1, marker='o')

plt.ylabel('Run-time in log scale [seconds]')
plt.xlabel('Amount of paths found')


#%% plot 4

plt.figure()
plots = np.array(plot4[1:])
plt.grid()
x_axis = [0, 25, 50, 75, 100]
plt.plot(x_axis, plots, linestyle = '--', linewidth=1, marker='o')

plt.ylabel('Run-time [seconds]')
plt.xlabel('Share of similar paths found')





        




