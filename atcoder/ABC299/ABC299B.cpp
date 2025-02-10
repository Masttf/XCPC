#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,t;
	cin>>n>>t;
	int res1=-1,res2=-1;
	int flag=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>b[i];
		if(a[i]==a[1]){
			if(res1==-1||b[res1]<b[i])res1=i;
		}
		if(a[i]==t){
			flag=1;
			if(res2==-1||b[res2]<b[i])res2=i;
		}
	}
	if(flag)cout<<res2;
	else cout<<res1;
	return 0;
}
