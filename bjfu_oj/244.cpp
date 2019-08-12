#include"iostream"
#include"string"
#include"stack"
#include"sstream"
#include"iomanip"
using namespace std;
typedef struct{
	string *list;
	int length;
}sqList;
template <class Type>
Type stringToNum(const string &str){
	istringstream iss(str);
	Type num;
	iss>>num;
	return num;
}
void initList(sqList &L,int n){
	L.list=new string[n];
	L.length=n;
}
bool isOperater(char &c){
	switch(c){
		case '+':
		case '-':
		case '*':
		case '/':
		case '=':
		case '#':
		case ' ':
			return true;
	}
	return false;
}
void splitString(string str,sqList &L){
	int k=0;
	for(int i=0;i<str.length();i++){
		if(isOperater(str[i])){
			if(str[i]==' '){
				continue;
			}else if(str[i]=='='){
				str[i]='#';
			}
			L.list[k]=str[i];
			k++;
		}else{
			L.list[k]="";
			while(!isOperater(str[i])){
				L.list[k]+=str[i];
				i++;
			}
			k++;
			i--;
		}
	}
	L.length=k;
}
float caculate(float a,float b,char c){
	switch(c){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
	}
}
void operate(sqList L){
	stack <float> opnd;
	for(int i=0;i<L.length-1;i++){
		if(!isOperater(L.list[i][0])){
			opnd.push(stringToNum<float>(L.list[i]));
		}else{
			float a,b;
			b=opnd.top();
			opnd.pop();
			a=opnd.top();
			opnd.pop();
			opnd.push(caculate(a,b,L.list[i][0]));
		}
	}
	cout<<fixed<<setprecision(2)<<opnd.top()<<endl;
}
int main(){
	string str;
	sqList L;
	while(1){
		getline(cin,str);
		if(str=="="){
			break;
		}
		initList(L,str.length());
		splitString(str,L);
		operate(L);
	}
	return 0;
}
