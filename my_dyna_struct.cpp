//
// Created by voldo on 13-Sep-24.
//

#include "my_dyna_struct.h"

person *create_person(int age, int gender, char *first_name, char *last_name) {
    person *tmp_person = (person *) malloc(sizeof(person));

    fill_person(tmp_person, age, gender, first_name, last_name);

    return tmp_person;
}


void fill_person(person *person_ptr, int age, int gender, char *first_name, char *last_name) {
    person_ptr->age = age;
    person_ptr->gender = gender;
    person_ptr->first_name = first_name;
    person_ptr->last_name = last_name;
}


void show_person_data(person *person_to_show) {
    std::cout << "-------------------------->\n";
    std::cout << person_to_show->first_name << " " << person_to_show->last_name << "\n";
    std::cout << "age: " << person_to_show->age;
    if (person_to_show->gender == MALE)
        std::cout << ", gender: MALE\n";
    else if (person_to_show->gender == FEMALE)
        std::cout << ", gender: FEMALE\n";
    else
        std::cout << ", gender: HIDDEN\n";
    std::cout << "--------------------------<\n\n";
}
