#include<bits/stdc++.h>
#define int long long
#define lowbit(x) ((x)&-(x))
using namespace std;
const int maxn=1e5+5;
const int mod=1e8-3;
int tree[maxn],n,d[maxn];
struct node{
	int id,val;
	bool operator <(const node &y)const{
		return val<y.val;
	}
}a[maxn],b[maxn];
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
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].val,a[i].id=i;
	for(int i=1;i<=n;i++)cin>>b[i].val,b[i].id=i;
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){//离散
		b[b[i].id].val=i;
		a[a[i].id].val=i;
	}
	for(int i=1;i<=n;i++){//优先级赋值
		d[b[i].val]=i;
	}
	for(int i=1;i<=n;i++){//偷梁换柱
		a[i].val=d[a[i].val];
	}
	int cnt=0;
	for(int i=n;i>=1;i--){
		updata(a[i].val,1);
		cnt+=sum(a[i].val-1);
		cnt%=mod;
	}
	cout<<cnt;
	return 0;
}
