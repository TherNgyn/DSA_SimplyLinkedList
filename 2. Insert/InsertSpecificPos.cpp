#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int x) {
        val = x;
        next = nullptr;
    }
};

// Hàm chèn node tại vị trí pos (1-based index)
Node* insertPos(Node* head, int pos, int val) {
    if (pos < 1) return head; // Vị trí không hợp lệ

    if (pos == 1) { // Nếu chèn ở đầu danh sách
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode; // head thay đổi
    }

    Node* curr = head;
    for (int i = 1; i < pos - 1 && curr != nullptr; i++) curr = curr->next; // Duyệt đến node ngay trước vị trí cần chèn
    if (curr == nullptr) return head; // Nếu vị trí lớn hơn số node hiện có

    Node* newNode = new Node(val);
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Hàm in danh sách liên kết
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->val;
        if (curr->next != nullptr) cout << " -> ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);             // Tạo danh sách: 1 -> 2 -> 4
    head->next = new Node(2);
    head->next->next = new Node(4);

    int val = 3, pos = 3;                 // Chèn 3 tại vị trí thứ 3
    head = insertPos(head, pos, val);

    printList(head);                      // In ra: 1 -> 2 -> 3 -> 4
    return 0;
}
