#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+5;
int a[maxn];
int n,k;
struct node{
	int val,l,r;
}tree[maxn<<2];
void bulid(int l,int r,int p){
	tree[p].l=l,tree[p].r=r;
	if(l==r){
		tree[p].val=k;
		return ;
	}
	int mid=(l+r)>>1;
	bulid(l,mid,p<<1);
	bulid(mid+1,r,p<<1|1);
	tree[p].val=max(tree[p<<1].val,tree[p<<1|1].val);
}
void updata(int x,int kk){
	int l=tree[x].l,r=tree[x].r;
	if(l==r){
		tree[x].val-=kk;return ;
	}
	if(tree[x<<1].val>=kk)updata(x<<1,kk);
	else updata(x<<1|1,kk);
	tree[x].val=max(tree[x<<1].val,tree[x<<1|1].val);
	return ;
}
int query(int x){
	int res=0;
	int l=tree[x].l,r=tree[x].r;
	if(l==r){
		if(tree[x].val==k)return 0;
		else return 1;
	}
	res+=query(x<<1);
	res+=query(x<<1|1);
	return res;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans1=0;
	bulid(1,n,1);
	for(int i=1;i<=n;i++){
		updata(1,a[i]);
	}
	ans1=query(1);
	multiset<int> st;
	for (int i = 1; i <= n; i++) {
		auto it = st.lower_bound(a[i]);
		if (it != st.end()) {
			st.insert(*it - a[i]);
			st.erase(it);
		}else {
			st.insert(k - a[i]);
		}
	}
	cout<<ans1<<' '<<st.size()<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}		
	return 0;
}
