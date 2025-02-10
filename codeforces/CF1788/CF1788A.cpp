#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e3+5;
int a[maxn],cnt[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cnt[i]=0;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==2)f++,cnt[i]++;
	}
	if(f%2==0){
		for(int i=1;i<=n;i++){
			cnt[i]+=cnt[i-1];
			if(cnt[i]==f/2){
				cout<<i<<'\n';
				break;
			}
		}
	}else cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
