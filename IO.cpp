// IO.cpp
// author bombard1004
// last_update Feb 20 2021

#include <bits/stdc++.h>

template <typename T>
T next() {
    T temp; std::cin >> temp;
    return temp;
}

template <>
int next() {
    int temp; scanf("%d", &temp);
    return temp;
}
template <>
long long next() {
    long long temp; scanf("%lld", &temp);
    return temp;
}
template <>
double next() {
    double temp; scanf("%lf", &temp);
    return temp;
}
template <>
float next() {
    float temp; scanf("%d", &temp);
    return temp;
}

template <typename T1, typename T2>
std::pair<T1, T2> next() {
    std::pair<T1, T2> temp;
    temp.first = next<T1>();
    temp.second = next<T2>();
    return temp;
}

template <typename T>
std::vector<T> next(int n) {
    std::vector<T> temp(n);
    for(int i = 0; i < n; i++)
        temp[i] = next<T>();
    return temp;
}

template <typename T1, typename T2>
std::vector<std::pair<T1, T2>> next(int n) {
    std::vector<std::pair<T1, T2>> temp(n);
    for(int i = 0; i < n; i++)
        temp[i] = next<T1, T2>();
    return temp;
}

template <typename T>
void print(const T &x, char endc = '\n') {
    std::cout << x << endc;
    return;
}
void print(const int &x, char endc = '\n') {
    printf("%d%c", x, endc);
    return;
}
void print(const long long &x, char endc = '\n') {
    printf("%lld%c", x, endc);
    return;
}
void print(const size_t &x, char endc = '\n') {
    printf("%zu%c", x, endc);
    return;
}
void print(const float &x, char endc = '\n') {
    printf("%f%c", x, endc);
    return;
}
void print(const double &x, char endc = '\n') {
    printf("%lf%c", x, endc);
    return;
}

template<typename T1, typename T2>
void print(const std::pair<T1, T2> &p, char sepc = ' ', char endc = '\n') {
    print(p.first, sepc);
    print(p.second, endc);
    return;
}

template<typename T>
void print(const std::vector<T> &v, char sepc = ' ', char endc = '\n') {
    for(const T &e : v) print(e, sepc);
    printf("%c", endc);
    return;
}
