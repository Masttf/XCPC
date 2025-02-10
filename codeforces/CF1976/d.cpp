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
	string s;cin>>s;
	int n=s.size();
	s=' '+s;
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(s[i]=='(')pre[i]++;
		else pre[i]--;
	}
	vector st(25,vector<int>(n+1));
	for(int i=1;i<=n;i++)st[0][i]=pre[i];
	for(int s=1;(1ll<<s)<=n;s++){
		for(int i=1;i+(1ll<<s)-1<=n;i++){
			st[s][i]=max(st[s-1][i],st[s-1][i+(1ll<<(s-1))]);
		}
	}
	auto get = [&](int l,int r)->int{
		int len=r-l+1;
		int d=__lg(len);
		return max(st[d][l],st[d][r-(1ll<<d)+1]);
	};
	int ans=0;
	vector<deque<int>>q(n+1);
	for(int i=1;i<=n;i++){
		while(!q[pre[i]].empty()&&get(q[pre[i]].front(),i)>2*pre[i]){
			q[pre[i]].pop_front();
		}
		ans+=q[pre[i]].size();
		q[pre[i]].push_back(i);
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