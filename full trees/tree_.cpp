#include <iostream>
using namespace std;


class Node{
    private:
        int data;
        Node *Left;
        Node *Right;
    public:
        void setdata(int data){
            this->data = data;
        }
        int getdata(){
            return data;
        }
        void setLeft(Node *p){
            Left = p;
        }
        Node *getleft(){
            return Left;
        }
        void setRight(Node *p){
            Right = p;
        }
        Node *getRight(){
            return Right;
        }
};

class Tree{
    private:
        int size;
        Node *RootNode;
        Node *preCurrentNode;
        Node *currentNode;
    public:
        Tree(){
            size= 0;
            currentNode = NULL;
        }
        void add(int data){
            Node *newNode = new Node();
                newNode->setdata(data);
                if(RootNode == NULL){
                    newNode->setLeft(NULL);
                    newNode->setRight(NULL);
                    currentNode = RootNode = newNode;
                }else{

                    Node *temp;
                    temp = RootNode;    
                    while(temp!=NULL){
                        if(newNode->getdata() < temp->getdata()){
                            temp->setLeft(newNode);
                            temp = newNode;
                        }else{
                            temp->setRight(newNode);
                        }
                }
            }
        }

};


int main(){

}