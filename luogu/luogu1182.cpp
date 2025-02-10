//明显子数组和与段数具有单调性
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+5;
int n,k;
int res[maxn];
bool check(int x){
	int cur=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cur+res[i]<=x){
			cur+=res[i];
		}else{
			cur=res[i];
			cnt++;
		}
	}
	if(cur)cnt++;
	return cnt<=k;
}
signed main(){
	cin>>n>>k;
	int sum=0;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		sum+=res[i];
		mx=max(mx,res[i]);
	}
	int ans=-1,left=mx,right=sum;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,right=mid-1;
		else left=mid+1;
	}
	cout<<ans;
	return 0;
}
