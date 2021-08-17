#include <iostream>

using namespace std;

/*class Complex{
public:
    Complex(int a,int b)
    {
        this->a = a;
        this->b = b;
    }
friend Complex operator+(Complex &c1,Complex &c2);//全局函数方式
Complex operator-(Complex &c2);//类成员函数方式
Complex operator++();    
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
Complex Complex::operator++()
{
    Complex tmp(this->a++,this->b++);
    return tmp;
}*/
class test_vector
{
private:    
    int m_length;
    int *myspace;
public:    
    test_vector(int length);
    test_vector(test_vector& tmp);
    ~test_vector();

    int add(int pos, int num);
    int del(int pos);
    int get(int pos);
    void getall();
    
    test_vector& operator=(test_vector& v2);
    friend istream& operator>>(istream& my_cin,test_vector &v1);
    friend ostream& operator<<(ostream& my_out, test_vector &v1);
};
test_vector::test_vector(int length)
{
    m_length = length;
    myspace = new int[m_length];
}
test_vector::test_vector(test_vector& tmp)
{
    this->m_length = tmp.m_length;
    this->myspace = new int[m_length];
}
test_vector::~test_vector()
{
    delete []myspace;
}
int test_vector::add(int pos,int num)
{
    if (pos > m_length)
    {
        return -1;   
    }
    myspace[pos-1] = num;
    return 0;
}
int test_vector::get(int pos)
{
    if(pos < m_length)
    {
        return myspace[pos-1];
    }
    else
    {
        return -1;
    }
}
int test_vector::del(int pos)
{
    
    for(int i = pos; i < this->m_length; i++)
    {
        myspace[i-1] = myspace[i];
    }
    myspace[m_length-1] = 0;
    this->m_length -= 1;
    return 0;
}
void test_vector::getall()
{
    for (int i = 0; i < m_length; i++)
    {
        cout << myspace[i] << endl;
    }
    
}
test_vector& test_vector::operator=(test_vector& v2)
{
    this->m_length = v2.m_length;
    for(int i = 0; i < v2.m_length; i++)
    {
        this->myspace[i] = v2.myspace[i];
    }
    return *this;
}
istream& operator>>(istream& my_cin,test_vector &v1)
{
   for (int i = 0; i < v1.m_length; i++)
   {
       my_cin >> v1.myspace[i];
   }
   
    return my_cin;
}
ostream& operator<<(ostream& my_out, test_vector &v1)
{
    for (int i = 0; i < v1.m_length; i++)
    {
        my_out << v1.myspace[i] << endl;
    }
    return my_out;
}
int main(int argc, char *argv[])
{
    /*Complex c1(5,6);
    Complex c2(2,3);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;
    c1.operator-(c2);
    c3.printcomplex();
    c4.printcomplex();*/
    int num = 5;
    test_vector v1(num);
    cin >> v1;
    cout << v1;
    return 0;
}
