#include"iostream"
#include"string"
#include"iomanip"
#include"algorithm"
using namespace std;
#define maxSize 10000
typedef struct{
	string no;
	string name;
	float price;
}book;
typedef struct{
	book *elem;
	int len;
}sqList;
void initSqList(sqList &sqL){
	sqL.elem=new book[maxSize];
	sqL.len=0;
}
//bool cmp(book a,book b){
//	return a.price>b.price;
//}
int main(){
	sqList sqL;
	string no,name;
	float price;
	book t;
	initSqList(sqL);
	cin>>no>>name>>price;
	while(no!="0"&&name!="0"&&price!=0){
		int i=sqL.len;
		sqL.elem[i].no=no;
		sqL.elem[i].name=name;
		sqL.elem[i].price=price;
		sqL.len++;
		cin>>no>>name>>price;
	}
//	sort(sqL.elem,sqL.elem+sqL.len,cmp);
	for(int i=0;i<sqL.len;i++){
		for(int j=0;j<sqL.len-i-1;j++){
			if(sqL.elem[j].price<sqL.elem[j+1].price){
				t=sqL.elem[j];
				sqL.elem[j]=sqL.elem[j+1];
				sqL.elem[j+1]=t;
			}
		}
	}
	
	for(int i=0;i<sqL.len;i++){
		cout<<sqL.elem[i].no<<" "<<sqL.elem[i].name<<" "<<fixed<<setprecision(2)<<sqL.elem[i].price<<endl;
	}
	return 0;
}
