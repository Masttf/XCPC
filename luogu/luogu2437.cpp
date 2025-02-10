#include<bits/stdc++.h>
using namespace std;
string res[1005];
string s;
int ans[10005],la=0;
int ans2[10005],lb=0;
int ans3[10005];
signed main(){
	int m,n;
	cin>>m>>n;
	res[1]="1";
	res[2]="1";
	for(int i=3;i<=n;i++){
		s="";
		for(int j=res[i-2].size()-1;j>=0;j--){
			ans[++la]=res[i-2][j]-'0';
		}
		for(int j=res[i-1].size()-1;j>=0;j--){
			ans2[++lb]=res[i-1][j]-'0';
		}
		int mx=max(la,lb);
		for(int i=1;i<=mx;i++){
			ans3[i]+=ans[i]+ans2[i];
			if(ans3[i]>9){
				ans3[i+1]+=ans3[i]/10;
				ans3[i]%=10;
			}
		}
		if(ans3[mx+1]>0)mx++;
		for(int i=mx;i>=1;i--){
			s+=to_string(ans3[i]);
		}
		res[i]=s;
		memset(ans,0,sizeof(ans));
		memset(ans2,0,sizeof(ans2));
		memset(ans3,0,sizeof(ans3));
		la=0;
		lb=0;
	}
	cout<<res[n-m+1];
	return 0;
}
