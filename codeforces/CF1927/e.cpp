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
	int n,k;cin>>n>>k;
	vector<int>ans(n+1);
	int l=1,r=n;
	for(int i=1;i<=k;i++){
		if(i%2==0){
			int x=i;
			while(x<=n){
				//dbg(x,l);
				ans[x]=l;
				l++;
				x+=k;
			}
		}else{
			int x=i;
			while(x<=n){
				//dbg(x,r);
				ans[x]=r;
				r--;
				x+=k;
			}
		}
	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<" \n"[i==n];
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}