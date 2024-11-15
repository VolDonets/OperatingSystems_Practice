//
// Created by voldo on 15-Nov-24.
//


#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <semaphore>
#include <mutex>

std::counting_semaphore<3> semaphore(3); // allows up to 3 threads to access the resource


// Function that will be executed by each thread
void print_message(int thread_id) {
    for (int i = 0; i < 1000; i++) {
        semaphore.acquire();

        std::cout << "TH: " << thread_id << " is working" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        semaphore.release();
    }
}

int main() {
    const int num_threads = 100;  // Number of threads we want to create
    std::vector<std::thread> threads;  // Vector to store the threads

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
