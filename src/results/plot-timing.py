#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Nov 24 09:32:58 2022

@author: joridholmen
"""


import matplotlib.pyplot as plt
import numpy as np

file1 = "TimeRunGraph.dat"
file2 = "TimeComparingPaths1.dat"
file3 = "TimeComparingPaths2.dat"
file4 = "TimeComparingPathsThread1.dat"
file5 = "TimeComparingPathsThread2.dat"

data1 = list(open(file1))


h = 0
for line in data1:
    if line == '\n':
        h += 1


df1 = []
i = 0
for k in range(0,h):
    e = []
    while data1[i] != '\n':
        try:
            e.append(data1[i])
        except:
            e.append(data1[i])
        i += 1
    i += 1
    df1.append(e)

df = []
for l in df1:
    f = []
    for i in l:
        try:
            n = i.split("\t")
            m = []
            for j in n[0:-1]:
                m.append(float(j))
            f.append(sum(m)/len(m))
        except:
            f.append(i)
    df.append(f)
            


data2 = list(open(file2))
data3 = list(open(file3))
data4 = list(open(file4))
data5 = list(open(file5))

plot3 = []
for i in data2:
    try:
        n = i.split("\t")
        m = []
        for j in n[0:-1]:
            m.append(float(j))
        plot3.append(sum(m)/len(m))
    except:
        plot3.append(i)
        
plot5 = []
for i in data4:
    try:
        n = i.split("\t")
        m = []
        for j in n[0:-1]:
            m.append(float(j))
        plot5.append(sum(m)/len(m))
    except:
        plot5.append(i)

plot4 = []
for i in data3:
    try:
        n = i.split("\t")
        m = []
        for j in n[0:-1]:
            m.append(float(j))
        plot4.append(sum(m)/len(m))
    except:
        plot4.append(i)

plot6 = []
for i in data5:
    try:
        n = i.split("\t")
        m = []
        for j in n[0:-1]:
            m.append(float(j))
        plot6.append(sum(m)/len(m))
    except:
        plot6.append(i)


        
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
    axs[i].plot(['10', '100', '1000', '10000'], np.log(plots), 
                linestyle = '--', linewidth=1, marker='o')
    axs[i].set_title(label=f'Query size {plot1[i][0][-2]}', fontsize=8)

fig.savefig("plot-run-graph1.png", bbox_inches='tight')
    

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
    ax.set_xlim([-1,5])
    ax.grid()

nodes = ['10', '100', '1000', '10000', '100000']
for i in range(0,5):
    plots = np.array(plot2[i][1:])
    axs[i].plot(nodes[0:len(plots)], np.log(plots), 
                linestyle = '--', linewidth=1, marker='o')
    axs[i].set_title(label=f'Graph with {nodes[i]} nodes', fontsize=8)
fig.delaxes(axs[5])
        
fig.savefig("plot-run-graph2.png", bbox_inches='tight')

#%% plot 3

plt.figure()
plots = np.array(plot3[1:])
plt.ylim(-11,-3)
plt.grid()
x_axis = ['16', '32', '64', '128', '256', '512', '1024', '2048', '4096', '8192']
plt.plot(x_axis, np.log(plots), linestyle = '--', linewidth=1, marker='o')

plt.ylabel('Run-time in log scale [seconds]')
plt.xlabel('Amount of paths found')
plt.title('Without threading')

plt.savefig("plot-compare-paths1.png", bbox_inches='tight')


#%% plot 4

plt.figure()
plots = np.array(plot4[1:])
plt.grid()
plt.ylim(0.00046,0.00065)
x_axis = ['0', '25', '50', '75', '100']
plt.plot(x_axis, plots, linestyle = '--', linewidth=1, marker='o')

plt.ylabel('Run-time [seconds]')
plt.xlabel('Share of similar paths found')
plt.title('Without threading')

plt.savefig("plot-compare-paths2.png", bbox_inches='tight')


#%% plot 5 

plt.figure()
plots = np.array(plot5[1:])
plt.grid()
plt.ylim(-11,-3)
x_axis = ['16', '32', '64', '128', '256', '512', '1024', '2048', '4096', '8192']
plt.plot(x_axis, np.log(plots), linestyle = '--', linewidth=1, marker='o')

plt.ylabel('Run-time in log scale [seconds]')
plt.xlabel('Amount of paths found')
plt.title('With threading')

plt.savefig("plot-compare-paths-thread1.png", bbox_inches='tight')




#%% plot 6

plt.figure()
plots = np.array(plot6[1:])
plt.grid()
plt.ylim(0.00046,0.00065)
x_axis = ['0', '25', '50', '75', '100']
plt.plot(x_axis, plots, linestyle = '--', linewidth=1, marker='o')

plt.ylabel('Run-time [seconds]')
plt.xlabel('Share of similar paths found')
plt.title('With threading')

plt.savefig("plot-compare-paths-thread2.png", bbox_inches='tight')













