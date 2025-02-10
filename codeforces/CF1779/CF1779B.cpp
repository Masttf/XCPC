#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	if(n%2==0){
		cout<<"yes\n";
		int t=1;
		for(int i=1;i<=n;i++){
			cout<<t<<' ';
			if(t==1)t=-1;
			else t=1;
		}
		cout<<'\n';
	}else{//肯定有负
		if(n==3)cout<<"no\n";
		else{
			cout<<"yes\n";
			int t=n/2-1;
			int q=-t-1;
			for(int i=1;i<=n;i++){
				if(i%2==0)cout<<q<<' ';
				else cout<<t<<' ';
			}
			cout<<'\n';
		}
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
