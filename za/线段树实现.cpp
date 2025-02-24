#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int res[maxn],f[maxn<<2],tag[maxn<<2];
int n,m;
void addtag(int p,int lp,int rp,int d){
	tag[p]+=d;
	f[p]+=d*(rp-lp+1);
	return ;
}
void push_down(int p,int lp,int rp){
	if(tag[p]){
		int mid=(lp+rp)>>1;
		addtag(p*2,lp,mid,tag[p]);
		addtag(p*2+1,mid+1,rp,tag[p]);
		tag[p]=0;
	}
	return ;
}
void bulid(int p,int lp,int rp){
	if(lp==rp){
		f[p]=res[lp];
		tag[p]=0;
		return ;
	}
	int mid=(lp+rp)>>1;
	bulid(p*2,lp,mid);
	bulid(p*2+1,mid+1,rp);
	f[p]=f[p*2]+f[p*2+1];
	tag[p]=0;
	return ;
}
int qu(int L,int R,int p,int lp,int rp){
	if(L<=lp&&rp<=R)return f[p];
	push_down(p,lp,rp);
	int ans=0;
	int mid=(lp+rp)>>1;
	if(L<=mid)ans+=qu(L,R,p*2,lp,mid);
	if(R>mid)ans+=qu(L,R,p*2+1,mid+1,rp);
	return ans;
}
void updata(int p,int lp,int rp,int L,int R,int d){//单点修改
	if(L<=lp&&rp<=R){
		addtag(p,lp,rp,d);
		return ;
	}
	push_down(p,lp,rp);//为什么要下传lazy标记呢，如果不下传下面的数是不正确的//所以每次不能完全覆盖都要下传标记
	int mid=(lp+rp)>>1;
	if(L<=mid)updata(p*2,lp,mid,L,R,d);
	if(R>mid) updata(p*2+1,mid+1,rp,L,R,d);
	f[p]=f[2*p]+f[2*p+1];
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>res[i];
	bulid(1,1,n);
	int t,x,y,k;
	while(m--){
		cin>>t;
		if(t==1){
			cin>>x>>y>>k;
			updata(1,1,n,x,y,k);
		}else{
			cin>>x>>y;
			cout<<qu(x,y,1,1,n)<<'\n';
		}
	}
	return 0;
}
