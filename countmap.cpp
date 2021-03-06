// countmap.cpp
// author bombard1004
// last_update Mar 7 2021

#include <bits/stdc++.h>

template<typename T>
class CountMap {
private:
    std::map<T, int> _cntmap;
    int _totalcnt = 0;

public:
    CountMap() {}

    CountMap(const std::vector<T> &v) {
        for(const T &x : v)
            _cntmap[x]++;
        _totalcnt = v.size();
    }

    void add(const T &x) {
        _cntmap[x]++;
        _totalcnt++;
    }

    void remove(const T &x) {
        if(--_cntmap[x] == 0) {
            _cntmap.erase(x);
        }
        _totalcnt--;
    }

    int count() const {
        return _totalcnt;
    }

    T minElement() const {
        return _cntmap.begin()->first;
    }

    T maxElement() const {
        return _cntmap.rbegin()->first;
    }

    bool empty() const {
        return _cntmap.empty();
    }

    std::vector<T> getElements() const {
        std::vector<T> ret;
        for(auto it = _cntmap.begin(); it != _cntmap.end(); it++)
            ret.push_back(it->first);
        
        return ret;
    }

    int operator[] (const T &x) const {
        auto it = _cntmap.find(x);
        if(it == _cntmap.end()) return 0;
        return it->second;
    }
};
