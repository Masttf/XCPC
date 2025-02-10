#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e7+5;
const int mod=1e9+7;
int g[maxn],sum[maxn];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;cin>>n;
	if(n==1){
		cout<<1<<'\n';
		return 0;
	}
	else if(n==2){
		cout<<2<<'\n';
		return 0;
	}
	else if(n==3){
		cout<<2<<'\n';
		return 0;
	}
	g[1]=1;
	g[2]=2;
	int l=2;
	sum[1]=1;
	sum[2]=3;
	for(int i=3;i<=10000000;i++){
		if(sum[l]<i)l++;
		g[i]=l;
		sum[i]+=sum[i-1];
		sum[i]+=l;
	}
	int sum1=5;//表示再派生一层后的数量
	int now=3;
	int i=3;
	while(1){
		sum1+=i*g[i];
		if(sum1>n){
			cout<<(now+(n-sum1+i*g[i]+i-1)/i);
			break;
		}
		now+=g[i];
		i++;
	}	
	return 0;
}
