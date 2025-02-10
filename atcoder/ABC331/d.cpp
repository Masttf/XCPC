#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)

void err() {
	cout<<endl<<endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout<<fixed<<setprecision(10)<<arg<< ' ';
	err(args...);
}
void solve(){
	int n,q;cin>>n>>q;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	vector pre(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+(a[i][j]=='B');
		}
	}
	for(int _=1;_<=q;_++){
		int a,b,c,d;cin>>a>>b>>c>>d;
		a++;b++;c++;d++;
		int k=a/n;
		a-=n*k;
		if(!a)a+=n,k--;
		c-=n*k;
		k=b/n;
		b-=n*k;
		if(!b)b+=n,k--;
		d-=n*k;
		if(c<=n&&d<=n){
			cout<<pre[c][d]-pre[a-1][d]-pre[c][b-1]+pre[a-1][b-1]<<'\n';
			continue;
		}
		//dbg(a,b,c,d);
		int d1=max(0ll,(d+n-1)/n-(b+n-1)/n-1);
		int d2=max(0ll,(c+n-1)/n-(a+n-1)/n-1);
		int ans=0;
		ans+=d1*d2*pre[n][n];
		//dbg(d1,d2,ans);
		if(c<=n){
			ans+=d2*(pre[n][n]-pre[n][b-1]);
			int temp1=d%n;
			if(!temp1)temp1+=n;
			ans+=d2*pre[n][temp1];

			ans+=pre[c][n]-pre[a-1][n]-pre[c][b-1]+pre[a-1][b-1];
			ans+=d1*(pre[c][n]-pre[a-1][n]);
			int t1=d%n;
			if(!t1)t1+=n;
			ans+=pre[c][t1]-pre[a-1][t1];
		}else if(d<=n){
			ans+=d1*(pre[n][n]-pre[a-1][n]);
			int temp1=c%n;
			if(!temp1)temp1+=n;
			ans+=d1*pre[temp1][n];

			ans+=d2*(pre[n][d]-pre[n][b-1]);
			ans+=pre[n][d]-pre[a-1][d]-pre[n][b-1]+pre[a-1][b-1];
			int t1=c%n;
			if(!t1)t1+=n;
			ans+=pre[t1][d]-pre[t1][b-1];
		}else{
			ans+=d1*(pre[n][n]-pre[a-1][n]);
			int temp1=c%n;
			if(!temp1)temp1+=n;
			ans+=d1*pre[temp1][n];

			ans+=d2*(pre[n][n]-pre[n][b-1]);
			temp1=d%n;
			if(!temp1)temp1+=n;
			ans+=d2*pre[n][temp1];

			ans+=pre[n][n]-pre[a-1][n]-pre[n][b-1]+pre[a-1][b-1];
			int t1=c%n;
			if(!t1)t1+=n;
			int t2=d%n;
			if(!t2)t2+=n;
			ans+=pre[t1][t2];

			ans+=pre[n][t2]-pre[a-1][t2];
			ans+=pre[t1][n]-pre[t1][b-1];
		}
		cout<<ans<<'\n';
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}