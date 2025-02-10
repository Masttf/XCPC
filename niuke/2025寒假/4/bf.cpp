#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=5e5+10;
const int mod=1e9+7;
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b>0)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
ll inv(ll x){return qpow(x,mod-2);}
const ll inv3=inv(3);
ll cal3(int l,int r)
{
	int n=r-l+1;
	return 1LL*(n-1)*n%mod*(n+1)%mod*inv3%mod;
}
ll cal2(int l1,int r1,int l2,int r2)
{
	if(l1>r1||l2>r2) return 0;
	ll res=0;
	res+=1LL*(l2+r2)*(r2-l2+1)/2%mod*(r1-l1+1);
	res-=1LL*(l1+r1)*(r1-l1+1)/2%mod*(r2-l2+1);
	res%=mod;
	if(res<0) return res+mod;
	return res;
}
ll cal(int l1,int r1,int l2,int r2)
{
	if(l1>l2)
	{
		swap(l1,l2);
		swap(r1,r2);
	}
	int x,y;
	x=max(l1,l2);
	y=min(r1,r2);
	if(x>y) return cal2(l1,r1,l2,r2);
	ll res=0;
	res+=cal2(l1,x-1,l2,r2);
	res+=cal2(x,y,y+1,max(r1,r2));
	res+=cal3(x,y);
	return res%mod;
}
int l[MAX],r[MAX];
int main()
{
	int t,n,i;
	ll ans,fz,fm;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
		ans=0;
		for(i=2;i<=n;i++)
		{
			fz=cal(l[i-1],r[i-1],l[i],r[i]);
			fm=1LL*(r[i-1]-l[i-1]+1)*(r[i]-l[i]+1)%mod;
			ans=(ans+fz*inv(fm))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
2 6
4 8
x,y [4,6]
[2,3]x[4,8]->[l1,x-1]x[l2,r2]
[4,6]x[7,8]->[x,y]x[y+1,r2]
[4,6]x[4,6]

2:4,5,6,7,8
3:4,5,6,7,8
4:4,5,6,7,8
5:4,5,6,7,8
6:4,5,6,7,8

l1,r1,l2,r2
(l2+r2)*(r2-l2)

012,101,210

3*2*4/3

*/