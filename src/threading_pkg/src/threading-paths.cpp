#include <iostream>
#include <chrono>
#include <unistd.h>
#include <fstream>
#include <vector>
#include <cassert>
#include <string>
#include <string.h>
#include <thread>
#include "threading-paths.h"
/* Uncomment if you want to use message-passing concurrency with ROS
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
*/
using namespace comp;

 
/*
 * This function works almost the same as the compare_paths function in comparing-pths.cpp, but we 
 * have included threading with message passing. This function reads a file containing a start node 
 * and a end node for a path q or path p. The paths will be divided into a vector for path p and a 
 * vector for path q. Then the code implements the compare function, which checks if there is a path 
 * p that has the same start node and end node as a path q, and will count the number of instances. 
 * The compare function will display the results on screen and use message-passing concurrency with 
 * ROS if wanted. The ROS code sends messages from a publisher node. 
 */


int comp::compare_paths(int argc, char** argv)
{
    assert(argc >= 2);
    std::ifstream ind(argv[1]); 

    if (!ind.is_open()){
        std::cout << "false";
    }
    if(!ind)
    {
        std::cerr << "Error! File " << argv[1] << " cannot be read.\n";
        return EXIT_FAILURE;
    }
    
    // Counts the amounts of paths found in the file 
    std::string l; 
    int t = 0;
    std::vector<std::string> length;
    while (ind) {
        getline(ind, l); 
        length.push_back(l);
        t = t + 1;
    }

    // Reads the file again
    std::ifstream indata(argv[1]); 
    if(!indata)
    {
        std::cerr << "Error! File " << argv[1] << " cannot be read.\n"; 
        return EXIT_FAILURE;
    }
    std::vector<std::string> q_paths;
    std::vector<std::string> p_paths;
    std::string line; 

    // Divides the results into path p and path q
    for (int m = 0; m < t-1; m++) {
        getline(indata, line); 
        std::string s1{line};
        char b = line[0]; 
        std::string path = s1.substr(2);
        
        if (b == 'p') {
            p_paths.push_back(path);}
        else if (b == 'q') {
            q_paths.push_back(path);}
    }

    // Counts instances of path p and path q
    int p_num = 0; 
    for (std::string i : p_paths){
        p_num = p_num +1;
    }
    int q_num = 0; 
    for (std::string i : q_paths){
        q_num = q_num +1;
    }
    
    // Divide the vectors p_path and q_path into two parts for threading
    std::vector<std::string> p_path1(p_paths.begin(), p_paths.begin() + p_paths.size()/2);
    std::vector<std::string> p_path2(p_paths.begin() + p_paths.size()/2, p_paths.end());

    std::vector<std::string> q_path1(q_paths.begin(), q_paths.begin() + q_paths.size()/2);
    std::vector<std::string> q_path2(q_paths.begin() + q_paths.size()/2, q_paths.end());

    int p1 = p_path1.size();
    int p2 = p_path2.size();
    int q1 = q_path1.size();
    int q2 = q_path2.size();

    // Start threading, where each thread uses the compare function
    std::thread t1(&compare, argc, argv, 0, p1, p_path1, q_path1, q1);
    std::thread t2(&compare, argc, argv, 0, p2, p_path2, q_path2, q2);
    t1.join();
    t2.join();

    
    return 0;
}


int comp::compare(int argc, char** argv, int start_index, int end_index, std::vector<std::string> p_paths, std::vector<std::string> q_paths, int q_num)
{
    int zero1 = 0;
    int* lq = &zero1;
    int zero2 = 0;
    int* lp = &zero2;
    std::string equal_path;

    // Checks for equal start node and end node 
    for (int* p = &start_index; (*p) < end_index; (*p)++) {
        for (int q = 0; q < q_num; q++)
        {
            if (q_paths[q] == p_paths[*p] && q_paths[q] != "" && p_paths[*p] != "")
            {

                *lq = *lq + 1;
  
                equal_path = q_paths[q];
                q_paths[q] = "";
                
            }
        }
        
        if (*lq > 1)
        {
            for (int z = 0; z < end_index; z++)
            {
                if (p_paths[z] == equal_path)
                {
                    
                    p_paths[z] = "";
                    *lp = *lp + 1;
  
                }
            }    
        }

        if (*p == end_index -1){

            if (*lp==0 && *lq==0){
                /* 
                // Uncomment if you want to print this to terminal
                std::cout << "none equal paths occurs" << "\n"; Uncomment if 
                */
            }

            else{
                /*
                // Uncomment if you want to print this to terminal
                std::cout <<  equal_path << " occurs " << *lq << " times in q and " <<  *lp << " times in p" << "\n";
                */
            }

            /*
            // Uncomment if you want to use message-passing concurrency with ROS. This code sends out messages from a Publisher node. 
            
            // Initializes ROS publisher and topic
            ros::init(argc, argv, "Publisher");
            ros::NodeHandle nh;
            ros::Publisher topic_pub = nh.advertise<std_msgs::String>("results", 1000);

            ros::Rate loop_rate(1);

            std_msgs::String path;
            std_msgs::String message;
            std_msgs::String msg1;
            std_msgs::String msg2;
            std_msgs::String msg3;
            std_msgs::String msg4;

            std::string lp_str = std::to_string(*lp);
            std::string lq_str = std::to_string(*lq);
            std_msgs::String countlq;
            std_msgs::String countlp;

            path.data = equal_path;
            msg1.data = " occurs ";
            countlq.data = lq_str;
            msg2.data = " times in q ";
            countlp.data = lp_str;
            msg3.data = " times in p ";
            msg4.data = "none equal parts occurs";
            std_msgs::Int32 count;
            count.data = 0;

            if (*lp==0 && *lq==0){
                message.data = msg4.data;
            }

            else{
                message.data = path.data + msg1.data + countlq.data + msg2.data + countlp.data + msg3.data;
            }
            
            // The publisher will publish 2 messages through ros topic "results"
            while (count.data < 3){
                topic_pub.publish(message);
                ros::spinOnce();
                loop_rate.sleep();
                ++count.data;
            }
            */
        }
    }
    
    return 0;
}


/* //Uncomment if you only want to run compare_paths without testing the efficiency.

int main(int argc, char** argv) {

    comp::compare_paths(argc, argv);
}
/*


/*
 * This main function checks the run time of comparing_paths on multiple files. The function will 
 * first test on the result files with different number of paths found. 
 * This is done 1000 times and the results are written to TimeComparingPathsThread1.dat.  
 * Secondly, the function will test on result files with different amount of similar paths found. 
 * This is done 5000 times and the results are written to TimeComparingPathsThread2.dat.  
 */
int main() {

    // creating a file for adding the time it takes to run comparing-paths.cpp with different amounts of paths found
    std::ofstream ("../../results/TimeComparingPathsThread1.dat");
    std::ofstream file1;
    file1.open("../../results/TimeComparingPathsThread1.dat", std::ios::out | std::ios::app);

    file1 << "Time for comparing-paths with different amounts of paths found" << std::endl;
    
    char* file;
    char* b;
    
    std::string res1[10] = {"../../results/results16.dat", "../../results/results32.dat", "../../results/results64.dat", 
                    "../../results/results128.dat", "../../results/results256.dat", "../../results/results512.dat", 
                    "../../results/results1024.dat", "../../results/results2048.dat",
                "../../results/results4096.dat", "../../results/results8192.dat"};
    for (std::string i : res1)
    {   
        for (int z=0; z<1000; z++) 
        {
            std::string f(i);
            file = &f[0];

            std::string bm("0");
            b = &bm[0];
            char* argv[2] = {b, file};

            // Starts to take the time 
            auto t0 = std::chrono::high_resolution_clock::now();
            comp::compare_paths(2,argv);
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;

            file1 << t << "\t";  // The time is written to the file 
        }
        file1 << "\n";
    }



    // Creating a file for adding the time it takes to run comparing-paths.cpp with different amounts of equal paths found
    std::ofstream ("../../results/TimeComparingPathsThread2.dat");
    std::ofstream file2;
    file2.open("../../results/TimeComparingPathsThread2.dat", std::ios::out | std::ios::app);
    file2 << "Time for comparing-paths with 100 paths found but with different amount of similiar paths" << std::endl;
  
    std::string res2[5] = {"../../results/results0.dat", "../../results/results25.dat", "../../results/results50.dat", 
                        "../../results/results75.dat", "../../results/results100.dat"};   // the name of the pre-made files with results
    
    for (std::string j : res2)
    {
        for (int z=0; z<5000; z++) 
        {
            std::string f(j);
            file = &f[0];

            std::string bm("0");
            b = &bm[0];

            char* argv[2] = {b, file};

            // Starts to take the time 
            auto t0 = std::chrono::high_resolution_clock::now();
            comp::compare_paths(2,argv);
            auto t1 = std::chrono::high_resolution_clock::now();
            double t = std::chrono::duration_cast<std::chrono::nanoseconds>(t1-t0).count() * 0.000000001;

            file2 << t << "\t"; // The time is written to the file
        }
        file2 << "\n";
    }

    return 0;
}
