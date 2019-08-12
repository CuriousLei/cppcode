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
void find(sqList list,int id){
	if(id>0&&id<=list.len){
		cout<<list.elem[id-1].no<<" "<<list.elem[id-1].name<<" "<<fixed<<setprecision(2)<<list.elem[id-1].price<<endl;
	}else{
		cout<<"Sorry£¬the book on the best position doesn't exist!"<<endl;
	}
}
int main(){
	sqList list;
	int n,m,id;
	initSqList(list);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>list.elem[i].no>>list.elem[i].name>>list.elem[i].price;
		list.len++;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>id;
		find(list,id);
	}
	return 0;
}
