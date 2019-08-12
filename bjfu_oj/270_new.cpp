#include"iostream"
#include"string"
using namespace std;
typedef struct node{
	node *left,*right;
	char v;
}*biTree;
void initNode(biTree &T){
	T=new node;
	T->left=NULL;
	T->right=NULL;
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
void traverseZero(biTree T,int &k){
	if(T){
		if(!T->left&&!T->right){
			k++;
		}else{
			traverseZero(T->left,k);
			traverseZero(T->right,k);
		}	
	}
}
void traverseOne(biTree T,int &k){
	if(T){
		if(T->left&&!T->right||!T->left&&T->right){
			k++;
		}
		traverseOne(T->left,k);
		traverseOne(T->right,k);
	}
}
void traverseTwo(biTree T,int &k){
	if(T){
		if(T->left&&T->right){
			k++;
		}
		traverseTwo(T->left,k);
		traverseTwo(T->right,k);
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
		T=NULL;
		createTree(T,s);
		int n0=0,n1=0,n2=0;
		traverseZero(T,n0);
		traverseOne(T,n1);
		traverseTwo(T,n2);
		cout<<n0<<" "<<n1<<" "<<n2<<endl;
	}
	return 0;
} 
