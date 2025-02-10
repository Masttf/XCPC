#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	int f=0;
	for(int i=1;i<n;i++){
		if(a[i]<0&&a[i+1]<0){
			f=1;
			break;
		}else if(a[i]*a[i+1]<0){
			f=2;
		}
	}
	if(f==1)cout<<sum+4<<'\n';
	else if(f==2)cout<<sum<<'\n';
	else cout<<sum-4<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
