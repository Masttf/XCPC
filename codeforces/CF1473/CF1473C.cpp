#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int res[maxn];
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		string s;cin>>s;
		memset(res,0,sizeof(res));
		for(int i=0;i<n;i++)cin>>res[i];
		int sum=0;
		int flag=-1;
		for(int i=0;i<n;i++){
			if(flag==-1&&s[i]=='0')flag=i;
			else if(s[i]=='0')flag=i;
			if(s[i]=='1'){
				if(res[i]>=res[flag]){
					sum+=res[i];
				}else{
					sum+=res[flag];
					flag=i;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
