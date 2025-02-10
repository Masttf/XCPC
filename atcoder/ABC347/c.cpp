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
const int mod=1e9+7;
const int Max=1e18;
void solve(){
	int n,a,b;cin>>n>>a>>b;
	vector<int>d(n+1);
	for(int i=1;i<=n;i++)cin>>d[i];
	vector<pair<int,int>>res;
	res.push_back({1,a});
	for(int i=n;i>=2;i--)d[i]-=d[i-1];
	for(int i=2;i<=n;i++){
		vector<pair<int,int>>temp;
		for(auto [l,r]:res){
			int mi=l+d[i];
			int mx=r+d[i];
			mi%=(a+b);
			mx%=(a+b);
			if(mx<mi){
				if(mi<=a){
					temp.push_back({mi,a});
				}
				temp.push_back({1,min(a,mx)});
			}else{
				int ll=max(1ll,mi);
				int rr=min(a,mx);
				if(ll<=rr)temp.push_back({ll,rr});
			}
		}
		// for(auto [l,r]:temp){
		// 	dbg(i,l,r);
		// }
		if(temp.empty()){
			cout<<"No\n";
			return ;
		}
		res=temp;
	}
	cout<<"Yes\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}