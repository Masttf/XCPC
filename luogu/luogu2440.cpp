//枚举即l的值明显具有单调性
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int res[maxn];
int mx=0;
int n,k;
bool check(int x){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=res[i]/x;
	}
	return sum>=k;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		mx=max(mx,res[i]);
	}
	int ans=0,left=1,right=mx;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,left=mid+1;
		else right=mid-1;
	}
	cout<<ans;
	return 0;
}
