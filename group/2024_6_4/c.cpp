#include<bits/stdc++.h>
#define int long long
using namespace std;
#define dbg(x...) \
do { \
	cout << #x << " -> "; \
	err(x); \
} while (0)
 
void err() {
	cout << endl;
}
 
template<class T, class... Ts>
void err(T arg, Ts ... args) {
	cout << fixed << setprecision(10) << arg << ' ';
	err(args...);
}
void solve(){
	int n,m;cin>>n>>m;
	vector<int>a(n+2),r(n+2);
	for(int i=2;i<=n+1;i++)cin>>a[i]>>r[i];
	vector<int>f(n+2);
	for(int i=1;i<=n+1;i++)f[i]=i;
	auto find = [&](auto self,int x)->int{
		return f[x]==x?x:f[x]=self(self,f[x]);
	};
	vector<double>val(n+5);
	val[1]=m;
	int ok=1;
	for(int i=2;i<=n+1;i++){
		double need=a[i]*5;
		for(int j=r[i]+1;j>=1;j--){
			j=find(find,j);
			//dbg(i,j);
			if(j<=0)break;
			if(val[j]>=need){
				val[j]-=need;
				need=0;
				break;
			}else{
				need-=val[j];
				val[j]=0;
				f[j]=j-1;
			}
		}
		if(need>0)ok=0;
		val[i]=a[i];
	}
	if(!ok){
		cout<<-1<<'\n';
		return ;
	}
	double ans=0;
	for(int j=n+1;j>=1;j--){
		j=find(find,j);
		if(j<=0)break;
		ans+=val[j]*1.0/5;
	}
	cout<<fixed<<setprecision(10)<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}