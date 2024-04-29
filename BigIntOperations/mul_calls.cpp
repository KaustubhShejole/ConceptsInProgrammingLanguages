#include "calls.h"

void AddBig_IntsForMul(Big_Int* b1,Big_Int* b2,Big_Int* b3)
{
    int carry;
    carry = 0;
    carry = add(b1->lower1,b2->lower1,b3->lower1,carry);
    carry = add(b1->lower2,b2->lower2,b3->lower2,carry);
    carry = add(b1->lower3,b2->lower3,b3->lower3,carry);
    carry = add(b1->lower4,b2->lower4,b3->lower4,carry);
    carry = add(b1->lower5,b2->lower5,b3->lower5,carry);
    carry = add(b1->lower6,b2->lower6,b3->lower6,carry);
    carry = add(b1->lower7,b2->lower7,b3->lower7,carry);
    carry = add(b1->lower8,b2->lower8,b3->lower8,carry);
    carry = add(b1->upper1,b2->upper1,b3->upper1,carry);
    carry = add(b1->upper2,b2->upper2,b3->upper2,carry);
    carry = add(b1->upper3,b2->upper3,b3->upper3,carry);
    carry = add(b1->upper4,b2->upper4,b3->upper4,carry);
    carry = add(b1->upper5,b2->upper5,b3->upper5,carry);
    carry = add(b1->upper6,b2->upper6,b3->upper6,carry);
    carry = add(b1->upper7,b2->upper7,b3->upper7,carry);
    carry = add(b1->upper8,b2->upper8,b3->upper8,carry);
    if(carry!=0)
    {
        cout<<"Overflow happened\n";
        exit(1);
    }
    
}
void fun(int arr[],Big_Int* b1,Big_Int* b2,Big_Int* b3,int &z)
{
    int j =0;
        while((size-j-1)>=0)
        {
            if(arr[size-j-1]==1)
            {
                for(int i = 0; i<z;i++)
                {
                    AddBig_IntsForMul(b3,b1,b3);
                }
            }
            z = z*2;
            j = j + 1;
        }
}
void MulBig_Ints(Big_Int* b1,Big_Int* b2,Big_Int* b3)
{
    int z,i;
    
    z = 1;
        fun(b2->lower1,b1,b2,b3,z);
        fun(b2->lower2,b1,b2,b3,z);
        fun(b2->lower3,b1,b2,b3,z);
        fun(b2->lower4,b1,b2,b3,z);
        fun(b2->lower5,b1,b2,b3,z);
        fun(b2->lower6,b1,b2,b3,z);
        fun(b2->lower7,b1,b2,b3,z);
        fun(b2->lower8,b1,b2,b3,z);
        fun(b2->upper1,b1,b2,b3,z);
        fun(b2->upper2,b1,b2,b3,z);
        fun(b2->upper3,b1,b2,b3,z);
        fun(b2->upper4,b1,b2,b3,z);
        fun(b2->upper5,b1,b2,b3,z);
        fun(b2->upper6,b1,b2,b3,z);
        fun(b2->upper7,b1,b2,b3,z);
        fun(b2->upper8,b1,b2,b3,z);

    cout<<"Multiplication Result = "<<endl;
    WriteOutBig_Int(b3);
}
