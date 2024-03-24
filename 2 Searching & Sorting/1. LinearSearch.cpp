#include<bits/stdc++.h>
using namespace std;

int linearSearch(int *arr,int n,int key){
    int idx=-1;

    for(int i=0;i<n;i++){
        if(arr[i]==key){
            idx = i;
        }
    }

    return idx;    
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
    
    int idx = linearSearch(arr,n,key);

    if(idx == -1){
        cout<<key<<" is not present in array."<<endl;
    }
    else{
        cout<<key<<" is present at "<<idx<<" index";
    }

}