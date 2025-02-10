#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int a[maxn];
struct node{
	int sum,l,r,tag1,tag2;
}s[maxn<<2];
int n,m,q;
void push_down(int p){
	s[p<<1].sum=(s[p<<1].sum*s[p].tag2+s[p].tag1*(s[p<<1].r-s[p<<1].l+1))%q;
	s[p<<1|1].sum=(s[p<<1|1].sum*s[p].tag2+s[p].tag1*(s[p<<1|1].r-s[p<<1|1].l+1))%q;
	s[p<<1].tag2=(s[p<<1].tag2*s[p].tag2)%q;
	s[p<<1|1].tag2=(s[p<<1|1].tag2*s[p].tag2)%q;
	s[p<<1].tag1=(s[p<<1].tag1*s[p].tag2+s[p].tag1)%q;
	s[p<<1|1].tag1=(s[p<<1|1].tag1*s[p].tag2+s[p].tag1)%q;
	s[p].tag1=0;
	s[p].tag2=1;
	return; 
}
void uadd(int p,int d){
	s[p].tag1+=d;
	s[p].tag1%=q;
	s[p].sum+=(s[p].r-s[p].l+1)*d;
	s[p].sum%=q;
}
void umul(int p,int d){
	s[p].tag1= (s[p].tag1*d)%q;//每次都先计算先乘后加，因此如果加法标签每次也要乘//如果加法优先会有精度问题
	s[p].tag2*=d;
	s[p].tag2%=q;
	s[p].sum*=d;
	s[p].sum%=q;
	return ;
}
void mul(int l,int r,int p,int d){
	if(l<=s[p].l&&s[p].r<=r){
		umul(p,d);
		return ;
	}
	push_down(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(l<=mid) mul(l,r,p<<1,d);
	if(r>mid) mul(l,r,p<<1|1,d);
	s[p].sum=(s[p<<1].sum+s[p<<1|1].sum)%q;
	return ;
}
void add(int l,int r,int p,int d){
	if(l<=s[p].l&&s[p].r<=r){
		uadd(p,d);
		return ;
	}
	push_down(p);
	int mid=(s[p].l+s[p].r)>>1;
	if(l<=mid) add(l,r,p<<1,d);
	if(r>mid) add(l,r,p<<1|1,d);
	s[p].sum=(s[p<<1].sum+s[p<<1|1].sum)%q;
	return ;
}
int qu(int l,int r,int p){
	if(l<=s[p].l&&s[p].r<=r){
		return s[p].sum;
	}
	push_down(p);
	int ans=0;
	int mid=(s[p].l+s[p].r)>>1;
	if(l<=mid)ans+=qu(l,r,p<<1);
	if(r>mid)ans+=qu(l,r,p<<1|1);
	return ans;
}
void bulid(int p,int l,int r){
	s[p].l=l;s[p].r=r;
	s[p].tag1=0;s[p].tag2=1;
	if(l==r){
		s[p].sum=a[l]%q;
		return ;
	}
	int mid=(l+r)>>1;
	bulid(p<<1,l,mid);
	bulid(p<<1|1,mid+1,r);
	s[p].sum=(s[p<<1].sum+s[p<<1|1].sum)%q;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	bulid(1,1,n);
	int t,x,y,k;
	while(m--){
		cin>>t;
		if(t==1){
			cin>>x>>y>>k;
			mul(x,y,1,k);
		}else if(t==2){
			cin>>x>>y>>k;
			add(x,y,1,k);
		}else{
			cin>>x>>y;
			cout<<qu(x,y,1)%q<<'\n';
		}
	}
	return 0;
}
