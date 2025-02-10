#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[20005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,h;
	cin>>n>>h;
	for(int i=1;i<=n;++i){
		cin>>res[i];
	}
	sort(res+1,res+1+n,cmp);
	int ans=0;
	int sum=0;
	for(int i=1;i<=n;++i){
		if(sum>=h)break;
		if(sum<h){
			sum+=res[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
