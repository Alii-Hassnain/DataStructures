#include<iostream>
using namespace std;


class Node{
    private:
        int data;
        Node *nextNode;
        Node *previousNode;
    public:
        void setdata(int obj){
            data = obj;
        }
        int getdata(){
            return data;
        }
        void setNext(Node *p){
            nextNode = p;
        }
        Node *getNext(){
            return nextNode;
        }
        void setPrevious(Node *p){
            previousNode = p;
        }
        Node* getPrevious(){
            return previousNode;
        }
};

class List{
    private:
        int size;
        Node *headNode;
        Node *currentNode;
        Node *endNode;
    
    public:
        List(){
            size = 0;
            headNode = NULL;
            currentNode = NULL;
            endNode = NULL;

        }
        void add(int obj){
            Node *newNode = new Node();
            newNode->setdata(obj);
            if(currentNode == NULL){
            newNode->setNext(NULL);
            newNode->setPrevious(NULL);
            currentNode = newNode;
            headNode = currentNode;
            size++;

            }else{
                newNode->setNext(currentNode->getNext());
                newNode->setPrevious(currentNode);
                // (currentNode->getNext()) -> setPrevious(newNode);
                currentNode->setNext(newNode);
                currentNode = newNode;
                endNode = newNode;
                size++;
            }
        }
        // int search(int obj){
        //     Node*temp;
        //     temp = headNode;
        //     if(temp->getdata() == obj){
        //         return 1;
        //     }else{
        //         while(temp!=NULL){

        //         }
        //     }

        // }
        void remove(int obj){
            Node*temp,*pre;
            temp = headNode;
            if(temp->getdata() == obj){
                headNode = temp->getNext();
                headNode->setPrevious(NULL);
                delete temp;
                size--;
            }else{
                while(temp!=NULL){
                    if(temp->getdata() == obj){
                        pre->setNext(temp->getNext());
                        (temp->getNext())->setPrevious(pre);

                        delete temp;
                        return;
                    }
                    pre = temp;
                    temp = temp->getNext();
                }
                    
            }

        }
        void end(){
            cout << endNode->getdata();
        }
        void display(){
            Node *temp;
            temp = endNode;
            cout << "List = ";
            while(temp != NULL){
                cout << temp->getdata() <<" ";
                temp = temp->getPrevious();
            }
        }
};


int main(){
    List list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.remove(2);
    list.remove(3);
    list.remove(5);
    // list.remove(3);
    list.display();


    
}