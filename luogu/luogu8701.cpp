#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
struct node{
	int l,r;
	int mx[10]={0,0,0,0,0,0,0,0,0,0};
}t[maxn<<2];
void up(int p){
	int l=1,r=1;
	for(int i=1;i<=8;i++){
		if(t[p<<1].mx[l]>=t[p<<1|1].mx[r]){
			t[p].mx[i]=t[p<<1].mx[l++];
		}else{
			t[p].mx[i]=t[p<<1|1].mx[r++];
		}
	}
	return ;
}
void bulid(int l,int r,int p){
	t[p].l=l,t[p].r=r;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	bulid(l,mid,p<<1);
	bulid(mid+1,r,p<<1|1);
	return ;
}
void add(int x,int y,int p){
	int l=t[p].l,r=t[p].r;
	if(l==r){
		t[p].mx[1]=y;
		return ;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(x,y,p<<1);
	else add(x,y,p<<1|1);
	up(p);
	return ;
}
node find(int x,int y,int p){
	int l=t[p].l,r=t[p].r;
	if(x<=l&&r<=y){
		return t[p];
	}
	int mid=(l+r)>>1;
	node res,ll,rr;//归并
	if(x<=mid) ll=find(x,y,p<<1);
	if(y>mid) rr=find(x,y,p<<1|1);
	int i=1,j=1;
	for(int k=1;k<=8;k++){
		if(ll.mx[i]>=rr.mx[j]){
			res.mx[k]=ll.mx[i++];
		}else{
			res.mx[k]=rr.mx[j++];
		}
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	bulid(1LL,n,1LL);
	while(q--){
		char tp;
		int x,y;
		cin>>tp>>x>>y;
		if(tp=='C'){
			add(x,y,1LL);
		}else{
			node ans=find(x,y,1LL);
			cout<<ans.mx[8]<<'\n';
		}
	}
	return 0;
}
