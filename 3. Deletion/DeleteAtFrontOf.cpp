#include <iostream>
using namespace std;

class Node {       //cấu trúc của 1 node
public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* deleteHead(Node* head) {
    // Kiểm tra danh sách có trống không
    if (head == nullptr)
        return nullptr;

    Node* temp = head;
    // Di chuyển con trỏ đầu đến node tiếp theo
    head = head->next;
    // Giải phóng bộ nhớ của node đầu cũ
    delete temp;
    return head;
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        if (head->next != nullptr) {
            cout << " -> ";
        }
        head = head->next;
    }
}

int main() {
    // 8 -> 2 -> 3 -> 1 -> 7
    Node* head = new Node(8);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(7);

    head = deleteHead(head);
    printList(head);

    return 0;
}


