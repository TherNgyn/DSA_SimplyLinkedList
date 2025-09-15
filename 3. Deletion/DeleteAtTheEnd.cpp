#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

Node* removeLastNode(Node* head) {
    // Nếu danh sách rỗng thì trả về nullptr
    if (head == nullptr) {
        return nullptr;
    }
    // Nếu danh sách chỉ có 1 node, xóa luôn node đó
    if (head->next == nullptr) {
        delete head;
        return nullptr;
    }
    // Tìm node áp chót (second last)
    Node* secondLast = head;
    while (secondLast->next->next != nullptr) {
        secondLast = secondLast->next;
    }
    // Xóa node cuối
    delete secondLast->next;
    // Cho con trỏ next của node áp chót thành nullptr
    secondLast->next = nullptr;
    return head;
}
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}
int main() {
    // Tạo danh sách: 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head = removeLastNode(head);

    printList(head);

    return 0;
}
