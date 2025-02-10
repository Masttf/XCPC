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
    vector<string>a(n);
    int sum=0;
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	int x;cin>>x;
    	sum+=x;
    }
    sort(a.begin(),a.end());
    sum%=n;
    cout<<a[sum]<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}