#include<bits/stdc++.h>
using namespace std;
int cnt1,cnt2;
char res[100000];
int main(){
	char ch;
	int i;
	for(i=1;cin>>ch&&ch!='E';i++){
		res[i]=ch;
	}
	for(int j=1;j<=i;j++){
		if(cnt1>=11&&cnt1-cnt2>=2){
			cout<<cnt1<<':'<<cnt2<<'\n';
			cnt1=cnt2=0;
		}else if(cnt2>=11&&cnt2-cnt1>=2){
			cout<<cnt1<<':'<<cnt2<<'\n';
			cnt1=cnt2=0;
		}
		if(res[j]=='W'){
			cnt1++;
		}else if(res[j]=='L'){
			cnt2++;
		}
	}
	cout<<cnt1<<':'<<cnt2<<'\n'<<'\n';
	cnt1=cnt2=0;
	for(int j=1;j<i;j++){
		if(cnt1>=21&&cnt1-cnt2>=2){
			cout<<cnt1<<':'<<cnt2<<'\n';
			cnt1=cnt2=0;
		}else if(cnt2>=21&&cnt2-cnt1>=2){
			cout<<cnt1<<':'<<cnt2<<'\n';
			cnt1=cnt2=0;
		}
		if(res[j]=='W'){
			cnt1++;
		}else if(res[j]=='L'){
			cnt2++;
		}
	}
	cout<<cnt1<<':'<<cnt2;
	return 0;
}
