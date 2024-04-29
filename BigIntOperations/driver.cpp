#include "calls.h"
#include "subcalls.h"
#include "mulcalls.h"
int main()
{
    Big_Int b1,b2,b3;
    cout<<"***********Addition************";
    InitializeNumber(&b1);
    InitializeNumber(&b2);
    Initialize(&b3);
    AddBig_Ints(&b1,&b2,&b3);
    cout<<"Result =";
    WriteOutBig_Int(&b3);
    cout<<endl;
    cout<<"************Subtraction*********";
    InitializeNumber(&b1);
    InitializeNumber(&b2);
    Initialize(&b3);
    SubBig_Ints(&b1,&b2,&b3);
    cout<<endl;
    cout<<"*************Multiplication*******";
    InitializeNumber(&b1);
    InitializeNumber(&b2);
    Initialize(&b3);
    MulBig_Ints(&b1,&b2,&b3);
    cout<<endl;
    return 0;
}