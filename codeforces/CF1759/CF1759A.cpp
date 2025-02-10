//A
#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;cin>>t;
	string s;
	for(int i=1;i<=t;i++){
		cin>>s;
		int flag=1;
		for(int j=0;j<s.size();j++){
			if(!(s[j]=='Y'||s[j]=='e'||s[j]=='s')){
				cout<<"NO"<<'\n';
				flag=0;
				break;
			}
			if(j!=s.size()-1){
				if(s[j]=='s'){
					if(s[j+1]!='Y'){
						cout<<"NO"<<'\n';
						flag=0;
						break;
					}	
				}else if(s[j]=='e'){
					if(s[j+1]!='s'){
						cout<<"NO"<<'\n';
						flag=0;
						break;
					}
				}else if(s[j]=='Y'){
					if(s[j+1]!='e'){
						cout<<"NO"<<'\n';
						flag=0;
						break;
					}
				}
			}
		}
		if(flag)cout<<"YES"<<'\n';
	}
	
	return 0;
}
