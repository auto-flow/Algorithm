#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <string>
#include <set>
#include <algorithm>
#define LEN 100

using namespace std;

struct hp {
    int len;
    int s[LEN + 1];

    hp() {
        len = 1;
        int i;
        for (i = 1; i <= LEN; i++) {
            s[i] = 0;
        }
    }

    hp(char *ch) {
        int i;
        len = strlen(ch);
        for (i = 1; i <= len; i++)
            s[i] = ch[len - i] - 48;
        for (; i <= LEN; i++)
            s[i] = 0;
    }

    void print() {
        int i;
        for (i = len; i >= 1; i--)
            printf("%d", s[i]);
    }

    string output() {
        int i;
        string ans;
        for (i = len; i >= 1; i--) {
            char buf[100];
            sprintf(buf, "%d", s[i]);
            ans += buf;
        }
        return ans;
    }
};


void multiply(const hp &a, int b, hp &c) {
    int i, len = a.len;
    c = hp();
    for (i = 1; i <= len; i++) {
        c.s[i] += a.s[i] * b;
        c.s[i + 1] += c.s[i] / 10;
        c.s[i] %= 10;
    }
    len++;
    while (c.s[len] >= 10) {    //处理末尾
        c.s[len + 1] += c.s[len] / 10;
        c.s[len] %= 10;
        len++;
    }
    while (len > 1 && c.s[len] == 0) len--;//删除末尾0
    c.len = len;
}

void multiplyh(const hp &a, const hp &b, hp &c) {
    int i, j, len;
    c = hp();
    for (i = 1; i <= a.len; i++) {
        for (j = 1; j <= b.len; j++) {
            c.s[i + j - 1] += a.s[i] * b.s[j];
            c.s[i + j] += c.s[i + j - 1] / 10;
            c.s[i + j - 1] %= 10;
        }
    }
    len = a.len + b.len + 1;
    while (len > 1 && c.s[len] == 0)len--;
    c.len = len;
}

void divide(const hp &a, int b, hp &c, int &d) {
    int i, len = a.len;
    c = hp();
    d = 0;
    for (i = len; i >= 1; i--) {    //在数据结构内部使用逆序，相当于使用正序
        d = d * 10 + a.s[i];
        c.s[i] = d / b;
        d %= b;
    }
    while (len > 1 && c.s[len] == 0) len--;
    c.len = len;
}

int compare(const hp &a, const hp &b) {
    int len = max(a.len, b.len);
    while (len > 0 && a.s[len] == b.s[len]) len--;
    if (len == 0)
        return 0;
    else return a.s[len] - b.s[len];
}

void multiply10(hp &a) {
    int i;
    for (i = a.len; i >= 1; i--)
        a.s[i + 1] = a.s[i];
    a.s[1] = 0;
    a.len++;
    while (a.len > 1 && a.s[a.len] == 0) a.len--;
}

void subtract(const hp &a, const hp &b, hp &c) {
    // 大数-小数，不支持负数
    int i, len = max(a.len, b.len);
    c = hp();
    for (i = 1; i <= len; i++) {
        c.s[i] += a.s[i] - b.s[i];
        if (c.s[i] < 0) {
            c.s[i] += 10;
            c.s[i + 1]--;
        }
    }
    while (len > 1 && c.s[len] == 0) len--;
    c.len = len;
}

void divideh(const hp &a, const hp &b, hp &c, hp &d) {
    hp e;
    int i, len;
    c = hp(), d = hp();
    len = a.len;
    for (i = len; i >= 1; i--) {
        multiply10(d);
        d.s[1] = a.s[i];
        while (compare(d, b) >= 0) { //余数d不断变小，直到等于除数b
            subtract(d, b, e);    //e=d-b
            d = e;                //两部合起来，d-=b
            c.s[i]++;
        }
    }
    while (len > 1 && c.s[len] == 0) len--;
    c.len = len;
}

void plush(const hp &a, const hp &b, hp &c) {
    int i, len;
    c = hp();
    len = max(a.len, b.len);
    for (i = 1; i <= len; i++) {
        c.s[i] += a.s[i] + b.s[i];
        if (c.s[i] >= 10) {
            c.s[i] -= 10;
            c.s[i + 1]++;
        }
    }
    if (c.s[len + 1] > 0) len++;
    c.len = len;
}

int main() {
    int d;
    hp c, D;
//    加法测试 
    plush("999", "999", c);
    if (c.output() == "1998") puts("加法编写正确");
    else puts("加法编写错误");
//    减法测试 
    subtract("2001", "999", c);
    if (c.output() == "1002") puts("减法编写正确");
    else puts("减法编写错误");
//    乘低精度测试 
    multiply("999", 1009, c);
    if (c.output() == "1007991") puts("乘低精度编写正确");
    else puts("乘低精度编写错误");
//    乘高精度测试 
    multiplyh("999", "1009", c);
    if (c.output() == "1007991") puts("乘高精度编写正确");
    else puts("乘高精度编写错误");
//    除低精度测试 
    divide("56090", 123, c, d);
    if (c.output() == "456" && d == 2) puts("除低精度编写正确");
    else puts("除低精度编写错误");
//    除高精度测试 
    divideh("56090", "123", c, D);
    if (c.output() == "456" && D.output() == "2") puts("除高精度编写正确");
    else puts("除高精度编写错误");
    return 0;
}