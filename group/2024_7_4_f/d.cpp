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
constexpr int Max=1e18;
void solve(){
	int q,m;cin>>q>>m;
	vector<int>tr(q*4,-Max);
	auto updata = [&](auto self,int l,int r,int x,int val,int p)->void{
		if(l==r){
			tr[p]=val;
			return ;
		}
		int mid=(l+r)>>1;
		if(x<=mid)self(self,l,mid,x,val,p<<1);
		else self(self,mid+1,r,x,val,p<<1|1);
		tr[p]=max(tr[p<<1],tr[p<<1|1]);
	};
	auto query = [&](auto self,int l,int r,int x,int y,int p)->int{
		if(x<=l&&r<=y)return tr[p];
		int res=0;
		int mid=(l+r)>>1;
		if(x<=mid)res=max(res,self(self,l,mid,x,y,p<<1));
		if(y>mid)res=max(res,self(self,mid+1,r,x,y,p<<1|1));
		return res;
	};
	int n=0;
	int last=0;
	for(int i=1;i<=q;i++){
		char t;cin>>t;
		if(t=='A'){
			int x;cin>>x;
			x=(x+last)%m;
			n++;
			updata(updata,1,q,n,x,1);
		}else{
			int x;cin>>x;
			last=query(query,1,q,n-x+1,n,1);
			cout<<last<<'\n';
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