#include "bits/stdc++.h"

using namespace std;

class Singleton {
private:
    Singleton() {};

    ~Singleton() {};

    Singleton(const Singleton &);

    Singleton &operator=(const Singleton &);

public:
    static Singleton &getInstance() {
        static Singleton instance;
        return instance;
    }
};
// C++11规定了local static在多线程条件下的初始化行为，要求编译器保证了【内部静态变量】的线程安全性
// 在C++11标准下，《Effective C++》提出了一种更优雅的单例模式实现，使用函数内的 【local static】 对象。
// 这样，只有当第一次访问getInstance()方法时才创建实例。这种方法也被称为Meyers’ Singleton