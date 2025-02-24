#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long p[400],q[400];
long long qpow(long long a,long long b){
	long long ans=1;
	while(b>0)
	{
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
long long dp[401],tdp[401],val[400][400],dp2[401][2],ans[400];
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,j,t;
	long long a,b,s;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>a>>b;
			p[i]=a*qpow(b,mod-2)%mod;
			q[i]=(1+mod-p[i])%mod;
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<=n;j++)
			{
				dp[j]=0;
				tdp[j]=0;
			}
			dp[0]=1;
			for(j=i;j<n;j++)
			{
				for(t=0;t<=n;t++)
				{
					if(t>0)tdp[t-1]=(tdp[t-1]+dp[t]*q[j])%mod;
					if(t<n)tdp[t+1]=(tdp[t+1]+dp[t]*p[j])%mod;
				}
				for(t=0;t<=n;t++)
				{
					dp[t]=tdp[t];
					tdp[t]=0;
				}
				val[i][j]=dp[0];
				dp[0]=0;
			}
		}
		for(i=0;i*2<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				dp2[j][0]=0;
				dp2[j][1]=0;
			}
			dp2[0][0]=1;
			for(j=0;j<n;j++)
			{
				for(t=j+1;t<n&&t<j+i*2;t+=2)
				{
					dp2[t+1][0]=(dp2[t+1][0]+dp2[j][0]*val[j][t])%mod;
					dp2[t+1][1]=(dp2[t+1][1]+dp2[j][1]*val[j][t])%mod;
				}
				dp2[j+1][0]=(dp2[j+1][0]+dp2[j][0]*q[j])%mod;
				dp2[j+1][1]=(dp2[j+1][1]+(dp2[j][0]+dp2[j][1])*p[j])%mod;
			}
			ans[i]=(dp2[n][0]+dp2[n][1])%mod;
		}
		for(i=n/2;i>0;i--)ans[i]=(ans[i]+mod-ans[i-1])%mod;
		s=0;
		for(i=1;i<=n/2;i++)s=(s+(i*2-1)*ans[i])%mod;
		cout<<s*(mod-mod/2)%mod<<'\n';
	}
	return 0;
}
