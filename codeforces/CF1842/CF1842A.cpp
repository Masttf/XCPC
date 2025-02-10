#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=55;
int a[maxn],b[maxn];
void solve(){
	int n,m;cin>>n>>m;
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum1+=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],sum2+=b[i];
	if(sum1>sum2){
		cout<<"Tsondu\n";
		return ;
	}else if(sum1==sum2){
		cout<<"Draw\n";
		return ;
	}else{
		cout<<"Tenzing\n";
		return ;
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
