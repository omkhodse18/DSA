#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int n,int key){
    int start = 0, end = n-1;

    while(start < end){
        int mid = start + (end-start)/2;

        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    
    return -1;    
}

int main(){
    int n;
    cout<<"Enter array size : ";
    cin>>n;

    int arr[n];
    cout<<"Enter "<<n<<" elements : ";
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    int key;
    cout<<"Enter searching element : ";
    
    int idx = binarySearch(arr,n,key);

    if(idx == -1){
        cout<<key<<" is not present in array."<<endl;
    }
    else{
        cout<<key<<" is present at "<<idx<<" index";
    }

}