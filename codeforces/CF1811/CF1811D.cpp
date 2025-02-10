#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=50;
int f[maxn];
void solve(){
	int n,x,y;cin>>n>>x>>y;
	while(n!=1){
		if(y>=f[n]+1)y-=f[n];
		swap(x,y);
		n--;
	}
	if(x==1&&(y==1||y==2))cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	f[0]=1;
	f[1]=1;
	for(int i=2;i<=44;i++){
		f[i]=f[i-1]+f[i-2];
	}
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
