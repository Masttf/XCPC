#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500;
int a[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int p1=0,p2=0;
	int p3=0;
	int p4=0,p5=0;
	for(int i=1;i<=8;i++){
		if(s[i-1]=='R'&&!p1)p1=i;
		else if(s[i-1]=='R'&&p1)p2=i;
		if(s[i-1]=='K')p3=i;
		if(s[i-1]=='B'&&!p4)p4=i;
		else if(s[i-1]=='B'&&p4)p5=i;
	}
	if(p1<p3&&p3<p2&&(p4%2!=p5%2))cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
