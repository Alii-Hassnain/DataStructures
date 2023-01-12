#include <iostream>
using namespace std;


class list{
    private:
        int start;
        int current;
        int end;
        int arr[10]{0};
        
    public:
        //constructor.........
        list(){
            start = end = current = 0;
            
        }
        //Function to add only elements......
        void add(int value){
            arr[current] = value;
            current++;
            end = current;
        }
        //Function to add element at any position after making space ........
        void add(int value , int index){
            if(index <= end){
            current = end;
            current--;
            int e = end;
            for(int i=current;i>=index;i--){
                arr[e] = arr[i];
                current--;
                e--;
            }
            arr[e] = value;
            end++;

            }else{
                cout << "Value can't be added the limit is exceeded =" << endl;
            }
        }
        //Function to remove the element.....

        void remove(int index){
            if(index <= end){
                current = index;
                for(int i = index ; i<end ; i++){
                    arr[i] = arr[++current];

                }
            }
            end--;


        }

        //Function to search the required value........
        void search(){
            int value;
            int flag=-1;
            cout << "Enter the value to search =";
            cin >> value;
            for(int i=0;i<end;i++){
                if(arr[i] == value){
                    flag = i;
                    break;
                }
            }
                if(flag != -1){
                    cout << "Value is found at index " << flag <<endl;
                }else{
                    cout << "Value is not found " << endl;
                }
        }

        //Function to update the value.......
        void update(int value,int index){
            if(index <= end){
                arr[index] = value; 

            }else{
                cout << "Can't be update index exceeded the limit.." <<endl;
            }
        }

        //Function to move pointer one step next
        void next(){
            if(current<=end){
            current++;
            }
        }
        void back(){
            if(current <= end && current >= start){
                current--;
            }
        }

        //Function to show the length of the array........
        void length(){
            int counter =0;
            for(int i=start;i<end;i++){
                counter++;
            }
            cout << "Length of the array is = " << counter << endl;

        }

        //Function to display the result.....
        void display(){
            for(int i=0;i<end;i++){
                cout << arr[i]<<" ";
                // cout << endl;
            }
        }



};


int main(){
    list obj;
    obj.add(0);
    obj.add(1);
    obj.add(2);
    obj.add(3);
    obj.add(4);
    obj.add(5,5);
    obj.update(10,8);
    // obj.remove();
    obj.length();
    obj.display();
    // cout << endl;
    // obj.search();
    // obj.display();
   
}