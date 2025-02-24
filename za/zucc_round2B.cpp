#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		if(n%2!=0){
			cout<<"NO"<<'\n';
		}else{
			int sum=0;
			for(int i=1;i<=n-1;i++){
				sum^=i;
			}
			if(sum!=0){
				cout<<"NO"<<'\n';
			}else {
				cout<<"YES"<<'\n';
				for(int i=0;i<=n-1;i++){
					cout<<i<<' ';
				}
				cout<<'\n';
			}
		}
	}
	return 0;
}
