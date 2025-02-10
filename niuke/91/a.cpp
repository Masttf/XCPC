#include<bits/stdc++.h>
#define int long long
using namespace std;
string res1="...|......_...../.\\....|.|....\\_/\\........";
string res2="...|......_...../.\\/...|.|....\\_/\\........";
string res3="...|......_...../.\\....|.|....\\_/.....|...";
void solve(){
	vector<string>a(10);
	for(int i=1;i<=6;i++){
		cin>>a[i];
		a[i]=' '+a[i];
	}
	if(a[1][4]=='.'){
		cout<<'o';
		return ;
	}
	if(a[6][4]=='.')cout<<'m';
	else cout<<'p';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}