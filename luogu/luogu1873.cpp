#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e6+5;
int res[MAX];
int n,m;
bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=max(0ll,res[i]-x);
	}
	return sum>=m;
}
signed main(){
	cin>>n>>m;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		mx=max(mx,res[i]);
	}
	int ans=0,left=0,right=mx;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,left=mid+1;
		else right=mid-1;
	}
	cout<<ans;
	return 0;
}
