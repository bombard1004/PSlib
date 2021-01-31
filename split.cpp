// split.cpp
// author bombard1004
// last_update Jan 31 2021

#include <bits/stdc++.h>

std::vector<std::string> split(std::string &inp, char delim) {
    std::stringstream ss(inp);
    std::vector<std::string> ret;

    std::string buf;
    while(std::getline(ss, buf, delim))
        ret.push_back(buf);
    
    return ret;
}
