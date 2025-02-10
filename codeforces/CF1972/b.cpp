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
    int n;cin>>n;
    string s;cin>>s;
    int ok=0;
    int tot=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U')ok=1,tot++;
    }
    if(tot%2==0){
        cout<<"NO\n";
    }else cout<<"YES\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}