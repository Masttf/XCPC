//容易得到跳跃距离越短则移除数量越少
#include<bits/stdc++.h>
using namespace std;
int l,n,m;
int res[50005];
bool check(int x){
	int p=0;
	int flag=0;
	int temp=n;
	while(l-res[temp]<x)temp--,p++;
	for(int i=1;i<=temp;i++){
		if(res[i]-res[flag]>=x){
			flag=i;
		}else{
			p++;
		}
	}
	return p<=m;
}
int main(){
	cin>>l>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	int ans=0,left=1,right=l;
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,left=mid+1;
		else right=mid-1;
	}
	cout<<ans;
	return 0;
}
