//
// Created by voldo on 13-Sep-24.
//

#ifndef KS_33_1_LABS_MY_DYNA_STRUCT_H
#define KS_33_1_LABS_MY_DYNA_STRUCT_H

#include <iostream>
#include "string_ops.h"

const int MALE = 0;
const int FEMALE = 1;


struct person {
    int age;
    int gender;
    char *first_name;
    char *last_name;
};

void fill_person(person* person_ptr, int age, int gender, char *first_name, char *last_name);
person *create_person(int age, int gender, char *first_name, char *last_name);
void show_person_data(person *person_to_show);

#endif //KS_33_1_LABS_MY_DYNA_STRUCT_H
