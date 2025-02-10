#include<bits/stdc++.h>
using namespace std;
int l,n,k;
int res[1000005];
bool check(int x){
	int p=0;
	for(int i=2;i<=n;i++){
		if(res[i]-res[i-1]>x){
			if((res[i]-res[i-1])%x==0){
				p+=(res[i]-res[i-1])/x-1;
			}else p+=(res[i]-res[i-1])/x;
		}
	}
	return p<=k;
}
int main(){
	cin>>l>>n>>k;
	int mx=0,mi=l;
	for(int i=1;i<=n;i++){
		cin>>res[i];
		mx=max(mx,res[i]);
		mi=min(mi,res[i]);
	}
	int ans=0,left=1,right=mx-mi;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,right=mid-1;
		else left=mid+1;
	}
	cout<<ans;
	return 0;
}
