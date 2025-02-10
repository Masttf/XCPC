#include<bits/stdc++.h>
using namespace std;
int n,m;
const int MAX=100005;
int ad[MAX];
bool check(int x){
	//第一个栅栏一定放牛
	int p=m-1;
	int flag=1;
	for(int i=2;i<=n;i++){
		if(p==0)break;
		if(ad[i]-ad[flag]>=x){
			p--;
			flag=i;
		}
	}
	return p==0;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ad[i];
	}
	sort(ad+1,ad+1+n);
	int ans=-1,left=1,right=ad[n]-ad[1];
	while(left<=right){
		int mid=(left+right)>>1;
		if(check(mid))ans=mid,left=mid+1;
		else right=mid-1;
	}
	cout<<ans;
	return 0;
}
