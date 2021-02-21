#include <iostream>

template<typename Type>
class MVector {
    private:
        Type* value;
        int SIZE_MVECTOR = 1;
        int COMPLEAT_SIZE_MVECTOR = 0;

    public:
        MVector();
        MVector(int );
        ~MVector();
        Type* M_get_value();
//        void M_set_value(Type*);
        void M_push_back(Type);
        void M_print_MVector();
};

template<typename Type>
void Mcopy(Type**, Type**,int);


