#include"iostream"
using namespace std;
typedef struct{
	char *base;
	char *top;
	int size;
}sqStack;
void push(sqStack &S,char &v){
	*S.top++=v;
}
bool pop(sqStack &S){
	if(S.top==S.base){
		return false;
	}else{
		S.top--;
		return true;
	}
}
bool empty(sqStack &S){
	if(S.top==S.base){
		return true;
	}else{
		return false;
	}
}
int main(){
	sqStack S;
	string s;
	int i;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		S.base=new char[1000];
		S.top=S.base;
		for(i=0;i<s.length();i++){
			if(s[i]=='I'){
				push(S,s[i]);
			}else{
				if(!pop(S)){
					cout<<"FALSE"<<endl;
					break;
				}
			}
		}
		if(i==s.length()){
			if(empty(S)){
				cout<<"TRUE"<<endl;	
			}else{
				cout<<"FALSE"<<endl;
			}	
		}
	}
	return 0;
}
