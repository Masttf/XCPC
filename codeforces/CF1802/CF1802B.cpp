#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){//未检查出来的一只一个检查出来的两只一个
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ans=0,now=0,cnt=0;;//最多的情况肯定是一个女或者一个男
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			cnt++;
			if(now==ans){
				ans++;
			}
			now++;
		}
		else{
			if(cnt>0){
				now=1;
				now+=cnt/2;
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
