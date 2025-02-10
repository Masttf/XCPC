//即中位数这个区间内大于和小于的数相等
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int res[maxn],psum[maxn],c[2*maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,b;cin>>n>>b;
	int id=0;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		if(res[i]>b)res[i]=1;
		else if(res[i]<b)res[i]=-1;
		if(res[i]==b)id=i,res[i]=0;
	}
	for(int i=1;i<=n;i++)psum[i]=psum[i-1]+res[i];
	for(int i=0;i<id;i++){
		c[psum[i]+maxn]++;
	}
	int cnt=0;
	for(int i=n;i>=id;i--){
		cnt+=c[maxn+psum[i]];
	}
	cout<<cnt;
	return 0;
}
