//
// Created by voldo on 11-Oct-24.
//

#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>

/// this variable might mutate
int shared_val;

/// this variable should NOT mutate
//int volatile shared_val;


// Function that will be executed by each thread
void print_message(int thread_id) {
    for (int i = 0; i < 1000000; i++) {
        shared_val += i % 2 != 0 ? 1 : -1;
    }
}

int main() {
    const int num_threads = 24;  // Number of threads we want to create
    std::vector<std::thread> threads;  // Vector to store the threads
    shared_val = 0;

    // Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(print_message, i));  // Create a new thread
    }

    // Wait for all threads to finish (join them)
    for (std::thread& t : threads) {
        t.join();  // Ensure that main waits for the thread to complete
    }

    std::cout << "All threads have finished execution." << std::endl;
    std::cout << "shared_val: " << shared_val << std::endl;

    return 0;
}
