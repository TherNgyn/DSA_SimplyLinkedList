#include <iostream>
using namespace std;

// Lớp Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// Hàm tìm kiếm kèm vị trí
int searchKey(Node* head, int key) {
    Node* curr = head;
    int pos = 1;

    while (curr != NULL) {
        if (curr->data == key) {
            return pos; // trả về vị trí nếu tìm thấy
        }
        curr = curr->next;
        pos++;
    }

    return -1; // trả về -1 nếu không tìm thấy
}

int main() {
    // Tạo danh sách: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int key = 5;

    int pos = searchKey(head, key);
    if (pos != -1)
        cout << "Tim thay " << key << " tai vi tri " << pos;
    else
        cout << "Khong tim thay!!!";

    return 0;
}
