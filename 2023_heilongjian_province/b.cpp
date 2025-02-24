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
	int cnt0,cnt1,tag,l,r;
};
void solve(){
	int n,q;cin>>n>>q;
	string s;cin>>s;
	s=' '+s;
	vector<node>tr(n*4);
	auto up = [&](node x,node y)->node{
		node res={0,0,0,0,0};
		res.l=x.l;
		res.r=y.r;
		if(x.r==y.l){
			if(x.r==0)res.cnt0++;
			else res.cnt1++;
		}
		res.cnt0+=x.cnt0+y.cnt0;
		res.cnt1+=x.cnt1+y.cnt1;
		return res;
	};
	auto cg = [&](node &x)->void{
		x.l=1-x.l;
		x.r=1-x.r;
		swap(x.cnt0,x.cnt1);
		x.tag++;
	};
	auto push_down = [&](int p)->void{
		tr[p].tag%=2;
		if(!tr[p].tag)return ;
		cg(tr[p<<1]);
		cg(tr[p<<1|1]);
		tr[p].tag=0;
	};
	auto build = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			if(s[l]=='1')tr[p].l=tr[p].r=1;
			else tr[p].l=tr[p].r=0;
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int p)->void{
		if(x<=l&&r<=y){
			cg(tr[p]);
			return ;
		}
		int mid=(l+r)>>1;
		push_down(p);
		if(x<=mid)self(self,l,mid,x,y,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
		return ;
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->node{
		if(x<=l&&r<=y)return tr[p];
		push_down(p);
		int mid=(l+r)>>1;
		node res={0,0,0,-1,-1};
		if(x<=mid)res=self(self,l,mid,x,y,p<<1);
		if(y>mid){
			node temp=self(self,mid+1,r,x,y,p<<1|1);
			if(res.l==-1)res=temp;
			else res=up(res,temp);
		}
		return res;
	};
	build(build,1,n,1);
	for(int i=1;i<=q;i++){
		char t;cin>>t;
		int x,y;cin>>x>>y;
		if(t=='Q'){
			node ans=query(query,1,n,x,y,1);
			int res=max(ans.cnt0,ans.cnt1)+1;
			cout<<res<<'\n';
		}else{
			updata(updata,1,n,x,y,1);
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//
	while(t--)solve();
	return 0;
}
/*
首先考虑 01010101 这样左是00 右是11的个数
很显然当我消掉这个极大字串 会产生出新的01(由左右两边合并而来)
那么我是不是可以看成就是这个极大字串不变因为操作都是1,而把左右两边都给消掉一个
那么在这种特殊情况下的答案就是max的(00个数和11个数)+1
考虑推广,对于全0 全1肯定符合
如果左右两边都是00 或者11也是符合
考虑由多个010101 的组成列如
00000001010101111010101111
那么我们在消01的过程中这两01串会慢慢的变成1个 同样的可以推到多个
因此答案就是max的(00个数和11个数)+1
*/