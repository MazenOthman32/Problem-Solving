#include <iostream>
using namespace std ;
template <typename T>
struct node {
    T data;
    node* next;

};

template <typename T>
class linkedlist {
    node<T>* head = nullptr;

public:

    void push_back(T value) {
        node<T>* newNode = new node<T>;
        newNode->data = value;
        newNode->next = nullptr;

        if (!head) {
            head = newNode;
            return;
        }

        node<T>* last = head;
        while (last->next) last = last->next;
        last->next = newNode;
    }

    void push_front(T value) {
        node<T>* newNode = new node<T>;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void pop_front() {
        if (!head) return;
        node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        node<T>* cur = head;
        node<T>* prev = nullptr;

        while (cur->next) {
            prev = cur;
            cur = cur->next;
        }

        prev->next = nullptr;
        delete cur;
    }

    void removeVal(T value) {
        if (!head) return;

        if (head->data == value) {
            node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node<T>* cur = head;
        node<T>* prev = nullptr;

        while (cur && cur->data != value) {
            prev = cur;
            cur = cur->next;
        }

        if (!cur) return;
        prev->next = cur->next;
        delete cur;
    }

    void display() {
        node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }


    int size() {
        int cnt = 0;
        node<T>* current = head;
        while (current) {
            cnt++;
            current = current->next;
        }
        return cnt;
    }

    void updateValue(int pos, T value) {
        if (pos < 0 || pos >= size()) return;

        node<T>* cur = head;
        for (int i = 0; i < pos; i++)
            cur = cur->next;

        cur->data = value;
    }


    T operator[](int pos) {
        if (pos < 0 || pos >= size())
            throw out_of_range("Index out of range");

        node<T>* cur = head;
        for (int i = 0; i < pos; i++)
            cur = cur->next;

        return cur->data;
    }


    ~linkedlist() {
        node<T>* cur = head;
        while (cur) {
            node<T>* temp = cur;
            cur = cur->next;
            delete temp;
        }
    }
};

