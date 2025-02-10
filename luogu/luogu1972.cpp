//利用树状数组统计区间内不同的数量
//离线做法
//到一开始到r时这个区间的数量都加1，之前这个数的区间都减一
//原因
//对于若干个询问的区间[l,r]，如果他们的r都相等的话，那么项链中出现的同一个数字，一定是只关心出现在最右边的那一个的，例如：
//项链是：1 3 4 5 1
//那么，对于r=5的所有的询问来说，第一个位置上的1完全没有意义，
//因为r已经在第五个1的右边，对于任何查询的[L,5]区间来说，如果第一个1被算了，那么他完全可以用第五个1来替代。
#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
using namespace std;
const int maxn=1e6+5;
int tree[maxn],n,a[maxn],vis[maxn],ans[maxn];
void updata(int x,int d){
	while(x<=n){
		tree[x]+=d;
		x+=lowbit(x);
	}
	return ;
}
int sum(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
struct node{
	int l,r,id;
	bool operator <(const node &y)const{
		return r<y.r;
	}
}q[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int m;cin>>m;
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	sort(q+1,q+1+m);
	int n=1;
	for(int i=1;i<=m;i++){
		for(int j=n;j<=q[i].r;j++){
			if(vis[a[j]]){
				updata(vis[a[j]],-1);//那个区间的种数减一这个再计算时可以正确的减掉
			}
			updata(j,1);
			vis[a[j]]=j;
		}
		n=q[i].r+1;
		ans[q[i].id]=sum(q[i].r)-sum(q[i].l-1);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}
