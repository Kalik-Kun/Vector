#include <string>

#define TYPE int//это тип определяемого значения
#define SIZE_MVECTOR_1 10
#define SIZE_MVECTOR_2 10
#define SIZE_MVECTOR_3 10
#define VALUE_MVECTOR_1 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
#define VALUE_MVECTOR_2 10, 9, 8, 7, 6, 5, 4, 3, 2, 1
#define VALUE_MVECTOR_3 2, 2, 2, 2, 2, 2, 2, 2, 2, 2
#define INPUT_VALUE_FOR_M_SET_VALUE_TEST 10
#define NUMB_CELL_FOR_M_SET_VALUE_TEST 0
#define NUMB_CELL_FOR_M_GET_VALUE_TEST 0
#define INPUT_VALUE_FOR_M_PUSH_BACK_TEST 11

std::string unit_test();
void set_value_MVectors(MVector<TYPE>& , MVector<TYPE>& , MVector<TYPE>& );