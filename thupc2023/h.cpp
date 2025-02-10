#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
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
const int maxn=1e6+5;
set<pair<int,int>>t1[maxn];
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='1'){
			t1[s[i]-'0'].insert({i,i});
		}
	}
	if(t1[1].empty()){
		for(int i=1;i<=n;i++){
			cout<<-1<<' '<<0<<'\n';
		}
		return ;
	}
	cout<<(*t1[1].begin()).first<<' '<<t1[1].size()<<'\n';
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

	auto nt = [&](int x)->int{
		return find(find,x)+1;
	};
	vector<int>t(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
			t[x]+=val;
			x+=lowbit(x);
		}
	};

	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=t[x];
			x-=lowbit(x);
		}
		return res;
	};
	
	for(int i=2;i<=n;i++){
		int d=i>>1;
		int x=i%2;
		int sz=t1[d].size();
		int len=__lg(i)+1;
		
		if(t1[i].empty()){
			cout<<-1<<' '<<0<<'\n';
		}else{
			cout<<(*t1[i].begin()).first<<' '<<t1[i].size()<<'\n';

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