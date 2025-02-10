#include<bits/stdc++.h>
//#define int long long
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
void err(T arg, Ts &... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
struct node{
	int l,r,sum;
	int tag=-1;
};
void solve(){
	int n,q;cin>>n>>q;
	int tot=0;
	vector<node>tr(q*50+5);
	auto up =[&](int u)->void{
		tr[u].sum=tr[tr[u].l].sum+tr[tr[u].r].sum;
		return ;
	};
	
	auto down = [&](int u,int l,int r)->void{
		if(tr[u].tag==-1)return ;
		int mid=(l+r)>>1;
		if(!tr[u].l)tr[u].l=++tot;
		if(!tr[u].r)tr[u].r=++tot;
		tr[tr[u].l].sum=(mid-l+1)*tr[u].tag;
		tr[tr[u].l].tag=tr[u].tag;
		tr[tr[u].r].sum=(r-mid)*tr[u].tag;
		tr[tr[u].r].tag=tr[u].tag;
		tr[u].tag=-1;
		return ;
	};
	auto updata = [&](auto self,int &u,int l,int r,int x,int y,int k)->void{
		if(!u)u=++tot;
		//dbg(l,r);
		if(x<=l&&r<=y){
			//dbg(tot,x,y,l,r);
			tr[u].sum=k*(r-l+1);
			tr[u].tag=k;
			return ;
		}
		int mid=(l+r)>>1;
		down(u,l,r);
		if(x<=mid)self(self,tr[u].l,l,mid,x,y,k);
		if(y>mid)self(self,tr[u].r,mid+1,r,x,y,k);
		up(u);
	};
	
	int root=0;
	for(int i=1;i<=q;i++){
		int l,r,k;cin>>l>>r>>k;
		if(k==2)k=0;
		updata(updata,root,1,n,l,r,k);
		//dbg(root);
		cout<<n-tr[root].sum<<'\n';
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