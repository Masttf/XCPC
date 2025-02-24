#include<bits/stdc++.h>
using namespace std;
struct SegmentTree{
	int ls,rs,num;
}c[10000010];
long long m,k,a[100010];
int n,q,cnt,nexpos1[100010],nexpos2[100010],f[100010];
void update(int i,long long l,long long r,long long t,int sum)
{
	c[i].num=sum;
	if(l==r)
		return;
	long long mid=(l+r)>>1;
	if(t<=mid)
	{
		if(!c[i].ls)
			c[i].ls=++cnt;
		update(c[i].ls,l,mid,t,sum);
	}
	else
	{
		if(!c[i].rs)
			c[i].rs=++cnt;
		update(c[i].rs,mid+1,r,t,sum);
	}
	return;
}
int query(int i,long long l,long long r,long long L,long long R)
{
	if(l>=L&&r<=R)
		return c[i].num;
	long long mid=(l+r)>>1;
	int sum=n+2;
	if(L<=mid)
		sum=min(sum,query(c[i].ls,l,mid,L,R));
	if(R>=mid+1)
		sum=min(sum,query(c[i].rs,mid+1,r,L,R));
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int i,j,l,r,maxnum,T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>k;
		for(i=1;i<=n;++i)
			cin>>a[i];
		cnt=1,c[1].num=n+1;
		c[0].num=n+1;
		for(i=n;i>=1;--i)
		{
			nexpos1[i]=query(1,1ll,m,a[i],min(m,a[i]+k));
			nexpos2[i]=query(1,1ll,m,max(1ll,a[i]-k),a[i]);
			update(1,1ll,m,a[i],i);
		}
		cin>>q;
		for(i=1;i<=q;++i)
		{
			cin>>l>>r;
			maxnum=0;
			for(j=l;j<=r;++j)
				f[j]=0;
			for(j=r;j>=l;--j)
			{
				f[j]=1;
				if(nexpos1[j]<=r)
					f[j]=max(f[j],f[nexpos1[j]]+1);
				if(nexpos2[j]<=r)
					f[j]=max(f[j],f[nexpos2[j]]+1);
				maxnum=max(f[j],maxnum);
			}
			cout<<(r-l+1-maxnum)<<'\n';
		}
		for(i=0;i<=cnt;++i)
			c[i].num=c[i].ls=c[i].rs=0;
	}
	return 0;
}
