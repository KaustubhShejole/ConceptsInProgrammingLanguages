
#include "calls.h"
void Complement1ofArray(int arr[],int arr1[],int size)
{
    int j = 0;
    while(j<size)
    {
        if(arr[j] == 0)
        {
            arr1[j] = 1;
        }
        else if(arr[j] == 1)
        {
            arr1[j] = 0;
        }
        else
        {
            cout<<"error";
        }
        j++;
    }
}
void ComplementOf1(Big_Int* b,Big_Int* c)
{
    Complement1ofArray(b->upper8,c->upper8,size);
    Complement1ofArray(b->upper7,c->upper7,size);
    Complement1ofArray(b->upper6,c->upper6,size);
    Complement1ofArray(b->upper5,c->upper5,size);
    Complement1ofArray(b->upper4,c->upper4,size);
    Complement1ofArray(b->upper3,c->upper3,size);
    Complement1ofArray(b->upper2,c->upper2,size);
    Complement1ofArray(b->upper1,c->upper1,size);

    Complement1ofArray(b->lower8,c->lower8,size);
    Complement1ofArray(b->lower7,c->lower7,size);
    Complement1ofArray(b->lower6,c->lower6,size);
    Complement1ofArray(b->lower5,c->lower5,size);
    Complement1ofArray(b->lower4,c->lower4,size);
    Complement1ofArray(b->lower3,c->lower3,size);
    Complement1ofArray(b->lower2,c->lower2,size);
    Complement1ofArray(b->lower1,c->lower1,size);
}
void ComplementOf2(Big_Int* b,Big_Int* c)
{
    Big_Int Unity;
    Initialize(&Unity);
    Itemtype num =1;
    to_binary(num,Unity.lower1,size);

    ComplementOf1(b,c);
    

    AddBig_Ints(c,&Unity,c);
}
void AddBig_IntsForSub(Big_Int* b1,Big_Int* b2,Big_Int* b3)
{
    cout<<"ENTERED"<<endl;
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
        cout<<"answer = ";
        WriteOutBig_Int(b3);
        
        cout<<endl;
    }
    else
    {
        cout<<"Negative number can't be represented by Unsigned Numbers\n";
        ComplementOf2(b3,b3);
        cout<<"answer = -";
        WriteOutBig_Int(b3);
        cout<<endl;
    }
    
}
void SubBig_Ints(Big_Int* b1,Big_Int* b2,Big_Int* b3)
{
    Big_Int c;
    Initialize(&c);
    ComplementOf2(b2,&c);
    AddBig_IntsForSub(b1,&c,b3);
}
