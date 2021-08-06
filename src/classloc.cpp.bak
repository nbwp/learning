#include <classloc.h>
#include <iostream>

using namespace std;
location::location(int x , int y)
{
    X = x;
    Y = y;
    cout << "有参构造函数" << endl;
}
location::location(const location &p)
{
    X = p.X;
    Y = p.Y;
    cout << "拷贝构造函数" << endl;
}
location::~location()
{
    cout << "析构函数" << getX() << endl;
};
int location::getX()
{
    return X;
}
int location::getY()
{
    return Y;
}