#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
#define dbg(x...) \
do { \
    cout << #x << " -> "; \
    err(x); \
} while (0)
 
void err() {
    cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
    cout << fixed << setprecision(10) << arg << ' ';
    err(args...);
}
void solve(){
    int t,d,m;cin>>t>>d>>m;
    vector<int>a(m+1);
    for(int i=1;i<=m;i++)cin>>a[i];
    sort(a.begin()+1,a.end());
    a[0]=0;
    a.push_back(d);
    for(int i=0;i<=m;i++){
        if(a[i+1]-a[i]>=t){
            cout<<"Y\n";
            return ;
        }
    }
    cout<<"N\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
} 