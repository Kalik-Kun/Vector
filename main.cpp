#include <iostream>
#include "Vector.h"

bool unit_test();

int main() {
    try {
        if(unit_test())
            std::cout << "UNIT TEST IS COMPLETED SUCCESSFULLY" << std::endl;
    }
    catch (MVectorException& exception) {
        std::cerr << "ERROR: " << exception.getError() << std::endl;
    }
    catch (std::exception& exception) {
        std::cerr << "Standard exception: " << exception.what() << std::endl;
    }
    catch (...) {
        std::cerr << "EROOR but i dont know why" << std::endl;
    }
    return 0;
}

bool unit_test() {

    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MVector<int> Malik_MVector_1nt_size(10);
    MVector<int> Malik_MVector_int_arr(arr, 10);

    std::cout << "INPUT MVector with func:" << std::endl << std::endl;

    Malik_MVector_1nt_size.M_print_MVector();
    Malik_MVector_int_arr.M_print_MVector();

    std::cout << "INPUT MVector with threads:" << std::endl << std::endl;

    std::cout << Malik_MVector_int_arr << std::endl << std::endl;

    return true;
}