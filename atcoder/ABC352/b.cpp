#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)

void err() {
    cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout<<fixed<<setprecision(10)<<arg<< ' ';
    err(args...);
}
void solve(){
    string s,t;cin>>s>>t;
    int n=s.size();
    int m=t.size();
    s=' '+s;
    t=' '+t;
    int l=1;
    for(int i=1;i<=m;i++){
        if(l<=n&&t[i]==s[l]){
            cout<<i<<' ';
            l++;
        }
    }
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}