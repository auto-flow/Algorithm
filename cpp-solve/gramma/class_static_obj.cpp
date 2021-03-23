#include "bits/stdc++.h"

using namespace std;

class Myclass {
public:
    Myclass(int a, int b, int c);

    void GetSum();

private:
    int a, b, c;
    static int Sum;//声明静态数据成员
};

int Myclass::Sum = 0;    //定义并初始化静态数据成员

Myclass::Myclass(int a, int b, int c) {
    this->a = a;
    this->b = b;
    this->c = c;
    Sum += a + b + c;
}

void Myclass::GetSum() {
    cout << "Sum=" << Sum << endl;
}

int main() {
    Myclass M(1, 2, 3);
    M.GetSum();
    Myclass N(4, 5, 6);
    N.GetSum();
    M.GetSum();
}
// 无论这个类的对象被定义了多少个，静态成员变量只分配一次内存
// 静态数据成员的值对每个对象都是一样的，它的值可以更新；
// sizeof 运算符不会计算 静态成员变量。
