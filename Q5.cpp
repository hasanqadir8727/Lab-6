#include<iostream>
using namespace std;
int interpolationSearch(int arr[],int lower, int upper, int search){
int position;
while(lower<=upper && search>=arr[lower] && search<=arr[upper]){

position=lower+(((search-arr[lower]*(upper-lower))/(arr[upper]-arr[lower])));
if(search==arr[position]){
return position;
}
else if(search<arr[position]){
return interpolationSearch(arr,lower,upper-1,search);
}
else if(search>arr[position]){
return interpolationSearch(arr,lower+1,upper, search);

}}
return -1;
}
int main(){
int array[]={1,2,3,4,5};
int size=sizeof(array)/sizeof(array[0]);
int search=4;
int output= interpolationSearch(array,0,size-1,search);
if(output==-1){
cout<<"This number does not exist";
}
else{
	cout<<"Array: ";
	for(int i=0;i<size;i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
	cout<<"The number exists at index: "<<output;
}
}