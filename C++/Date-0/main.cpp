

    #include <iostream>
    #include <string>
    #include "Date.h"
     
    int main() {
    Date d;
    int iy, im, id;
    std::string is;
    d.reset();
    std::cout << d.toStr() << std::endl;
    std::cin >> iy >> im >> id;
    d.set(iy, im, id);
    std::cout << d.toStr() << std::endl;
    std::cin >> is;
    d.fromStr(is);
    std::cout << d.toStr() << std::endl;
    return 0;
    }

