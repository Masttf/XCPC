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
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	vector<int>premin(n+1);
	for(int i=1;i<=n;i++)premin[i]=min(premin[i-1],pre[i]);
	vector<int>sufmin(n+1);
	sufmin[n]=pre[n];
	for(int i=n-1;i>=1;i--)sufmin[i]=min(sufmin[i+1],pre[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		int d=pre[i-1];
		int dd=pre[n]-pre[i-1];
		if(sufmin[i]-d>=0&&premin[i-1]+dd>=0){
			ans++;
		}
	}
	//-3 2 3 5
	cout<<ans<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}