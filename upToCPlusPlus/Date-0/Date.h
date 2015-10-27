#ifndef DATE_H
#define DATE_H
 
#include <string>
 
class Date {
public:
void reset();
void set(int y, int m, int d);
void fromStr(std::string str);
std::string toStr() const;
private:
int year, month, day;
};
 
#endif
