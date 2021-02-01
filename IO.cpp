// IO.cpp
// author bombard1004
// last_update Feb 1 2021

#include <bits/stdc++.h>

int nextInt() {
    int temp; scanf("%d", &temp);
    return temp;
}
long long nextLL() {
    long long temp; scanf("%lld", &temp);
    return temp;
}

void print(int x, char endc = '\n') {
    printf("%d%c", x, endc);
    return;
}
void print(long long x, char endc = '\n') {
    printf("%lld%c", x, endc);
    return;
}
void print(size_t x, char endc = '\n') {
    printf("%zu%c", x, endc);
    return;
}
void print(float x, char endc = '\n') {
    printf("%f%c", x, endc);
    return;
}
void print(double x, char endc = '\n') {
    printf("%lf%c", x, endc);
    return;
}

template<typename T1, typename T2>
void print(std::pair<T1, T2> &p, char sepc = ' ', char endc = '\n') {
    print(p.first, sepc);
    print(p.second, endc);
    return;
}

template<typename T>
void print(std::vector<T> &v, char sepc = ' ', char endc = '\n') {
    for(T e : v) print(e, sepc);
    printf("%c", endc);
    return;
}
