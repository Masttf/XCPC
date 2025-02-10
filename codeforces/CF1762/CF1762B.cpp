#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int res[maxn];
void slove(){
	memset(res,0,sizeof(res));
	int n;cin>>n;
	cout<<n<<'\n';
	for(int i=1;i<=n;i++){
		cin>>res[i];
		int p=1<<(int(log2(res[i]))+1);//全部凑成2的次方
		cout<<i<<' '<<p-res[i]<<'\n';
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--){
		slove();
	}
	return 0;
}
