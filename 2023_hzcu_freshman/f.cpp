#include<bits/stdc++.h>
#define int long long
using namespace std;
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
	int n,k,m,x;cin>>n>>k>>m>>x;
	vector<int>a(n+1);
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	vector<int>val(n+1);
	vector<int>pp(n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		for (int j=1;j<=a[i];j++) {
            sum++;
            val[i]+=(sum+(k-1))/k;
        }
        pp[i]=pp[i-1]+val[i];
	}
	int ans=pp[n];
	vector<pair<int,int>>tt(n+1);
	for(int i=1;i<=n;i++){
		tt[i]={pp[min(n,i+x)]-pp[i],a[i]};
	}
	sort(tt.begin()+1,tt.end(),greater<pair<int,int>>());
	for(int i=1;i<=n&&m;i++){
		int d=tt[i].second;
		int v=tt[i].first;
		if(m>=d){
			ans+=d*v;
			m-=d;
		}else{
			ans+=m*v;
			break;
		}
		//dbg(ans,d,v);
	}
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