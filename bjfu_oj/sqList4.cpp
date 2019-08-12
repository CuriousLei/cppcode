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
	sqList list,idL;
	initSqList(list);
	int n;
	string no,name;
	float price,maxPrice=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>list.elem[i].no>>list.elem[i].name>>list.elem[i].price;
		list.len++;
	}
	initSqList(idL);
	for(int i=0;i<n;i++){
		if(list.elem[i].price>maxPrice){
			maxPrice=list.elem[i].price;
			delete []idL.elem;
			initSqList(idL);
			idL.elem[idL.len]=list.elem[i];
			idL.len++;
		}else if(list.elem[i].price==maxPrice){
			idL.elem[idL.len]=list.elem[i];
			idL.len++;
		}
	}
	cout<<idL.len<<endl;
	for(int i=0;i<idL.len;i++){
		cout<<idL.elem[i].no<<" "<<idL.elem[i].name<<" "<<fixed<<setprecision(2)<<idL.elem[i].price<<endl;
	}
	return 0;
}
