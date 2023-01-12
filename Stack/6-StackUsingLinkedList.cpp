#include <iostream>
using namespace std;

class Node{
    private:
        int object;
        Node *nextNode;
    public:
        void setObject(int obj){
            object = obj;
        }
        int getObject(){
            return object;
        }
        void setNext(Node *p){
            nextNode = p;
        }
        Node *getNext(){
            return nextNode;
        }

};

class List{
    private:
        int size;
        Node *headNode;
    public:

        List(){
            size = 0;
            headNode = NULL;
        }

        void push(int obj){
            Node *newNode = new Node();
            if(isEmpty()){
                newNode->setObject(obj);
                newNode->setNext(NULL);
                headNode = newNode;
            }else{
                newNode->setObject(obj);
                newNode->setNext(headNode);
                headNode = newNode;
            }

        }
        void pop(){
            Node *tempNode;
            tempNode = new Node();
            tempNode = headNode;
            if(isEmpty()){
                cout << "Node is already empty";
            }else{
                headNode = headNode->getNext();
                delete tempNode;
            }
        }
        void top(){
            cout << headNode->getObject();
        }

        int isEmpty(){
            return headNode == NULL;
        }

        void display(){
            Node *temp = new Node();
            temp = headNode;
            while(temp!=NULL){
                cout << temp->getObject() << " ";
                temp = temp->getNext();
            }

        }
        
};



int main(){
    List list;
    list.push(10);
    list.push(20);
    list.push(30);
    list.pop();
    list.pop();
    list.pop();
    list.push(40);
    if(list.isEmpty()){
        cout<<"list is empty Now";
    }
    list.display();



}
