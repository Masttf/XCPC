#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d;
void get(int x){
	int temp1=x%(a+b);
	int ans=0;
	if(temp1<=a&&temp1!=0)ans++;
	
	int temp2=x%(c+d);
	if(temp2<=c&&temp2!=0)ans++;
	if(ans==2)cout<<"both\n";
	else if(ans==1)cout<<"one\n";
	else cout<<"none\n";
	return ;
}
void solve(){
	cin>>a>>b>>c>>d;
	for(int i=1;i<=3;i++){
		int x;cin>>x;
		get(x);
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}