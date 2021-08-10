#include <iostream>

using namespace std;

class Complex{
public:
    Complex(int a,int b)
    {
        this->a = a;
        this->b = b;
    }
friend Complex operator+(Complex &c1,Complex &c2);//全局函数方式
Complex operator-(Complex &c2);//类成员函数方式
    void printcomplex()
    {
        cout << a <<"+" << b <<"i\n";
    }
private:
    int a,b;
    int c;
    
};
Complex operator+(Complex &c1,Complex &c2)
{
    Complex tmp(c1.a+c2.a,c1.b+c2.b);
    return tmp;
}
Complex Complex::operator-(Complex &c2)
{
    Complex tmp(this->a-c2.a, this->b-c2.b);
    return tmp;
}
//类成员函数需要被隐含

int main(int argc, char *argv[])
{
    Complex c1(5,6);
    Complex c2(2,3);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    c3.printcomplex();
    c4.printcomplex();
    return 0;
}

