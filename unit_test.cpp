#include <iostream>
#include <string.h>
#include "Vector.h"

#define TYPE int//это тип определяемого значения
#define SIZE_MVECTOR_1 10
#define SIZE_MVECTOR_2 10
#define VALUE_MVECTOR_1 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
#define VALUE_MVECTOR_2 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
#define INPUT_VALUE_FOR_M_SET_VALUE_TEST 10
#define NUMB_CELL_FOR_M_SET_VALUE_TEST 0
#define NUMB_CELL_FOR_M_GET_VALUE_TEST 0
#define INPUT_VALUE_FOR_M_PUSH_BACK_TEST 11


std::string unit_test() {

    TYPE arr1[10] = {VALUE_MVECTOR_1};
//    int input_value = 0;
    MVector<TYPE> Malik_MVector_1nt_size(SIZE_MVECTOR_1);
    MVector<TYPE> Malik_MVector_arr1(arr1, SIZE_MVECTOR_1);
    bool point;

    std::cout << "BEGIN TEST: CLASS FUNC" << std::endl << std::endl << std::endl;

    std::cout << "TEST:        M_set_value(set VALUE: 10 in CELL: 0):" << std::endl;
    Malik_MVector_arr1.M_set_value(INPUT_VALUE_FOR_M_SET_VALUE_TEST, NUMB_CELL_FOR_M_SET_VALUE_TEST);
    std::cout << "SUCCESS" << std::endl;

    std::cout << std::endl << "TEST:        M_get_value(get VALUE in CELL: 1)" << std::endl;
    if(Malik_MVector_arr1.M_get_value(NUMB_CELL_FOR_M_GET_VALUE_TEST) != INPUT_VALUE_FOR_M_SET_VALUE_TEST) {
        return "ERROR: TEST CLASS FUNC (unit_test.cpp 34)\nM_set_value or M_get_value(38 or 41)";
    }
    std::cout << "SUCCESS" << std::endl;

    std::cout << std::endl << "TEST:        M_print_MVector:" << std::endl;
    Malik_MVector_arr1.M_print_MVector();
    std::cout << "SUCCESS" << std::endl;

    std::cout << std::endl << "TEST:        M_len(): " << std::endl;
    if(Malik_MVector_arr1.M_len() != SIZE_MVECTOR_1) {
        return "ERROR: TEST CLASS FUNC (unit_test.cpp 34)\nM_len(49)";
    }
    std::cout << "SUCCESS" << std::endl;

    std::cout << std::endl << "TEST:        M_push_back:" << std::endl;
    Malik_MVector_arr1.M_push_back(INPUT_VALUE_FOR_M_PUSH_BACK_TEST);
    if (Malik_MVector_arr1.M_get_value(SIZE_MVECTOR_1) != INPUT_VALUE_FOR_M_PUSH_BACK_TEST) {
        return "ERROR: TEST CLASS FUNC (unit_test.cpp 34)\nM_push_value(56)";
    }
    std::cout << "SUCCESS" << std::endl;

    std::cout << std::endl << "TEST:        M_pop_back:" << std::endl;
    Malik_MVector_arr1.M_pop_back();
    if (Malik_MVector_arr1.M_len() != SIZE_MVECTOR_1) {
        return "ERROR: TEST CLASS FUNC (unit_test.cpp 34)\nM_pop_back(62)";
    }
    std::cout << "SUCCESS" << std::endl;

    std::cout << std::endl << "TEST:        M_begin:" << std::endl;
    if(*Malik_MVector_arr1.M_begin() != Malik_MVector_arr1.M_get_value(0)) {
        return "ERROR: TEST CLASS FUNC (unit_test.cpp 34)\nM_begin(62)";
    }
    std::cout << "SUCCESS" << std::endl;

    std::cout << std::endl << "TEST:        M_end:" << std::endl;
    if (*Malik_MVector_arr1.M_end() != Malik_MVector_arr1.M_get_value(SIZE_MVECTOR_1 - 1))
        return "ERROR: TEST CLASS FUNC (unit_test.cpp 34)\nM_end(62)";
    std::cout << "SUCCESS" << std::endl;

//    тест ввода вывода пройден но если потребуется просто раскомитить
//
//    std::cout << "BEGIN TEST: INPUT OUPUT operator  << std::endl << std::endl << std::endl;
//
//    std::cout << "OUTPUT MVector with func M_print_MVector:" << std::endl << std::endl;
//
//    Malik_MVector_1nt_size.M_print_MVector();
//    Malik_MVector_arr1.M_print_MVector();
//
//    std::cout << "OUTPUT MVector with thread cout:" << std::endl << std::endl;
//
//    std::cout << Malik_MVector_arr1 << std::endl << std::endl;
//
//    std::cout << "INPUT MVector with func M_set_value(input 1 value): " << std::endl << std::endl;
//
//    std::cin >> input_value;
//    Malik_MVector_1nt_size.M_set_value(input_value, 1);
//
//    std::cout << "INPUT MVector with thread cin(input 10 value in first MVector): " << std::endl << std::endl;
//    std::cin >> Malik_MVector_1nt_size;
//
//    std::cout << "OUTPUT first MVector with func M_print_MVector: " << std::endl << std::endl;
//    Malik_MVector_1nt_size.M_print_MVector();

    std::cout << std::endl << std::endl <<"BEGIN TEST OPERATORS" << std::endl << std::endl << std::endl;

    TYPE arr2[] = {VALUE_MVECTOR_2};
    MVector<TYPE> Malik_MVector_arr2(arr2, SIZE_MVECTOR_2);
    MVector<TYPE> Malik_MVector_arr3(0);


    std::cout << std::endl << "TEST:        operator+() and operator=(): " << std::endl;
    Malik_MVector_arr3 = Malik_MVector_arr1 + Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) + Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator+() or operator=() 105";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST:        operator-() and operator=(): " << std::endl;
    Malik_MVector_arr3 = Malik_MVector_arr1 - Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) - Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator-() or operator=() 109";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST:        operator*() and operator=(): " << std::endl;
    Malik_MVector_arr3 = Malik_MVector_arr1 * Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) * Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator*() or operator=() 117";
    }
    std::cout << "SUCCESS" << std::endl;

//    Malik_MVector_arr1.M_print_MVector();
//    Malik_MVector_arr2.M_print_MVector();
//    Malik_MVector_arr3.M_print_MVector();
//
    std::cout << std::endl << "TEST:        operator+=(): " << std::endl;
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 += Malik_MVector_arr2;

    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) + Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator+=() 131";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST:        operator-=(): " << std::endl;
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 -= Malik_MVector_arr2;

    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) - Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator-=() 140";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST:        operator*=(): " << std::endl;
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 *= Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) * Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator*=() 149";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST:        operator/=(): " << std::endl;
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 /= Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != (TYPE) Malik_MVector_arr3.M_get_value(i) / Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator/=() 158";
    }
    std::cout << "SUCCESS" << std::endl;


    Malik_MVector_arr3 = Malik_MVector_arr1;

    point = (Malik_MVector_arr1 == Malik_MVector_arr3);
    std::cout << std::endl << "TEST:        operator==(): " << std::endl;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if (!point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator==() 180";
    }

    point = (Malik_MVector_arr2 == Malik_MVector_arr3);
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator==() 184";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST:        operator!=(): " << std::endl;
    point = (Malik_MVector_arr1 != Malik_MVector_arr3);
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator!=() 193";
    }
    point = (Malik_MVector_arr1 != Malik_MVector_arr2);
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(!point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator==() 197";
    }
    std::cout << "SUCCESS" << std::endl;



    std::cout << std::endl << "TEST:        unary operator+(): " << std::endl;
    Malik_MVector_arr1 = +Malik_MVector_arr3;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\n unary operator+() 210";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST:        unary operator-(): " << std::endl;
    Malik_MVector_arr1 = -Malik_MVector_arr3;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != -Malik_MVector_arr3.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\nunary operator-() 219";
    }
    std::cout << "SUCCESS" << std::endl;
    
    return "Y";
}
