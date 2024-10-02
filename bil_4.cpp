#include <iostream>

/*
    Программа, которая находит число различных элементов в линейном двухсвязном списке. 
*/

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Сама функция
int countUniqueElements(Node* head) {
    if (!head) return 0;

    Node* current = head;
    int uniqueCount = 0;

    while (current) {
        bool isUnique = true;
        Node* checker = head;

        while (checker != current) {
            if (checker->data == current->data) {
                isUnique = false;
                break;
            }
            checker = checker->next;
        }

        if (isUnique) {
            uniqueCount++;
        }

        current = current->next;
    }

    return uniqueCount;
}

// Тест
int main() {
    Node* head = new Node{2, nullptr, nullptr};
    Node* second = new Node{2, nullptr, head};
    Node* third = new Node{2, nullptr, second};
    Node* fourth = new Node{2, nullptr, third};
    Node* fifth = new Node{2, nullptr, fourth};
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    int uniqueCount = countUniqueElements(head);
    std::cout << "Number of unique elements: " << uniqueCount << std::endl;

    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}
