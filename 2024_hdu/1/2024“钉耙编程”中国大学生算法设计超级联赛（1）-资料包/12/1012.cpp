#include<bits/stdc++.h>
using namespace std;
const int N=4e3+7,p=998244353; 
int n,f[N][4],x[N],y[N],w[N][N],g[N],q[N],ans[N],C[N][N]; unordered_map<int,int>A,B;
long long pows(long long u,int v){
	long long ans=1;
	while(v>0){
		if(v&1) ans=ans*u%p; u=u*u%p,v=v>>1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	cin>>n;
	for(int i=0;i<=4000;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=3;j++) cin>>f[i][j];
		x[++x[0]]=f[i][0],x[++x[0]]=f[i][2],y[++y[0]]=f[i][1],y[++y[0]]=f[i][3];
	}
	sort(x+1,x+x[0]+1);
	memset(q,0,sizeof(q));
	for(int i=1;i<=n*2;i++) if(x[i]!=x[i+1]) q[++q[0]]=x[i];
	memset(x,0,sizeof(x));
	for(int i=1;i<=2*n;i++) x[i]=q[i];
	sort(y+1,y+y[0]+1);
	memset(q,0,sizeof(q));
	for(int i=1;i<=n*2;i++) if(y[i]!=y[i+1]) q[++q[0]]=y[i];
	memset(y,0,sizeof(y));
	for(int i=1;i<=2*n;i++) y[i]=q[i];
//	cerr<<"sss"<<endl; 
	for(int i=2*n;i>=1;i--) A[x[i]]=i,B[y[i]]=i;
	
	for(int i=1;i<=n;i++){
		f[i][0]=A[f[i][0]];
		f[i][1]=B[f[i][1]];
		f[i][2]=A[f[i][2]];
		f[i][3]=B[f[i][3]];
//		cerr<<f[i][0]<<","<<f[i][1]<<","<<f[i][2]<<","<<f[i][3]<<endl;
		w[f[i][0]][f[i][1]]++;
		w[f[i][2]][f[i][1]]--;
		w[f[i][0]][f[i][3]]--;
		w[f[i][2]][f[i][3]]++;
	}
	long long S=0;
	for(int i=1;i<=2*n;i++)
		for(int j=1;j<=2*n;j++) w[i][j]+=w[i][j-1]; x[0]=y[0]=0;
	for(int i=1;i<=2*n;i++){
		for(int j=1;j<=2*n;j++){
			w[i][j]+=w[i-1][j],g[w[i][j]]=(g[w[i][j]]+1ll*(x[i+1]-x[i])*(y[j+1]-y[j]))%p;
		}
	}
	for(int i=1;i<=n;i++) S=(S+g[i])%p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) ans[j]=(ans[j]-1ll*C[n-i][j]*g[i]%p+p)%p;
	}
	for(int i=1;i<=n;i++) ans[i]=(ans[i]*pows(C[n][i],p-2)%p+S)%p;
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	return 0;
}
//4
//1 1 2 2
//3 3 4 4
//1 1 4 4
//2 2 100 100
