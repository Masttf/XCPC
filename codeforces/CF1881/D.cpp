#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	map<int,int>m;
	for(int i=1;i<=n;i++){
		int temp=a[i];
		for(int j=2;j*j<=temp;j++){
			if(temp%j==0){
				int cnt=0;
				while(temp%j==0){
					cnt++;
					temp/=j;
				}
				m[j]+=cnt;
			}
		}
		if(temp!=1)m[temp]++;
	}
	int ok=1;
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second%n!=0)ok=0;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}