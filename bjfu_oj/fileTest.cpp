#include"iostream"
#include"fstream"
using namespace std;
int main(){
	char buf[256];
	ifstream file("test.txt");
	if(file.is_open()){
		while(!file.eof()){
			file.getline(buf,100);
			cout<<buf;
		}
		file.close();
	}
	ofstream File("test2.txt");
	if(File.is_open()){
		if(!File.eof()){
			File<<"huhuhuhuu"<<endl;
			File<<buf;
		}
		File.close();
	}
	return 0;
}
