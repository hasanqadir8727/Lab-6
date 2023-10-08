#include<iostream>
using namespace std;
void quickSort(int array[], int size){
	if(size<=1){
		return;
	}
	int middle = size/2;
	int pivot= array[middle];
	int left[size];
	int right[size];
	int rightIndex=0;
	int leftIndex=0;
	for(int i=0;i<size;i++){
		if(i==middle){
			continue;
		}
		if(array[i]<=pivot){
			left[leftIndex]=array[i];
			leftIndex++;
		}
		else{
			right[rightIndex]=array[i];
			rightIndex++;
		}
	}
	quickSort(left,leftIndex);
	quickSort(right,rightIndex);
	for(int i=0;i<leftIndex;i++){
		array[i]=left[i];
	}
	
	array[leftIndex]=pivot;
	for(int i=0;i<rightIndex;i++){
		array[i+leftIndex+1]=right[i];
	}
	return;
	
}
int main(){
	int arr[]={9,3,4,10,6,7,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,size);
	cout<<"Sorted Array: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}