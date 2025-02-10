#include<bits/stdc++.h>
using namespace std;
#define int __int128
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
signed main(){
	ios::sync_with_stdio(false);
	long long n;cin>>n;
	long long x,y;cin>>x>>y;
	int a1=x,m1=y;
	int flag=1;
	for(int i=1;i<=n-1;i++){
		cin>>x>>y;
		int k1,k2;
		int a2=x,m2=y;
		int d=exgcd(a1,a2,k1,k2);
		if((m2-m1)%d!=0){
			flag=0;
			break;
		}
		k1*=(m2-m1)/d;
		int t=a2/d;
		k1=(k1%t+t)%t;
		m1=k1*a1+m1;
		a1=a1/d*a2;
	}
	long long ans=m1;
	if(flag){
		cout<<ans;
	}else cout<<-1;
}
