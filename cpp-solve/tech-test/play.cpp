#include "bits/stdc++.h"

using  namespace std;

class Point
{ public:
    Point(int a=3,int b=5){ X=a;Y=b;}
    int GetX(){return X;}
    int GetY(){return Y;}
private:
    int  X,Y;};

int main(){
    Point *p=new Point[2];
    cout<<p[0].GetX();
}

//
// Created by tqc on 2021/3/11.
//

