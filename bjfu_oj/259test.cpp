#include"iostream"
using namespace std;
void test(char *s,char str[]){
	cout<<*s<<endl;//����ַ�����һ���ַ� 
	cout<<str<<endl;//��������ַ��� 
}
int main(){
	char s[100];
	s[0]='e';
	s[1]='a';
	s[2]='\0';
	cout<<s<<endl;
	test(s,s);
	return 0;
}
