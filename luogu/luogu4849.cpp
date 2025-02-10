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
	int a,b,c,d,val,id,mk;
	bool operator == (const node&y)const{
		return ((a==y.a)&&(b==y.b)&&(c==y.c)&&(d==y.d));
	}
};
bool cmp1 (node&x,node&y){
	if(x.a!=y.a)return x.a<y.a;
	if(x.b!=y.b)return x.b<y.b;
	if(x.c!=y.c)return x.c<y.c;
	return x.d<y.d;
}
const int mod=998244353;
void solve(){
	int n,m;cin>>n>>m;
	vector<node>aa(n+1);
	vector<int>p;
	for(int i=1;i<=n;i++){
		int a,b,c,d,val;cin>>a>>b>>c>>d>>val;
		aa[i]={a,b,c,d,val,0,0};
		p.push_back(d);
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	auto get = [&](int x)->int{
		return lower_bound(p.begin(),p.end(),x)-p.begin()+1;
	};
	sort(aa.begin()+1,aa.end(),cmp1);
	vector<node>res(1);
	for(int i=1;i<=n;i++){
		int j=i;
		int val=0;
		while(j<=n&&aa[i]==aa[j])j++,val+=aa[j].val;
		aa[i].id=res.size();
		aa[i].val=val;
		aa[i].d=get(aa[i].d);
		res.push_back(aa[i]);
	}
	n=res.size()-1;
	vector<pair<int,int>>tr(n*4);
	auto mxx = [&](pair<int,int>x,pair<int,int>y)->pair<int,int>{
		if(x.first<y.first){
			return y;
		}else if(x.first==y.first)x.second=(y.second+x.second)%mod;
		return x;
	};
	auto updata = [&](auto self,int l,int r,int x,pair<int,int> y,int t,int p)->void{
		if(l==r){
			if(!t)tr[p]={0,0};
			else tr[p]=mxx(tr[p],priority_queue);
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,y,t,p<<1);
		else self(self,mid+1,r,x,y,t,p<<1|1);
		tr[p]=mxx(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->pair<int,int>{
		if(x<=l&&r<=y)return tr[p];
		pair<int,int>res={0,0};
		int mid=(l+r)>>1;
		if(x<=mid)res=mxx(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=max(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	vector<pair<int,int>>dp(n+1);
	auto cdq2 = [&](auto self,int l,int r)->void{
		if(l==r){
			dp[res[l].id]=mxx(dp[res[l].id],{res[l].val,1});
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid);
		int i=l,j=mid+1;
		for(;j<=r;j++){
			if(!res[j].mk)continue;
			while(i<=mid&&res[i].c<=res[j].c){
				if(!res[i].mk)updata(updata,1,n,res[i])
				i++;
			}
		}
	};
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}