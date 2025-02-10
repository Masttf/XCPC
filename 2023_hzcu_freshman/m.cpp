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
	int n,m;cin>>n>>m;
	string s;cin>>s;
	s=' '+s;
	int now=1;
	int ans=m-1;
	vector<int>p(m+1);
	vector<int>pre(m+1);
	vector<int>ps(m+1);
	for(int i=1;i<=m;i++){
		pre[i]=pre[i-1];
		if(s[i]=='L'){
			pre[i]++;
			if(now!=1)now--;
		}else{
			if(now!=n)now++;
		}
		p[i]=now;
		ps[pre[i]]=i;
	}
	auto check = [&](int x,int i)->bool{
		int d=ps[x];
		if(p[d]+i-d>=n)return true;
		else return false;
	};
	for(int i=n-1;i<=m;i++){
		int l=0,r=pre[i];
		int res=r;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(pre[i]-mid,i)){
				r=mid-1;
				res=mid;
			}else l=mid+1;
		}
		ans=min(ans,res);
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}