#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int js(int x){
	int res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	return res;
}
void solve(){
	map<int,int>m;
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i],m[i]=a[i];
	m[n+1]=1;m[0]=1;//注意map迭代器的使用
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int l,r;cin>>l>>r;
			for(auto it=m.lower_bound(l);it->first<=r;it++){
				int k=js(it->second);
				if(k<=9)a[it->first]=k,it=m.erase(it),it--;
				else it->second=k;
			}
		}else{
			int x;cin>>x;
			if(m.count(x))cout<<m[x]<<'\n';
			else cout<<a[x]<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
/*线段树解法
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
struct node{
	int l,r,sum,val;
};
node tree[maxn<<2];
int a[maxn];
void bulid(int l,int r,int p){
	tree[p].l=l;tree[p].r=r;
	if(l==r){
		tree[p].val=a[l];
		if(tree[p].val<=9)tree[p].sum=1;
		else tree[p].sum=0;
		return ;
	}
	int mid=(l+r)>>1;
	bulid(l,mid,p<<1);
	bulid(mid+1,r,p<<1|1);
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
	return ;
}
int js(int x){
	int res=0;
	while(x){
		res+=x%10;
		x/=10;
	}
	return res;
}
void updata(int p,int l,int r){
	if(tree[p].l==tree[p].r){
		tree[p].val=js(tree[p].val);
		if(tree[p].val<=9)tree[p].sum=1;
		else tree[p].sum=0;
		return ;
	}
	if(tree[p].l>=l&&tree[p].r<=r&&tree[p].sum==tree[p].r-tree[p].l+1){
		return ;
	}
	int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid)updata(p<<1,l,r);
	if(r>mid)updata(p<<1|1,l,r);
	tree[p].sum=tree[p<<1].sum+tree[p<<1|1].sum;
	return ;
}
int query(int p,int l,int r){
	if(tree[p].l>=l&&tree[p].r<=r){
		return tree[p].val;
	}
	int res=0;
	int mid=(tree[p].l+tree[p].r)>>1;
	if(l<=mid)res+=query(p<<1,l,r);
	if(r>mid)res+=query(p<<1|1,l,r);
	return res;
}
void solve(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	bulid(1,n,1);
	for(int i=1;i<=q;i++){
		int t;cin>>t;
		if(t==1){
			int l,r;cin>>l>>r;
			updata(1,l,r);
		}else{
			int x;cin>>x;
			cout<<query(1,x,x)<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
 */
