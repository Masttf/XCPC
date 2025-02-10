//看自身的2 与5 然后凑尽可能多的零，最后乘10
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int t;cin>>t;
	for(int i=1;i<=t;i++){
		int n,m;cin>>n>>m;
		int temp1=n;
		int c2=0,c5=0;
		//拿到2与5的个数
		while(temp1%2==0){
			c2++;
			temp1/=2;
		}
		while(temp1%5==0){
			c5++;
			temp1/=5;
		}
		int v=1;
		if(c2>c5){
			int d=c2-c5;
			while(d&&v*5<=m)v*=5,d--;
		}else if(c2<c5){
			int d=c5-c2;
			while(d&&v*2<=m)v*=2,d--;
		}
		//自身不能造0了看能否乘10
		while(v*10<=m){
			v*=10;
		}
		m/=v;
		cout<<n*v*m<<'\n';
	}
	return 0;
}
