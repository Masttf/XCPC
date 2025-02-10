#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int a1,a2,a3,a4;
	cin>>a1>>a2>>a3>>a4;
	if(a1==0)cout<<1<<'\n';
	else{
		int h1=a1,h2=a1;
		if(h1+a2-a3>=0&&h2+a3-a2>=0){//用到第四个
			cout<<h1+a2+a3+min(a4,min(h1+a2-a3,h2+a3-a2)+1)<<'\n';
		}else{
			if(h1+a2-a3<0&&h2+a3-a2<0){
				cout<<max((h1+a2)*2+1,(h2+a3)*2+1)<<'\n';
			}
			else if(h1+a2-a3<0){
				cout<<(h1+a2)*2+1<<'\n';
			}else cout<<(h2+a3)*2+1<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
