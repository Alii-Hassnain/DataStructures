#include<iostream>
using namespace std;

class queueNode{
    private:
        int data;
        queueNode*nextNode;
    public:
        void setdata(int obj){
            data = obj;
        }
        int getdata(){
            return data;
        }
        void setNext(queueNode *p){
            nextNode = p;
        }  
        queueNode *getNext(){
            return nextNode;
        } 
};
class Queue{
    private:
        int size;
        queueNode*front;
        queueNode*rear;
    public:
        Queue(){
            size = 0;
            front = NULL;
            rear = NULL;
        }
        void enqueue(int obj){
            queueNode*newNode = new queueNode();
            newNode->setdata(obj);
            if(isEmpty()){
                newNode->setNext(NULL);
                rear = newNode;
                front = rear;
            }else{
                rear->setNext(newNode);
                newNode->setNext(NULL);
                rear = newNode;
            }

        }
        void dequeue(){
            queueNode* temp;
            temp = front;
            if(isEmpty()){
                cout << "Queue is already empty"<<endl;
            }else{
                front = front->getNext();
                delete temp;

            }
        }
        int isEmpty(){
            return front==NULL;
        }
        void display(){
            queueNode*temp;
            temp = front;
            while(temp!=NULL){
                cout << temp->getdata() << " ";
                temp = temp->getNext();
            }
        

        }
};


int main(){
    Queue l1;
    l1.enqueue(20);
    l1.enqueue(30);
    l1.dequeue();
    l1.dequeue();
    l1.dequeue();
    l1.enqueue(40);
    l1.enqueue(50);
    l1.display();

}