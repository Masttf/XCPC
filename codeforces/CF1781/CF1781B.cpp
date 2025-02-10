#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int res[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>res[i];//至少有ai人才去,如果他不去人数一定要小于a[i]
	sort(res+1,res+1+n);
	int cnt=1,cur=n;//都去
	for(int i=n;i>=1;i--){
		cur--;
		while(i!=1&&res[i]==res[i-1])i--,cur--;
		if(cur<res[i]){
			if(max(cur-1,0LL)>=res[i-1])cnt++;
		}
	}
	cout<<cnt<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}//0/ 2 3 3/ 6 6 7 7
