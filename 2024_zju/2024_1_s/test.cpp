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
const int maxn=1e6+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int>lis;
	lis.push_back(a[1]);
	vector<set<int>>tem(n+1);
	for(int i=2;i<=n;i++){
		if(a[i]>=lis.back())lis.push_back(a[i]);
		else{
			int ps=lower_bound(lis.begin(),lis.end(),a[i])-lis.begin();
			tem[ps].insert(lis[ps]);
			lis[ps]=a[i];
		}
	}
	int ans=lis.size();
	int last=INT_MAX;
	for(int i=ans-1;i>=0;i--){
		if(i!=ans-1)last=lis[i+1];
		int mx=0;
		for(auto it=tem[i].begin();it!=tem[i].end();it++){
			if(*it<last)mx=max(mx,*it);
		}
		dbg(i,mx);
		if(mx){
			lis[i]=mx;
		}
	}
	vector<int>res;
	int p=0;
	for(int i=1;i<=n;i++){
		if(p==ans)break;
		if(a[i]>lis[p])res.push_back(i);
		if(a[i]==lis[p])p++;
	}
	cout<<ans<<' '<<res.size()<<'\n';
	if(!res.empty()){
		for(auto x:res)cout<<x<<' ';
		cout<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}