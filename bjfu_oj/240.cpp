#include"iostream"
#include"string"
#include"stack"
#include"sstream"
#include"iomanip"
using namespace std;
char database[8][8]={{'t','+','-','*','/','(',')','#'},
					{'+','>','>','<','<','<','>','>'},
					{'-','>','>','<','<','<','>','>'},
					{'*','>','>','<','<','<','>','>'},
					{'/','>','>','>','>','<','>','>'},
					{'(','<','<','<','<','<','=',' '},
					{')','>','>','>','>',' ','>','>'},
					{'#','<','<','<','<','<',' ','='}};
int length=0;
//判断字符是否是运算符 
bool isOperater(char symbol){
	switch(symbol){
		case '+':
		case '-':
		case '*':
		case '/':
		case '(':
		case ')':
		case '=':
		case '#':
			return true;
	}
	return false;
}
//将string转化为数值型
template <class type>
type stingToType(string str){
	istringstream iss(str);
	type num;
	iss>>num;
	return num;
}
//拆分输入的字符串，存入数组 
void splitString(string s,string sList[]){
	int k=0;
	string str;
	for(int i=0;i<s.length();i++){
		if(isOperater(s[i])){
			sList[k]=s[i];
			if(sList[k]=="="){
				sList[k]="#";
			}
			k++;
		}else{
			str="";
			do{
				str+=s[i];
				i++;
			}while(!isOperater(s[i]));
			sList[k]=str;
			k++;
			i--;
			continue;
		}
	}
	length=k;
//	for(int i=0;i<k;i++){
//		cout<<sList[i]<<endl;
//	}
}
char compare(char a,char b){
	int i,j;
	for(i=0;i<8;i++){
		if(database[i][0]==a){
			break;
		}
	}
	for(j=0;j<7;j++){
		if(database[0][j]==b){
			break;
		}
	}
	return database[i][j];
}
//计算具体过程
float caculate(float a,float b,char c){
	switch(c){
		case '+':
			return (a+b);
		case '-':
			return (a-b);
		case '*':
			return (a*b);
		case '/':
			return (a/b);
	}
} 
//进行运算
void operate(string sList[]){
	stack<char> optr;
	stack<float> opnd;
	int i=0;
	optr.push('#');
	while(i<length){
		if(!isOperater(sList[i][0])){
			opnd.push(stingToType<float>(sList[i]));
		}else{
//			cout<<optr.top()<<" "<<sList[i][0]<<endl;
//			cout<<compare(optr.top(),sList[i][0])<<endl;
			switch(compare(optr.top(),sList[i][0])){
				case '>':
					float a,b;
					a=opnd.top();
					opnd.pop();
					b=opnd.top();
					opnd.pop();
					opnd.push(caculate(b,a,optr.top()));
					optr.pop();
					i--;
					break;
				case '<':
					optr.push(sList[i][0]);
					break;
				case '=':
					optr.pop();
					break;
			}	
		}
		i++;
	}
	cout<<fixed<<setprecision(2)<<opnd.top()<<endl;
}
int main(){
	string s,*sList;
	while(1){
		cin>>s;
		if(s=="="){
			break;
		}
		sList=new string[s.length()];
		splitString(s,sList);
		operate(sList);
	}
	return 0;
}
