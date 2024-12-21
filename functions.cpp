 template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};
//linklist for results
void displayResults() {
        Node<pair<string, int>>* current = head;
        while (current) {
            cout << "Exam: " << current->data.first << " - Score: " << current->data.second << endl;
            current = current->next;
        }
    }