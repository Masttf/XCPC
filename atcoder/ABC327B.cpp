#include<bits/stdc++.h>
#define int __int128
using namespace std;
int qmi(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
void solve(){
	long long b;cin>>b;
	long long i=1;
	while(1){
		int d=qmi(i,i);
		if(d>b)break;
		if(d==b){
			cout<<i;
			return ;
		}
		i++;
	}
	cout<<-1;
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t=1;
	while(t--)solve();
	return 0;
}