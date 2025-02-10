#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int c1=0,c2=0;
	for(int i=1;i<=n;i++){
		if(a[i]<0)c2++;
		else c1++;
	}
	int cnt=0;
	while(c1<c2||c2%2!=0){
		c1++;
		c2--;
		cnt++;
	}
	cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
