#include <iostream>
using namespace std;

int main(){
    int arr[10] = {10,20,30,40,50,60,70,80,90,100};
    int number;
    int start = 0;
    int end = 9;
    int mid;
    int flag = 0;
    int loc = -1;

    cout << "Enter any number to find ==";
    cin >> number;

    while(start <= end){
        mid = (start+end)/2;
        if(arr[mid] == number){
            loc = mid;
            flag = 1;
            break;
        }else if(number < arr[mid]){
            end = mid-1;
        }else{
            start = mid + 1;
        }
    }
    if(flag != 1){
        cout << "Not found!" << endl;
    }else{
        cout << "found at index " << loc <<endl;
    }
}