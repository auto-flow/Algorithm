#include "bits/stdc++.h"

using namespace std;

class Singleton{
public:
    static Singleton& getInstance(){
        return a;
    }

private:
    Singleton();
    Singleton(const Singleton&rhs);
    static Singleton a;
};


int main(){

}