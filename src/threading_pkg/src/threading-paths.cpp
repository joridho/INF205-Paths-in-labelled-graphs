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
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
using namespace comp;

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
    
    std::string l; 
    int t = 0;
    std::vector<std::string> length;
    while (ind) {
        getline(ind, l); 
        length.push_back(l);
        t = t + 1;
    }

    std::ifstream indata(argv[1]); 
    if(!indata)
    {
        std::cerr << "Error! File " << argv[1] << " cannot be read.\n"; 
        return EXIT_FAILURE;
    }
    std::vector<std::string> q_paths;
    std::vector<std::string> p_paths;
    std::string line; 
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

    
    int p_num = 0; 
    for (std::string i : p_paths){
        p_num = p_num +1;
    }
    int q_num = 0; 
    for (std::string i : q_paths){
        q_num = q_num +1;
    }
    
    std::vector<std::string> p_path1(p_paths.begin(), p_paths.begin() + p_paths.size()/2);
    std::vector<std::string> p_path2(p_paths.begin() + p_paths.size()/2, p_paths.end());

    std::vector<std::string> q_path1(q_paths.begin(), q_paths.begin() + q_paths.size()/2);
    std::vector<std::string> q_path2(q_paths.begin() + q_paths.size()/2, q_paths.end());


    int p1 = p_path1.size();
    int p2 = p_path2.size();
    int q1 = q_path1.size();
    int q2 = q_path2.size();

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
                //std::cout << "none equal paths occurs" << "\n";
            }

            else{
                //std::cout <<  equal_path << " occurs " << *lq << " times in q and " <<  *lp << " times in p" << "\n";
            }

            // Publisher 
            //ros::init(argc, argv, "Publisher");
            //ros::NodeHandle nh;
            //ros::Publisher topic_pub = nh.advertise<std_msgs::String>("results", 1000);

            //ros::Rate loop_rate(1);

            //std_msgs::String path;
            //std_msgs::String message;
            //std_msgs::String msg1;
            //std_msgs::String msg2;
            //std_msgs::String msg3;
            //std_msgs::String msg4;

            //std::string lp_str = std::to_string(*lp);
            //std::string lq_str = std::to_string(*lq);
            //std_msgs::String countlq;
            //std_msgs::String countlp;

            //path.data = equal_path;
            //msg1.data = " occurs ";
            //countlq.data = lq_str;
            //msg2.data = " times in q ";
            //countlp.data = lp_str;
            //msg3.data = " times in p ";
            //msg4.data = "none equal parts occurs";
            //std_msgs::Int32 count;
            //count.data = 0;

            //if (*lp==0 && *lq==0){
            //    message.data = msg4.data;
            //}

            //else{
            //    message.data = path.data + msg1.data + countlq.data + msg2.data + countlp.data + msg3.data;
            //}
            
        
        
        
            //while (count.data < 3){
            //    topic_pub.publish(message);
            //    ros::spinOnce();
            //    loop_rate.sleep();
            //    ++count.data;
            //}


        }

    }

    return 0;

}



//int main(int argc, char** argv) {

//    comp::compare_paths(argc, argv);
//}


int main() {

    // creating a file for adding the time it takes to run comparing-paths.cpp with different amounts of paths found
    std::ofstream ("../../results/TimeComparingGraphThread1.dat");
    std::ofstream file1;
    file1.open("../../results/TimeComparingGraphThread1.dat", std::ios::out | std::ios::app);

    file1 << "Time for comparing-paths with different amounts of paths found" << std::endl;
    
    char* file;
    char* b;
    
    // the name of the pre-made files with results
 
    //std::string res1[1] = {"results_thread/results100p.dat"};
    std::string res1[7] = {"../../results/results16.dat", "../../results/results32.dat", "../../results/results64.dat", 
                    "../../results/results128.dat", "../../results/results256.dat", "../../results/results512.dat", 
                    "../../results/results1024.dat"};
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



    // creating a file for adding the time it takes to run comparing-paths.cpp with different amounts of equal paths found
    std::ofstream ("../../results/TimeComparingGraphThread2.dat");
    std::ofstream file2;
    file2.open("../../results/TimeComparingGraphThread2.dat", std::ios::out | std::ios::app);
    file2 << "Time for comparing-paths with 100 paths found but with different amount of similiar paths" << std::endl;

    /*std::string res2[5] = {"results_thread/results0.dat", "results_thread/results25.dat", "results_thread/results50.dat", 
                        "results_thread/results75.dat", "lammestek.txt"};   // the name of the pre-made files with results
    
    */

    //std::string res2[1] = {"results_thread/results100p.dat"};   // the name of the pre-made files with results    
    std::string res2[5] = {"../../results/results0.dat", "../../results/results25.dat", "../../results/results50.dat", 
                        "../../results/results75.dat", "../../results/results100p.dat"};   // the name of the pre-made files with results
    
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







