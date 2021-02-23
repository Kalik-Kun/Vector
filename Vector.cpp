#include <iostream>
#include "Vector.h"


template<typename Type>
void Mcopy(Type* INPUT_VALUE_TO_COPY, Type* INPUT_VALUE_FROM_COPY,int INPUT_SIZE_FOR_COPY) {

    for (int i = 0; i < INPUT_SIZE_FOR_COPY; i ++) {
        INPUT_VALUE_TO_COPY[i] = INPUT_VALUE_FROM_COPY[i];
    }
}

int Mlen(const char* input_str) {
    int len_input_str;

    for (len_input_str = 0; input_str[len_input_str] != '\0'; len_input_str ++)
        len_input_str++;

    return len_input_str;
}

const char* MVectorException::getError() {
    return m_error.c_str();
}


template<typename Type>
MVector<Type> operator+ (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {

    MVector<Type> Output_MVector(first_MVector.SIZE_MVECTOR);

//    assert(first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR && "EROOR: Size input vectors not equal");

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        Output_MVector.M_set_value(first_MVector.M_get_value(i) + second_MVector.M_get_value(i), i);


    return Output_MVector;
}

template<typename Type>
MVector<Type> operator- (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {

    MVector<Type> Output_MVector(first_MVector.SIZE_MVECTOR);

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        Output_MVector.M_set_value(first_MVector.M_get_value(i) - second_MVector.M_get_value(i), i);

    return Output_MVector;

}

template<typename Type>
MVector<Type> operator* (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {

    MVector<Type> Output_MVector(first_MVector.SIZE_MVECTOR);

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        Output_MVector.M_set_value(first_MVector.M_get_value(i) * second_MVector.M_get_value(i), i);


    return Output_MVector;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator+= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->M_set_value(this->M_get_value(i) + input_MVector.M_get_value(i), i);

    return input_MVector;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator-= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->M_set_value(this->M_get_value(i) - input_MVector.M_get_value(i), i);

    return *this;
}


template<typename Type>
MVector<Type>& MVector<Type>::operator*= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->M_set_value(this->M_get_value(i) * input_MVector.M_get_value(i), i);

    return *this;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator/= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->M_set_value(this->M_get_value(i) / input_MVector.M_get_value(i), i);

    return *this;
}

template<typename Type>
std::ostream& operator<< (std::ostream& out, const MVector<Type>& input_MVector) {
    out << "Size MVector: " << input_MVector.SIZE_MVECTOR << std::endl;
    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++) {
        out << i << " element of MVector: " << input_MVector.value[i] << std::endl;
    }
    return out;
}

template<typename Type>
std::istream& operator>> (std::istream& in, const MVector<Type>& input_MVector) {
    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++) {
        Type input_value;
        in >> input_value;
        input_MVector.M_set_value(input_value, i);
    }
}




template<typename Type>
bool operator== (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        return false;

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i++)
        if (first_MVector.M_get_value(i) != second_MVector.M_get_value(i))
            return false;

    return true;
}

template<typename Type>
bool operator!= (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        return true;

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        if (first_MVector.M_get_value(i) != second_MVector.M_get_value(i))
            return true;

    return false;
}

template<typename Type>
bool operator< (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {
    if (first_MVector.SIZE_MVECTOR < second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename Type>
bool operator<= (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {
    if (first_MVector.SIZE_MVECTOR <= second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename Type>
bool operator> (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {
    if (first_MVector.SIZE_MVECTOR > second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename Type>
bool operator>= (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector){
    if (first_MVector.SIZE_MVECTOR >= second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename Type>
bool operator&& (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {
    bool pointer = true;

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++) {
        pointer = pointer && first_MVector.value[i] && second_MVector.value[i];
    }
    return pointer;
}

template<typename Type>
bool operator|| (const MVector<Type>& first_MVector, const MVector<Type>& second_MVector) {
    bool pointer = false;

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++) {
        pointer = pointer || first_MVector.value[i] || second_MVector.value[i];
    }

    return pointer;
}


template<typename Type>
MVector<Type>& MVector<Type>::operator+() {
    return *this;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator-() {
    for (int i = 0; i < this->SIZE_MVECTOR; i ++)
        this->value[i] = -this->value[i];

    return *this;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator++() {
    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] + 1;
    }
    return *this;
}

template<typename Type>
MVector<Type> MVector<Type>::operator++(int) {
    MVector<Type> old_value(this->value);

    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] + 1;
    }
    return old_value;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator--() {
    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] - 1;
    }
    return *this;
}

template<typename Type>
MVector<Type> MVector<Type>::operator--(int) {
    MVector<Type> old_value(this->value);

    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] - 1;
    }
    return old_value;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator= (const MVector<Type>& input_vector) {

    if (this == input_vector) {
        return *this;
    }

    delete[] this->value;
    this->value = new Type[input_vector.SIZE_MVECTOR];
    this->SIZE_MVECTOR = input_vector.SIZE_MVECTOR;
    this->REAL_SIZE_MVECTOR = input_vector.REAL_SIZE_MVECTOR;

    for (int i = 0; i < input_vector.SIZE_MVECTOR; i ++) {
        this->value[i] = input_vector.value[i];
    }

    return *this;
}

template<typename Type>
Type& MVector<Type>::operator[](const int input_cell) {
    return this->value[input_cell];
}

template<typename Type>
const Type& MVector<Type>::operator[](const int input_cell) const {
    return this->value[input_cell];
}