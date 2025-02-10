#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		s=' '+s;
		int res=0;
		for(int j=1;j<=m;j++){
			res=res*2+s[j]-'0';
		}
		//dbg(i,res);
		a[i]=res;
	}
	sort(a.begin()+1,a.end());
	int k=(1ll<<m)-n;
	k=(k+1)/2;
	//dbg(k);
	int l=0,r=(1ll<<m)-1;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		int p=upper_bound(a.begin()+1,a.end(),mid)-a.begin()-1;
		int d=mid-p;
		//dbg(mid,d);
		if(d>=k-1){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	//dbg(n,m);
	vector<int>res(m+1);
	int i=m;
	while(ans){
		res[i]=ans%2;
		ans/=2;
		i--;
	}
	for(i=1;i<=m;i++)cout<<res[i];
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}