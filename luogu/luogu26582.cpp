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
struct edge{
	int u,v,w;
	bool operator < (const edge&y)const{
		return w<y.w;
	}
};
void solve(){
    int n,m;cin>>n>>m;
    vector a(n+1,vector<int>(m+1));
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++)cin>>a[i][j];
    }
	auto get = [&](int i,int j)->int{
		return (i-1)*m+j;
	};
	vector<int>sz(n*m+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			if(x==1){
				sz[get(i,j)]=1;
				sum++;
			}
		}
	}
	if(sum<=1){
		cout<<0<<'\n';
		return ;
	}
	vector<int>f(n*m+1);
	for(int i=1;i<=n*m;i++){
		f[i]=i;
	}
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	auto merge = [&](int a,int b)->bool{
		int fa=find(find,a);
		int fb=find(find,b);
		if(fa==fb)return false;
		sz[fb]+=sz[fa];
		f[fa]=fb;
		//dbg(a,b,sz[fa]);
		return sz[fb]==sum;
	};
	vector<edge>e;
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			e.push_back({get(i,j),get(i,j+1),abs(a[i][j]-a[i][j+1])});
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			e.push_back({get(i,j),get(i+1,j),abs(a[i][j]-a[i+1][j])});
		}
	}
	sort(e.begin(),e.end());
	for(auto [u,v,w]:e){
		if(merge(u,v)){
			cout<<w<<'\n';
			return ;
		}
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