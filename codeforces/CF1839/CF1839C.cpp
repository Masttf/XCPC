#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	vector<int>b;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[n]==1){
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
	for(int i=n;i>=1;i--){
		if(a[i]==0)b.push_back(0);
		else{
			int j=i;
			while(j>=1&&a[j]==a[i])j--;
			j++;
			for(int k=1;k<i-j+1;k++)b.push_back(0);
			b.push_back(i-j+1);
			i=j;
		}
	}
	for(auto x:b)cout<<x<<' ';
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
