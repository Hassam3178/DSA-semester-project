// Instructor class
class Instructor {
private:
    QuestionQueue questionQueue;
    LinkedList<string> examTitles;
    LinkedList<Question> savedQuestions;
public:
    void createExam() {
        string title;
        cout << "Enter exam title: ";
        cin.ignore();
        getline(cin, title);
        examTitles.append(title);

        int numQuestions;
        cout << "Enter number of questions: ";
        cin >> numQuestions;
        cin.ignore();

        for (int i = 0; i < numQuestions; ++i) {
            string questionText, options[4];
            char correctOption;
            cout << "Enter question " << i + 1 << ": ";
            getline(cin, questionText);
            for (int j = 0; j < 4; ++j) {
                cout << "Option " << char('A' + j) << ": ";
                getline(cin, options[j]);
            }
            cout << "Enter correct option (A/B/C/D): ";
            cin >> correctOption;
            cin.ignore();

            Question newQuestion(questionText, options, correctOption);
            questionQueue.enqueue(newQuestion);
            savedQuestions.append(newQuestion);
        }

        cout << "Exam created successfully!\n";
    }

    void viewExams() {
        if (examTitles.isEmpty()) {
            cout << "No available exams.\n";
            return;
        }

        cout << "\nAvailable Exams:\n";
        examTitles.display();
    }

    void reviewQuestions() {
        if (savedQuestions.isEmpty()) {
            cout << "No questions have been added yet.\n";
            return;
        }

        cout << "\nReviewing all saved questions:\n";
        Node<Question>* current = savedQuestions.getHead();
        while (current) {
            current->data.displayQuestion();
            current = current->next;
        }
    }

    LinkedList<Question> getSavedQuestions() const {
        return savedQuestions;
    }

    string selectExam() {
        if (examTitles.isEmpty()) {
            return "";
        }

        cout << "\nSelect an exam to attempt:\n";
        Node<string>* current = examTitles.getHead();
        int index = 1;
        while (current) {
            cout << index++ << ". " << current->data << endl;
            current = current->next;
        }

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        current = examTitles.getHead();
        for (int i = 1; i < choice && current; ++i) {
            current = current->next;
        }

        return current ? current->data : "";
    }
};
