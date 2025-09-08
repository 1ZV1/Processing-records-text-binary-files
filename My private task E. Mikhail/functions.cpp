#include "sort.h"

bool CompareInt(const int &a, const int &b)
{
    return a > b;
}
bool CompareDouble(const double &a, const double &b){
    return a > b;
}
bool CompareChar(const char &a, const char &b)
{
    return a > b;
}
bool CompareString(const std::string &a, const std::string &b)
{
    return a > b;
}

bool CompareStudent(const Student &a, const Student &b)
{
    if(a.course != b.course)
    {
        return a.course > b.course;
    }
    if(a.group != b.group)
    {
        return a.group > b.group;
    }
    return a.fio > b.fio;
}
