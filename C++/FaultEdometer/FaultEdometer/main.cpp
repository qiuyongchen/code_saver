#include <iostream>
void main() {
    int temp;
    std::cin >> temp;
    while (temp != 0) {
        int sum = 0, i = 0;
        while (temp != 0) {
            int son = temp % 10, itemp = i;
            temp /= 10;
            if (son > 4) --son;
            while (itemp--) son *= 10;
            sum += son;
            ++i;
        }
        std::cout << sum << std::endl;
        std::cin >> temp;
    }
}
