#ifndef MY_HEADER
#define MY_HEADER
#include<bits/stdc++.h>
using namespace std;
using lint = long long;
#endif

struct Frac {
    lint upper, lower;
    Frac() {
        Frac(0,1);
    }
    Frac(lint u, lint l) {
        assert(l != 0);
        if(u <= 0 && l < 0) {
            upper = -u;
            lower = -l;
        } else {
            upper = u;
            lower = l;
        }
        reduction();
    }

    Frac(lint u) {
        upper = u;
        lower = 1;
    } 

    void reduction() {
        if(upper != 0) {
            lint g = gcd(abs(upper), abs(lower));
            upper /= g;
            lower /= g;
        
            if(lower < 0) {
                lower *= -1;
                upper *= -1;
            }
        } else {
            lower = 1;
        }
    }

    Frac operator+(const Frac &other) {
        lint L = lower * other.lower;
        lint U = upper*other.lower + lower*other.upper;
        return Frac(U, L);
    }

    Frac operator-(const Frac &other) {
        lint L = lower * other.lower;
        lint U = upper*other.lower - lower*other.upper;
        upper = U;
        lower = L;
        return Frac(U, L);
    }

    bool operator<=(const Frac &other) {
        return upper*other.lower <= lower*other.upper;
    }

    Frac operator*(const Frac &other) {
        lint L = lower * other.lower;
        lint U = upper * other.upper;
        return Frac(U, L);
    }

    Frac operator/(const Frac &other) {
        assert(other.upper != 0);
        lint L = lower * other.upper;
        lint U = upper * other.lower;
        return Frac(U, L);
    }
};