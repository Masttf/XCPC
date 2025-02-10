#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[100005];
signed main(){
	int n,x;
	cin>>n>>x;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	int ans=0;
	if(res[1]>x){
		ans+=res[1]-x;
		res[1]=x;
	}
	for(int i=1;i<n;i++){
		if(res[i]+res[i+1]>x)
		{
			ans+=res[i+1]+res[i]-x;
			res[i+1]-=res[i+1]+res[i]-x;
		}
	}
	cout<<ans;
	return 0;
}
