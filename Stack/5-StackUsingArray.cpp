#include <iostream>
using namespace std;

class Stack{
    private:
        int object;
        int current;
        int size;
        int Arr[10]{0};

    public:
        Stack(){
            size =10;
            current= -1;

        }
        void push(int p){
            Arr[++current] = p;
        }
        int pop(){
            return Arr[current--];

        }
        int top(){

            return Arr[current];
            cout << Arr[current];
            

        }
        int isEmpty(){
            return current==-1;
        }
        int isFull(){
            return current == size-1;
        }
        void display(){
            for(int i=0 ; i<=current;i++){
                cout << Arr[i] << " ";
            }
        }


};


int main(){
    Stack stack;
    stack.push(10);
    stack.push(11);
    cout << endl;
    // stack.pop();
    // stack.pop();

    stack.display();
    stack.top();
    

}
