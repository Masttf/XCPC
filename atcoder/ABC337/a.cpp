#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int sum1=0,sum2=0;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x>>y;
		sum1+=x;
		sum2+=y;
	}
	if(sum1>sum2){
		cout<<"Takahashi\n";
	}else if(sum1<sum2){
		cout<<"Aoki\n";
	}else{
		cout<<"Draw\n";
	}
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;
	while(t--)solve();
	return 0;
}