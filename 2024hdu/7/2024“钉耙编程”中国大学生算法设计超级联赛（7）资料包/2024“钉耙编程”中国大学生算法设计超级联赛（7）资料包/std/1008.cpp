#include<bits/stdc++.h>
using namespace std;
const long long MOD=1e9+7;
long long n,m,L,R,ans,e[210][210],f1[110],f3[110],f4[110];
struct node{
	long long c[110][110];
}f2,t,p,t3,t4,t5;
node operator +(node a1,node a2)
{
	long long i,j;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			t.c[i][j]=(a1.c[i][j]+a2.c[i][j])%MOD;
	return t;
}
node operator *(node a1,node a2)
{
	long long i,j,k;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			t.c[i][j]=0;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=n;++k)
				t.c[i][j]=(t.c[i][j]+a1.c[i][k]*a2.c[k][j])%MOD;
	return t;
}
node ksm(long long c)
{
	if(c==1)
		return f2;
	node t2=ksm(c/2);
	if(c%2)
		return t2*t2*f2;
	else
		return t2*t2;
}
node dac(long long c)
{
	if(c==1)
	{
		t3=f2;
		return f2;
	}
	node t2=dac(c/2);
	if(c%2)
	{
		t4=t3*t3*f2;
		t5=t3;
		t3=t4;
		return (t2+(t2*t5))+t3;
	}
	else
	{
		t4=t3*t3;
		t5=t3;
		t3=t4;
		return t2+(t2*t5); 
	}
}
int main()
{
	long long i,j,k,t1,t2,t3,st,ed,T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld %lld %lld",&n,&m,&L,&R);
		ans=0;
		for(i=1;i<=n*2;++i)
			for(j=1;j<=n*2;++j)
				e[i][j]=0;
		for(i=1;i<=n;++i)
			f1[i]=f3[i]=f4[i]=0;
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				f2.c[i][j]=t.c[i][j]=p.c[i][j]=0;
		for(i=1;i<=m;++i)
		{
			scanf("%lld %lld %lld",&t1,&t2,&t3);
			e[t1][t2]=(e[t1][t2]+t3)%MOD;
		}
		f1[1]=1;
		for(i=2;i<=n;++i)
			for(j=1;j<i;++j)
				f1[i]=(f1[i]+f1[j]*e[j][i])%MOD;
		for(i=1;i<=n;++i)
			for(j=1;j<n+i;++j)
			{
				if(j<=n)
					f2.c[j][i]=(f2.c[j][i]+e[j][n+i])%MOD;
				else
				{
					for(k=1;k<=n;++k)
						f2.c[k][i]=(f2.c[k][i]+f2.c[k][j-n]*e[j-n][i])%MOD;
				}
			}
		st=L/n;
		if(L%n==0)
			--st;
		ed=R/n;
		if(R%n==0)
			--ed;
		if(!st)
		{
			for(i=1;i<=n;++i)
				f3[i]=f1[i];
		}
		else
		{
			p=ksm(st);
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					f3[i]=(f3[i]+f1[j]*p.c[j][i])%MOD;
		}
		t1=L%n;
		if(!t1)
			t1=n;
		if(st!=ed)
		{
			for(i=t1;i<=n;++i)
				ans=(ans+f3[i])%MOD;
			for(i=1;i<=n;++i)
				f4[i]=f3[i];
			for(i=1;i<=n;++i)
				f3[i]=0;
			p=ksm(ed);
			for(i=1;i<=n;++i)
				for(j=1;j<=n;++j)
					f3[i]=(f3[i]+f1[j]*p.c[j][i])%MOD;
			t2=R%n;
			if(!t2)
				t2=n;
			for(i=1;i<=t2;++i)
				ans=(ans+f3[i])%MOD;
			if(st!=ed-1)
			{
				p=dac(ed-st-1);
				for(i=1;i<=n;++i)
					f3[i]=0;
				for(i=1;i<=n;++i)
					for(j=1;j<=n;++j)
						f3[i]=(f3[i]+f4[j]*p.c[j][i])%MOD;
				for(i=1;i<=n;++i)
					ans=(ans+f3[i])%MOD;
			}
		}
		else
		{
			t2=R%n;
			if(!t2)
				t2=n;
			for(i=t1;i<=t2;++i)
				ans=(ans+f3[i])%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
