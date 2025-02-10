#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int a[maxn];
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l=1,r=1;
	int len=0;
	while(r<=n){
		r++;
		len++;
		while(len>1&&a[l]<len){
			l++;
			len--;
		}
		cout<<len<<' ';
	}
	cout<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t ;cin>>t;
	while(t--)solve();
	return 0;
}
