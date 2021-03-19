#include<bits/stdc++.h>

using namespace std;
int a[101], b[101], c[101];

int main(void) {
    int lena, lenb, lenc;
    string s1, s2;
    cin >> s1 >> s2;
    lena = s1.length();
    lenb = s2.length();

    //将上述字符串以int型数据存入数组
    //因为减法是从个位算起，所以存储时到倒着存
    for (int i = 1; i <= lena; i++) {
        a[i] = s1[lena - i] - '0';//以数字存储
    }
    for (int j = 1; j <= lenb; j++) {
        b[j] = s2[lenb - j] - '0';//以数字存储
    }

    //开始模拟减法并将数据存入c数组
    lenc = lena;
    for (int p = 1; p <= lenc; p++) {
        //同位相减，不够减时
        if (a[p] < b[p]) {
            a[p + 1]--;//向高位借1
            a[p] += 10;//此时同位加10
        }
        c[p] = a[p] - b[p];
    }
    //处理c数组的前导0
    while (c[lenc] == 0 && lenc > 1)
        lenc--;

    //确定好c数组的位数后，就可以倒序输出了
    for (int q = lenc; q >= 1; q--) {
        cout << c[q];
    }
    return 0;
}
