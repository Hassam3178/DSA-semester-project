#include<iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
using namespace std;


class Stack {
private:
    LinkedList<int> stackList;
public:
    void push(int value) {
        stackList.append(value);
    }

    int pop() {
        return stackList.pop();
    }

    bool isEmpty() {
        return stackList.isEmpty();
    }

    void displayStack() {
        stackList.display();
    }
};


// Node for linked list
template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

//Linked List Implementation
template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void display() {
        Node<T>* current = head;
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
    }

    Node<T>* getHead() const {
        return head;
    }

    void setHead(Node<T>* newHead) {
        head = newHead;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    T pop() {
        if (!head) {
            throw runtime_error("List is empty!");
        }
        T value = head->data;
        Node<T>* temp = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete temp;
        return value;
    }
};

//Linked List for results
class ResultList {
private:
    Node<pair<string, int>>* head;
    Node<pair<string, int>>* tail;
public:
    ResultList() : head(nullptr), tail(nullptr) {}

    void addResult(string examTitle, int score) {
        Node<pair<string, int>>* newNode = new Node<pair<string, int>>({examTitle, score});
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayResults() {
        Node<pair<string, int>>* current = head;
        while (current) {
            cout << "Exam: " << current->data.first << " - Score: " << current->data.second << endl;
            current = current->next;
        }
    }
};
class Stack {
private:
    LinkedList<int> stackList;
public:
    void push(int value) {
        stackList.append(value);
    }

    int pop() {
        return stackList.pop();
    }

    bool isEmpty() {
        return stackList.isEmpty();
    }

    void displayStack() {
        stackList.display();
    }
};