#include"iostream"
#include"string"
#include"iomanip"
#include"queue"
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
void deleteItem(sqList &list,int id){
	if(id>0&&id<list.len){
		for(int i=id-1;i<list.len-1;i++){
			list.elem[i]=list.elem[i+1];
		}
		list.len--;
	}
}
int main(){
	sqList list;
	int n;
	queue <int> idList;
	initSqList(list);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>list.elem[i].no>>list.elem[i].name>>list.elem[i].price;
		list.len++;
	}
	for(int i=0;i<list.len-1;i++){
		for(int j=i+1;j<list.len;j++){
			if(list.elem[i].no==list.elem[j].no&&list.elem[i].name==list.elem[j].name&&list.elem[i].price==list.elem[j].price){
				deleteItem(list,j);
			}
		}
	}
	cout<<list.len<<endl;
	for(int i=0;i<list.len;i++){
		cout<<list.elem[i].no<<" "<<list.elem[i].name<<" "<<fixed<<setprecision(2)<<list.elem[i].price<<endl; 
	}
	return 0;
}
