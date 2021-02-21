#include <iostream>
#include "Vector.h"

template<typename Type>
MVector<Type>::MVector() {
    value = new Type;
    SIZE_MVECTOR = 1;
    *value = 0;
}

template<typename Type>
MVector<Type>::MVector(int size) {
    if (size > 1) {

        value = new Type[size];
        SIZE_MVECTOR = size;
        for (int i = 0; i < SIZE_MVECTOR; i ++) {
            value[i] = 0;
        }

    }
    else {

        value = new Type;
        SIZE_MVECTOR = 1;
        *value = 0;

    }
}
template<typename Type>
MVector<Type>::~MVector() {
    delete [] value;
}
template<typename Type>
Type* MVector<Type>::M_get_value() {
    return value;
}

template <typename Type>
void MVector<Type>::M_push_back(Type INPUT_TYPE) {
    if(SIZE_MVECTOR == COMPLEAT_SIZE_MVECTOR) {

        Type* value_for_copy = new Type[SIZE_MVECTOR];
        Mcopy(&value_for_copy, &value, SIZE_MVECTOR);
        delete[] value;

        SIZE_MVECTOR = SIZE_MVECTOR * 2 + 1;

        value = new Type[SIZE_MVECTOR];
        Mcopy(&value, &value_for_copy, (int) (SIZE_MVECTOR - 1) / 2);
        delete[] value_for_copy;

        value[COMPLEAT_SIZE_MVECTOR] = INPUT_TYPE;
        COMPLEAT_SIZE_MVECTOR++;
    }
    else {

        value[COMPLEAT_SIZE_MVECTOR] = INPUT_TYPE;
        COMPLEAT_SIZE_MVECTOR++;

    }
}

template<typename Type>

void MVector<Type>::M_print_MVector() {
    for (int i = 0; i < SIZE_MVECTOR; i ++) {
        std::cout << "Это " << i << " значение МВекотра" << value[i] << std::endl;
    }
    std::cout << std::endl;
}

//template<typename Type>
//void Vector<Type>::set_value_vec(Type* Input_user_array) {
//
//    for (int i = 0; i < )
//}

template<typename Type>
void Mcopy(Type** INPUT_VALUE_TO_COPY, Type** INPUT_VALUE_FROM_COPY,int INPUT_SIZE_FOR_COPY) {

    for (int i = 0; i < INPUT_SIZE_FOR_COPY; i ++) {
        *INPUT_VALUE_TO_COPY[i] = *INPUT_VALUE_FROM_COPY[i];
    }
}