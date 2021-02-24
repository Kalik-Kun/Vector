#include <iostream>
#include <string.h>
#include "Vector.h"
#include "unit_test.h"




std::string unit_test();

int main() {
    try {
        std::string unit_str = unit_test();
        if(unit_str.size() == 1)
            std::cout << std::endl << "UNIT TEST IS COMPLETED SUCCESSFULLY" << std::endl;
        else
            std::cerr << std::endl << unit_str << std::endl;
    }
    catch (MVectorException& exception) {
        std::cerr << std::endl << "ERROR: " << exception.getError() << std::endl;
    }
    catch (std::exception& exception) {
        std::cerr << std::endl << "Standard exception: " << exception.what() << std::endl;
    }
    catch (...) {
        std::cerr << std::endl << "EROOR but i dont know why" << std::endl;
    }
    return 0;
}
