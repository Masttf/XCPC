#include<bits/stdc++.h>
using namespace std;
const int N=30,M=1e7+7,p=998244353;
int n,f1[M],f2[M],w[N];
long long pows(long long u,int v){
	long long ans=1;
	while(v>0){
		if(v&1) ans=ans*u%p; u=u*u%p,v=v>>1;
	}
	return ans;
}
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout); 
	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
	f1[0]=1;
	for(int i=1;i<=10000000;i++) f1[i]=1ll*f1[i-1]*i%p;
	f2[10000000]=pows(f1[10000000],p-2);
	for(int i=10000000;i>=1;i--) f2[i-1]=1ll*f2[i]*i%p;
	int T;
	cin>>T;
	while(T--){
		memset(w,0,sizeof(w)),cin>>n; int S=0;
		for(int i=1;i<=n;i++){
			char g; cin>>g; while(g<'a'||'z'<g) cin>>g;
			cin>>w[g-'a'],S+=w[g-'a'];
		}
		if(S%2==0){
			int c=f2[S];
			for(int i=0;i<=25;i++) c=1ll*c*f1[w[i]]%p;
			c=1ll*c*f1[S/2]%p;
			for(int i=0;i<=25;i++)
				if(w[i]%2==1) c=0;
				else c=1ll*c*f2[w[i]/2]%p;
			cout<<1ll*(1-c+p)*f2[2]%p<<endl;
		}
		else{
			int c=f2[S],x=0;
			for(int i=0;i<=25;i++) c=1ll*c*f1[w[i]]%p;
			for(int i=0;i<=25;i++) x+=(w[i]%2);
			if(x!=1){
				cout<<f2[2]<<endl;
			}
			else{
				c=1ll*c*f1[S/2]%p;
				for(int i=0;i<=25;i++) c=1ll*c*f2[w[i]/2]%p;
				cout<<1ll*(1+c)*f2[2]%p<<endl;
			}
				
		}
	}
	return 0;
}
//1
//3
//a 1
//b 4
//c 2
