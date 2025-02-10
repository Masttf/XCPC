#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	while(t--){
		int len;cin>>len;
		if(len%2!=0){
			for(int i=1;i<=len;i++){
				cout<<1<<' ';
			}
			cout<<'\n';
		}
		else{
			for(int i=1;i<=len-2;i++){
				cout<<2<<' ';
			}
			cout<<1<<' ';
			cout<<3<<' '<<'\n';
		}
	}
	return 0;
}
