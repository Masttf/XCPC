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
    int n; cin >> n;
    vector<int> a(n + 1);
    vector<int>f(n+1);
    for(int i=1;i<=n;i++)f[i]=i;
    auto find = [&](auto self,int x)->int{
    	return f[x]==x?x:f[x]=self(self,f[x]);
    };
    for(int i = 1; i <= n; i++){
    	cin>>a[i];
    }
    vector<pair<int,int>>ans(n+1);
    map<int,int>m;
    for(int i = n -1;i>=1;i--){
    	vector g(i,vector<int>());
    	for(int j=1;j<=n;j++){
    		g[a[j]%i].push_back(j);
    	}
    	int ff=0;
    	for(int j=0;j<i;j++){
    		m.clear();
    		for(auto v:g[j]){
    			if(!m.empty()){
    				if(!m.count(find(find,v))){
    					ff=1;
    					auto it=m.begin();
    					auto [x,y]=*it;
    					ans[i]={v,y};
    					f[find(find,y)]=v;
    				}
    				if(ff)break;
    			}
    			m[find(find,v)]=v;
    		}
    		if(ff)break;
    	}
    }
	cout<<"Yes\n";
	for(int i=1;i<n;i++){
		auto [x,y]=ans[i];
		cout<<x<<' '<<y<<'\n';
	}
    return ;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;cin>>t;
    while(t--)solve();
    return 0;
}