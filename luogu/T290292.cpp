#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	int n;
	for(int m=1;m<=t;m++){
		cin>>n;
		int cnt=0;
		int j=1;
		while(j<n){
			j<<=1;
			cnt++;
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
