//二维数组差分
#include<bits/stdc++.h>
using namespace std;
#define int long long
int deff[100005];
int res[100005];
int a,b,c;
signed main(){
	int n,m;cin>>n>>m;
	int temp;cin>>temp;
	int p;
	for(int i=2;i<=m;i++){
		cin>>p;
		deff[min(temp,p)]++;
		deff[max(temp,p)]--;
		temp=p;
	}
	for(int i=1;i<=n;i++){
		res[i]=deff[i]+res[i-1];
	}
	int sum=0;
	for(int i=1;i<=n-1;i++){
		cin>>a>>b>>c;
		if(b*res[i]+c>a*res[i])sum+=a*res[i];
		else sum+=b*res[i]+c;
	}
	cout<<sum;
	return 0;
}
