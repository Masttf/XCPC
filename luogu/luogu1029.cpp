#include<bits/stdc++.h>
#define int long long
using namespace std;
bool juduge(int q,int i,int x){
	int c;
	while(q>0){
		c=i%q;
		i=q;
		q=c;
	}
	if(i==x)return 1;
	else return 0;
}
signed main(){
	int x,y;
	cin>>x>>y;
	int cnt=0;
	for(int i=x;i*i<=x*y;i+=x){
		if(x*y%i!=0){
			continue;
		}
		if(juduge(i,x*y/i,x)){
			cnt+=2;
		}
	}
	if(x==y)cnt--;
	cout<<cnt;
	return 0;
}
