//
// Created by voldo on 15-Nov-24.
//

#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>


/// this variable might mutate
int shared_val;
bool is_runs = true;

/// this variable should NOT mutate
//int volatile shared_val;


// Function that will be executed by each thread
void thread_inf_run(int thread_id) {
    int inx = 0;
    int sleeping_time = 0;
    while (is_runs) {
        inx += 1;
        shared_val += inx % 2 != 0 ? 1 : -1;
        sleeping_time = rand() % 1000;
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeping_time));
        std::cout << "TH: " << thread_id
                  << " shared val: " << shared_val
                  << " slept time: " << sleeping_time / 1000.0 << "s" << std::endl;
    }
}

int main() {
    const int NUM_THREADS = 1;  // Number of threads we want to create
    std::vector<std::thread> threads;  // Vector to store the threads
    shared_val = 0;

    // Launch a group of threads
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.push_back(std::thread(thread_inf_run, i));  // Create a new thread
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    // Stop all threads after 5s for sleep
    is_runs = false;

    // Wait until all thread stops
    for (std::thread &t: threads) {
        if (t.joinable())
            t.join();
    }

    std::cout << "The thread have finished execution." << std::endl;
    std::cout << "shared_val: " << shared_val << std::endl;

    return 0;
}
