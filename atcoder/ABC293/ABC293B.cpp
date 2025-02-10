#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
bool vis[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[a[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])cnt++;
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++){
		if(!vis[i])cout<<i<<' ';
	}
	return 0;
}
