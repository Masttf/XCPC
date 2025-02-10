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
    int n; cin>>n;
    string a;cin>>a;
    string b;cin>>b;
    a=' '+a;
    b=' '+b;
    int cnt1=0;
    int cnt2=0;
    for(int i=1;i<=n;i++){
    	if(a[i]=='0')cnt1++;
    	else break;
    }
    for(int i=1;i<=n;i++){
    	if(b[i]=='0')cnt2++;
    	else break;
    }
    if(cnt1<=cnt2)cout<<"Yes\n";
    else cout<<"No\n";
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}