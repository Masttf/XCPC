#include<bits/stdc++.h>
using namespace std;
#define cs const
#define re register
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define gc getchar
inline int read(){
	char ch=gc();
	int res=0;bool f=1;
	while(!isdigit(ch))f^=ch=='-',ch=gc();
	while(isdigit(ch))res=(res+(res<<2)<<1)+(ch^48),ch=gc();
	return f?res:-res;
}

template<class tp>inline void chemx(tp &a,tp b){a<b?a=b:0;}
template<class tp>inline void chemn(tp &a,tp b){a>b?a=b:0;}



/*
先topsort找环
环点标记

先dfs求出往下最长的，

对环上的点求出往其他环点的最长路径 odis：
双指针维护一下
左边的走右边，右边的走左边

求完之后
往下换根dfs，

这样树上所有点都知道每个子树出去的最长路径
最大加次大。

这样树上没问题了

环上的点：
向树的几个子树的mxd，和odis一起选最大次大。

*/
cs int N=200005;

int n,inc[N];
vector<int> e[N];

int id[N],cirlen;

int vis[N],fa[N],findcircle;
void tarjan(int u){
	vis[u]=1;
	if(findcircle)return;
	for(int v:e[u])if(v!=fa[u]){
	//	cerr<<u<<" to "<<v<<endl;
		if(findcircle)return;
		if(!vis[v]){
			vis[v]=1;
			fa[v]=u;
			tarjan(v);
		}
		else{
			int x=u;
			do{
				inc[x]=1;
				id[++cirlen]=x;
				x=fa[x];
			}while(x!=v);
			inc[v]=1;
			id[++cirlen]=v;
			findcircle=1;
		}
	}
}

int d[N],odis[N],mxd[N],a[N];
vector<int> son[N];

void dfs(int u,int fa){
	for(int v:e[u])if(!inc[v]&&v!=fa){
		dfs(v,u);
		son[u].pb(mxd[v]+1);
		mxd[u]=max(mxd[u],mxd[v]+1);
	}
}


void calc_odis(){

	for(int i=cirlen+1;i<=cirlen*2;i++)a[i]=a[i-cirlen],id[i]=id[i-cirlen];
	//for(int i=1;i<=cirlen*2;i++)cout<<a[i]<<" ";puts("");
	//for(int i=1;i<=cirlen*2;i++)cout<<id[i]<<" ";puts("");
	
	int del=(cirlen+1)/2;
//	cout<<del<<"\n";
	multiset<int>s1,s2;
	for(int i=1;i<=del;i++)s2.insert(a[i]-i);
	for(int i=1;i<=cirlen*2;i++){
		int j=i+del;
		s2.erase(s2.find(a[i]-i));
		if(j<=cirlen*2)s2.insert(a[j]-j);

		if(s1.size())
		odis[id[i]]=max(odis[id[i]],(*s1.rbegin())+cirlen-i);
		if(s2.size())
		odis[id[i]]=max(odis[id[i]],(*s2.rbegin())+cirlen+i);

	//	cout<<id[i]<<" "<<odis[id[i]]<<endl;
		j=i-del;
		if(j>0)s1.erase(s1.find(a[j]+j));
		s1.insert(a[i]+i);
	}
}

int ans[N];

void dfs2(int u,int fa,int up){
	son[u].pb(up);
	sort(son[u].begin(),son[u].end());
	reverse(son[u].begin(),son[u].end());
	int now=son[u][0];
	if(son[u].size()>1)now+=son[u][1];
	ans[u]=max(ans[u],now);

	for(int v:e[u])if(!inc[v]&&v!=fa){
		int now=son[u][0];
		assert(son[u].size()>1);
		if(now==mxd[v]+1){
			dfs2(v,u,max(up,son[u][1])+1);
		}
		else dfs2(v,u,max(up,son[u][0])+1);
	}
}
namespace Circle{

void calc_circle(int *a,int n,int *id){//a:mxd of length n. note ans store in ans[id[i]]
	// for(int i=n+1;i<=n*2;i++)a[i]=a[i-n],id[i]=id[i-n];
	// //for(int i=1;i<=cirlen*2;i++)cout<<a[i]<<" ";puts("");
	// //for(int i=1;i<=cirlen*2;i++)cout<<id[i]<<" ";puts("");	
	// int del=(n+1)/2;
	// for(int i=1;i<=2*n;i++){
	// 	for(int j=i-1;j>0;j--)
	// 	for(int k=i+1;k<=n*2&&k-j<n;k++){
	// 		chemx(ans[id[i]],k-j+a[j]+a[k]);
	// 	}
	// }
	for(int i=1;i<=n;i++)
		ans[id[i]]=max(ans[id[i]],a[i]);
    static int pre[N+5],suf[N+5];
    //max(a_i-i+a_j+j)
    pre[0]=suf[n+1]=-(1<<29);
    for(int i=1;i<=n;i++)
        pre[i]=max(pre[i-1],a[i]-i);
    for(int i=n;i;i--)
        suf[i]=max(suf[i+1],a[i]+i);
    for(int i=1;i<=n;i++)
        ans[id[i]]=max({ans[id[i]],pre[i]+suf[i+1],pre[i-1]+suf[i]});
	// for(int i=1;i<=n;i++)
	// 	printf("%d %d; ",id[i],ans[id[i]]);
	// puts("");
    //max(a_i+i+a_j-j+n)
    int mxi=-(1<<29),mxj=-(1<<29);
    for(int i=1;i<=n;i++){
        mxj=max(mxj,mxi+a[i]-i+n);
        mxi=max(mxi,a[i]+i);
        ans[id[i]]=max(ans[id[i]],mxj);
    }
	// for(int i=1;i<=n;i++)
	// 	printf("%d %d; ",id[i],ans[id[i]]);
	// puts("");
    mxi=mxj=-(1<<29);
    for(int i=n;i;i--){
        mxj=max(mxj,mxi+a[i]+i+n);
        mxi=max(mxi,a[i]-i);
        ans[id[i]]=max(ans[id[i]],mxj);
    }
	// for(int i=1;i<=n;i++)
	// 	printf("%d %d; ",id[i],ans[id[i]]);
	// puts("");
}

}

int main(){
	int T=read();
	while(T--){
	n=read();
	for(int i=1;i<=n;i++){
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	//cout<<1<<endl;
	tarjan(1);
	//cout<<1<<endl;
	memset(fa,0,sizeof(fa));
	//for(int i=1;i<=n;i++)cout<<inc[i]<<" ";puts("");
	for(int i=1;i<=cirlen;i++)dfs(id[i],0);
	//cout<<1<<endl;
	for(int i=1;i<=cirlen;i++)a[i]=mxd[id[i]];
	calc_odis();
	//for(int i=1;i<=cirlen;i++)cout<<id[i]<<" "<<odis[id[i]],puts("");
	for(int i=1;i<=cirlen;i++)dfs2(id[i],0,odis[id[i]]);
	
	Circle::calc_circle(a,cirlen,id);

	for(int i=1;i<=n;i++){
		printf("%d%c",ans[i],(i==n)?('\n'):(' '));
	}
	memset(ans,0,sizeof(int)*(n+1));
	for(int i=1;i<=n;i++)e[i].clear(),son[i].clear();
	findcircle=cirlen=0;
	memset(inc,0,sizeof(int)*(n+1));
	memset(vis,0,sizeof(int)*(n+1));
	memset(fa,0,sizeof(int)*(n+1));
	memset(id,0,sizeof(int)*(2*n+1));
	memset(d,0,sizeof(int)*(n+1));
	memset(odis,0,sizeof(int)*(n+1));
	memset(mxd,0,sizeof(int)*(n+1));
	memset(a,0,sizeof(int)*(2*n+1));
	}
	return 0;
}