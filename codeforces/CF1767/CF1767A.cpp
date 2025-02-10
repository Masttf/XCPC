#include<bits/stdc++.h>
using namespace std;
void solve(){
	int x1,x2,x3,y1,y2,y3;cin>>x1>>y1>>x2>>y2>>x3>>y3;//判断直角
	if((x1==x2&&y1==y3)||(x2==x3&&y1==y2)||
		(x1==x3&&y3==y2)||(x1==x3&&y1==y2)||(x2==x1&&y2==y3)||(x3==x2&&y3==y1))cout<<"NO"<<'\n';
	else cout<<"YES"<<'\n';
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
