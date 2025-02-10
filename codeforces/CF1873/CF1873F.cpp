#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n,k;cin>>n>>k;
	vector<int>a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	int len=0;
	vector<int>l(n+1);
	for(int i=1;i<=n;i++){
		l[i]=i;
		int j=i+1;
		while(j<=n&&a[j-1]%a[j]==0){
			l[j]=i;
			j++;
		}
		i=j-1;
	}
	vector<int>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+b[i];
	}
	for(int i=1;i<=n;i++){
		int ll=1;
		int rr=i-l[i]+1;
		while(ll<=rr){
			int mid=(ll+rr)>>1;
			int b=i-mid;
			if(pre[i]-pre[b]>k){
				rr=mid-1;
			}else{
				len=max(len,mid);
				ll=mid+1;
			}
		}
	}
	cout<<len<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
