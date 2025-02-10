#include<bits/stdc++.h>
using namespace std;
struct student{
	int id;
	int g1;
	int g2;
	int get_sum(int g1,int g2){
		return g1*7+g2*3;
	}
};
int main(){
	int n;cin>>n;
	student s;
	for(int i=1;i<=n;i++){
		cin>>s.id>>s.g1>>s.g2;
		if(s.get_sum(s.g1,s.g2)>=800&&s.g1+s.g2>140){
			cout<<"Excellent"<<'\n';
		}else
			cout<<"Not excellent"<<'\n';
	}
	return 0;
}
