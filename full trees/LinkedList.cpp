#include <iostream>
using namespace std;

class Node{
    private:
        int object;
        Node *nextNode;
    public:
        int get(){
            return object;
        }
        void set(int obj){
            object = obj;
        }
        Node *getNext(){
            return nextNode;
        }
        void setNext(Node *nxtNode){
            nextNode = nxtNode;
        }
};
class List{
    private:
        int size;
        Node* headNode;
        Node* currentNode;
        Node* lastCurrentNode;
    public:
        //Constructur to add the make the head of the node....
        List(){
            headNode = new Node();
            headNode->setNext(NULL);
            currentNode = NULL;
            lastCurrentNode = NULL;
            size = 0;
        }
        friend List addNodes();
        friend void traverse(List list);
        //Used to add the node at the end or the start......
        void add(int addObject){
            Node*newNode = new Node();
            newNode->set(addObject);
            if(currentNode != NULL){
                newNode->setNext(currentNode->getNext());
                currentNode->setNext(newNode);
                lastCurrentNode = currentNode;
                currentNode = newNode;
                
            }else{
                newNode->setNext(NULL);
                headNode->setNext(newNode);
                lastCurrentNode = headNode;
                currentNode = newNode;
            }
            size++;

        }

        int get(){
            if(currentNode != NULL){
                return currentNode->get();
            }
        }
        bool next(){
            if (currentNode == NULL){
                return false;
            }else{
                lastCurrentNode = currentNode; 
                currentNode = currentNode->getNext();// return true; 
            }
            if (currentNode == NULL || size == 0) 
            return false; 
            else 
            return true; 
        }
        void remove(){


        } 
};
        void traverse(List list){
            Node* savedCurrentNode = list.currentNode;
            list.currentNode = list.headNode;

            for(int i=1;list.next();i++){
                cout << "\n Element"<<i << " " << list.get();
            }
            list.currentNode = savedCurrentNode;
        }
        List addNodes(){

            List list;
            list.add(2);
            list.add(6);
            list.add(8);
            list.add(7);
            list.add(1);

            cout << "\n List size =" << list.size <<"\n";
            return list;

        }

        int main(){
            List list = addNodes();
            
            traverse(list);
        }