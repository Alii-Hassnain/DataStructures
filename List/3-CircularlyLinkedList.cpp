#include<iostream>
using namespace std;


class Node{
    private:
        int data;
        Node*nextnode;
    public:
        void setdata(int obj){
            data = obj;
        }
        int getdata(){
            return data;
        }
        void setNext(Node *p){
            nextnode = p;
        }
        Node* getNext(){
            return nextnode;
        }
};
class CircleList{
    private:
        int size;
        Node *headNode;
        Node *endNode;
    public:
        CircleList(){
            headNode = NULL;
            endNode= NULL;
            size = 0;
        }
        void add(int obj){
            Node *newNode = new Node();
            newNode->setdata(obj);
            if( endNode==NULL){
                newNode->setNext(newNode);
                endNode = newNode;
                headNode = endNode;
            }else{
                endNode->setNext(newNode);
                newNode->setNext(headNode);
                endNode = newNode;

            }
        }
};


int main(){

}
