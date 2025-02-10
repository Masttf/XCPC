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
	int mi=INT_MAX;
	map<int,int>m;
	for(int i=1;i<=n;i++)mi=min(a[i],mi),m[a[i]]++;
	auto dfs = [&](auto self)->int{
		
		int cnt=0;
		int tot=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				tot++;
				int temp=mi;
				mi=min(mi,a[i]-1);
				m[a[i]]--;
				m[a[i]-1]++;
				a[i]--;
				if(n>2*m[mi])cnt+=self(self);
				mi=temp;
				a[i]++;
				m[a[i]]++;
				m[a[i]-1]--;
			}
		}
		int res=0;
		if(cnt)res=0;
		else res=1;
		// for(int i=1;i<=n;i++){
		// 	cout<<a[i]<<" \n"[i==n];
		// }
		// dbg(res);
		return res;
	};
	int res=dfs(dfs);
	if(res==0)cout<<"Cat\n";
	else cout<<"Dog\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}