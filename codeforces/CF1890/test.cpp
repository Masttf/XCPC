#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
std::cout << #x << " -> "; \
err(x); \
} while (0)
 
void err() {
    std::cout << std::endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts &... args) {
    std::cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int i=1234567890;
    float f=1.23456789e10;
    cout<<(i==(int)(float)i)<<'\n';
    cout<<(i==(int)(double)i)<<'\n';
    cout<<(f==(float)(int)i)<<'\n';
    cout<<(i==(float)(double)i)<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}