#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
const long long g=3;
const long long gi=332748118;
long long n,m,r,s,ans,p[200010];
long long cnt1,cnt2;
vector<long long> f1[401010],f2[401010];
long long limit,N,M,num,L,a[300010],b[300010],q[300010],pa[200010],pinv[200010],inv[200010];
inline void init()
{
	long long i;
	inv[1]=1;
	for(i=2;i<=200005;++i)
		inv[i]=(MOD-MOD/i)*inv[MOD%i]%MOD;
	return;
}
inline long long ksm(long long d,long long e)
{
	long long sum=1;
	while(e)
	{
		if(e&1)
			sum=(sum*d)%MOD;
		d=(d*d)%MOD;
		e>>=1;
	}
	return sum;
}
inline void NTT(long long *A,long long type)
{
	long long i,j,k,mid,Wn,w,x,y;
	for(i=0;i<limit;++i)
	{
		if(i<q[i])
			swap(A[i],A[q[i]]);
	}
	for(mid=1;mid<limit;mid<<=1)
	{
		Wn=ksm(type==1?g:gi,(MOD-1)/(mid<<1));
		for(j=0;j<limit;j+=(mid<<1))
		{
			w=1;
			for(k=0;k<mid;++k,w=(w*Wn)%MOD)
			{
				x=A[j+k],y=w*A[j+k+mid]%MOD;
				A[j+k]=(x+y)%MOD,A[j+k+mid]=(x-y+MOD)%MOD;
			}
		}
	}
	return;
}
int main()
{
	long long i,j,l,r,t,ny,sum,inv0,T;
	init();
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld %lld %lld",&n,&m,&r,&s);
		ny=ksm(2ll*s+1,MOD-2),cnt1=cnt2=0;
		for(i=1;i<=n;++i)
		{
			scanf("%lld",&p[i]);
			if(p[i]<=r)
			{
				t=(min(r,p[i]+s)-(p[i]-s)+1)*ny%MOD,++cnt1;
				f1[cnt1].push_back((1ll-t+MOD)%MOD); f1[cnt1].push_back(t);
			}
			else
			{
				if(p[i]-s<=r)
				{
					t=(r-(p[i]-s)+1)*ny%MOD,++cnt2;
					f2[cnt2].push_back((1ll-t+MOD)%MOD); f2[cnt2].push_back(t);
				}
			}
		}
		++cnt1;	f1[cnt1].push_back(1ll); f1[cnt1].push_back(0ll);
		++cnt2;	f2[cnt2].push_back(1ll); f2[cnt2].push_back(0ll);
		l=1,r=cnt1;
		while(l!=r)
		{
			for(i=l;i<r;i+=2)
			{
				N=f1[i].size()-1,M=f1[i+1].size()-1;
				limit=1,L=0;
				while(limit<=N+M)
					limit<<=1,++L;
				for(j=0;j<limit;++j)
					q[j]=a[j]=b[j]=0;
				for(j=0;j<=N;++j)
					a[j]=f1[i][j];
				for(j=0;j<=M;++j)
					b[j]=f1[i+1][j];
				for(j=0;j<limit;++j)
					q[j]=(q[j>>1]>>1)|((j&1)<<(L-1));
				NTT(a,1); NTT(b,1);
				for(j=0;j<limit;++j)
					a[j]=(a[j]*b[j])%MOD;
				NTT(a,-1);
				inv0=ksm(limit,MOD-2),++cnt1;
				for(j=0;j<=N+M;++j)
				{
					t=(a[j]*inv0)%MOD;
					f1[cnt1].push_back(t);
				}
			}
			if(i==r)
			{
				++cnt1;
				for(j=0;j<f1[r].size();++j)
					f1[cnt1].push_back(f1[r][j]);
			}
			l=r+1,r=cnt1;
		}
		l=1,r=cnt2;
		while(l!=r)
		{
			for(i=l;i<r;i+=2)
			{
				N=f2[i].size()-1,M=f2[i+1].size()-1;
				limit=1,L=0;
				while(limit<=N+M)
					limit<<=1,++L;
				for(j=0;j<limit;++j)
					q[j]=a[j]=b[j]=0;
				for(j=0;j<=N;++j)
					a[j]=f2[i][j];
				for(j=0;j<=M;++j)
					b[j]=f2[i+1][j];
				for(j=0;j<limit;++j)
					q[j]=(q[j>>1]>>1)|((j&1)<<(L-1));
				NTT(a,1); NTT(b,1);
				for(j=0;j<limit;++j)
					a[j]=(a[j]*b[j])%MOD;
				NTT(a,-1);
				inv0=ksm(limit,MOD-2),++cnt2;
				for(j=0;j<=N+M;++j)
				{
					t=(a[j]*inv0)%MOD;
					f2[cnt2].push_back(t);
				}
			}
			if(i==r)
			{
				++cnt2;
				for(j=0;j<f2[r].size();++j)
					f2[cnt2].push_back(f2[r][j]);
			}
			l=r+1,r=cnt2;
		}
		N=f1[cnt1].size()-1,M=f2[cnt2].size()-1;
		ans=0,num=N+M;
		limit=1,L=0;
		while(limit<=num)
			limit<<=1,++L;
		for(j=0;j<limit;++j)
			q[j]=b[j]=0;
		for(j=0;j<=M;++j)
			b[j]=f2[cnt2][j];
		for(j=0;j<limit;++j)
			q[j]=(q[j>>1]>>1)|((j&1)<<(L-1));
		NTT(b,1);
		inv0=ksm(limit,MOD-2);
		for(j=0;j<=N;++j)
			pa[j]=f1[cnt1][j];
		for(j=0;j<=num;++j)
			pinv[j]=1;
		for(i=1;i<=m;++i)
		{
			if(i-1<=N)
				pa[i-1]=0;
			for(j=i;j<=N;++j)
				pa[j]=(pa[j]*(j+1-i))%MOD;
			for(j=0;j<limit;++j)
				a[j]=0;
			for(j=0;j<=N;++j)
				a[j]=pa[j];
			NTT(a,1);
			for(j=0;j<limit;++j)
				a[j]=(a[j]*b[j])%MOD;
			NTT(a,-1);
			sum=0;
			for(j=i;j<=num;++j)
			{
				pinv[j]=(pinv[j]*inv[j+1-i])%MOD;
				sum=(sum+a[j]*inv0%MOD*pinv[j])%MOD;
			}
			ans=(ans+sum)%MOD;
		}
		printf("%lld\n",ans);
		for(i=1;i<=cnt1;++i)
			f1[i].clear();
		for(i=1;i<=cnt2;++i)
			f2[i].clear();
	}
	return 0;
}
