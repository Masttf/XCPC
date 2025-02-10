#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,m,k;cin>>n>>m>>k;
	vector<int>a(n+1);
	vector<int>b(m+1);
	int sum1=0;
	int sum2=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum1+=a[i];
	for(int i=1;i<=m;i++)cin>>b[i],sum2+=b[i];
	if(k%2==1)k=11;
	else k=10;
	for(int i=1;i<=k;i++){
		sort(a.begin()+1,a.end());
		sort(b.begin()+1,b.end());
		if(i%2==1){
			if(a[1]<b[m]){
				sum1+=b[m]-a[1];
				sum2+=a[1]-b[m];
				swap(a[1],b[m]);
			}
		}else{
			if(b[1]<a[n]){
				sum2+=a[n]-b[1];
				sum1+=b[1]-a[n];
				swap(b[1],a[n]);
			}
		}
	}
	cout<<sum1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
