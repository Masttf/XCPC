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
struct node{
	int x,y1,y2,id,val,f,ty;
};
bool cmp1(node x,node y){
	if(x.x!=y.x)return x.x<y.x;
	return x.ty<y.ty;
}
struct tnode{
	int sum,tag;
};
void solve(){
	char t;int n,m;
	cin>>t>>n>>m;
	vector<tnode>tr((2050)*4);
	auto cg = [&](tnode &x,int val,int l,int r)->void{
		x.sum+=(r-l+1ll)*val;
		x.tag+=val;
	};
	auto up = [&](tnode x,tnode y)->tnode{
		tnode res={0ll,0ll};
		res.sum=x.sum+y.sum;
		return res;
	};
	auto down = [&](int p,int l,int r)->void{
		if(tr[p].tag==0)return ;
		int mid=(l+r)>>1;
		cg(tr[p<<1],tr[p].tag,l,mid);
		cg(tr[p<<1|1],tr[p].tag,mid+1,r);
		tr[p].tag=0;
	};
	auto updata = [&](auto self,int l,int r,int x,int y,int val,int p)->void{
		if(x<=l&&r<=y){
			cg(tr[p],val,l,r);
			return ;
		}
		int mid=(l+r)>>1;
		down(p,l,r);
		if(x<=mid)self(self,l,mid,x,y,val,p<<1);
		if(y>mid)self(self,mid+1,r,x,y,val,p<<1|1);
		tr[p]=up(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(x<=l&&r<=y)return tr[p].sum;
		int res=0;
		down(p,l,r);
		int mid=(l+r)>>1;
		if(x<=mid)res+=self(self,l,mid,x,y,p<<1);
		if(y>mid)res+=self(self,mid+1,r,x,y,p<<1|1);
		return res;
	};
	vector<node>a(1);
	int cnt=1;
	while(cin>>t){
		if(t=='L'){
			int x1,y1,x2,y2,val;cin>>x1>>y1>>x2>>y2>>val;
			a.push_back({x1,y1,y2,cnt,val,1,1});
			a.push_back({x2+1,y1,y2,cnt,-val,1,1});
		}else{
			int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
			a.push_back({x1-1,y1,y2,cnt,0,-1,2});
			a.push_back({x2,y1,y2,cnt,0,1,2});
		}
		cnt++;
	}
	auto cdq = [&](auto self,int l,int r)->void{
		if(l==r)return ;
		int mid=(l+r)>>1;
		self(self,l,mid);
		self(self,mid+1,r);
		int i=l,j=mid+1;
		for(;j<=r;j++){
			if(a[j].ty==1)continue;
			while(i<=mid&&a[i].x<=a[j].x){
				if(a[i].ty==1){
					updata(updata,1,m,a[i].y1,a[i].y2,a[i].val,1);
				}
				i++;
			}
			a[j].val+=a[j].f*(a[j].x+1)*(query(query,1,m,a[j].y1,a[j].y2,1));
		}
		for(i--;i>=l;i--){
			if(a[i].ty==1)updata(updata,1,m,a[i].y1,a[i].y2,-1ll*a[i].val,1);
		}
		i=l,j=mid+1;
		for(;j<=r;j++){
			if(a[j].ty==1)continue;
			while(i<=mid&&a[i].x<=a[j].x){
				if(a[i].ty==1){
					updata(updata,1,m,a[i].y1,a[i].y2,-1ll*a[i].x*a[i].val,1);
				}
				i++;
			}
			a[j].val+=a[j].f*(query(query,1,m,a[j].y1,a[j].y2,1));
		}
		for(i--;i>=l;i--){
			if(a[i].ty==1)updata(updata,1,m,a[i].y1,a[i].y2,a[i].x*a[i].val,1);
		}
		sort(a.begin()+l,a.begin()+r+1,cmp1);
	};
	int len=a.size()-1;
	cdq(cdq,1,len);
	vector<int>ans(cnt);
	for(int i=1;i<len;i++){
		if(a[i].ty==1)ans[a[i].id]=-1e18;
		else ans[a[i].id]+=a[i].val;
	}
	for(int i=1;i<cnt;i++){
		if(ans[i]==-1e18)continue;
		cout<<ans[i]<<'\n';
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