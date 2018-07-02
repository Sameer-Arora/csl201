#include<iostream>
#include<stack>
#include<string>

using namespace std;
int prec(char c){
	if(c=='^') return 3;
	else if(c=='*' || c=='/')  return 2;
	else if(c=='+'|| c=='-') return 1;
	else return-1;
}

void inftopost(string ex){
	int l=ex.length(),i;
	
	stack<char> oprtors;

	
	for (i = 0; i < l; ++i)
	{ 
		if( ex[i] >='a'&& ex[i]<='z'||ex[i] >='A'&& ex[i]<='Z' ){cout<< ex[i];}
		else if(ex[i]=='(')  oprtors.push('(');
		else if(ex[i]==')'){
			while(oprtors.top()!='('){
				cout<< oprtors.top();
				oprtors.pop();
			}
			oprtors.pop();
		}    
		else if (ex[i]=='^' || ex[i]=='*'||ex[i]=='/'||ex[i]=='-'||ex[i]=='+'){
			if(oprtors.empty())oprtors.push(ex[i]);
			else{
				while(prec(ex[i])<prec(oprtors.top())){
					cout<< oprtors.top();
					oprtors.pop();
				}
				oprtors.push(ex[i]);
			}
		}
		else{cout<< "wrong input:"; return;}
	}
	while(!oprtors.empty()){
					cout<< oprtors.top();
					oprtors.pop();
				}
	cout<< endl;
}

int main(){
	inftopost("a+b*(c^d-e)^(f+g*h)-i");

	return 0;
}