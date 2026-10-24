#ifndef MY_HEADER
#define MY_HEADER
// https://github.com/deuteridayo/MyLibrary を含む場合がある。
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using lint = long long;
using ulint = unsigned long long;
using llint = __int128_t;
struct edge;
using graph = vector<vector<edge>>;
#define endl '\n'
constexpr int INF = 1<<30;
constexpr lint INF64 = 1LL<<61;
constexpr lint mod107 = 1e9+7;
using mint107 = modint1000000007;
constexpr long mod = 998244353;
using mint = modint998244353;
lint ceilDiv(lint x, lint y){if(x >= 0){return (x+y-1)/y;}else{return x/y;}}
lint floorDiv(lint x, lint y){if(x >= 0){return x/y;}else{return (x-y+1)/y;}}
lint Sqrt(lint x) {assert(x >= 0); lint ans = sqrt(x); while(ans*ans > x)ans--; while((ans+1)*(ans+1)<=x)ans++; return ans;}
double Dist(double x1, double y1, double x2, double y2){return sqrt(pow(x1-x2, 2) + pow(y1-y2,2));}
lint DistSqr(lint x1, lint y1, lint x2, lint y2){return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2); }
string toString(lint n){string ans = "";if(n == 0){ans += "0";}else{while(n > 0){int a = n%10;char b = '0' + a;string c = "";c += b;n /= 10;ans = c + ans;}}return ans;}
string toString(lint n, lint k){string ans = toString(n);string tmp = "";while(ans.length() + tmp.length() < k){tmp += "0";}return tmp + ans;}
vector<lint>prime;void makePrime(lint n){prime.push_back(2);for(lint i=3;i<=n;i+=2){bool chk = true;for(lint j=0;j<prime.size() && prime[j]*prime[j] <= i;j++){if(i % prime[j]==0){chk=false;break;}}if(chk)prime.push_back(i);}}
lint Kai[20000001]; bool firstCallnCr = true; 
lint ncrmodp(lint n,lint r,lint p){ if(firstCallnCr){ Kai[0] = 1; for(int i=1;i<=20000000;i++){ Kai[i] = Kai[i-1] * i; Kai[i] %= p;} firstCallnCr = false;} if(n<0)return 0; if(r<0)return 0;
if(n < r)return 0;if(n==0)return 1;lint ans = Kai[n];lint tmp = (Kai[r] * Kai[n-r]) % p;for(lint i=1;i<=p-2;i*=2){if(i & p-2){ans *= tmp;ans %= p;}tmp *= tmp;tmp %= p;}return ans;}
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, x, y) for(int i = x; i < y; i++)
#define rrep(i, x) for(int i = x-1; i >= 0; i--)
#define vec vector
#define pb push_back
#define eb emplace_back
#define se second
#define fi first
#define al(x) x.begin(),x.end()
#define ral(x) x.rbegin(),x.rend()


struct edge{
    edge(lint v, lint c = 1) {to = v, cost = c;}
    lint to;
    lint cost;
};

#endif


int main(){

}

