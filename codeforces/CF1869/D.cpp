#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int sum=0;
	for(int i=1;i<=n;i++)cin>>a[i],sum+=a[i];
	if(sum%n!=0){
		cout<<"No\n";
		return ;
	}
	sum/=n;
	vector<int>cnt(35);
	int ok=1;
	for(int i=1;i<=n;i++){
		if(a[i]==sum)continue;
		int p=-1;
		int d=a[i]-sum;
		int f=1;
		if(d<0)d=-d,f=0;
		for(int j=32;j>=0;j--){
			if(d>>j&1){
				if(p==-1){
					if(f)cnt[j+1]++;
					else cnt[j+1]--;
				}else{
					if(j!=p-1)ok=0;
				}
				p=j;
			}
		}
		if(f)cnt[p]--;
		else cnt[p]++;
		// for(int j=5;j>=0;j--)cout<<cnt[j]<<' ';
		// cout<<endl;
	}
	for(int i=0;i<=32;i++){
		if(cnt[i]!=0)ok=0;
	}
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}