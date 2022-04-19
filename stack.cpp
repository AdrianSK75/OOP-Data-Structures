#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
    Node() {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList {
    Node *head;
    public:
        LinkedList() {
            head = NULL;
        }
        int countNodes() {
            Node *temp = head;
            int count = 0;
            while(temp != NULL) {
                    ++count;
                    temp = temp->next;
            }
            return temp;
        }
        void printList() {
            Node *temp = head;
            
            while (temp != NULL) {
                    cout << temp->data <<" ";
                    temp = temp->next;
            }
            cout << endl;
        }
        bool searchNode(int value) {
                Node *temp1 = head;
                while (temp1 != NULL) {
                        if (temp1->data == value) {
                                return 1;
                        }
                        temp1 = temp1->next;
                }
                return 0;
        }
        int searchPosition(int position) {
                Node *temp = head;
                int count = 0;
                while (temp != NULL) {
                        if (count == position) {
                                return temp->data;
                        }
                        ++count;
                        temp = temp->next;

                }
                return 0;
        }
        int searchNthPostionFromTheEnd(int count, int n) {
                if (count < n)  
                        return 0;
                
                Node *temp = head;
                for (int i = 0; i < count - n + 1; ++i) 
                        temp = temp->next;
                
                return temp->data;
        }
        void insertNode(int data) {
                Node *new_node = new Node(data);
                if (head == NULL) {
                    head = new_node;
                    return;
                }
                // traverse to the end of the list
                Node *temp = head;
                while (temp->next != NULL) {
                        temp = temp->next;
                }

                temp->next = new_node;
        }
        void deleteNode(int node) {
            Node *temp1 = head, *temp2 = NULL;
            int length = 0;
            if (head == NULL) {
                    cout <<"List is empty\n";
                    return;
            }
            while (temp1 != NULL) {
                    temp1 = temp1->next;
                    ++length;
            }
            if (length < node) {
                    cout << "Index out of range\n";
                    return;
            }
            temp1 = head;
            if (node == 1) {
                    head = head->next;
                    delete temp1;
                    return;
            }
            while (node --> 1) {
                    temp2 = temp1;
                    temp1 = temp1->next;
            }
            temp2->next = temp1->next;
            delete temp1;
            
        }
};

int main() {
       LinkedList list;

       list.insertNode(7);
       list.insertNode(3);
       list.insertNode(8);
       list.printList();
       //list.deleteNode(3);
       bool found = list.searchNode(8);
       int position = list.searchPosition(2);
       int count = list.countNodes();
       int searchNthPostionFromTheEnd = list.searchNthpositionEnd(count, 3)
       cout << count <<"\n";
       cout << position <<"\n";
       cout << found <<"\n";
       list.printList();
       
}