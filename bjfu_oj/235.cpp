#include"iostream"
using namespace std;
typedef struct node{
	int value;
	node *next;
}*LNode;
void initNode(LNode &L){
	L=new node;
	L->next=NULL;
}
void createList(LNode L,int n){
	LNode p;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->value;
		p->next=L->next;
		L->next=p;
	} 
}
int main(){
	LNode L,p;
	int n,k;
	cin>>n;
	while(n!=0){
		initNode(L);
		createList(L,n);
		cin>>k;
		p=L;
		while(k!=0){	
			p=p->next;
			k--;
		}
		cout<<p->value<<endl;
		cin>>n;
	}
	return 0;
}
