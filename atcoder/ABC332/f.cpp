#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
struct node{
	int val,tag1=1,tag2; 
};
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int l,r,x;cin>>l>>r>>x;
	}
	vector<node>tr(n*4);
	auto down = [&](int p)->void{
		tr[p<<1].val=tr[p<<1].val*tr[p].tag1+tr[p].tag2;
		tr[p<<1].tag1=tr[p].tag1;
		tr[p<<1].tag2=tr[p].tag2;
		tr[p<<1|1].val=tr[p<<1|1].val*tr[p].tag1+tr[p].tag2;
		tr[p<<1|1].tag1=tr[p].tag1;
		tr[p<<1|1].tag2=tr[p].tag2;
		tr[p].tag1=1;
		tr[p].tag2=0;
	};
	auto bulid = [&](auto self,int l,int r,int p)->void{
		if(l==r){
			tr[p].val=a[l];
			return ;
		}
		int mid=(l+r)>>1;
		self(self,l,mid,p<<1);
		self(self,mid+1,r,p<<1|1);
	};

	auto updata = [&](auto self,int l,int r,int x,int y,int val1,int val2,int p)->void{
		if(x<=l&&r<=y){
			tr[p].val=tr[p].val*val1%mod+val2;
			
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}