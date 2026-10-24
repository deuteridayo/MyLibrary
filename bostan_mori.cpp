#ifndef MY_HEADER
#define MY_HEADER
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
struct edge{
    int to;  
    long long cost;
};
#define vec vector
using lint = long long;
constexpr long long INF64 = 1LL<<61;
using graph = vector<vector<edge>>;
using mint = atcoder::modint998244353;
#endif

mint bostan_mori(lint N, const vec<mint>&P, const vec<mint>&Q) {
    if(N==0) return P[0] / Q[0];

    auto half = [](int mod2, const vec<mint>&P) {
        vec<mint>ret;
        for(int i = mod2; i < P.size(); i+=2) {
            ret.push_back(P[i]);
        }
        return ret;
    };


    vec<mint> mq = Q;
    for(int i = 1; i < mq.size(); i+=2) mq[i] *= -1;

    auto np = half(N%2, atcoder::convolution(P, mq));
    auto nq = half(0, atcoder::convolution(Q, mq));
    return bostan_mori(N/2, np, nq);   
}