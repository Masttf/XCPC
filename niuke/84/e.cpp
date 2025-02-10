#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	int mi=INT_MAX;
	for(int i=1;i<=n;i++){
		mi=min(a[i],mi);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==mi)cnt++;
	}
	sort(a.begin()+1,a.end());
	if(mi==0&&2*cnt>=n){
		cout<<"Dog\n";
		return ;
	}
	if(n==2){
		if(a[2]==a[1]+1){
			cout<<"Cat\n";
		}else cout<<"Dog\n";
		return ;
	}
	int sum=0;
	for(int i=1;i<=(n+1)/2-1;i++){
		sum+=a[i];
	}
	for(int i=(n+1)/2;i<=n;i++){
		sum+=a[i]-1;
	}
	sum++;
	sum%=2;
	if(sum%2==0)cout<<"Cat\n";
	else cout<<"Dog\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}