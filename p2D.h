#ifndef P2D_H_INCLUDED
#define P2D_H_INCLUDED
#include <iostream>
using namespace std;

class pnt2ds
{
    public:
        double x,y,w;

        pnt2ds();
        pnt2ds(double,double,double);

        void setx(double);
        void sety(double);
        void setw(double);

        double getx(void);
        double gety(void);
        double getw(void);

        void setxy(double,double,double);
        void print();
};

pnt2ds::pnt2ds()
{
    x=0;
    y=0;
    w=0;
}
pnt2ds::pnt2ds(double x1,double y1,double w1)
{
    x=x1;
    y=y1;
    w=w1;
}

void pnt2ds::setx(double x1)
{
    x=x1;
}
double pnt2ds::getx(void)
{
    return x;
}
void pnt2ds::sety(double y1)
{
    y=y1;
}
double pnt2ds::gety(void)
{
    return y;
}
void pnt2ds::setw(double w1)
{
    w=w1;
}
double pnt2ds::getw(void)
{
    return w;
}

void pnt2ds::setxy(double x1,double y1,double w1)
{
    x=x1;
    y=y1;
    w=w1;
}

void pnt2ds::print()
{
    cout << "x:" << " " << x << endl;
    cout << "y:" << " " << y << endl;
    cout << "w:" << " " << w << endl;
}


#endif // P2D_H_INCLUDED
