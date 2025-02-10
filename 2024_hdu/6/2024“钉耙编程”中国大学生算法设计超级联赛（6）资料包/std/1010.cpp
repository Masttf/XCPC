#include<bits/stdc++.h>
#define ll long long
#define ssz(x) ((int)x.size())
using namespace std;
const int N=3e5+5,mod=998244353;
inline void Add(int&a,int b){((a+=b)>=mod)&&(a-=mod);}
inline void Dec(int&a,int b){a=a<b?a-b+mod:a-b;}
inline void Mul(int&a,int b){a=1ll*a*b%mod;}
inline int add(int a,int b){return (a+=b)>=mod?a-=mod:a;}
inline int dec(int a,int b){return a<b?a-b+mod:a-b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int red(){
	int data=0;int w=1; char ch=0;
	ch=getchar();
	while(ch!='-' && (ch<'0' || ch>'9')) ch=getchar();
	if(ch=='-') w=-1,ch=getchar();
	while(ch>='0' && ch<='9') data=(data<<3)+(data<<1)+ch-'0',ch=getchar();
	return data*w;
}
int lim=1,l;
typedef vector<int> poly;
int *w[50],inw[N];
vector<int>rev[50];
bool done[50];
int Inv[N];
inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,a=mul(a,a))if(p&1)Mul(ret,a);return ret;}
inline void pre(const int &mx){
	lim=1,l=0;
	while(lim<mx)lim<<=1,++l;
	if(done[l])return;
	done[l]=1;
	rev[l].resize(lim);
	for(int i=0;i<lim;i++)
		rev[l][i]=(rev[l][i>>1]>>1)|((i&1)<<(l-1));
}
inline void ntt(poly&a,int type){
	for(int i=0;i<lim;i++)
		if(i<rev[l][i])
			swap(a[i],a[rev[l][i]]);
	for(int i=1,t=1,a0,a1;i<lim;i<<=1,++t)
		for(int j=0,len=i<<1;j<lim;j+=len)
			for(int k=0;k<i;k++)
				a0=a[j+k],a1=mul(a[j+k+i],w[t][k]),a[j+k]=add(a0,a1),a[j+k+i]=dec(a0,a1);
	if(~type)return;
	reverse(a.begin()+1,a.end());
	for(int i=0;i<lim;i++)
		Mul(a[i],inw[l]);
}
inline poly operator*(poly a,poly b){
	int n=a.size(),m=b.size(),t=n+m-1;
	if(t<=128||n<=5||m<=5){
		if(n==0)return a;
		if(m==0)return b;
		poly c(t);
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				Add(c[i+j],mul(a[i],b[j]));
		return c;
	}
	pre(t);
	a.resize(lim),ntt(a,1);
	b.resize(lim),ntt(b,1);
	for(int i=0;i<lim;i++)
		Mul(a[i],b[i]);
	ntt(a,-1);a.resize(t);
	return a;
}
inline poly operator+(poly a,poly b){
	if(a.empty())return b;
	if(b.empty())return a;
	int n=max(a.size(),b.size());
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++)
		Add(a[i],b[i]);
	return a.resize(n),a;
}
poly X,I,O;
int fac[N],ifac[N];
void init(int n){
	X.resize(2);
	X[0]=0;X[1]=1;
	I.resize(1);
	I[0]=1;
	O.clear();
	fac[0]=fac[1]=1; 
	Inv[1]=1;
	inw[0]=1;
	ifac[0]=ifac[1]=1;
	int mx=n<<1;
	for(int i=1;i<=mx;i++)fac[i]=mul(fac[i-1],i);
	for(int i=2;i<=mx;i++)Inv[i]=mul(Inv[mod%i],(mod-mod/i));
	for(int i=2;i<=mx;i++)ifac[i]=mul(ifac[i-1],Inv[i]);
	for(int i=1,mt=(mod+1)>>1;i<23;i++)inw[i]=mul(inw[i-1],mt);
	for(int i=1;i<=23;i++)w[i]=new int[1<<(i-1)];
	int w0=ksm(3,(mod-1)>>23);
	w[23][0]=1;
	for(int i=1,up=1<<22;i<up;++i)w[23][i]=mul(w[23][i-1],w0);
	for(int i=22;i>=1;i--)
		for(int j=0,up=1<<(i-1);j<up;++j)
			w[i][j]=w[i+1][j<<1]; 
}
struct matrix{
	poly a[3][3];
	void clear(){
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				a[i][j].clear();
	}
	int max_siz(){
		int x=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				x=max(x,ssz(a[i][j]));
		return x;
	}
	friend matrix operator*(matrix A,matrix B){
		matrix C;
		C.clear();
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				for(int k=0;k<3;k++)
					C.a[i][j]=C.a[i][j]+A.a[i][k]*B.a[k][j];
		return C;
	}
};
matrix st;
void get_st(){
	st.a[0][0]=I+X;
	st.a[0][1]=O;
	st.a[0][2]=O;
	st.a[1][0]=I;
	st.a[1][1]=O;
	st.a[1][2]=O;
	st.a[2][0]=O;
	st.a[2][1]=O;
	st.a[2][2]=O;
}
int n,rt;
vector<int>g[N];
int siz[N],son[N],_size,id[N],top[N];
poly dp[N],sum[N],f[N],gx[N],ans;
matrix det[N];
vector<int>dv[N];
void dfs1(int u,int fa){
	siz[u]=1;
	son[u]=-1;
	for(int v:g[u]){
		if(v==fa)continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(son[u]==-1||siz[son[u]]<siz[v])
			son[u]=v;
	}
}
void dfs2(int u,int fa){
	if(son[u]!=-1){
		top[son[u]]=top[u];
		dv[top[son[u]]].push_back(son[u]);
		dfs2(son[u],u);
	}
	for(int v:g[u]){
		if(v==fa||v==son[u])continue;
		top[v]=v;
		dv[top[v]].push_back(v);
		dfs2(v,u);
	}
}
typedef pair<int,int>T;
void det_init(int u){
	det[u].a[0][0]=gx[u];
	det[u].a[0][1]=I;
	det[u].a[0][2]=O;
	det[u].a[1][0]=O;
	det[u].a[1][1]=I;
	det[u].a[1][2]=O;
	det[u].a[2][0]=I;
	det[u].a[2][1]=f[u];
	det[u].a[2][2]=I;
}
matrix rlt;
matrix solve(int l,int r,int u){
	if(l>r){
		matrix p;
		p.a[0][0]=I;
		p.a[1][1]=I;
		p.a[2][2]=I;
		return p;
	}
	if(l==r)return det[dv[u][l]];
	int mid=(l+r)>>1;
	return solve(l,mid,u)*solve(mid+1,r,u);
}
void print(poly x){
	cout<<x.size()<<"\n";
	for(int i=0;i<ssz(x);i++)
		cout<<x[i]<<(" \n"[i==ssz(x)-1]);
}
void dfs3(int u,int fa){
	if(son[u]!=-1)
		dfs3(son[u],u);
	priority_queue<T>q;
	for(int v:g[u]){
		if(v==fa||v==son[u])continue;
		dfs3(v,u);
		sum[v]=sum[v]+dp[v];
		q.push(T(-siz[v],v));
	}
	while(q.size()>1){
		auto [s1,x]=q.top();q.pop();
		auto [s2,y]=q.top();q.pop();
		dp[x]=dp[x]*dp[y];
		sum[x]=sum[x]+sum[y];
		q.push(T(s1+s2,x));
	}
	if(q.size()==1){
		int id=q.top().second;
		gx[u]=X*dp[id];
		f[u]=sum[id];
	}
	else{
		gx[u]=X;
		f[u]=O;
	}
	det_init(u);
	if(top[u]==u){
		int l=0,r=ssz(dv[u])-1;
		rlt=solve(l,r-1,u)*st;
		dp[u]=rlt.a[0][0];
		sum[u]=rlt.a[2][0];
	}
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		g[i].clear();
		dv[i].clear();
	}
	for(int i=2;i<=n;i++){
		int x;
		cin>>x;
		g[x].push_back(i);
		g[i].push_back(x);
	}
	dfs1(1,0);
	top[1]=1;
	dv[1].push_back(1);
	dfs2(1,0);
	dfs3(1,0);
	ans=sum[1]+dp[1];
	ans.resize(n+1);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<(" \n"[i==n]);
}
int main()
{
	// int size = 512 << 20; // 512M
	// __asm__("movq %0, %%rsp\n" :: "r"((char *)malloc(size) + size));
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	init(100000);
	get_st();
	int T_T=1;
	cin>>T_T;
	while(T_T--)solve();
	// exit(0);
	return 0;
}
/*
  1
  7
  1 1 1 2 2 2
  1
  2
  1
  1
  10
  1 1 1 2 3 2 3 3 4
  10
  1 1 1 2 3 2 3 3 4
 */
