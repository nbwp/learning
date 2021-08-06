#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <classloc.h>
using namespace std;


int main(int argc, char const *argv[])
{
    location l1(10,20);
    location l2(l1);
    location l3 = l1;
    l1.getX();
    l2.getX();
    l3.getY();
    return 0;
}




