#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) : data(value), next(0), prev(0) {}
};
class DoublyLinkedList{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(0), tail(0) {}
    ~DoublyLinkedList(){
        while (head){
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    class ForwardIterator{
    private:
        Node* current;
    public:
        ForwardIterator(Node* startNode) : current(startNode) {}
        ForwardIterator& operator++(){
            if(current){
                current=current->next;
            }
            return *this;
        }
        bool operator==(const ForwardIterator& other) const{
            return current==other.current;
        }
        bool operator!=(const ForwardIterator& other) const{
            return current!=other.current;
        }
        int operator*() const{
            if(current){
                return current->data;
            } 
            else{
                throw out_of_range("Iterator out of range");
            }
        }
    };
    class ReverseIterator {
    private:
        Node* current;
    public:
        ReverseIterator(Node* startNode) : current(startNode) {}
        ReverseIterator& operator++(){
            if (current){
                current=current->prev;
            }
            return *this;
        }
        bool operator==(const ReverseIterator& other) const{
            return current==other.current;
        }
        bool operator!=(const ReverseIterator& other) const{
            return current!=other.current;
        }
        int operator*() const{
            if (current){
                return current->data;
            } 
            else{
                throw out_of_range("Iterator out of range");
            }
        }
    };
    void insertEnd(int value){
        Node* newNode=new Node(value);
        if(!head){
            head=tail=newNode;
        } else {
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
        }
    }
    ForwardIterator fbegin() const{
        return ForwardIterator(head);
    }
    ForwardIterator fend() const{
        return ForwardIterator(nullptr);
    }
    ReverseIterator rbegin() const{
        return ReverseIterator(tail);
    } 
    ReverseIterator rend() const{
        return ReverseIterator(nullptr);
    }
};
int main() {
    DoublyLinkedList myList;
    myList.insertEnd(1);
    myList.insertEnd(2);
    myList.insertEnd(3);
    myList.insertEnd(4);
    // Forward iteration
    cout<<"Forward iteration: ";
    for(DoublyLinkedList::ForwardIterator it = myList.fbegin(); it != myList.fend();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    // Reverse iteration
    cout<<"Reverse iteration: ";
    for(DoublyLinkedList::ReverseIterator it=myList.rbegin();it!=myList.rend();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}