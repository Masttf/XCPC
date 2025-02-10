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
    int n,m;cin>>n>>m;
    vector<int>f(n+1);
    for(int i=1;i<=n;i++)f[i]=i;
    auto find = [&](auto self,int x)->int{
    	return f[x]==x?x:f[x]=self(self,f[x]);
    };
    auto merge = [&](int a,int b)->void{
    	int fa=find(find,a);
    	int fb=find(find,b);
    	if(fa==fb)return ;
    	f[fa]=fb;
    };
    vector<pair<int,int>>w(m+1);
    vector<vector<int>>res(m+1);
    for(int i=1;i<=m;i++){
    	int k;cin>>k>>w[i].first;
    	w[i].second=i;
    	for(int j=1;j<=k;j++){
    		int x;cin>>x;
    		res[i].push_back(x);
    	}
    }
    sort(w.begin()+1,w.end());
    int ans=0;
    for(int i=1;i<=m;i++){
    	int now=w[i].second;
    	int sz=res[now].size();
    	for(int j=1;j<sz;j++){
    		int fa=find(find,res[now][0]);
    		int fb=find(find,res[now][j]);
    		if(fa!=fb){
    			f[fa]=fb;
    			ans+=w[i].first;
    		}
    	}
    }
    int ok=0;
    for(int i=1;i<=n;i++){
    	if(find(find,i)==i)ok++;
    }
    if(ok==1)cout<<ans<<'\n';
    else cout<<-1<<'\n';
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;//cin>>t;
    while(t--)solve();
    return 0;
}