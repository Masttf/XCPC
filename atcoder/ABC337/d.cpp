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
	int n,m,k;cin>>n>>m>>k;
	vector<string>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	int ans=-1;
	auto get = [&](int x)->void{
		if(m<k)return ;
		int res1=0,res2=0;
		for(int i=1;i<=k;i++){
			if(a[x][i]=='o')res1++;
			else if(a[x][i]=='.')res2++;
		}
		if(res1+res2==k){
			if(ans==-1||ans>res2){
				ans=res2;
			}
		}
		for(int i=k+1;i<=m;i++){
			if(a[x][i-k]=='o')res1--;
			else if(a[x][i-k]=='.')res2--;
			if(a[x][i]=='o')res1++;
			else if(a[x][i]=='.')res2++;
			if(res1+res2!=k)continue;
			if(ans==-1||ans>res2){
				ans=res2;
			}
			//dbg(x,i,res1,res2,ans);
		}
	};
	auto get2 = [&](int x)->void{
		if(n<k)return ;
		int res1=0,res2=0;
		for(int i=1;i<=k;i++){
			if(a[i][x]=='o')res1++;
			else if(a[i][x]=='.')res2++;
		}
		if(res1+res2==k){
			if(ans==-1||ans>res2){
				ans=res2;
			}
		}
		for(int i=k+1;i<=n;i++){
			if(a[i-k][x]=='o')res1--;
			else if(a[i-k][x]=='.')res2--;
			if(a[i][x]=='o')res1++;
			else if(a[i][x]=='.')res2++;
			if(res1+res2!=k)continue;
			if(ans==-1||ans>res2){
				ans=res2;
			}
		}
	};
	for(int i=1;i<=n;i++)get(i);
	for(int i=1;i<=m;i++)get2(i);
	if(ans==-1)cout<<-1<<'\n';
	else{
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