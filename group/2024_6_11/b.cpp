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
 	vector<vector<int>>g(n+1);
 	vector<pair<int,int>>temp(m+1);
 	for(int i=1;i<=m;i++){
 		int u,v;cin>>u>>v;
 		g[u].push_back(v);
 		temp[i]={u,v};
 	}
 	vector<int>dfn(n+1),low(n+1);
 	vector<int>stk;
 	vector<int>f(n+1);
 	vector<int>num(n+1);
 	int tot=0;
 	int cnt=0;
 	auto tarjan = [&](auto self,int x)->void{
 		dfn[x]=low[x]=++tot;
 		stk.push_back(x);
 		for(auto v:g[x]){
 			if(!dfn[v]){
 				self(self,v);
 				low[x]=min(low[x],low[v]);
 			}else if(!f[v]){
 				low[x]=min(low[x],dfn[v]);
 			}
 		}
 		if(dfn[x]==low[x]){
 			int y;
 			cnt++;
 			do{
 				y=stk.back();
 				stk.pop_back();
 				f[y]=cnt;
 				num[cnt]++;
 			}while(y!=x);
 		}
 	};
 	for(int i=1;i<=n;i++){
 		if(!dfn[i])tarjan(tarjan,i);
 	}
 	vector<int>du(cnt+1);
 	for(int k=1;k<=m;k++){
 		auto[i,j]=temp[k];
 		int u=f[i],v=f[j];
 		if(u==v)continue;
 		du[u]++;
 		
 	}
 	int ans=0;
 	int ok=0;
 	for(int i=1;i<=cnt;i++){
 		if(!du[i]){
 			ok++;
 			ans=num[i];
 		}
 	}
 	if(ok==1)cout<<ans<<'\n';
 	else cout<<0<<'\n';
 	return ;
 }
 signed main(){
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	int t=1;//cin>>t;
 	while(t--)solve();
 	return 0;
 }