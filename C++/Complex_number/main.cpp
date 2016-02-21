    #include <iostream>
    using std::cin;
    using std::cout;
    using std::endl;
     
    #include "Complex.h"
     
    int main() {
    int n[8];
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    cin >> n[4] >> n[5] >> n[6] >> n[7];
    Complex a(n[0], n[1]), b(n[2], n[3]), c;
     
    a.printComplex();
    cout << " + ";
    b.printComplex();
    cout << " = ";
    c = a.add(b);
    c.printComplex();
     
    cout << '\n';
    a.setComplexNumber(n[4], n[5]);
    b.setComplexNumber(n[6], n[7]);
    a.printComplex();
    cout << " - ";
    b.printComplex();
    cout << " = ";
    c = a.subtract(b);
    c.printComplex();
    cout << endl;
    }
