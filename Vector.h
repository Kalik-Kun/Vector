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

        const Type* M_get_value(const int );
        void M_set_value(const Type ,const unsigned int );
        const int M_len();
        const Type* M_begin();
        const Type* M_end();
        void M_print_MVector();

        void M_push_back(const Type);
        void M_pop_back();
//        void M_erase(Type* );


//      бинарные операраторы

        friend MVector<Type> operator+ (const MVector<Type>& , const MVector<Type>& );
        friend MVector<Type> operator- (const MVector<Type>& , const MVector<Type>& );
        friend MVector<Type> operator* (const MVector<Type>& , const MVector<Type>& );
        MVector<Type>& operator+= (const MVector<Type>& );
        MVector<Type>& operator-= (const MVector<Type>& );
        MVector<Type>& operator*= (const MVector<Type>& );
        MVector<Type>& operator/= (const MVector<Type>& );
        friend std::ostream& operator<< (std::ostream& , const MVector<Type>&);
        friend std::istream& operator>> (std::istream& , const MVector<Type>&);

//      убинарные логические операторы

        friend bool operator== (const MVector<Type>& , const MVector<Type>& );
        friend bool operator!= (const MVector<Type>& , const MVector<Type>& );
        friend bool operator< (const MVector<Type>& , const MVector<Type>& );
        friend bool operator<= (const MVector<Type>& , const MVector<Type>& );
        friend bool operator> (const MVector<Type>& , const MVector<Type>& );
        friend bool operator>= (const MVector<Type>& , const MVector<Type>& );
        friend bool operator&& (const MVector<Type>& , const MVector<Type>& );
        friend bool operator|| (const MVector<Type>& , const MVector<Type>& );

//      унарные операторы

        MVector<Type>& operator+();
        MVector<Type>& operator-();
        MVector<Type>& operator++();
        MVector<Type> operator++(int);
        MVector<Type>& operator--();
        MVector<Type> operator--(int);

//        унарные логические операторы
        bool operator! ();

//      важные сложные операторы для непосредственной раюоты MVector-a
        MVector<Type>& operator=(const MVector<Type>& );
        Type& operator[](const int );
        const Type& operator[](const int ) const;


};

template<typename Type>
void Mcopy(Type* , Type* ,int );

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
const Type* MVector<Type>::M_get_value(const int i) {
    return value[i];
}

template<typename Type>
void MVector<Type>::M_set_value(const Type Input_value, const unsigned int Numb_cell) {
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


