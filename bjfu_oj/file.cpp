#include"iostream"
#include"fstream"
#include"string"
using namespace std;

int main(){
	char buf[256];
	string str,s("I am an ambitious student aaa");
	ofstream file("test.txt");
	if(file.is_open()){
		file<<s<<endl;
		file<<"I am an ambitious stu"<<endl;
		file.close();
	}
	ifstream inFile("test.txt");
	if(inFile.is_open()){
		while(!inFile.eof()){
			inFile.getline(buf,100);//只能是char数组 
			str=buf;
			cout<<str.length()<<";"<<endl;
		}
		inFile.close();
	}
	return 0;
}
