#include<bits/stdc++.h>
#define int long long
using namespace std;
string a[105];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<m-1;j++){
			if(a[i][j]==a[i][j+1]&&a[i][j]=='T'){
				a[i][j]='P';
				a[i][j+1]='C';
			}
		}
	}
	for(int i=0;i<n;i++)cout<<a[i]<<'\n';
	return 0;
}
