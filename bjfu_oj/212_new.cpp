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
bool outOf(sqList &L,int id){
	if(id>=1&&id<=L.len){
		for(int i=id;i<L.len;i++){
			L.elem[i-1]=L.elem[i];
		}
		L.len--;
		return true;
	}else{
		return false;
	}
	
}
void output(sqList L){
	for(int i=0;i<L.len;i++){
		cout<<L.elem[i].no<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
	}
} 
int main(){
	sqList L;
	int n,id;
	L.elem=new book[10000];
	L.len=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;
		L.len++;
	}
	cin>>id;
	if(outOf(L,id)){
		output(L);	
	}else{
		cout<<"抱歉，出库位置非法！"<<endl;
	}
	
	return 0;
}
