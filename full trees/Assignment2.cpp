#include <iostream>
using namespace std;


class Node{
    private:
        int object;
        Node* nextNode;
    public:
        void setObject(int p){
            object = p;
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
        Node *headNode;
        Node *currentNode;
        Node *endNode;
        int size;
    public:
        List(){
            headNode    = NULL;
            currentNode = NULL;
            endNode     = NULL;
            size        = 0;
        }


        //Function to add new node  and add object in it...........
        void add(int obj){
            Node*newNode = new Node();
            newNode->setObject(obj);
            if(currentNode == NULL){
                newNode->setNext(NULL);
                headNode = newNode;
                currentNode = headNode;
            }else{
                newNode->setNext(currentNode->getNext());
                currentNode->setNext(newNode);
                currentNode = newNode;
                endNode = currentNode;
            }
            size++;
        }

        //Function to remove the object from the list.............
        void remove(int obj){
            Node *temp,*temp2;
            temp = headNode;
            if(temp->getObject() == obj){
                headNode = temp->getNext();
                delete temp;
                cout << "\n Value is deleted after 1st step"<<endl;
                size--;
                return;
            }else{

                temp2 = temp;
                while(temp != NULL){
                    if(temp->getObject() == obj){
                        temp2->setNext(temp->getNext());
                        delete temp;
                        cout <<"\nValue is deleted after N steps of work" <<endl;
                        size--;
                        return;
                    }
                    temp2 = temp;
                    temp = temp->getNext();
                }
            }
                cout << "\nSearching.....Value not found ";
        }

        //Fucntion to update the object because of wrong input......
        void update(int obj,int newobj){
            Node *temp;
            temp = headNode;
            if(temp->getObject() == obj){
                headNode->setObject(newobj);

                
            }else{
                while (temp!=NULL)
                {
                    if(temp->getObject() == obj){
                        temp->setObject(newobj);
                        return;
                    }
                    temp = temp->getNext();
                    
                }
                cout <<"Object Not found to update"<<endl;
                
            }
        }



        //Function to search the required object............
        bool search(int obj){
            Node*temp = headNode;
            int num=0;
            int flag=0;
            while (temp != NULL)
            {
                if(temp->getObject() == obj){
                    flag = 1;
                    break;
                }else{
                    flag = 0;
                }
                temp = temp->getNext();

            }
            if(flag == 1){
                
                cout << obj <<" is found";
                return true;
            }else{
                
                cout << obj <<" is not found";
                return false;
            }
            

        }




        //Function to move the current to the start
        void start(){
            currentNode = headNode;
            cout << "Start object =" << currentNode->getObject() << endl;
        }

        //Function to move the current to the endl
        void end(){
            currentNode = endNode;
            cout << "End object =" << currentNode->getObject() << endl;
        }

        //Function to get the vlaue at the current position
        // void get(){
        //     cout << "CurrentNode object =" << currentNode->getObject() << endl;
        // }

        //Function to increment the current pointer a next step ahead
        void next(){
            currentNode = currentNode->getNext();
            cout << "Next object =" << currentNode->getObject() << endl;
        }

        //Fucntion to move the current to its previous..
        void back(){
            Node *temp1;
            temp1=headNode;
            if(currentNode == headNode || currentNode == endNode){
                cout << "can't move" <<endl;
            }else{
                while (temp1!=NULL)
                {
                    if(temp1->getNext() == currentNode){
                        currentNode=temp1;
                        cout << "Back object =" << currentNode->getObject() << endl;
                        return;
                    }
                    temp1 = temp1->getNext();
                }
                
            }

        }

        //Function to get total length of the list object being added..
        void length(){
            cout << "Length of the list ="<< size<<endl;
        }





        //Function to display the whole list....  
        void display(){
            Node*temp = headNode;
            cout << "List = ";
            while (temp != NULL)
            {
                cout <<" "<< temp->getObject();
                temp = temp->getNext();
            }
            cout << endl;
            
        }


};



int main(){
    List list;
    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);
    // list.search(20);
    // list.remove(2);
    // list.update(10,100);
    // list.update(30,500);
    // list.update(50,20);
    list.display();
    // list.display();

    cout << endl;

    //movement of the current  node.......
    list.start();
    list.next();
    list.next();
    list.back();
    list.end();
    
    
    


}