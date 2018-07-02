#include <iostream >
#include <string>
using namespac std;

int chk(string qr,string arr[] ,int  n){
	int count=0;
	for (int j=0;j<n;j++){
		if ( qr== arr[j]  )
			count++;
	}

	return count;
}

int main(int argc, char const *argv[])
{
	int n,i,j,q;
	cin >> n;
	string arr[n];
    for( i=0;i<n;i++)
    	getline(cin,arr[i]);
    cin >> q;
    string qr;

    for( i=0;i<n;i++){
    	getline(cin,qr);
    	cout << chk( qr,arr,n )>>endl;

	}


	return 0;
}