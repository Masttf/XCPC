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
const int Max=1e18;
void solve(){
	int n,s,k;cin>>n>>s>>k;
	vector<int>ans(n+1,1);
	s-=n;
	if(k==0){
		ans[1]+=s;
		for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
		cout<<'\n';
		return ;
	}
	if(k*2+1>n){
		cout<<-1<<'\n';
		return ;
	}
	s--;
	ans[1]++;
	for(int i=1;i<=k;i++){
		ans[i*2+1]=2;
		s--;
	}
	if(s<0){
		cout<<-1<<'\n';
		return ;
	}
	if(k*2+1==n){
		for(int i=1;i<=n;i+=2)ans[i]+=s/(k+1);
		s%=(k+1);
		for(int i=2;i<=n;i+=2)ans[i]+=s/k;
		s%=k;
		for(int i=2;i<=n;i+=2){
			if(s){
				ans[i]++;
				s--;
			}
		}
		int ok=1;
		for(int i=2;i<=n;i+=2){
			if(ans[i]>=ans[i-1])ok=0;
		}
		if(!ok){
			cout<<-1<<'\n';
			return ;
		}
	}else{
		ans[(k+1)*2]+=s;
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}