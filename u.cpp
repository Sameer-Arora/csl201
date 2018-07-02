#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;


int check(int arr[],int st,int nxt_g[],int nxt_l[]){
  
  int lt,rt,c=1,d=1;

	  //cout<<st<<"ree\n";
    if(nxt_g[st]==-1 && nxt_l[st]==-1) return 1;
    
	  if(nxt_g[st]!=-1 && nxt_g[st]<nxt_l[st]){
	  	  		return 0;
	  		
	  }else {
	  			
	  		
	  			if(nxt_l[st]!=-1 ) {  lt=nxt_l[st];
	  		                         	                      
	  			                      c=check(arr,lt,nxt_g,nxt_l); 
	  			            }
	  		       
	  	 		if(nxt_g[st]!=-1) { rt=nxt_g[st];
	  	 			
	  	 						     d=check(arr,rt,nxt_g,nxt_l); 
	  	 						 }
	  	       //cout<<c<<d<<endl; 
	  	 		return c*d;
	  	  		
  }

 
}
int main() {
      int t,n,k,l;
    cin>>t;
    int b[t];
    for(int k=0;k<t;k++){
        cin>>n;
        int arr[n];
        for(int l=0;l<n;l++){
            cin>>arr[l];
        }
  // cout<<"next g";     
   int i,j,size=n;
	stack<int> s;
	int nxt_g[size];
	for(int i=0;i<size;i++){
		if(!s.empty()){
			if(s.top()==i) {
			 s.pop();    	}
			 }
			 
		if(s.empty()){
			for(j=i;j<size;j++){
				if(arr[j]>arr[i]){
					s.push(j);
					break;}
			}
			if(!s.empty())  nxt_g[i]=s.top();
			else     nxt_g[i]=-1;         //no next greatest element.
			
		}else{
		
		for(j=i;j<s.top();j++){
				if(arr[j]>arr[i]){
					s.push(j);
					break;}
			}
		 nxt_g[i]=s.top();

		
		}
		//cout<<nxt_g[i]<<"\t";
    }
   // cout<<endl<<"next l";
    
    stack<int > s1;   
    int nxt_l[size];
	for(int i=0;i<size;i++){
		if(!s1.empty()){
		
			if(s1.top()==i) {
			 s1.pop();    	}
			 }
			 
		if(s1.empty()){
			for(j=i;j<size;j++){
				if(arr[j]<arr[i]){
					s1.push(j);
					break;}
			}
			if(!s1.empty())  nxt_l[i]=s1.top();
			else     nxt_l[i]=-1;        //no next least element.
			
		}else{
		
		for(j=i;j<s1.top();j++){
				if(arr[j]<arr[i]){
					s1.push(j);
					break;}
			}
		 nxt_l[i]=s1.top();

		
		}
		//cout<<nxt_l[i]<<"\t";
}
   // cout<<endl;  
    
    b[i]=check(arr,0,nxt_g,nxt_l);
    }
    for(int i=0;i<t;i++){
       if(b[t]>0)
          cout<<"True"<<endl;
        else  cout<<"False"<<endl;
    }
    return 0;
}

