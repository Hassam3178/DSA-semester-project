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

    Node<T>* getHead() const {
        return head;
    }

    void setHead(Node<T>* newHead) {
        head = newHead;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

   
};