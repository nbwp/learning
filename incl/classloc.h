#ifndef _CLASSLOC_H_
#define _CLASSLOC_H_

class location
{
public:
    location(int x = 0, int y = 0);
    location(const location &p);    
    
    ~location();

    int getX();
    int getY();
private:
    int X,Y;
};


#endif










