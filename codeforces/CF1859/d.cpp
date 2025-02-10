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
	int n;cin>>n;
	vector<int>p;
	vector<array<int,4>>qq(n+1);
	for(int _=1;_<=n;_++){
		int l,r,a,b;cin>>l>>r>>a>>b;
		qq[_]={l,r,a,b};
		p.push_back(a);
		p.push_back(b);
		p.push_back(l);
		p.push_back(r);
	}
	int q;cin>>q;
	vector<int>ans(q+1);
	for(int i=1;i<=q;i++){
		int x;cin>>x;
		ans[i]=x;
		p.push_back(x);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	vector<int>f(p.size()+1);
	for(int i=1;i<=p.size();i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	for(int i=1;i<=n;i++){
		qq[i][0]=get(qq[i][0]);
		qq[i][1]=get(qq[i][1]);
		qq[i][2]=get(qq[i][2]);
		qq[i][3]=get(qq[i][3]);
	}
	for(int _=1;_<=n;_++){
		auto [l,r,a,b]=qq[_];
		for(int i=l;i<=b;){
			int fa=find(find,i);
			int fb=find(find,b);
			i=fa+1;
			if(fa==fb)continue;
			f[fa]=fb;
		}
	}
	for(int i=1;i<=q;i++){
		int res=find(find,get(ans[i]));
		cout<<p[res-1]<<" \n"[i==q];
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