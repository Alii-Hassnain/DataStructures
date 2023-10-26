#include <iostream>
using namespace std;

int main(){

    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int number;
    int flag = 0;
    int index = 0;

    cout << "Enter the number to find =";
    cin >> number;

    for(int i =0;i<10;i++){
        if(arr[i] == number){
            index = i;
            flag = 1;
        }

    }
    if(flag != 1){
        cout << "Value is not found in the array";

    }else{
        cout << "Value is found at index " <<index<< endl;
    }
    
}