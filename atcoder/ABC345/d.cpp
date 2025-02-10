#include <bits/stdc++.h>

#if defined (_WIN64)
#pragma clang diagnostic ignored "-Wunused-value"
// #pragma clang diagnostic ignored "-Wshift-op-parentheses"
#define LOG(x) if(!(x)){std::cout<<"error at:"<<__LINE__<<std::endl;exit(-1);}
#else
#define LOG(x)
#endif
#define int long long
#define rep(i,b,e) for(int i=b;i<(int)(e);++i)
#define range(i,b,e,step) for(int i=b;(b<e?i<e:i>e);i+=(b<e?step:-step))
#define RETURN(x) do{return x,void();}while(0);
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define inf INT_MAX
#define INF LONG_LONG_MAX;
template <class T>using vec=std::vector<T>;
template<class K,class V> using umap=std::unordered_map<K,V>;
template<class T>std::istream& operator>>(std::istream&in,std::vector<T>&v) 
{for(auto &i:v)in>>i;return in;}template<class T>std::ostream& 
operator<<(std::ostream&out,const std::vector<T>&v) {
for(auto i=v.begin();i!=v.end();++i)out<<*i<<" \n"[i==v.end()];
return out;}template<class T,class FUN>void foreach
(std::vector<T>&v,FUN fun){for(int i=0;i<v.size();++i)fun(v[i],i);}
template <class T>void sort(std::vector<T>&v) {std::sort(v.begin(),v.end());}
template <class T,class FUN>void sort(std::vector<T>&v,FUN fun) 
{std::sort(v.begin(),v.end(),fun);}template<class T>void input
(T begin,T end){while(begin!=end)std::cin>>*begin++;}
using Pii = std::pair<int, int>;

vec<vec<bool>> a;
vec<Pii> v;
int k, n, m;
void dfs(vec<bool> &p);
void check(int x, int y, int p, vec<bool> &P) {
    if(x + v[p].first - 1 > n || y + v[p].second - 1 > m) goto A;
    rep(i, x, x + v[p].first) {
        rep(j, y, y + v[p].second) {
            if(a[i][j]) goto A;
        }
    }
    rep(i, x, x + v[p].first) {
        rep(j, y, y + v[p].second) {
            a[i][j] = 1;
        }
    }
    
    dfs(P);
    rep(i, x, x + v[p].first) {
        rep(j, y, y + v[p].second) {
            a[i][j] = 0;
        }
    }
    A:;
    if(x + v[p].second - 1 > n || y + v[p].first - 1 > m) return;
    rep(i, x, x + v[p].second) {
        rep(j, y, y + v[p].first) {
            if(a[i][j]) return ;
        }
    }
    rep(i, x, x + v[p].second) {
        rep(j, y, y + v[p].first) {
            a[i][j] = 1;
        }
    }
    dfs(P);
    rep(i, x, x + v[p].second) {
        rep(j, y, y + v[p].first) {
            a[i][j] = 0;
        }
    }
}

void dfs(vec<bool> &p) {
    int X, Y;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            if(!a[i][j]) {
                X = i, Y = j;
                goto A;
            }
        }
    }
    std::cout << "Yes\n";
    exit(0);
    A:;
    rep(i, 0, k) {
        if(p[i]) continue;
        p[i] = 1;
        check(X, Y, i,  p);
        p[i] = 0;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> k >> n >> m;
    a.assign(n + 1, vec<bool>(m + 1));
    rep(i, 0, k) {
        Pii x;
        std::cin >> x.first >> x.second;
        v.pb(x);
    }
    vec<bool> p(k);
    dfs(p);
    std::cout << "No\n";

    return 0;
}