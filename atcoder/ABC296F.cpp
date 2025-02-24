#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x)&-(x)
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn],t[maxn];
int n;
void updata(int x,int k){
	while(x<=n){
		t[x]+=k;
		x+=lowbit(x);
	}
	return ;
}
int query(int x){
	int res=0;
	while(x){
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
signed main(){//首先考虑 交换 i,j,k i,j,h 就实现了a不动而b两个交换了位置  因此有两个一样就可以一定一样
	//然后考虑逆序对,当逆序对奇偶性不同时 最后会有两队对不一样
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	int cnt1=0,cnt2=0;
	for(int i=n;i>=1;i--){
		cnt1+=query(a[i]-1);
		updata(a[i],1);
	}
	for(int i=1;i<=n;i++)t[i]=0;
	for(int i=n;i>=1;i--){
		cnt2+=query(b[i]-1);
		updata(b[i],1);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int flag=1;
	int res=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i])flag=0;
		if(i!=1&&a[i]==a[i-1])res=1;
	}
	if(!flag)cout<<"No";
	else{
		if(res)cout<<"Yes";
		else{
			if(cnt1%2==cnt2%2)cout<<"Yes";
			else cout<<"No";
		}
	}
	return 0;
}
