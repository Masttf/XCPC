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
const int Max=1e18;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	vector<int>cnt(40);
	map<int,int>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m[a[i]]++;
		cnt[a[i]%36]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		cnt[a[i]%36]--;
		for(int j=0;j<36;j++){
			int d=j;
			if(j==0)d=36;
			__int128 res=a[i];
			while(d){
				res=res*10;
				d/=10;
			}
			res+=j;
			if(j==0)res+=36;
			if(res%36==0){
				if(j<10&&j){
					if(res-=j){
						res=res*10+j;
						if(res%36==0)ans+=cnt[j];
						else ans+=m[j];
					}
				}else ans+=cnt[j];

			}
		}
		cnt[a[i]%36]++;
		//dbg(ans);
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