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
void insert(sqList &list,int id,book item){
	if(id>0&&id<=list.len){
		int j;
		list.len++;
		for(j=list.len-1;j>=id;j--){
			list.elem[j]=list.elem[j-1];
		}
		list.elem[j]=item;
	}
}
int main(){
	sqList list;
	book item;
	int n,id;
	initSqList(list);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>list.elem[i].no>>list.elem[i].name>>list.elem[i].price;
		list.len++;
	}
	cin>>id>>item.no>>item.name>>item.price;
	insert(list,id,item);
	for(int i=0;i<n+1;i++){
		cout<<list.elem[i].no<<" " <<list.elem[i].name<<" "<<fixed<<setprecision(2)<<list.elem[i].price<<endl;
	}
	return 0;
}
