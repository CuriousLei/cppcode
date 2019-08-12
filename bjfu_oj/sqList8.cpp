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
void deleteItem(sqList &list,int id){
	if(id>0&&id<=list.len){
		for(int i=id-1;i<list.len-1;i++){
			list.elem[i]=list.elem[i+1];
		}
		list.len--;
		for(int i=0;i<list.len;i++){
			cout<<list.elem[i].no<<" "<<list.elem[i].name<<" "<<fixed<<setprecision(2)<<list.elem[i].price<<endl; 
		}
	}else{
		cout<<"抱歉，出库位置非法！"<<endl;
	}
}
int main(){
	sqList list;
	int n,id;
	initSqList(list);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>list.elem[i].no>>list.elem[i].name>>list.elem[i].price;
		list.len++;
	}
	cin>>id;
	deleteItem(list,id);
	
	return 0;
} 
