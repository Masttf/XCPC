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
	int l,r,val;
};
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(m+1);
	vector<int>p;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		p.push_back(a[i]);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	for(int i=1;i<=m;i++)a[i]=get(a[i]);
	// vector<int>last(n+1);
	// vector<node>tr(m*32);
	// vector<int>root(m+1);
	// int tot=0;
	// auto updata = [&](auto self,int &u,int v,int l,int r,int x,int val)->void{
	// 	u=++tot;
	// 	tr[u]=tr[v];
	// 	if(l==r){
	// 		tr[u].val=val;
	// 		return ;
	// 	}
	// 	int mid=(l+r)>>1;
	// 	if(x<=mid)self(self,tr[u].l,tr[v].l,l,mid,x,val);
	// 	else self(self,tr[u].r,tr[v].r,mid+1,r,x,val);
	// 	tr[u].val=tr[tr[u].l].val+tr[tr[u].r].val;
	// };
	// auto query = [&](auto self,int u,int l,int r,int x,int y)->int{
	// 	if(x<=l&&r<=y)return tr[u].val;
	// 	int res=0;
	// 	int mid=(l+r)>>1;
	// 	if(x<=mid)res+=self(self,tr[u].l,l,mid,x,y);
	// 	if(y>mid)res+=self(self,tr[u].r,mid+1,r,x,y);
	// 	return res;
	// };
	// for(int i=1;i<=m;i++){
	// 	if(last[a[i]]){
	// 		int v;
	// 		updata(updata,v,root[i-1],1,m,last[a[i]],0);
	// 		updata(updata,root[i],v,1,m,i,1);
	// 	}else{
	// 		updata(updata,root[i],root[i-1],1,m,i,1);
	// 	}
	// 	last[a[i]]=i;
	// }
	// //dbg("yes");
	// int ans=0;
	// last.assign(n+1,0);
	// for(int i=1;i<=m;i++){
	// 	//dbg(i);
	// 	if(last[a[i]]){
	// 		int d=query(query,root[i],1,m,last[a[i]],i);
	// 		if(d<=n)ans++;
	// 	}
	// 	last[a[i]]=i;
	// }
	// //dbg(ans);
	// cout<<ans<<'\n';
	set<array<int,3>>s;
	vector<int>last(m+1);
	vector<int>cnt(m+1);
	int ans=0;
	for(int i=1;i<=m;i++){
		if(last[a[i]]){
			ans++;
			auto it=s.find({cnt[a[i]],last[a[i]],a[i]});
			auto [num,time,id]=*it;
			s.erase(it);
			cnt[a[i]]++;
			s.insert({cnt[a[i]],last[a[i]],a[i]});
		}else{
			if(s.size()==n){
				auto it=s.begin();
				auto [num,time,id]=*it;
				s.erase(it);
				last[id]=0;
				cnt[id]=0;
			}
			last[a[i]]=i;
			cnt[a[i]]=1;
			s.insert({cnt[a[i]],last[a[i]],a[i]});
		}
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