#include <iostream>

#include "my_dyna_struct.h"

int main(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        std::cout << i << ": " << argv[i] << "\n";
    }

    return 0;
}

//int main() {
//    srand((unsigned int)time(NULL));
//
//    const int NUM_PERSONS = 10;
//    const int NAME_LENGTH = 10;
//
//    person *persons_arr = (person *) malloc(sizeof(person) *NUM_PERSONS); // MUST CLEAN
//    // person persons_arr2[NUM_PERSONS]; // DO NOT CLEAN
//
//    for (int p_num = 0; p_num < NUM_PERSONS; p_num++) {
//        char *name = (char *) malloc(sizeof(char) * (NAME_LENGTH + 1));
//        char *surname = (char *) malloc(sizeof(char) * (NAME_LENGTH + 1));
//        generateRandomString(name, NAME_LENGTH);
//        generateRandomString(surname, NAME_LENGTH);
//        int gender = rand() % 3;
//        int age = rand() % 100;
//
//        fill_person(&persons_arr[p_num], age, gender, name, surname);
//    }
//
//    for (int p_num = 0; p_num < NUM_PERSONS; p_num++) {
//        show_person_data(&persons_arr[p_num]);
//    }
//
//    for (int p_num = 0; p_num < NUM_PERSONS; p_num++) {
//        free(persons_arr[p_num].first_name);
//        free(persons_arr[p_num].last_name);
//    }
//
//    free(persons_arr);
//
//    return 0;
//}

/// C-style code
//int main() {
//    int length;
//    printf("Enter the desired length of the random string: ");
//    scanf("%d", &length);
//
//    char randomString[length + 1]; // +1 for null terminator
//    generateRandomString(randomString, length);
//
//    printf("Random String: %s\n", randomString);
//
//    return 0;
//}
