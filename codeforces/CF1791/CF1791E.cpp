#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	int sum=0,cnt=0;
	int mi=INT_MAX;
	for(int i=1;i<=n;i++){
		cin>>a[i],sum+=abs(a[i]);//考虑传递
		mi=min(mi,abs(a[i]));
		if(a[i]<0){
			cnt++;
		}
	}
	if(cnt%2==0)cout<<sum<<'\n';
	else cout<<sum-2*mi<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
