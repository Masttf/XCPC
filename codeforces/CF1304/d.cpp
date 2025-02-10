#include<bits/stdc++.h>
#define int int long long
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
	string s;cin>>s;
	s=' '+s;
	vector<vector<int>>g(n+1);
	vector<int>d1(n+1);
	for(int i=1;i<n;i++){
		if(s[i]=='>'){
			g[i+1].push_back(i);
			d1[i]++;
		}else{
			g[i].push_back(i+1);
			d1[i+1]++;
		}
	}
	vector ans(3,vector<int>(n+1));
	auto bfs = [&](int t,vector<int>du)->void{
		priority_queue<int,vector<int>,greater<int>>q;
		int now=1;
		int f=1;
		if(t==2)f=-1;
		for(int i=1;i<=n;i++){
			if(du[i]==0){
				q.push(f*i);
			}
		}
		while(!q.empty()){
			int u=q.top();
			q.pop();
			u=f*u;
			ans[t][u]=now;
			now++;
			for(auto v:g[u]){
				du[v]--;
				if(!du[v]){
					q.push(f*v);
				}
			}
		}
	};
	bfs(1,d1);
	bfs(2,d1);
	for(int i=1;i<=n;i++)cout<<ans[2][i]<<" \n"[i==n];
	for(int i=1;i<=n;i++)cout<<ans[1][i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}