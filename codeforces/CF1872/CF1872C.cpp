#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int l,r;cin>>l>>r;
	if(r<=3){
		cout<<-1<<'\n';
		return ;
	}
	if(r-l>=1){
		if(r%2==0)cout<<2<<' '<<r-2<<'\n';
		else cout<<2<<' '<<r-3<<'\n';
		return ;
	}else{
		int temp=r;
		for(int i=2;i<=sqrt(r);i++){
			if(r%i==0){
				while(r%i==0){
					r/=i;
				}
				if(temp/i>=2){
					cout<<i<<' '<<(temp/i-1)*i<<'\n';
					return ;
				}
			}
		}
	}
	cout<<-1<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
