#include <bits/stdc++.h>

using namespace std;

int nextInt() {
    int temp; scanf("%d", &temp);
    return temp;
}

void printPair(pair<int, int> &p) {
    printf("%d %d\n", p.first, p.second);
    return;
}

void printVector(vector<int> &v) {
    for(int e : v) printf("%d ", e);
    puts("");
    return;
}

void printInt(int x) {
    printf("%d\n", x);
    return;
}
void printInt(long long x) {
    printf("%lld\n", x);
    return;
}
void printInt(size_t x) {
    printf("%zu\n", x);
    return;
}