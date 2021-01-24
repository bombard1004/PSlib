#include <bits/stdc++.h>

using namespace std;

bool inRange(int target, int r1, int r2) {
    int minR = min(r1, r2), maxR = max(r1, r2);
    return target >= minR && target <= maxR;
}

int ceilGauss(int a, int b) {
    return (a + b - 1) / b;
}

void removeFromMap(map<int, int> &m, int target) {
    if(--m[target] == 0) {
        m.erase(target);
    }
}