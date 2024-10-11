//
// Created by voldo on 11-Oct-24.
//

#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>


volatile int shared_val = 0;


// Function that will be executed by each thread
void print_message(int thread_id) {
    std::cout << "Thread " << thread_id << " is running." << std::endl;
    std::cout << "shared_val: " << shared_val << " in " << thread_id  << std::endl;

    int sleeping_time = rand() % 10;
    std::this_thread::sleep_for(std::chrono::seconds(sleeping_time));  // Simulating work with sleep

    int rand_change = rand() % 20 - 10;
    shared_val += rand_change;
    std::cout << "shared_val modified: " << shared_val << " in " << thread_id << std::endl;

    sleeping_time = rand() % 10;
    std::this_thread::sleep_for(std::chrono::seconds(sleeping_time));
    std::cout << "Thread " << thread_id << " has finished." << std::endl;
}

int main() {
    const int num_threads = 5;  // Number of threads we want to create
    std::vector<std::thread> threads;  // Vector to store the threads
    shared_val = 10;

    // Launch a group of threads
    for (int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(print_message, i));  // Create a new thread
    }

    // Wait for all threads to finish (join them)
    for (std::thread& t : threads) {
        t.join();  // Ensure that main waits for the thread to complete
    }

    std::cout << "All threads have finished execution." << std::endl;

    return 0;
}
