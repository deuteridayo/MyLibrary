#ifndef MY_HEADER
#define MY_HEADER
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int to;  
    long long cost;
};
using graph = vector<vector<edge>>;
#endif

class LCA
{
public:
    LCA(const graph& g, int root = 0): G(g), N(g.size()), Root(root) {
        par.assign(31, vector<int>(N, -1));
        depth.assign(N, 0);
        init();
    }

    int query(int x, int y)
    {
      
        if(depth[x] < depth[y]) return query(y, x);

        for(int d = 30; d >= 0; d--) {
            int p = par[d][x];
            if(p == -1) continue;
            if(depth[p] >= depth[y]) x = p;
        }
        if(x == y) return x;
        for(int d = 30; d >= 0; d--) {
            if(par[d][x] != par[d][y]) {
                x = par[d][x];
                y = par[d][y];
            }
        }

        return par[0][x];
    }

    int getDepth(int v) {
        return depth[v];
    }

private:
    void init(){
        dfs(Root, -1);
        for(int d = 0; d < 30; d++) {
            for(int i = 0; i < N; i++){
                if(par[d][i] == -1) continue;
                par[d+1][i] = par[d][par[d][i]];
            }
        }
    }

    void dfs(int v, int p) {
        par[0][v] = p;
        for(auto e: G[v]) {
            if(e.to == p) continue;
            depth[e.to] = depth[v] + 1;
            dfs(e.to, v);
        }
    }

    vector<vector<int>>par;
    vector<int>depth;
    const graph& G;
    const int N;
    const int Root;
};