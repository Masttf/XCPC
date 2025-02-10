#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int ca=0,cb=0;
	ca=1;
	n-=1;
	int first=5,flag=0;
	while(n){
		int temp=first;
		if(n<=first){
			temp=n;
		}
		if(!flag){
			cb+=temp;
		}else{
			ca+=temp;
		}
		flag=1-flag;
		n-=temp;
		first+=4;
	}
	cout<<ca<<' '<<cb<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
