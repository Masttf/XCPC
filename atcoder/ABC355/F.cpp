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
struct edge{
	int u,v,w;
	bool operator <(const edge &y)const{
		return w<y.w;
	}
};
void solve(){
	int n,q;cin>>n>>q;
	vector<edge>e;
	vector f(11,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			f[j][i]=i;
		}
	}
	auto find = [&](auto self,int x,int y)->int{
		return f[y][x]==x?x:f[y][x]=self(self,f[y][x],y);
	};
	auto merge = [&](int a,int b,int y)->void{
		int fa=find(find,a,y);
		int fb=find(find,b,y);
		if(fa==fb)return ;
		f[y][fa]=fb;
		return ;
	};
	int sum=0;
	for(int i=1;i<n;i++){
		int u,v,w;cin>>u>>v>>w;
		sum+=w;
		e.push_back({u,v,w});
	}
	sort(e.begin(),e.end());
	for(auto [u,v,w]:e){
		int fa=find(find,u,w);
		int fb=find(find,v,w);
		if(fa!=fb){
			for(int i=w;i<=10;i++){
				merge(u,v,i);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v,w;cin>>u>>v>>w;
		int fa=find(find,u,w);
		int fb=find(find,v,w);
		if(fa!=fb){
			sum+=w;
			for(int j=w;j<=10;j++){
				fa=find(find,u,j);
				fb=find(find,v,j);
				if(fa==fb){
					sum-=j;
					break;
				}
			}
			for(int j=w;j<=10;j++){
				merge(u,v,j);
			}
		}
		cout<<sum<<'\n';
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