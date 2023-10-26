#include <iostream>
using namespace std;

class Node{
    private:
        int data;
        Node *next;
    public:
        void set(int p){
            data = p;
        }
        int get(){
            return data;
        }
        Node *getNext(){
            return next;
        }
        void setNext(Node *p){
            next = p;
        }
};
class List{
    private:
        int size;
        Node *head;
        Node *lastcurrent;
        Node *current;
    public:
        List(){
            head = new Node();
            head->setNext(NULL);
            lastcurrent = NULL;
            current = NULL;
        }
        void add(int p){
            Node *newNode;
            newNode = new Node();
            newNode->set(p);
            if(current == NULL){
                
                newNode->setNext(NULL);
                lastcurrent = head;
                current = newNode;
            }else{
                
            }


        }

}


int main(){

}