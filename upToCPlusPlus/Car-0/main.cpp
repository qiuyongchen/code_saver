

    #include <iostream>
    #include <string>
    #include "Car.h"
     
    int main() {
    Car a;
    std::string ts;
    double td;
    std::cin >> ts >> td;
    a.setManufacturer(ts);
    a.setDisplacement(td);
    std::cout << a.getManufacturer() << "," << a.getDisplacement() << std::endl;
    std::cin >> ts >> td;
    a.setManufacturer(ts);
    a.setDisplacement(td);
    std::cout << a.getManufacturer() << "," << a.getDisplacement() << std::endl;
    return 0;
    }

