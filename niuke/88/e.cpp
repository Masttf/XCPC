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
const int Max=1e18;
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
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
		return ;
	};
	map<int,int>s;
	for(int i=1;i<=n;i++){
		if(s.count(a[i])){
			merge(i,s[a[i]]);
			int f=find(find,i);
			s[a[i]]=f;
		}else s[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		if(!s.count(x))continue;
		if(x==y)continue;
		if(s.count(y)){
			int d=s[y];
			//dbg(s[x],s[y]);
			merge(s[x],s[y]);
			s[y]=find(find,d);
			//dbg(s[y]);
			s.erase(x);
		}else{
			s[y]=s[x];
			s.erase(x);
		}
	}
	map<int,int>ss;
	for(auto [x,y]:s){
		ss[y]=x;
		//dbg(x,y);
	}
	for(int i=1;i<=n;i++){
		int f=find(find,i);
		cout<<ss[f]<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}