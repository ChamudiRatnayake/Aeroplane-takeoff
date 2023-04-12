#include <iostream>
#include <graphics.h>
#include <p2D.h>
#include <Matrix.h>
using namespace std;

                                                //PLANE TAKING OFF
int main()
{
    initwindow(1500,750);
    int i=0,j=0,k;
    pnt2ds B1,B2,C1,C2,D1,D2,F1,F2,F3,O1,O2,O3,O4,O5,O6,O7,O8,W1,W2,W3,N1,N2,N3,N4,L1,L2;
    pnt2ds a(0,590,1),g1(0,605,1),g2(1500,605,1);
    pnt2ds b1(0,595,1),c1(0,585,1),d1(0,575,1);
    pnt2ds b2(20,595,1),c2(20,585,1),d2(20,575,1);
    pnt2ds f1(80,595,1),f2(80,585,1),f3(80,575,1);
    pnt2ds o1(-100,575,1),o2(100,575,1),o3(-140,555,1),o4(-105,535,1),o5(-105,480,1),o6(100,550,1),o7(100,525,1),o8(-80,525,1);
    pnt2ds w1(30,555,1),w2(-10,555,1),w3(-30,590,1);
    pnt2ds n1(40,545,1),n2(20,545,1),n3(0,545,1),n4(-20,545,1);
    pnt2ds l1(120,530,1),l2(100,540,1);

    pieslice(a.getx(),a.gety(),0,90,10);
    while(i<300)
    {
        if(i<100)
        {
            i++;
        }
        else if(i<200)
        {
            i+=2;   //Increase the speed
        }
        else
        {
            i+=3;   //Increase the speed
        }

        //ground
        line(g1.getx(),g1.gety(),g2.getx(),g2.gety());

        //backwheel1
        pieslice(b1.getx()+i,b1.gety(),0-i,90-i,10);
        pieslice(b1.getx()+i,b1.gety(),180-i,270-i,10);
        circle(b1.getx()+i,b1.gety(),10);
        line(c1.getx()+i,c1.gety(),d1.getx()+i,d1.gety());

        //backwheel2
        pieslice(b2.getx()+i,b2.gety(),0-i,90-i,10);
        pieslice(b2.getx()+i,b2.gety(),180-i,270-i,10);
        circle(b2.getx()+i,b2.gety(),10);
        line(c2.getx()+i,c2.gety(),d2.getx()+i,d2.gety());

        //frontwheel
        pieslice(f1.getx()+i,f1.gety(),0-i,90-i,10);
        pieslice(f1.getx()+i,f1.gety(),180-i,270-i,10);
        circle(f1.getx()+i,f1.gety(),10);
        line(f2.getx()+i,f2.gety(),f3.getx()+i,f3.gety());

        //body
        line(o1.getx()+i,o1.gety(),o2.getx()+i,o2.gety());
        line(o1.getx()+i,o1.gety(),o3.getx()+i,o3.gety());
        line(o3.getx()+i,o3.gety(),o4.getx()+i,o4.gety());
        line(o4.getx()+i,o4.gety(),o5.getx()+i,o5.gety());
        arc(o6.getx()+i,o6.gety(),270,90,25);
        line(o7.getx()+i,o7.gety(),o8.getx()+i,o8.gety());
        line(o8.getx()+i,o8.gety(),o5.getx()+i,o5.gety());

        //wing
        line(w1.getx()+i,w1.gety(),w3.getx()+i,w3.gety());
        line(w3.getx()+i,w3.gety(),w2.getx()+i,w2.gety());
        line(w1.getx()+i,w1.gety(),w2.getx()+i,w2.gety());

        //cabin
        setfillstyle(SOLID_FILL,WHITE);
        circle(n1.getx()+i,n1.gety(),5);
        floodfill(n1.getx()+i,n1.gety(),WHITE);
        circle(n2.getx()+i,n2.gety(),5);
        floodfill(n2.getx()+i,n2.gety(),WHITE);
        circle(n3.getx()+i,n3.gety(),5);
        floodfill(n3.getx()+i,n3.gety(),WHITE);
        circle(n4.getx()+i,n4.gety(),5);
        floodfill(n4.getx()+i,n4.gety(),WHITE);

        //flightdeck
        arc(l1.getx()+i,l1.gety(),170,280,25);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(l2.getx()+i,l2.gety(),WHITE);
        delay(5);
        cleardevice();
    }

    //lifting
    while(i>=300)
    {
        i+=4;
        if(i<440)
        {
            j-=1;
            if(i<310)
            {
                k=-1;
            }
            else if(i<320)
            {
                k=-2;
            }
            else if(i<330)
            {
                k=-3;
            }
            else if(i<340)
            {
                k=-4;
            }
            else if(i<350)
            {
                k=-5;
            }
            else if(i<360)
            {
                k=-6;
            }
            else if(i<370)
            {
                k=-7;
            }
            else if(i<380)
            {
                k=-8;
            }
            else if(i<390)
            {
                k=-9;
            }
            else if(i<400)
            {
                k=-10;
            }
            else if(i<410)
            {
                k=-11;
            }
            else if(i<420)
            {
                k=-12;
            }
            else if(i<430)
            {
                k=-13;
            }
            else if(i<440)
            {
                k=-14;
            }
            else
            {
                k=-15;
            }
        }
        else
        {
            j-=2;
        }

        //rotating the full image
        matrix obj;
        B1=obj.frotatepoint(b1,k,50,500);
        B2=obj.frotatepoint(b2,k,50,500);
        C1=obj.frotatepoint(c1,k,50,500);
        C2=obj.frotatepoint(c2,k,50,500);
        D1=obj.frotatepoint(d1,k,50,500);
        D2=obj.frotatepoint(d2,k,50,500);
        F1=obj.frotatepoint(f1,k,50,500);
        F2=obj.frotatepoint(f2,k,50,500);
        F3=obj.frotatepoint(f3,k,50,500);
        O1=obj.frotatepoint(o1,k,50,500);
        O2=obj.frotatepoint(o2,k,50,500);
        O3=obj.frotatepoint(o3,k,50,500);
        O4=obj.frotatepoint(o4,k,50,500);
        O5=obj.frotatepoint(o5,k,50,500);
        O6=obj.frotatepoint(o6,k,50,500);
        O7=obj.frotatepoint(o7,k,50,500);
        O8=obj.frotatepoint(o8,k,50,500);
        W1=obj.frotatepoint(w1,k,50,500);
        W2=obj.frotatepoint(w2,k,50,500);
        W3=obj.frotatepoint(w3,k,50,500);
        N1=obj.frotatepoint(n1,k,50,500);
        N2=obj.frotatepoint(n2,k,50,500);
        N3=obj.frotatepoint(n3,k,50,500);
        N4=obj.frotatepoint(n4,k,50,500);
        L1=obj.frotatepoint(l1,k,50,500);
        L2=obj.frotatepoint(l2,k,50,500);

        //ground
        line(g1.getx(),g1.gety(),g2.getx(),g2.gety());

        //backwheel1
        pieslice(B1.getx()+i,B1.gety()+j,0,90,10);
        pieslice(B1.getx()+i,B1.gety()+j,180,270,10);
        circle(B1.getx()+i,B1.gety()+j,10);
        line(C1.getx()+i,C1.gety()+j,D1.getx()+i,D1.gety()+j);

        //backwheel2
        pieslice(B2.getx()+i,B2.gety()+j,0,90,10);
        pieslice(B2.getx()+i,B2.gety()+j,180,270,10);
        circle(B2.getx()+i,B2.gety()+j,10);
        line(C2.getx()+i,C2.gety()+j,D2.getx()+i,D2.gety()+j);

        //frontwheel
        pieslice(F1.getx()+i,F1.gety()+j,0,90,10);
        pieslice(F1.getx()+i,F1.gety()+j,180,270,10);
        circle(F1.getx()+i,F1.gety()+j,10);
        line(F2.getx()+i,F2.gety()+j,F3.getx()+i,F3.gety()+j);

        //body
        line(O1.getx()+i,O1.gety()+j,O2.getx()+i,O2.gety()+j);
        line(O1.getx()+i,O1.gety()+j,O3.getx()+i,O3.gety()+j);
        line(O3.getx()+i,O3.gety()+j,O4.getx()+i,O4.gety()+j);
        line(O4.getx()+i,O4.gety()+j,O5.getx()+i,O5.gety()+j);
        arc(O6.getx()+i,O6.gety()+j,270-k,90-k,25);
        line(O7.getx()+i,O7.gety()+j,O8.getx()+i,O8.gety()+j);
        line(O8.getx()+i,O8.gety()+j,O5.getx()+i,O5.gety()+j);

        //wing
        line(W1.getx()+i,W1.gety()+j,W3.getx()+i,W3.gety()+j);
        line(W3.getx()+i,W3.gety()+j,W2.getx()+i,W2.gety()+j);
        line(W1.getx()+i,W1.gety()+j,W2.getx()+i,W2.gety()+j);

        //cabin
        setfillstyle(SOLID_FILL,WHITE);
        circle(N1.getx()+i,N1.gety()+j,5);
        floodfill(N1.getx()+i,N1.gety()+j,WHITE);
        circle(N2.getx()+i,N2.gety()+j,5);
        floodfill(N2.getx()+i,N2.gety()+j,WHITE);
        circle(N3.getx()+i,N3.gety()+j,5);
        floodfill(N3.getx()+i,N3.gety()+j,WHITE);
        circle(N4.getx()+i,N4.gety()+j,5);
        floodfill(N4.getx()+i,N4.gety()+j,WHITE);

        //flightdeck
        arc(L1.getx()+i,L1.gety()+j,170-k,280-k,25);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(L2.getx()+i,L2.gety()+j,WHITE);

        delay(5);
        cleardevice();
    }


    getch();
    closegraph();
    return 0;
}
