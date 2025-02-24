#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,d;cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=-1;
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]<=d){
			ans=a[i];
			break;
		}
	}
	cout<<ans;
	return 0;
}
