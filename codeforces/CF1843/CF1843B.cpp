#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	int res=0,cnt=0;
	for(int i=1;i<=n;i++)cin>>a[i],res+=abs(a[i]);
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			int j=i;
			while(j<=n&&a[j]<=0)j++;
			cnt++;
			j--;
			i=j;
		}
	}
	cout<<res<<' '<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
