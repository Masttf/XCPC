#include<bits/stdc++.h>
#define int long long
using namespace std;
int exgcd(int a,int b,int &x,int &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int a,b;cin>>a>>b;
	int x,y;
	int d=exgcd(a,b,x,y);
	x=(x%b+b)%b;
	cout<<x;
	return 0;
}
