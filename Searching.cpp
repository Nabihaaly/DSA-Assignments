#include<bits/stdc++.h>
using namespace std;

void linearSearch(int arr[],int size,int toSearch);
int binarySearch(int arr[],int size,int toSearch);

int main(){
    int arr[]={3,5,6,8,11,22,44};
    // int arr[]={3,5,6,11,9,22,44};
    int size=7;
    // cout<<"specify total no. to sort ";
    // cin >> size;

    // int arr[size];
    // cout<<"enter numbers: ";
    // for(int i=0;i<size;i++){
    //     cin >> arr[i];
    // }

    int toSearch;
    cout<<"enter num to search: ";
    cin >> toSearch;

    int searchBy;
    cout <<"which search? 1.linearSearch, 2.binarySearch "<<endl;
    cin >> searchBy;

     switch (searchBy){
        case 1:
            linearSearch(arr,size,toSearch);
            cout<<"array by linearSearch";
            break;
        case 2:
            int index=binarySearch(arr,size,toSearch);
            cout << "the number is at index "<< index;
            break;
            
     }
    
    return 0;
}

void linearSearch(int arr[],int size,int toSearch){
    bool result;
    int ind=0;

    for(int i=0;i<size;i++){
        if(arr[i]==toSearch){
            result=true;
            ind=i;
            break;
        }
    }
    if(result){
        cout<<"number found at index "<<ind;
    }
    else{
        cout<<"number not found";
    }
}

int binarySearch(int arr[],int size,int toSearch){
    
    int sp=0;
    int lp=size-1;
    int mp=(sp+lp)/2;

    while(sp<=lp){
        if(arr[mp]==toSearch){
            return mp;
        }
        else if(arr[mp]<toSearch){
            sp=mp+1;
        }
        else{
            lp=mp-1;
        }
        mp=sp+(lp-sp)/2;
    }
    return -1;
}