//
// Created by voldo on 27-Sep-24.
//

#include <iostream>
#include <csignal>


int main() {
    int counter = 0;
    while (1) {
        std::cout << "I'm working: " << counter++ << std::endl;
        sleep(1);
    }

    return 0;
}
