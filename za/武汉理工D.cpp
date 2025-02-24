#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;cin>>t;
	int n;
	while(t--){
		cin>>n;
		int sum=0;
		int a;
		int ci;
		int mi=9999999999;
		for(int i=1;i<=n;i++){
			cin>>a;
			sum+=a;
			if(mi>sum){
				mi=sum;
				ci=i;
			}
		}
		if(ci==n)mi-=a;
		int d=sum*514-mi*400;
		if(d>=0)cout<<d<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
