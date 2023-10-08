#include<iostream>
using namespace std;
void merge(int array[], int left[], int right[], int leftSize, int rightSize, int arraySize){
	int leftIndex=0;
	int rightIndex=0;
	for(int i=0;i<arraySize;i++){
		if(leftIndex < leftSize && rightIndex < rightSize){
			if(left[leftIndex]<right[rightIndex]){
				array[i]=left[leftIndex];
				leftIndex++;
			}
			else{
				array[i]=right[rightIndex];
				rightIndex++;
			}
		}
		else if(leftIndex < leftSize){
			array[i]=left[leftIndex];
			leftIndex++;
		}
		else if(rightIndex < rightSize){
			array[i]=right[rightIndex];
			rightIndex++;
		}
	}
}
void mergeSort(int array[], int lower, int upper){
	if(upper-lower<=1){
		return;
	}
	int arraySize= upper-lower;
	int middle= arraySize/2;
	int leftSize= middle;
	int rightSize=arraySize-middle;
	int left[leftSize];
	int right[rightSize];
	for(int i=0;i<leftSize;i++){
		left[i]=array[i];
	}
	mergeSort(left, lower, lower+middle);
	for(int i=0;i<rightSize;i++){
		right[i]=array[middle+i];
	}
	mergeSort(right, middle+lower, upper);
	merge(array,left,right,leftSize,rightSize,arraySize);
}
int main(){
	int array[]={9,4,10,3,6};
	int size=sizeof(array)/sizeof(array[0]);
	cout<<"Unsorted Array: ";
	for(int i=0;i<size;i++){
		cout<<array[i]<< " ";
	}
	cout<<"\n";
	mergeSort(array,0,size);
	cout<<"Sorted Array: ";
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
}