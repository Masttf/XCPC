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
	int n,m,p,q;cin>>n>>m>>p>>q;
	vector<int>f(2*(n+m)+5);
	vector<int>sz1(2*(n+m)+5,1),sz2(2*(n+m)+5,1);
	for(int i=1;i<=2*(n+m)+1;i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	auto merge = [&](int a,int b)->void{
		int fa=find(find,a);
		int fb=find(find,b);
		if(fa==fb)return ;
		f[fa]=fb;
		sz1[fb]+=sz1[fa];
		sz2[fb]+=sz2[fa];
	};
	for(int i=1;i<=p;i++){
		int x,y;cin>>x>>y;
		if(x<0){
			x=n+m+abs(x);
		}
		if(y<0){
			y=n+m+abs(y);
		}
		merge(x,y);
	}
	

	int fa=find(find,1);
	int v1=sz1[fa];
	int v2=sz2[fa];
	for(int i=1;i<=2*(n+m)+1;i++)f[i]=i;
	sz1.assign(2*(n+m)+5,1);
	sz2.assign(2*(n+m)+5,1);
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		if(x<0){
			x=n+m+abs(x);
			
		}
		if(y<0){
			y=n+m+abs(y);
			
		}
		merge(x,y);
	}
	int fb=find(find,n+m+1);
	//dbg(v1,v2);
	cout<<min(v1,sz2[fb])<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}