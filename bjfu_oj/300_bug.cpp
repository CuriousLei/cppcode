#include"iostream"
using namespace std;
typedef struct node{
	node *next;
	int v;
}*linkNode;
void initNode(linkNode &L){
	L=new node;
	L->next=NULL;
}
void createList(linkNode L,int n){
	linkNode p,e;
	e=L;
	for(int i=0;i<n;i++){
		initNode(p);
		cin>>p->v;
		e->next=p;
		e=p;
	}
}
void search(linkNode L,int m){
	linkNode p;
	p=L;
	while(m>=0&&p){
		m--;
		p=p->next;
	}
	if(m==-1){
		cout<<p->v<<endl;
	}
}
int main(){
	linkNode L;
	int n,k;
	cin>>n;
	initNode(L);
	createList(L,n);
	cin>>k;
	search(L,n-k);
	return 0;
}
