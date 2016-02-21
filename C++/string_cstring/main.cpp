    #include <cstdio>
    #include <iostream>
    #include <cstring>
    #include <string>
    #include "exchange.h"
    std::string st1;
    char st2[100];
    int main() {
    std::cin >> st1;
    change2(st1, st2);
    puts(st2);
    scanf("%s", st2);
    std::cout << change1(st2) << std::endl;
    return 0;
    }
     

