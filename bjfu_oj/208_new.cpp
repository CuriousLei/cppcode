#include"iostream"
#include"string"
#include"iomanip"
using namespace std;
typedef struct{
	string no;
	string name;
	float price;
}book;
typedef struct{
	book *elem;
	int len;
}sqList;
void findMax(sqList L){
	sqList maxList;
	float max=0;
	maxList.elem=new book[L.len];
	maxList.len=0;
	for(int i=0;i<L.len;i++){
		if(L.elem[i].price>max){
			max=L.elem[i].price;
		}
	}
	for(int i=0;i<L.len;i++){
		if(L.elem[i].price==max){
			maxList.elem[maxList.len]=L.elem[i];
			maxList.len++;
		}
	}
	cout<<maxList.len<<endl;
	for(int i=0;i<maxList.len;i++){
		cout<<maxList.elem[i].no<<" "<<maxList.elem[i].name<<" "<<fixed<<setprecision(2)<<maxList.elem[i].price<<endl;
	}
}
int main(){
	sqList L;
	int n;
	L.elem=new book[10000];
	L.len=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;
		L.len++;
	}
	findMax(L);
	return 0;
}
