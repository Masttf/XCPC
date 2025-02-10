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
struct node{
	int x,y,z,id;
};
bool cmp1(node x,node y){
	return x.x<y.x;
}
bool cmp2(node x,node y){
	return x.y<y.y;
}
bool cmp3(node x,node y){
	return x.z<y.z;
}
struct edge{
	int u,v,w;
	bool operator <(const edge&y)const{
		return w<y.w;
	}
};
void solve(){
	int n;cin>>n;
	vector<node>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].id=i;
	}
	vector<edge>e;
	sort(a.begin()+1,a.end(),cmp1);
	for(int i=1;i<n;i++){
		e.push_back({a[i].id,a[i+1].id,a[i+1].x-a[i].x});
	}
	sort(a.begin()+1,a.end(),cmp2);
	for(int i=1;i<n;i++){
		e.push_back({a[i].id,a[i+1].id,a[i+1].y-a[i].y});
	}
	sort(a.begin()+1,a.end(),cmp3);
	for(int i=1;i<n;i++){
		e.push_back({a[i].id,a[i+1].id,a[i+1].z-a[i].z});
	}
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
	int ans=0;
	sort(e.begin(),e.end());
	for(auto [u,v,w]:e){
		int fa=find(find,u);
		int fb=find(find,v);
		if(fa==fb)continue;
		f[fa]=fb;
		ans+=w;
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}