#include <iostream>
#include <string.h>
#include "Vector.h"
#include "unit_test.h"


std::string unit_test() {


//    int input_value = 0;
    MVector<TYPE> Malik_MVector_1nt_size(SIZE_MVECTOR_1);
    MVector<TYPE> Malik_MVector_arr1(SIZE_MVECTOR_1);
    MVector<TYPE> Malik_MVector_arr2(SIZE_MVECTOR_2);
    MVector<TYPE> Malik_MVector_arr3(SIZE_MVECTOR_3);

    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
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



    std::cout << std::endl << "TEST_1:        operator+() and operator=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 + Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) + Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator+() or operator=() 99";
    }
    std::cout << "SUCCESS" << std::endl;



    std::cout << std::endl << "TEST_2:        operator+() for numb: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 + 1;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) + 1)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator+() for numb 110";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_3:        operator-() and operator=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 - Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) - Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator-() or operator=() 119";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_4:        operator-() for numb: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 - 1;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) - 1)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator-() for numb 130";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_5:        operator*() and operator=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 * Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) * Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator*() or operator=() 140";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_6:        operator*() for numb: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 * 2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) * 2)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperato*() for numb 150";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_7:        operator/() and operator=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 / Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) / Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator/() or operator=() 160";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_8:        operator/() for numb: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1 / 2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr3.M_get_value(i) != Malik_MVector_arr1.M_get_value(i) / 2)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator/() for numb 170";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_9:        operator+=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 += Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr3.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) + Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator+=() 181";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_10:        operator-=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 -= Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) - Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator-=() 192";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_11:        operator*=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 *= Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) * Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator*=() 203";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_12:        operator/=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1;
    Malik_MVector_arr1 /= Malik_MVector_arr2;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != (TYPE) Malik_MVector_arr3.M_get_value(i) / Malik_MVector_arr2.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator/=() 214";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_13:        operator==(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1;
    point = (Malik_MVector_arr1 == Malik_MVector_arr3);
    std::cout << std::endl << "TEST:        operator==(): " << std::endl;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if (!point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator==() 226";
    }

    point = (Malik_MVector_arr2 == Malik_MVector_arr3);
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator==() 232";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_14:        operator!=(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr3 = Malik_MVector_arr1;
    point = (Malik_MVector_arr1 != Malik_MVector_arr3);
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator!=() 243";
    }

    point = (Malik_MVector_arr1 != Malik_MVector_arr2);
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(!point)
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\noperator==() 249";
    }
    std::cout << "SUCCESS" << std::endl;



    std::cout << std::endl << "TEST_15:        unary operator+(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr1 = +Malik_MVector_arr3;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\n unary operator+() 260";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_16:        unary operator-(): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr1 = -Malik_MVector_arr3;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != -Malik_MVector_arr3.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\nunary operator-() 270";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_17:        unary operator++() pref: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr2 = Malik_MVector_arr3;
    Malik_MVector_arr1 = ++Malik_MVector_arr3;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) && Malik_MVector_arr2.M_get_value(i) != (Malik_MVector_arr3.M_get_value(i) - 1))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\nunary operator++() pref 281";
    }
    std::cout << "SUCCESS" << std::endl;



    std::cout << std::endl << "TEST_18:        unary operator++() post: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr2 = Malik_MVector_arr3;
    Malik_MVector_arr1 = Malik_MVector_arr3++;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != (Malik_MVector_arr3.M_get_value(i) - 1) && Malik_MVector_arr2.M_get_value(i) != Malik_MVector_arr1.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\nunary operator++() post 293";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_19:        unary operator--() pref: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr2 = Malik_MVector_arr3;
    Malik_MVector_arr1 = --Malik_MVector_arr3;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != Malik_MVector_arr3.M_get_value(i) && Malik_MVector_arr2.M_get_value(i) != (Malik_MVector_arr3.M_get_value(i) + 1))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\nunary operator--() pref 304";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_20:        unary operator--() post: " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    Malik_MVector_arr2 = Malik_MVector_arr3;
    Malik_MVector_arr1 = Malik_MVector_arr3--;
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if(Malik_MVector_arr1.M_get_value(i) != (Malik_MVector_arr3.M_get_value(i) + 1) && Malik_MVector_arr2.M_get_value(i) != Malik_MVector_arr1.M_get_value(i))
            return "ERROR: TEST OPERATORS (unit_test.cpp 94)\nunary operator--() post 315";
    }
    std::cout << "SUCCESS" << std::endl;


    std::cout << std::endl << "TEST_21:        unary operator[](): " << std::endl;
    set_value_MVectors(Malik_MVector_arr1, Malik_MVector_arr2, Malik_MVector_arr3);
    for (int i = 0; i < Malik_MVector_arr1.M_len(); i ++) {
        if (Malik_MVector_arr1[i] != Malik_MVector_arr1.M_get_value(i))
        return "ERROR: TEST OPERATORS (unit_test.cpp 94)\nunary operator[]()  324";
    }
    std::cout << "SUCCESS" << std::endl;

    return "Y";
}


void set_value_MVectors(MVector<TYPE>& first_MVector, MVector<TYPE>& second_MVector, MVector<TYPE>& third_MVector) {
    TYPE arr1[SIZE_MVECTOR_1] = {VALUE_MVECTOR_1};
    first_MVector.M_set_value( arr1, SIZE_MVECTOR_1);

    TYPE arr2[SIZE_MVECTOR_2] = {VALUE_MVECTOR_2};
    second_MVector.M_set_value( arr2, SIZE_MVECTOR_2);

    TYPE arr3[SIZE_MVECTOR_3] = {VALUE_MVECTOR_3};
    third_MVector.M_set_value( arr3, SIZE_MVECTOR_3);
}