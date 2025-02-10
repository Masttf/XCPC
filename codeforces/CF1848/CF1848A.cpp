#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int x[maxn],y[maxn];
void solve(){
	int n,m,k;cin>>n>>m>>k;
	cin>>x[0]>>y[0];
	for(int i=1;i<=k;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=k;i++){
		if((abs(x[i]-x[0])+abs(y[i]-y[0]))%2==0){
			cout<<"NO\n";
			return ;
		}
	}
	cout<<"YES\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
