#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m;cin>>n>>m;
	vector<string>a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	
	vector<string>ans=a;
	int ok=1;
	int flag=1;
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=0;j<m;j++){
			if(a[i][j]=='U'){
				cnt++;
				if(flag){
					ans[i][j]='W';
					ans[i+1][j]='B';
				}else{
					ans[i][j]='B';
					ans[i+1][j]='W';
				}
				flag=1-flag;
			}
		}
		if(cnt%2!=0)ok=0;
	}
	flag=1;
	for(int j=0;j<m;j++){
		int cnt=0;
		for(int i=0;i<n;i++){
			if(a[i][j]=='L'){
				cnt++;
				if(flag){
					ans[i][j]='W';
					ans[i][j+1]='B';
				}else{
					ans[i][j]='B';
					ans[i][j+1]='W';
				}
				flag=1-flag;
			}
		}
		if(cnt%2!=0)ok=0;
	}
	if(ok){
		for(int i=0;i<n;i++)cout<<ans[i]<<'\n';
	}else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
