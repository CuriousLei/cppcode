#include"iostream"
#include"string"
using namespace std;
typedef struct TNode{
	char c;
	TNode *lChild,*rChild;
}*biTree;
void initNode(biTree &T){
	T=new TNode;
	T->lChild=NULL;
	T->rChild=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->c=s[k];
		createTree(T->lChild,s);
		createTree(T->rChild,s);
	}
}
void exchange(biTree T){
	if(T){
		biTree p;
		p=T->rChild;
		T->rChild=T->lChild;
		T->lChild=p; 
		exchange(T->lChild);
		exchange(T->rChild);
	}	
}
void output(biTree T){
	if(T){
		cout<<T->c;
		output(T->lChild);
		output(T->rChild);
	}
}
int main(){
	biTree T;
	string s;
	while(1){
		cin>>s;
		if(s=="0"){
			break;
		}
		k=-1;
		createTree(T,s);
		exchange(T);
		output(T);
		cout<<endl;
	} 
	return 0;
}
