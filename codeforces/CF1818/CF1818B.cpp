#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1005;
int a[maxn];
void solve(){
	int n;cin>>n;
	if(n==1){
		cout<<1<<'\n';
		return ;
	}
	if((1+n)*n/2%n==0){
		cout<<-1<<'\n';
		return ;
	}
	for(int i=2;i<=n;i+=2){
		a[i-1]=i;
	}
	for(int i=1;i<=n;i+=2){
		a[i+1]=i;
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
