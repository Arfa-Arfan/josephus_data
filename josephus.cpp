#include <iostream>
using namespace std;

// Node structure for circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to create a circular linked list of size n
Node* createCircularList(int n) {
    Node* head = new Node();
    head->data = 1;
    Node* prev = head;

    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        Node* temp = new Node();
        temp->data = i;
        prev->next = temp;
        prev = temp;
    }

    // Complete the circle
    prev->next = head;
    return head;
}

// Function to solve Josephus Problem
int josephus(int n, int k) {
    Node* head = createCircularList(n);
    Node* ptr = head;
    Node* prev = NULL;

    // Loop until only one node is left
    while (ptr->next != ptr) {
        // Move k-1 steps
        for (int count = 1; count < k; count++) {
            prev = ptr;
            ptr = ptr->next;
        }

        // Eliminate the k-th person
        cout << "Eliminated: " << ptr->data << endl;
        prev->next = ptr->next;
        delete ptr;
        ptr = prev->next;
    }

    int survivor = ptr->data;
    delete ptr; // Clean memory
    return survivor;
}

// Driver code
int main() {
    int n, k;
    cout << "Enter number of people (n): ";
    cin >> n;
    cout << "Enter step count (k): ";
    cin >> k;

    int survivor = josephus(n, k);
    cout << "\nThe survivor is person: " << survivor << endl;

    return 0;
}
