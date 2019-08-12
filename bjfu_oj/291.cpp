#include"iostream"
using namespace std;
int main(){
	biTree T;
	string s;
	while(1){
		cin>>s;
		if(s=="#"){
			break;
		}
		int k=0,i;//k记录0之前-1个数 
		for(i=1;i<s.length()+1;i++){
			if(s[i-1]=='#'){
				k++;
			}
			if(s[i-1]=='0'){
				break;
			}
		}
		cout<<i+k<<endl;
	}
	return 0;
}
