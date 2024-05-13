#include<bits/stdc++.h>
using namespace std;

// Functiom declaration
void selectionSort(int arr[],int size);
void bubbleSort(int arr[],int size);
void insertionSort(int arr[],int size);

int main(){
    // int arr[] = {2,8,9,1,7,3};

    int size;
    cout<<"specify total no. to sort ";
    cin >> size;

    int arr[size];
    cout<<"enter numbers: ";
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    int sort;
    cout <<"which sort? 1.selection, 2.bubble, 3.insertion"<<endl;
    cin >> sort;
    
    switch (sort){
        case 1:
            selectionSort(arr,size);
            cout<<"array by selectionSort";
            break;
        case 2:
            bubbleSort(arr,size);
            cout<<"array by bubbleSort";
            break;
        case 3:
            insertionSort(arr,8);
            cout<<"array by insertionSort";
            break;
    }
    //printing
    for (const int &n : arr) {
        cout << n << "  ";
    }
    return 0;
}


void selectionSort(int arr[] , int size){

    for(int j=0;j<size-1;j++){
        int m_i=j;
        for(int i=j+1;i<size;i++){
            if(arr[i]<arr[m_i]){
                m_i=i;
            }
        }
        int min=arr[m_i];
        arr[m_i]=arr[j];
        arr[j]=min;
    }
    // cout<< "inside selection ";
}

void bubbleSort(int arr[],int size){
    for(int j=0;j<size-1;j++){
        for(int i=0;i<size-j;i++){
            if(arr[i]>arr[i+1]){
                int temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
    // cout<<"inside bubble ";
}

void insertionSort(int arr[],int size){
    // cout<< "inside insertion ";
    for(int i=0;i<size;i++){
        int hold=arr[i];
        int j=i;
        while (j>0 && hold<arr[j-1])
        {
           arr[j]=arr[j-1];
           j=j-1;
        }
        if(arr[j]==arr[j+1])
            arr[j]=hold;
    }
}
