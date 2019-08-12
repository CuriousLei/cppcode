#include"iostream"
#include"string"
using namespace std;
typedef struct node{
	node *left,*right;
	char v;
}*biTree;
void initNode(biTree &T){
	T=new node;
	T->right=NULL;
	T->left=NULL;
}
int k;
void createTree(biTree &T,string s){
	k++;
	if(s[k]=='0'){
		T=NULL;
	}else{
		initNode(T);
		T->v=s[k];
		createTree(T->left,s);
		createTree(T->right,s);
	}
}
void preOrder(biTree T){
	if(T){
		cout<<T->v;
		preOrder(T->left);
		preOrder(T->right);
	}
}
void postOrder(biTree T){
	if(T){	
		postOrder(T->left);
		postOrder(T->right);
		cout<<T->v;
	}
}
void medOrder(biTree T){
	if(T){
		medOrder(T->left);
		cout<<T->v;
		medOrder(T->right);
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
		preOrder(T);
		cout<<endl;
		medOrder(T);
		cout<<endl;
		postOrder(T);
		cout<<endl;
	}
	return 0;
}
