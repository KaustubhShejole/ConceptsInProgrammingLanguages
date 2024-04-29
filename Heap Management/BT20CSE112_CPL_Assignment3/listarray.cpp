#include "listarray.h"
#include "list.h"
array_of_list::array_of_list():arr(NULL),size(0){}
array_of_list::~array_of_list()
{
    delete [] arr;
    arr = NULL;
    size = 0;
}
list& array_of_list::operator[](int j)
{
    return arr[j];
}
ostream& operator<<(ostream& out,const array_of_list& a)
{
    print(a.arr);
}
void array_of_list::make_space(int n)
{
    arr = new list[n];
    size = n;
}
void print(const list* arr)
{
    int len;
    len = fibo_list.size();
    cout<<"[ ";
    for(int i=0;i<len-1;i++)
    {
        cout<<arr[i];
        cout<<" , ";
    }
    cout<<arr[len-1];
    cout<<" ]"<<endl;
}
int array_of_list::len() const
{
    return size;
}
int array_of_list::index(const Itemtype& j) const
{
    int ret_val,i;
    ret_val = -1;
    i = 0;
    while(arr[i].index(j) == -1 && i<size-1)
    {
        i++;
    }
    if(arr[i].index(j) != -1)
    {
        ret_val = i;
    }
    return ret_val;
}