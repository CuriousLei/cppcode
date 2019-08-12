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
	string no ,name;
	int n;
	float price;
	initSqList(list);
	cin>>n;
	for(int i=0;i<n;i++){
		list.len++;
		for(int j=list.len-1;j>0;j--){
			list.elem[j].no=list.elem[j-1].no;
			list.elem[j].name=list.elem[j-1].name;
			list.elem[j].price=list.elem[j-1].price;
		}
		cin>>list.elem[0].no>>list.elem[0].name>>list.elem[0].price;
	}
	
	for(int i=0;i<list.len;i++){
		cout<<list.elem[i].no<<" "<<list.elem[i].name<<" "<<fixed<<setprecision(2)<<list.elem[i].price<<endl;
	}
	return 0;
}

