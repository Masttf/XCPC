//逆序对  树状数组的方式实现
#include<bits/stdc++.h>
#define lowbit(x) ((x)&-(x))
#define int long long
using namespace std;
const int maxn=5e5+5;
int res[maxn],tree[maxn];
int n;
struct node{
	int id,val;
	bool operator <(const node &y)const{
		return val<y.val;
	}
}p[maxn];
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
	for(int i=1;i<=n;i++){
		cin>>p[i].val;
		p[i].id=i;
	}
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i++){//离散化
		res[p[i].id]=i;
		if(p[i-1].val==p[i].val){
			res[p[i].id]=res[p[i-1].id];
		}
	}
	int cnt=0;
	for(int i=n;i>=1;i--){
		updata(res[i],1);
		cnt+=sum(res[i]-1);
	}
	cout<<cnt;
	return 0;
}
