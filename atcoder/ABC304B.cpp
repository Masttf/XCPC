#include<bits/stdc++.h>
#define int long long
using namespace std;
int maxn=1e3-1;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;cin>>n;
	if(n<=maxn)cout<<n<<'\n';
	else if(n<=1e4-1){
		int d=n/10;
		cout<<d*10<<'\n';
	}else if(n<=1e5-1){
		int d=n/100;
		cout<<d*100<<'\n';
	}else if(n<=1e6-1){
		int d=n/1000;
		cout<<d*1000<<'\n';
	}else if(n<=1e7-1){
		int d=n/10000;
		cout<<d*10000<<'\n';
	}else if(n<=1e8-1){
		int d=n/100000;
		cout<<d*100000<<'\n';
	}else{
		int d=n/1000000;
		cout<<d*1000000<<'\n';
	}
	return 0;
}
