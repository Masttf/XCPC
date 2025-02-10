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
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
struct node{
	int l,r,val,id,cnt;
};
bool cmp1(node &x,node &y){
	if(x.l!=y.l)return x.l<y.l;
	if(x.r!=y.r)return x.r>y.r;
	return x.cnt>y.cnt;
}
bool cmp2(node &x,node &y){
	if(x.r!=y.r)return x.r>y.r;
	return x.cnt>y.cnt;
}
void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>>g(n+1);
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int>l(n+1),r(n+1);
	vector<set<int>>s(n+1);
	auto dfs = [&](auto self,int now,int father)->void{
		s[now].insert(now);
		for(auto v:g[now]){
			if(v==father)continue;
			self(self,v,now);
			if(s[v].size()>s[now].size())swap(s[v],s[now]);
			s[now].insert(s[v].begin(),s[v].end());
		}
		auto it=s[now].lower_bound(now);
		if(it!=s[now].begin()){
			it--;
			l[now]=*it+1;
			it++;
		}else l[now]=1;
		it++;
		if(it!=s[now].end()){
			r[now]=*it-1;
		}else r[now]=n;
	};
	dfs(dfs,1,0);
	vector<node>res(n+m+1);
	for(int i=1;i<=n;i++){
		res[i]={l[i],r[i],i,-1,1};
	}
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		res[n+i]={x,y,0,i,0};
	}
	vector<int>tr(n+1);
	auto updata = [&](int x,int val)->void{
		while(x<=n){
			tr[x]+=val;
			x+=lowbit(x);
		}
	};
	auto ask = [&](int x)->int{
		int res=0;
		while(x){
			res+=tr[x];
			x-=lowbit(x);
		}
		return res;
	};
	sort(res.begin()+1,res.end(),cmp1);
	// for(int i=1;i<=n+m;i++){
	// 	cout<<res[i].cnt<<' '<<res[i].l<<' '<<res[i].r<<' '<<res[i].val<<endl;
	// }
	auto cdq = [&](auto self,int l,int r)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid);
		self(self,mid+1,r);
		//dbg(l,r);
		int i=l,j=mid+1;
		for(;j<=r;j++){
			if(res[j].cnt)continue;
			while(i<=mid&&res[i].r>=res[j].r){
				if(res[i].cnt){
					updata(res[i].val,1);
				}
				i++;
			}
			res[j].val+=ask(res[j].r)-ask(res[j].l-1);
			//dbg(i,res[j].id,res[j].val);
		}
		for(i--;i>=l;i--){
			if(res[i].cnt){
				updata(res[i].val,-1);
			}
		}
		sort(res.begin()+l,res.begin()+r+1,cmp2);
	};
	cdq(cdq,1,n+m);
	vector<int>ans(m+1);
	for(int i=1;i<=n+m;i++){
		if(!res[i].cnt){
			if(res[i].r==res[i].l)ans[res[i].id]=0;
			else ans[res[i].id]=res[i].val;
		}
	}
	// dbg(l[1],r[1]);
	// dbg(l[2],r[2]);
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}