#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		string res;cin>>res;
		int cnt=0;
		for(int i=0;i<n;i++){
			if(res[i]=='y'){
				if(res[i+1]=='b')i++;
				while(i<=n-2&&res[i+1]=='b')cnt++,i++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
