#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <conio.h>
#include <iostream>
#include <math.h>
#include <p2D.h>

class matrix
{
    public:
        double v[3][3];
        matrix();
        matrix(double[]);
        void settranslation(double,double);
        void setrotation(int);
        void setscaling(double,double);
        void fscaling(double,double,double,double);
        void frotate(int,double,double);
        void RFx();
        void RFy();
        void RFxy();
        void RFmx();
        void SHx(double);
        void SHx2(double,double);
        void SHy(double);
        void SHy2(double,double);
        matrix mul(matrix,matrix);
        void print();
        pnt2ds mulpntmat(pnt2ds,matrix);
        matrix translate(matrix,double,double);
        pnt2ds transpoint(pnt2ds,double,double);
        pnt2ds scalpoint(pnt2ds,double,double);
        pnt2ds rotatepoint(pnt2ds,int);
        pnt2ds fscalpoint(pnt2ds,double,double,double,double);
        pnt2ds frotatepoint(pnt2ds,int,double,double);
        pnt2ds RFxpoint(pnt2ds);
        pnt2ds RFypoint(pnt2ds);
        pnt2ds RFxypoint(pnt2ds);
        pnt2ds RFmxpoint(pnt2ds);
        pnt2ds SHxpoint(pnt2ds,double);
        pnt2ds SHx2point(pnt2ds,double,double);
        pnt2ds SHypoint(pnt2ds,double);
        pnt2ds SHy2point(pnt2ds,double,double);
};

matrix::matrix()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            v[i][j]=0;
        }
    }
}

matrix::matrix(double arr[])
{
    int i=0;
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                v[m][n]=arr[i];
                i++;
            }
        }
}
void matrix::settranslation(double tx,double ty)
{
    v[0][0]=1;
    v[1][1]=1;
    v[0][2]=tx;
    v[1][2]=ty;
    v[2][2]=1;
}
void matrix::setrotation(int deg)
{
    double theta=(M_PI/180)*deg;
    v[0][0]=cos(theta);
    v[0][1]=-sin(theta);
    v[1][0]=sin(theta);
    v[1][1]=cos(theta);
    v[2][2]=1;
}
void matrix::setscaling(double sx,double sy)
{
    v[0][0]=sx;
    v[1][1]=sy;
}
void matrix::fscaling(double sx1,double sy1,double xf,double yf)
{
    double x1 = (1-sx1)*xf;
    double y1 = (1-sy1)*yf;
    v[0][0]=sx1;
    v[0][2]=x1;
    v[1][2]=y1;
    v[1][1]=sy1;
    v[2][2]=1;
}
void matrix::frotate(int deg,double xr,double yr)
{
    double theta=(M_PI/180)*deg;
    double z1 = (xr*(1-cos(theta)))+(yr*sin(theta));
    double z2 = (yr*(1-cos(theta)))-(xr*sin(theta));
    v[0][0]=cos(theta);
    v[0][1]=-sin(theta);
    v[0][2]=z1;
    v[1][0]=sin(theta);
    v[1][1]=cos(theta);
    v[1][2]=z2;
    v[2][2]=1;
}
void matrix::RFx()
{
    v[0][0]=1;
    v[1][2]=-1;
    v[2][2]=1;
}
void matrix::RFy()
{
    v[0][0]=-1;
    v[1][2]=1;
    v[2][2]=1;
}
void matrix::RFxy()
{
    v[0][1]=1;
    v[1][0]=1;
    v[2][2]=1;
}
void matrix::RFmx()
{
    v[0][0]=-1;
    v[1][1]=-1;
    v[2][2]=1;
}
void matrix::SHx(double shx)
{
    v[0][0]=1;
    v[0][1]=shx;
    v[1][1]=1;
    v[2][2]=1;
}
void matrix::SHx2(double shx,double yref)
{
    double x2 = -shx*yref;
    v[0][0]=1;
    v[0][1]=shx;
    v[0][2]=x2;
    v[1][1]=1;
    v[2][2]=1;
}
void matrix::SHy(double shy)
{
    v[0][0]=1;
    v[1][0]=shy;
    v[1][1]=1;
    v[2][2]=1;
}
void matrix::SHy2(double shy,double xref)
{
    double y2 = -shy*xref;
    v[0][0]=1;
    v[0][1]=shy;
    v[1][2]=y2;
    v[1][1]=1;
    v[2][2]=1;
}
matrix matrix::mul(matrix a,matrix b)
{
    matrix result;
    for(int k=0;k<3;k++)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                result.v[k][i]+=(a.v[k][j]*b.v[j][i]);
            }
        }
    }
return result;
}
void matrix::print()
{
    for(int m=0;m<3;m++)
    {
        for(int n=0;n<3;n++)
        {
            cout<<v[m][n];
        }
        cout<<endl;
    }
}
pnt2ds matrix::mulpntmat(pnt2ds m,matrix f)
{
    pnt2ds n;
    n.x=(f.v[0][0]*m.x)+(f.v[0][1]*m.y)+(f.v[0][2]*m.w);
    n.y=(f.v[1][0]*m.x)+(f.v[1][1]*m.y)+(f.v[1][2]*m.w);
    n.w=1;
    return n;
}
matrix matrix::translate(matrix e,double s,double n)
{
    matrix b,d,c;
    b.settranslation(s,n);
    d=c.mul(b,e);
    return d;
}
pnt2ds matrix::transpoint(pnt2ds g,double tx,double ty)
{
    pnt2ds res;
    matrix a,c;
    a.settranslation(tx,ty);
    res=c.mulpntmat(g,a);
    return res;
}
pnt2ds matrix::scalpoint(pnt2ds h,double sx,double sy)
{
    pnt2ds sres;
    matrix a,c;
    a.setscaling(sx,sy);
    sres=c.mulpntmat(h,a);
    return sres;
}
pnt2ds matrix::rotatepoint(pnt2ds j,int deg)
{
    pnt2ds rers;
    matrix a,c;
    a.setrotation(deg);
    rers=c.mulpntmat(j,a);
    return rers;
}
pnt2ds matrix::fscalpoint(pnt2ds n,double sx1,double sy1,double xf,double yf)
{
    pnt2ds res;
    matrix a,c;
    a.fscaling(sx1,sy1,xf,yf);
    res=c.mulpntmat(n,a);
    return res;
}
pnt2ds matrix::frotatepoint(pnt2ds n,int deg,double xr,double yr)
{
    pnt2ds res;
    matrix a,c;
    a.frotate(deg,xr,yr);
    res=c.mulpntmat(n,a);
    return res;
}
pnt2ds matrix::RFxpoint(pnt2ds j)
{
    pnt2ds rers;
    matrix a,c;
    a.RFx();
    rers=c.mulpntmat(j,a);
    return rers;
}
pnt2ds matrix::RFypoint(pnt2ds j)
{
    pnt2ds rers;
    matrix a,c;
    a.RFy();
    rers=c.mulpntmat(j,a);
    return rers;
}
pnt2ds matrix::RFxypoint(pnt2ds j)
{
    pnt2ds rers;
    matrix a,c;
    a.RFxy();
    rers=c.mulpntmat(j,a);
    return rers;
}
pnt2ds matrix::RFmxpoint(pnt2ds j)
{
    pnt2ds rers;
    matrix a,c;
    a.RFmx();
    rers=c.mulpntmat(j,a);
    return rers;
}
pnt2ds matrix::SHxpoint(pnt2ds j,double shx)
{
    pnt2ds re;
    matrix a,c;
    a.SHx(shx);
    re=c.mulpntmat(j,a);
    return re;
}
pnt2ds matrix::SHx2point(pnt2ds j,double shx,double yref)
{
    pnt2ds re;
    matrix a,c;
    a.SHx2(shx,yref);
    re=c.mulpntmat(j,a);
    return re;
}
pnt2ds matrix::SHypoint(pnt2ds q,double shy)
{
    pnt2ds re;
    matrix a,c;
    a.SHy(shy);
    re=c.mulpntmat(q,a);
    return re;
}
pnt2ds matrix::SHy2point(pnt2ds j,double shy,double xref)
{
    pnt2ds re;
    matrix a,c;
    a.SHy2(shy,xref);
    re=c.mulpntmat(j,a);
    return re;
}


#endif // MATRIX_H_INCLUDED
