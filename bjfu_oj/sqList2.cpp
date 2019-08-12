#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
#define maxSize 10000
typedef struct{
	string no;
	string name;
	float price;
}book;
typedef struct{
	int len;
	book *elem;
}sqList;
void initSqList(sqList &list){
	list.elem=new book[maxSize];
	list.len=0;
}
int main(){
	sqList list;
	initSqList(list);
	string no,name;
	float price,med=0;
	cin>>no>>name>>price;
	while(no!="0"&&name!="0"&&price!=0){
		int i=list.len;
		list.elem[i].no=no;
		list.elem[i].name=name;
		list.elem[i].price=price;
		list.len++;
		med+=price;
		cin>>no>>name>>price;
	}
	med=med/list.len;
	cout<<fixed<<setprecision(2)<<med<<endl;
	for(int i=0;i<list.len;i++){
		if(list.elem[i].price<med){
			list.elem[i].price=list.elem[i].price*1.2;
		}else{
			list.elem[i].price=list.elem[i].price*1.1;
		}
	}
	for(int i=0;i<list.len;i++){
		cout<<list.elem[i].no<<" "<<list.elem[i].name<<" "<<fixed<<setprecision(2)<<list.elem[i].price<<endl;
	}
	return 0;
}
