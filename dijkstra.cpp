#ifndef MY_HEADER
#define MY_HEADER
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to;  
    long long cost;
};
#define vec vector
using lint = long long;
constexpr long long INF64 = 1LL<<61;
using graph = vector<vector<edge>>;
#endif

vector<long long>dijkstra(int s, graph &g) {
    vec<long long>ret(g.size(), INF64);
    priority_queue<pair<lint, lint>>que;
    que.push({-0, s});
    ret[s] = 0;
    vec<bool>went(g.size(), false);
    while(!que.empty()) {
        auto q = que.top();
        que.pop();
        if(went[q.second]) continue;
        went[q.second] = true;
        ret[q.second] = -q.first;
        for(auto&& e: g[q.second]) {
            if(ret[e.to] > -q.first + e.cost) {
                ret[e.to] = -q.first + e.cost;
                que.push({-ret[e.to], e.to});
            }
        }
    }
    return ret;
}