#ifndef LIST_H
#define LIST_H
#include<iostream>
using namespace std;
typedef int Itemtype;
typedef struct Node_tag
{
    Itemtype data;
    struct Node_tag* next;
} Node;

class list
{
    private:
        Node* lptr;
    public:
        list();
        ~list();
        void append(const Itemtype& j);
        void remove(const Itemtype& j);
        bool operator==(const list& l1) const;
        list& operator=(const list& l1);
        int index(const Itemtype& j) const;
        friend ostream& operator<<(ostream& out,const list& l);
        int size() const;
        Itemtype& operator[](int);
};
#endif