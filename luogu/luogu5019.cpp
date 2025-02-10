//贪心我挖这块的时候能把旁边的一起挖了
#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[100005];
int ans=0;
signed main(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i];
	}
	for(int i=1;i<=n;i++){
		if(res[i]>res[i-1])
			ans+=res[i]-res[i-1];
	}
	cout<<ans;
	
	return 0;
}
