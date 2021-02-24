#include <iostream>
#include <string>

class MVectorException {
private:

    std::string m_error;

public:
    MVectorException(std::string error) : m_error(error) {}

    const char* getError();
};


//как сделать еще тип для входящего значения шаблонным я  хз

template<typename Type>
class MVector {
    private:
        Type* value;
        unsigned int REAL_SIZE_MVECTOR = 1;
        unsigned int SIZE_MVECTOR= 0;

    public:

        MVector();
        MVector(const int );
        MVector(const double );
        MVector(const Type* , const int );
        ~MVector();

        const Type M_get_value(const int );
        void M_set_value(const Type ,const  int );
        const int M_len();
        const Type* M_begin();
        const Type* M_end();
        void M_print_MVector();

        void M_push_back(const Type);
        void M_pop_back();
//        void M_erase(Type* );


//      бинарные операраторы
// я не знвю почему тут нужно создавать новый шаблон но мне сказали что так работаето а  по другому нет

        template<typename opr_Type>
        friend MVector<opr_Type> operator+ (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend MVector<opr_Type> operator- (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend MVector<opr_Type> operator* (const MVector<opr_Type>& , const MVector<opr_Type>& );

        MVector<Type>& operator+= (const MVector<Type>& );
        MVector<Type>& operator-= (const MVector<Type>& );
        MVector<Type>& operator*= (const MVector<Type>& );
        MVector<Type>& operator/= (const MVector<Type>& );

        template<typename opr_Type>
        friend std::ostream& operator<< (std::ostream& , const MVector<opr_Type>&);

        template<typename opr_Type>
        friend std::istream& operator>> (std::istream& , MVector<opr_Type>&);

//      убинарные логические операторы


        template<typename opr_Type>
        friend bool operator== (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend bool operator!= (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend bool operator< (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend bool operator<= (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend bool operator> (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend bool operator>= (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend bool operator&& (const MVector<opr_Type>& , const MVector<opr_Type>& );

        template<typename opr_Type>
        friend bool operator|| (const MVector<opr_Type>& , const MVector<opr_Type>& );


//      унарные операторы

        MVector<Type>& operator+();
        MVector<Type> operator-();
        MVector<Type>& operator++();
        MVector<Type> operator++(int);
        MVector<Type>& operator--();
        MVector<Type> operator--(int);

//        унарные логические операторы
//        bool operator! ();

//      важные сложные операторы для непосредственной раюоты MVector-a


        MVector<Type>& operator=(const MVector<Type>& );
        Type& operator[](const int );
        const Type& operator[](const int ) const;


};

template<typename Type>
void Mcopy(Type* INPUT_VALUE_TO_COPY, Type* INPUT_VALUE_FROM_COPY,int INPUT_SIZE_FOR_COPY) {

    for (int i = 0; i < INPUT_SIZE_FOR_COPY; i ++) {
        INPUT_VALUE_TO_COPY[i] = INPUT_VALUE_FROM_COPY[i];
    }
}

int Mlen(const char *);

template<typename Type>
MVector<Type>::MVector() {
    value = new Type;
    REAL_SIZE_MVECTOR = 1;
    SIZE_MVECTOR = 0;
    *value = 0;
}

template<typename Type>
MVector<Type>::MVector(const int size) {
    if (size < 0)
        throw MVectorException("Input size is negative");

    if (size >= 1) {

        value = new Type[size];
        REAL_SIZE_MVECTOR = size;
        SIZE_MVECTOR = size;
        for (int i = 0; i < SIZE_MVECTOR; i ++) {
            value[i] = 0;
        }

    }
    else {

        value = new Type;
        REAL_SIZE_MVECTOR = 1;
        SIZE_MVECTOR= 0;
        *value = 0;

    }
}

template <typename Type>
MVector<Type>::MVector(const double ) {

    throw MVectorException("Input size is fractional\nif you want to write this number to a MVector enter a pointer to it\n");

}

//template<>
//MVector<char>::MVector(const char* Input_str) {
//
//    int size_input_str = Mlen(Input_str);
//    value = new char[size_input_str];
//    SIZE_MVECTOR = size_input_str;
//    REAL_SIZE_MVECTOR = size_input_str;
//
//    for (int i = 0; i < size_input_str; i ++) {
//        value[i] = Input_str[i];
//    }
//}

template<typename Type>
MVector<Type>::MVector(const Type* Input_value, const int size_input_value) {

    value = new Type[size_input_value];
    SIZE_MVECTOR = size_input_value;
    REAL_SIZE_MVECTOR = size_input_value;

    for (int i = 0; i < size_input_value; i ++) {
        value[i] = Input_value[i];
    }
}

template<typename Type>
MVector<Type>::~MVector() {
    REAL_SIZE_MVECTOR = 0;
    SIZE_MVECTOR = 0;
    delete [] value;
}



template<typename Type>
const Type MVector<Type>::M_get_value(const int i) {
    return value[i];
}

template<typename Type>
void MVector<Type>::M_set_value(const Type Input_value, const int Numb_cell) {
    try {
        if (Numb_cell < SIZE_MVECTOR)

            value[Numb_cell] = Input_value;
        else
            throw "This cell doesn't exist";
    }

    catch (const char* std) {
        std::cerr << std << std::endl;
    }

}

template<typename Type>
const int MVector<Type>::M_len() {
    return SIZE_MVECTOR;
}

template<typename Type>
const Type* MVector<Type>::M_begin() {
    if(SIZE_MVECTOR > 0)
        return &value[0];
    else
        return nullptr;
}

template<typename Type>
const Type* MVector<Type>::M_end() {
    if(SIZE_MVECTOR > 0)
        return &value[SIZE_MVECTOR - 1];
    else
        return nullptr;
}

template<typename Type>
void MVector<Type>::M_print_MVector() {
    for (int i = 0; i < SIZE_MVECTOR; i ++) {
        std::cout << "Это " << i << " значение МВекотра  " << value[i] << std::endl;
    }
    std::cout << std::endl;
}



template <typename Type>
void MVector<Type>::M_push_back(const Type INPUT_TYPE) {
    if(REAL_SIZE_MVECTOR == SIZE_MVECTOR) {

        Type* value_for_copy = new Type[SIZE_MVECTOR
                                        ];
        Mcopy(value_for_copy, value, SIZE_MVECTOR);
        delete[] value;

        REAL_SIZE_MVECTOR = REAL_SIZE_MVECTOR * 2 + 1;

        value = new Type[REAL_SIZE_MVECTOR];
        Mcopy(value, value_for_copy, SIZE_MVECTOR);
        delete[] value_for_copy;

        value[SIZE_MVECTOR] = INPUT_TYPE;
        SIZE_MVECTOR++;
    }
    else {

        value[SIZE_MVECTOR] = INPUT_TYPE;
        SIZE_MVECTOR++;

    }
}

template<typename Type>
void MVector<Type>::M_pop_back() {
    if(SIZE_MVECTOR)
    SIZE_MVECTOR--;
}


//template<typename Type>
//void MVector<Type>::M_erase(Type* elem_ptr) {
//    Type* New_MVector = new Type[SIZE_MVECTOR];
//    for( elem_ptr; )
//}










template<typename opr_Type>
MVector<opr_Type> operator+ (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {

//    assert(first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR && "EROOR: Size input vectors not equal");

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    opr_Type* output_value = new opr_Type[first_MVector.SIZE_MVECTOR];
    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        output_value[i] = first_MVector.value[i] + second_MVector.value[i];


    return MVector<opr_Type>(output_value, first_MVector.SIZE_MVECTOR);
}

template<typename opr_Type>
MVector<opr_Type> operator- (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {

//    assert(first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR && "EROOR: Size input vectors not equal");

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    opr_Type* output_value = new opr_Type[first_MVector.SIZE_MVECTOR];
    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        output_value[i] = first_MVector.value[i] - second_MVector.value[i];


    return MVector<opr_Type>(output_value, first_MVector.SIZE_MVECTOR);
}

template<typename opr_Type>
MVector<opr_Type> operator* (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {

//    assert(first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR && "EROOR: Size input vectors not equal");

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    opr_Type* output_value = new opr_Type[first_MVector.SIZE_MVECTOR];
    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        output_value[i] = first_MVector.value[i] * second_MVector.value[i];


    return MVector<opr_Type>(output_value, first_MVector.SIZE_MVECTOR);
}

template<typename Type>
MVector<Type>& MVector<Type>::operator+= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->value[i] = this->M_get_value(i) + input_MVector.value[i];



    return *this;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator-= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->value[i] = this->value[i] - input_MVector.value[i];

    return *this;
}


template<typename Type>
MVector<Type>& MVector<Type>::operator*= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->value[i] = this->value[i] * input_MVector.value[i];

    return *this;
}

template<typename Type>
MVector<Type>& MVector<Type>::operator/= (const MVector<Type>& input_MVector) {
    if (this->SIZE_MVECTOR != input_MVector.SIZE_MVECTOR)
        throw MVectorException("Input size vectors are not equal");

    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++)
        this->M_set_value(this->value[i] / input_MVector.value[i], i);

    return *this;
}

template<typename opr_Type>
std::ostream& operator<< (std::ostream& out, const MVector<opr_Type>& input_MVector) {
    out << "Size MVector: " << input_MVector.SIZE_MVECTOR << std::endl;
    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++) {
        out << i << " element of MVector: " << input_MVector.value[i] << std::endl;
    }
    return out;
}

template<typename opr_Type>
std::istream& operator>> (std::istream& in, MVector<opr_Type>& input_MVector) {
    for (int i = 0; i < input_MVector.SIZE_MVECTOR; i ++) {
        opr_Type input_value;
        in >> input_value;
        input_MVector.M_set_value(input_value, i);
    }
}




template<typename opr_Type>
bool operator== (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        return false;

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i++)
        if (first_MVector.value[i] != second_MVector.value[i])
            return false;

    return true;
}

template<typename opr_Type>
bool operator!= (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {

    if (first_MVector.SIZE_MVECTOR != second_MVector.SIZE_MVECTOR)
        return true;

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++)
        if (first_MVector.value[i] != second_MVector.value[i])
            return true;

    return false;
}

template<typename opr_Type>
bool operator< (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {
    if (first_MVector.SIZE_MVECTOR < second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename opr_Type>
bool operator<= (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {
    if (first_MVector.SIZE_MVECTOR <= second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename opr_Type>
bool operator> (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {
    if (first_MVector.SIZE_MVECTOR > second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename opr_Type>
bool operator>= (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector){
    if (first_MVector.SIZE_MVECTOR >= second_MVector.SIZE_MVECTOR)
        return true;
    return false;
}

template<typename opr_Type>
bool operator&& (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {
    bool pointer = true;

    for (int i = 0; i < first_MVector.SIZE_MVECTOR; i ++) {
        pointer = pointer && first_MVector.value[i] && second_MVector.value[i];
    }
    return pointer;
}

template<typename opr_Type>
bool operator|| (const MVector<opr_Type>& first_MVector, const MVector<opr_Type>& second_MVector) {
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
MVector<Type> MVector<Type>::operator-() {
    Type* func_value = new Type[this->SIZE_MVECTOR];
    for (int i = 0; i < this->SIZE_MVECTOR; i ++)
        func_value[i] = -this->value[i];

    return MVector<Type>(func_value, this->SIZE_MVECTOR);
}

//префиксная версия возвращает значение после инкремента
template<typename Type>
MVector<Type>& MVector<Type>::operator++() {
    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] + 1;
    }
    return *this;
}

//постфиксная версия возвращает значение до инкремента
template<typename Type>
MVector<Type> MVector<Type>::operator++(int) {
    MVector<Type> old_value(this->value);

    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] + 1;
    }
    return old_value;
}

//префиксная версия возвращает значение после инкремента
template<typename Type>
MVector<Type>& MVector<Type>::operator--() {
    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] - 1;
    }
    return *this;
}

//постфиксная версия возвращает значение до инкремента
template<typename Type>
MVector<Type> MVector<Type>::operator--(int) {
    MVector<Type> old_value(this->value);

    for (int i = 0; i < this->SIZE_MVECTOR; i ++) {
        this->value[i] = this->value[i] - 1;
    }
    return old_value;
}


// унарный логический оператор

//template<typename Type>
//bool MVector<Type>::operator!() {
//
//    for (int i = 0 ; i < this->SIZE_MVECTOR; i ++) {
//
//    }
//}



// сложные операторы
template<typename Type>
MVector<Type>& MVector<Type>::operator= (const MVector<Type>& input_vector) {

    if (*this == input_vector) {
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