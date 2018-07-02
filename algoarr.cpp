
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,m,i,j,m1;       // m1 as virtual max till each row.
    cin >> n;
    cin >> m;
    int arr[m][3];
    for (i=0;i<m;i++){
    	cin >> arr[i][0];
    	cin >> arr[i][1] ;
    	cin>> arr[i][2];

   }
   int max=arr[0][2];
   for (i=1; i<m ;i++){
   		m1=0;

   		for(j=0 ;j <i; j++ ){
   			if  ( arr[j][0]<=arr[i][0] && arr[j][1]>=arr[i][0] || 
   				arr[j][0]<=arr[i][1] && arr[j][1]>=arr[i][1] )
   				m1 += arr[j][2];
   		} 
   		m1+=arr[i][2];
   		if( m1 > max )  max=m1;
   }

   cout << max;

    return 0;
}