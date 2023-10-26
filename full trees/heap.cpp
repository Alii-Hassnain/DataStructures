#include <iostream>
using namespace std;


void MaxHeap(int arr[],int end){
    int temp,i;
    int parent;
    i = end;
    temp = arr[i];
    parent = arr[i/2];

    while (i>1 && temp > arr[i/2]){
        arr[i] = arr[i/2];
            i  = i/2;
     }
            arr[i] = temp;

}
void MinHeap(int arr [],int end){
    int temp,i;
    i = end;
    temp = arr [i];

    while (i>1 && temp < arr [i/2])
    {
        arr [i] = arr [i/2];
        i = i / 2;

    }
        arr [i] = temp;
}

void del(int A[],int n){
    int x,i,j;
    x = A[1];
    A[1] = A[n];
    // A[n] = x;
    i = 1;//parent
    j = i*2;//left child

    while (j<n-1){
        if(A[j+1] > A[j]){
            j = j+1;
        }
        if(A[i] < A[j]){
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i=j;
            j = 2*j;
        }else{
            break;
        }
        
        
    }
    A[n] = x;

}



void display(int arr[], int size){
    for(int i=1;i<=size;i++){
        cout << arr[i] << " ";
    }
}




int main(){


    int arr[] = {0,10,20,30,25,5,40,35};

    for (int i = 2; i<=7;i++){
        // cout << arr[i] << endl;
        MaxHeap(arr,i);
    }
    display(arr,7);
    cout << endl;
    for (int i = 7; i >=1 ; i--){
        del (arr,i);
    }
    display(arr,7);
    // cout << endl;
    // for (int i = 2; i<=7;i++){
    //     MinHeap(arr,i);
    // }
    // display(arr,7);
    
}