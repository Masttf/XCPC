#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[305];
void solve(){
	int n;cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==0)cnt++;
	}
	if(n-cnt>=3){
		cout<<"yes\n";
		int f=0;
		for(int i=1;i<=n;i++){
			if(f==3)break;
			if(a[i]%2!=0)cout<<i<<' ',f++;
		}
		cout<<'\n';
	}else if(n-cnt>=1&&n-cnt<=2&&cnt>=2){
		cout<<"yes\n";
		int f1=0,f2=0;
		for(int i=1;i<=n;i++){
			if(f2==2&&f1==1)break;
			if(a[i]%2==0&&f2<2)f2++,cout<<i<<' ';
			if(a[i]%2!=0&&!f1)f1++,cout<<i<<' ';
		}
		cout<<'\n';
	}
	else cout<<"no\n";
	return ;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
