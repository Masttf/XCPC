#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a,b;
	while(n){
		int t=n%10;
		if(t%2==0){
			a.push_back(t/2);
			b.push_back(t/2);
		}else{
			a.push_back(t/2+1);
			b.push_back(t/2);
			swap(a,b);
		}
		n/=10;
	}
	while(a.size()>1&&a[a.size()-1]==0)a.erase(a.end()-1);
	while(b.size()>1&&b[b.size()-1]==0)b.erase(b.end()-1);
	for(int i=a.size()-1;i>=0;i--)cout<<a[i];
	cout<<' ';
	for(int i=b.size()-1;i>=0;i--)cout<<b[i];
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
