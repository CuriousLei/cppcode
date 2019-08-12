#include"iostream"
#include"string"
using namespace std;

string getBackFigure(string M){
	int l=M.length();
	string M0="";
	for(int i=l-1;i>=0;i--){
		M0+=M[i];
	}
	return M0;
}
int ascConversion(char c){
	int re;
	if(c>64){
		re=c-'7';
	}else{
		re=c-'0';
	}
}
int main(){
	int N,a,b,c,d,m;
	string M,M0,step0;
	while(cin>>N>>M){
		M0=getBackFigure(M);
		int j=0;
		while(!(M0==M)){
			int l=M.length();
			c=0;
			step0="";
			for(int i=l-1;i>=0;i--){
				a= ascConversion(M[i]);
				b = ascConversion(M0[i]);
				m=a+b+c;
				c=m/N;
				d=m%N;
				step0+=d+'0';
			}
			if(c!=0){
				step0+=c+'0';
			}
			M=step0;
			M0=getBackFigure(M);
			j++;
			if(j>30){
				cout<<"Impossible!"<<endl;
				break;
			}
		}
		if(j<=30){
			cout<<"STEP="<<j<<endl;		
		}
	}
	return 0;
}
