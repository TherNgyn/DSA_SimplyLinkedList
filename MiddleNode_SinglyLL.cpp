#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* CreateNode(int data){
    Node* node = new Node();
    node-> data = data;
    node-> next = NULL;
    return node;
}
struct SinglyLinkedList{
    Node* head;
    Node* tail;
};
void CreateList(SinglyLinkedList &list){
    list.head = NULL;
    list.tail = NULL;
}
void printList(Node* current){
    while(current!=nullptr){
        cout << current -> data << " ";
        current = current -> next;
    }
}
// PP Naive
int getMiddle_Naive(Node* head){
    if(head==nullptr) return -1; // Danh sách rỗng
    else{
        int length = 0;
        Node* current = head;
        while(current != nullptr){
            length++;
            current = current -> next;
        }
        int middle = length/2;
        
        for(int i = 0; i<middle; i++){
            head = head->next;
        }
        return head -> data;
    }
}
// PP Rùa và thỏ 
int getMiddle_HareTortoise(Node* head){
    if(head==nullptr) return -1;
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow -> data;
}
int main(){
    SinglyLinkedList singlyll;
    CreateList(singlyll);
    //HEAD --> 1 --> 2 --> 3 --> 4 --> NULL
    Node* head = CreateNode(1);
    head->next = CreateNode(2);
    head->next->next = CreateNode(3);
    head->next->next->next = CreateNode(4);
    

    singlyll.head = head;
    cout<<"Danh sách liên kết đơn: ";
    printList(singlyll.head);
    cout<<endl;
    cout<<"Giá trị middle theo Naive: "<< getMiddle_Naive(singlyll.head);
    cout<<endl;
    cout<<"Giá trị middle theo Rùa và thỏ: "<< getMiddle_HareTortoise(singlyll.head);
    cout<<endl;
    // Đo độ phức tạp của getMiddle:
    // Độ phức tạp O(n) với n là số node trong danh sách
    // Không gian phức tạp O(1) vì không sử dụng bộ nhớ phụ
    return 0;
}