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
	int n,q;cin>>n>>q;
	string s;cin>>s;
	s=' '+s;
	s+=' ';
	vector<int>pre(n+1);
	vector<int>suf(n+5);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(s[i]=='1'){
			pre[i]+=(s[i-1]=='1'?0:1);
		}
	}
	for(int i=n;i>=1;i--){
		suf[i]=suf[i+1];
		if(s[i]=='1'){
			suf[i]+=(s[i+1]=='1'?0:1);
		}
	}
	for(int i=1;i<=q;i++){
		int l,r;cin>>l>>r;
		int ans=pre[n];

		if(s[l-1]!='1'&&s[l]=='1')ans--;
		if(s[r]=='1'&&s[r+1]!='1')ans--;
		if(s[l-1]!='1'&&s[r]=='1')ans++;
		if(s[r+1]!='1'&&s[l]=='1')ans++;
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}