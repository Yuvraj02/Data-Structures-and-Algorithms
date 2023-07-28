#include <iostream>

using namespace std;

void seeding(int n) {
	// Write your code here.
	for(int i = 0; i<n ;i++){
		for(int j = n-1; j>=i ;j--){
			cout<<"* ";
		}
		cout<<endl;
	}
}