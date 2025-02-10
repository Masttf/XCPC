#include<bits/stdc++.h>
#define int long long
using namespace std;
int res[5];
signed main(){
	for(int i=1;i<=3;i++){
		cin>>res[i];
	}
	sort(res+1,res+4);
	bool flag=0;
	if(res[1]+res[2]>res[3])flag=1;
	if(flag){
		int duan=res[1]*res[1]+res[2]*res[2];
		int chang=res[3]*res[3];
		if(duan>chang){
			cout<<"Acute triangle"<<'\n';
		}else if(duan==chang){
			cout<<"Right triangle"<<'\n';
		}else if(duan<chang){
			cout<<"Obtuse triangle"<<'\n';
		}
		if(res[1]==res[2])
			cout<<"Isosceles triangle"<<'\n';
		if(res[1]==res[2]&&res[2]==res[3])
			cout<<"Equilateral triangle"<<'\n';
	}else
		cout<<"Not triangle";
	return 0;
}
