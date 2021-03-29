#include "bits/stdc++.h"

using namespace std;

class PlayGround {
public:
    PlayGround(int a = 1, int b = 2) : a(a), b(b) {}

    void public_play() {
        cout << a << endl;
        cout << b << endl;
        private_play();
    }

private:
    void private_play() {
        a += 1;
        cout << a << endl;
        cout << b << endl;
    }

    int a;
    int b;
};


class Part {
public:
    int value = 666;

    Part(int value = 0) : value(value) {
        cout << "construct part" << endl;
    }

    ~Part() {
        cout << "deconstruct part" << endl;
    }
};

class Total {
public:
    Part p1;
    Part p2;

    Total() {
        cout << "construct total" << endl;
    }

    ~Total() {
        cout << "deconstruct total" << endl;
    }
};


class Base {
public:
//    Part * part=new Part(666);
    Part part = Part(666);

    virtual void func(){
        cout<<"调用父类func"<<endl;
    }

    Base() {
        func();
        cout << part.value << endl;
        cout << "construct Base" << endl;
    }

    ~Base() {
        cout << "deconstruct Base" << endl;
    }
};

class Derived : Base {
public:
    Part part = Part(777);


    void func() override{
        cout<<"调用子类func"<<endl;
    }

    Derived() {
        func();
        cout << part.value << endl;
        cout << "construct Derived" << endl;
    }

    ~Derived() {
        cout << "deconstruct Derived" << endl;
    }
};

int main() {
    Total tt;
    Derived derived;
    int a = 1, b = 2, c = 3;
    a += b += c;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    PlayGround obj;
    obj.public_play();
    // Big Three
    // 拷贝构造
    // 拷贝赋值
    // 析构函数
}