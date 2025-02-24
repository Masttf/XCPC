#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=105,M=1e5+5;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<a[1]<<' ';
	for(int i=2;i<=n;i++){
		if(a[i-1]>a[i]){
			for(int j=a[i-1]-1;j>=a[i];j--)cout<<j<<' ';
		}else{
			for(int j=a[i-1]+1;j<=a[i];j++)cout<<j<<' ';
		}
	}
	return 0;
}
