#include <iostream>
using namespace std;

void InsertionSort(int arr[],int n){
	int i,j,key;
	for(int i=1;i<n;i++){
			key=arr[i];
			j=i-1;
			while(j>=0 && arr[j]>key){
				arr[j+1]=arr[j];
				j--;
			}
			arr[j+1]=key;
	}	
}

int main(){
	int array1[]={8,1,5,3,2,10};
	int size=sizeof(array1)/sizeof(array1[0]);
	selectionSort(array1,size);
	for(int i=0;i<size;i++){
		cout<<array1[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}