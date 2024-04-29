#ifndef LISTARRAY_H
#define LISTARRAY_H
#include"list.h"
extern list fibo_list;
class array_of_list
{
    private:
        int size;
        list* arr;
    public:
    array_of_list();
    ~array_of_list();
    list& operator[](int i);
    friend ostream& operator<<(ostream& out,const array_of_list& a);
    void make_space(int n);
    int index(const Itemtype& j) const;
    int len() const;
};
void print(const list* arr);
#endif