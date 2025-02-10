#include<bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;cin>>n;
	int c1=0,c2=0,c3=0,c4=0;
	c1=1;
	n-=1;
	int first=5,flag=0;
	while(n){
		int temp=first;
		if(n<=first){
			temp=n;
		}
		if(!flag){
			c3+=temp/2;//3表示白
			c4+=temp-temp/2;
		}else{
			c2+=temp/2;
			c1+=temp-temp/2;
		}
		flag=1-flag;
		n-=temp;
		first+=4;
	}
	cout<<c1<<' '<<c2<<' '<<c3<<' '<<c4<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
