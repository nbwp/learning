#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <classloc.h>
using namespace std;

location g()
{
    location A(1,2);
    cout << "/////////" <<endl;
    return A;
}
location g1()
{
    location A(2,3);
    cout << "/////////" <<endl;
    return A;
}
int main(int argc, char const *argv[])
{
    location B;
    cout << "////////////////" <<endl;
    B = g();//直接析构掉 匿名对象赋值后直接析构   B在程序运行结束后被析构
    cout << "////////////////" <<endl;
    location C = g1();//转正不会被析构
    return 0;
}




