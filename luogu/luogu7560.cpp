#include<bits/stdc++.h>
#define int int long long
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
	int l,r,k;
};
struct node2{
	int tag,mi,mx;
};
struct qnode{
	int i,id,k;
};
void solve(){
	int n,m,q;cin>>n>>m>>q;
	vector b1(n+5,vector<node>());
	vector b2(n+5,vector<node>());
	vector<vector<qnode>>d(n+5);
	vector<int>color(q+5);
	int cnt=0;
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int l,r,c,k;cin>>l>>r>>c>>k;
			color[i]=c;
			b1[l].push_back({i,q,k});
			b1[r+1].push_back({i,q,-k});
		}else if(t==2){
			int l,r,k;cin>>l>>r>>k;
			b2[l].push_back({i,q,-k});
			b2[r+1].push_back({i,q,k});
		}else{
			int x,k;cin>>x>>k;
			cnt++;
			d[x].push_back({i,cnt,k});
		}
	}
	vector tr(2,vector<node2>(q*4));
	auto cg = [&](node2 &x,int val)->void{
		x.mi+=val;
		x.mx+=val;
		x.tag+=val;
	};
	auto down = [&](int p,int t)->void{
		if(tr[t][p].tag==0)return ;
		cg(tr[t][p<<1],tr[t][p].tag);
		cg(tr[t][p<<1|1],tr[t][p].tag);
		tr[t][p].tag=0;
	};
	auto merge = [&](node2 x,node2 y)->node2{
		node2 res={0,0,0};
		res.mi=min(x.mi,y.mi);
		res.mx=max(x.mx,y.mx);
		return res;
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int val,int p,int t)->void{
		if(x<=l&&r<=y){
			cg(tr[t][p],val);
			return ;
		}
		down(p,t);
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,val,p<<1,t);
		if(y>mid)self(self,mid+1,r,x,y,val,p<<1|1,t);
		tr[t][p]=merge(tr[t][p<<1],tr[t][p<<1|1]);
		return ;
	};
	auto get_sum= [&](auto self,int l,int r,int x,int p)->pair<int,int>{
		if(l==r) return {tr[0][p].mx,tr[1][p].mi};
		int mid=(l+r)>>1;
		down(p,0);
		down(p,1);
		if(x<=mid)return self(self,l,mid,x,p<<1);
		else return self(self,mid+1,r,x,p<<1|1);
	};
	auto get_mi = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(x<=l&&r<=y) return tr[1][p].mi;
		int res=0;
		int mid=(l+r)>>1;
		if(x<=mid)res=min(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=min(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	auto query = [&](auto self,int l,int r,int k,int p)->int{
		if(l==r)return l;
		down(p,0);
		int mid=(l+r)>>1;
		int d=tr[0][p<<1].mx;
		if(k<=d)return self(self,l,mid,k,p<<1);
		else return self(self,mid+1,r,k,p<<1|1);
	};
	vector<int>ans(cnt+1);
	for(int i=1;i<=n;i++){
		for(auto [l,r,k]:b1[i]){
			updata(updata,1,q,l,r,k,1,0);
			updata(updata,1,q,l,r,k,1,1);
		}
		for(auto [l,r,k]:b2[i]){
			updata(updata,1,q,l,r,k,1,1);
		}
		for(auto [id,qid,k]:d[i]){
			auto [w,ww]=get_sum(get_sum,1,q,id,1);
			int mi=get_mi(get_mi,1,q,1,id,1);
			mi=min(mi,0ll);
			k+=w-ww+mi;
			if(k>w)continue;
			int p=query(query,1,q,k,1);
			ans[qid]=color[p];
		}
	}
	for(int i=1;i<=cnt;i++)cout<<ans[i]<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}