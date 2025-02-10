#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
#define dbg(x...) \
do{ \
	cout<<#x<<" -> "; \
	err(x); \
}while(0)
void err(){
	cout<<endl;
}
template<class T,class ...Ts>
void err(T arg,Ts ...args){
	cout<<fixed<<setprecision(10)<<arg<<' ';
	err(args...);
}
void solve(){
	int n,x;cin>>n>>x;
	vector<int>a(n+1);
	vector<int>b(n+1);
	vector<pair<int,int>>c(n+1);
	for(int i=1;i<=n;i++)cin>>a[i],c[i].first=a[i],c[i].second=i;
	for(int i=1;i<=n;i++)cin>>b[i];
	sort(b.begin()+1,b.end());
	sort(c.begin()+1,c.end());
	int ok=1;
	vector<int>ans(n+1);
	for(int i=n-x+1,j=1;i<=n&&j<=x;i++,j++){
		ans[c[i].second]=b[j];
		if(c[i].first<=b[j])ok=0;
	}
	if(!ok){
		cout<<"No\n";
		return ;
	}
	multiset<int>s;
	for(int i=x+1;i<=n;i++)s.insert(b[i]);
	for(int i=1;i<=n-x;i++){
		auto it=s.lower_bound(c[i].first);
		if(it==s.end()){
			cout<<"No\n";
			return ;
		}else{
			ans[c[i].second]=*it;
			s.erase(it);
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}