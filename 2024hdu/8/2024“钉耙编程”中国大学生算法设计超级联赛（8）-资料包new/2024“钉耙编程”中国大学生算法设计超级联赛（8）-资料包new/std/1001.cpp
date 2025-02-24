#include<bits/stdc++.h>
using namespace std;
struct dval{
	long long a;
	long long b;
	int id;
	friend bool operator<(dval a,dval b){
		if(b.a==0&&b.b==0)return 0;
		if(a.a==0&&a.b==0)return 1;
		return a.b*b.a<b.b*a.a;
	}
};
dval d[200000],stk[200000],vl[400000],vl2[400000];
int pos[400000];
vector<int>ins[200001],rmv[200001];
long long s[200001];
long long tre[400001][2];
int N;
int lowbit(int x){
	return x-(x&(x-1));
}
void add(int p,long long vl,int tag){
	for(;p<=N;p+=lowbit(p))tre[p][tag]+=vl;
}
long long qsum(int p,int tag){
	long long vl=0;
	for(;p>0;p-=lowbit(p))vl+=tre[p][tag];
	return vl;
}
void clr(){
	int i;
	for(i=0;i<=N;i++)
	{
		tre[i][0]=0;
		tre[i][1]=0;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T,n,i,stkpos;
	long long xval,csum,ans;
	vector<int>::iterator it;
	for(cin>>T;T>0;T--)
	{
		cin>>n;
		xval=0;
		for(i=0;i<n;i++)
		{
			cin>>d[i].a>>d[i].b;
			xval+=d[i].a*d[i].b;
		}
		for(i=0;i<=n;i++)s[i]=0;
		stkpos=0;
		csum=0;
		for(i=0;i<n;i++)
		{
			vl[i]=d[i];
			vl[i].id=i;
			while(stkpos>0&&vl[i]<stk[stkpos-1])
			{
				csum+=stk[stkpos-1].a*vl[i].b;
				rmv[i+1].push_back(stk[stkpos-1].id);
				vl[i].a+=stk[stkpos-1].a;
				vl[i].b+=stk[stkpos-1].b;
				stkpos--;
			}
			ins[i+1].push_back(vl[i].id);
			stk[stkpos]=vl[i];
			stkpos++;
			s[i+1]+=csum;
		}
		stkpos=0;
		csum=0;
		for(i=n-1;i>-1;i--)
		{
			vl[i+n]=d[i];
			vl[i+n].id=i+n;
			while(stkpos>0&&vl[i+n]<stk[stkpos-1])
			{
				csum+=stk[stkpos-1].a*vl[i+n].b;
				ins[i+1].push_back(stk[stkpos-1].id);
				vl[i+n].a+=stk[stkpos-1].a;
				vl[i+n].b+=stk[stkpos-1].b;
				stkpos--;
			}
			rmv[i+1].push_back(vl[i+n].id);
			stk[stkpos]=vl[i+n];
			stkpos++;
			s[i]+=csum;
		}
		for(;stkpos>0;stkpos--)ins[0].push_back(stk[stkpos-1].id);
		for(i=0;i<n*2;i++)vl2[i]=vl[i];
		sort(vl2,vl2+n*2);
		for(i=0;i<n*2;i++)pos[vl2[i].id]=i+1;
		N=n*2;
		ans=0;
		csum=0;
		for(i=0;i<=n;i++)
		{
			for(it=ins[i].begin();it!=ins[i].end();it++)
			{
				csum+=(qsum(n*2,1)-qsum(pos[*it],1))*vl[*it].a;
				add(pos[*it],vl[*it].a,0);
				csum+=qsum(pos[*it]-1,0)*vl[*it].b;
				add(pos[*it],vl[*it].b,1);
			}
			for(it=rmv[i].begin();it!=rmv[i].end();it++)
			{
				csum-=(qsum(n*2,1)-qsum(pos[*it],1))*vl[*it].a;
				add(pos[*it],-vl[*it].a,0);
				csum-=qsum(pos[*it]-1,0)*vl[*it].b;
				add(pos[*it],-vl[*it].b,1);
			}
			ans=max(ans,csum+s[i]);
		}
		for(i=0;i<=n;i++)
		{
			ins[i].clear();
			rmv[i].clear();
		}
		clr();
		cout<<ans+xval<<'\n';
	}
	return 0;
}
