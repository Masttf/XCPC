#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int p[maxn],q[maxn];
map<int,int>mp,mq;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>p[i],mp[p[i]]=i;
	for(int i=1;i<=n;i++)cin>>q[i],mq[q[i]]=i;
	int cnt=0;//找出p和q中mex=1的区间然后取并
	int d1=mp[1],d2=mq[1];
	int l1=min(d1,d2),l2=max(d1,d2);
	cnt+=(l1)*(l1-1)/2;
	cnt+=(1+n-l2)*(n-l2)/2;
	cnt+=(l2-l1)*(l2-l1-1)/2;
	for(int i=2;i<=n;i++){//每次取交集
		d1=mp[i];
		d2=mq[i];
		if((d1>=l1&&d1<=l2)||(d2>=l1&&d2<=l2)){
			l1=min(l1,min(d1,d2));
			l2=max(l2,max(d1,d2));
			continue;
		}
		if(d1>l2&&d2>l2){
			int t=min(d1,d2);
			cnt+=l1*(t-l2);
			l2=d1+d2-t;
		}else if(d1<l1&&d2<l1){
			int t=max(d1,d2);
			cnt+=(n-l2+1)*(l1-t);
			l1=d1+d2-t;
		}else if(d1<l1&&d2>l2){
			cnt+=(l1-d1)*(d2-l2);
			l1=d1,l2=d2;
		}else{
			cnt+=(l1-d2)*(d1-l2);
			l1=d2,l2=d1;
		}
	}
	cnt++;
	cout<<cnt;
	return 0;
}
