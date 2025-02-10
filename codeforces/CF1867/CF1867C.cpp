#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int res=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==res)res++;
	}
	int x=res,y;
	do{
		cout<<x<<endl;
		cin>>y;
		x=y;
	}while(y!=-1);
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;cin>>t;
	while(t--)solve();
	return 0;
}
