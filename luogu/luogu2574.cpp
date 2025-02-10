#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct node{
	int sum,l,r,tag;
}tree[maxn<<2];
int a[maxn];
void push_down(int p){
	if(tree[p].tag){//可能子区间也有lazy标记
		tree[p<<1].sum=(tree[p<<1].r-tree[p<<1].l+1)-tree[p<<1].sum;
		tree[p<<1].tag^=1;
		tree[p<<1|1].sum=(tree[p<<1|1].r-tree[p<<1|1].l+1)-tree[p<<1|1].sum;
		tree[p<<1|1].tag^=1;
		tree[p].tag=0;
	}
	return ;
}
void updata(int l,int r,int p){
	if(l<=tree[p].l&&tree[p].r<=r){
		tree[p].sum=(tree[p].r-tree[p].l+1)-tree[p].sum;
		tree[p].tag^=1;
		return ;
	}
	push_down(p);
	int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid) updata(l,r,p<<1);
	if(r>mid) updata(l,r,p<<1|1);
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
}
int query(int l,int r,int p){
	if(l<=tree[p].l&&tree[p].r<=r){
		return tree[p].sum;
	}
	push_down(p);
	int ans=0;
	int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid) ans+=query(l,r,p<<1);
	if(r>mid) ans+=query(l,r,p<<1|1);
	return ans;
}
void bulid(int p,int l,int r){
	tree[p].l=l,tree[p].r=r;
	tree[p].tag=0;
	if(l==r){
		tree[p].sum=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	bulid(p<<1,l,mid);
	bulid(p<<1|1,mid+1,r);
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	string s;cin>>s;
	for(int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	bulid(1,1,n);
	int t,x,y;
	while(m--){
		cin>>t>>x>>y;
		if(t==0){
			updata(x,y,1);
		}else{
			cout<<query(x,y,1)<<'\n';
		}
	}
	return 0;
}
