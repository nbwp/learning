#include <iostream>
using namespace std;
struct s1
{
    int i;
    int j;
    int k;
    static int b;
};

int main(int argc, char const *argv[])
{
    cout << sizeof(s1);
    return 0;
}

