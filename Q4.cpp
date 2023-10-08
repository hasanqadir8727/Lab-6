#include<iostream>
using namespace std;
void sort(int arr[], int size){
	int temp;
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j+1]<arr[j]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	cout<<"Sorted Array: ";
	for(int i=0;i<size;i++){
		cout<<arr[i]<<" ";
	}
}
int binarySearch(int arr[], int lower, int upper,int find){
	if(lower<=upper){
		int middle=lower+(upper-lower)/2;
		if(arr[middle]==find){
			return middle;
		}
		if(arr[middle]<find){
			return binarySearch(arr,middle+1,upper, find);
		}
		return binarySearch(arr,lower,middle-1,find);
	}
	return -1;
	
}
int searchInsertionIndex(int arr[], int size, int find){
	for(int i=0;i<size;i++){
		if(arr[i]>=find){
			return i;
		}
	}
	return size;
}
int main(){
	int array[]={1,3,12,14,23,34,55,65,75,78};
	int size= sizeof(array)/sizeof(array[0]);
	sort(array, size);
	//Roll number: 22K-8727, so we have to find 27
	int lastTwoDigits=27;
	int search=binarySearch(array,0,size-1,lastTwoDigits);
	cout<<"\n";
	if(search==-1){
		int insertionIndex=searchInsertionIndex(array,size,lastTwoDigits);
		int newSize=size+1;
		array[newSize];
		for(int i=newSize-1;i>insertionIndex;i--){
			array[i]=array[i-1];
		}
		array[insertionIndex]=lastTwoDigits;
		int searchFinal=binarySearch(array,0,newSize-1,lastTwoDigits);
		cout<<"Sorted array with the last two digits of the roll number added: ";
		for(int i=0;i<newSize;i++){
			cout<<array[i]<<" ";
		}
		cout<<"\n";
		cout<<"The last two digits of the roll number have been added at index "<< searchFinal<<" in the array";
	}
	else{
		cout<<"The last two digits of the roll number have been found at index "<< search<<" in the array";
	}
	
}