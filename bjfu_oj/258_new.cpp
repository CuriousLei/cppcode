#include"iostream"
#include"string"
using namespace std;
void reverse(string &s,int i){
	if(i<s.length()/2){
		char m=s[i];
		s[i]=s[s.length()-i-1];
		s[s.length()-i-1]=m;
		reverse(s,i+1);	
	}
}
int main(){
	string s;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		reverse(s,0);
		cout<<s<<endl;
	}
	return 0;
}
