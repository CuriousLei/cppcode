#include"iostream"
#include"string"
#include"queue"
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
void find(sqList list,string str){
	int k=0;
	queue <book> q;
	for(int i=0;i<list.len;i++){
		if(list.elem[i].name==str){
			k++;
			q.push(list.elem[i]);
		}
	}
	if(k==0){
			cout<<"Sorry£¬there is no your favourite!"<<endl;
		}else{
			cout<<k<<endl;
			while(!q.empty()){
				book e=q.front();
				cout<<e.no<<" "<<e.name<<" "<<fixed<<setprecision(2)<<e.price<<endl;
				q.pop();
			}
		}
}
int main(){
	sqList list;
	int n,m;
	string str;
	initSqList(list);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>list.elem[i].no>>list.elem[i].name>>list.elem[i].price;
		list.len++;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>str;
		find(list,str);
	}
	return 0;
}
