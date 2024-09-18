using namespace std;
// ѧ����
class Student {
private:
    string studentID;  // ѧ��
    string name;       // ����
    int borrowedBooks;      // �ѽ��鼮��

public:
    Student(string id, string n) : studentID(id), name(n), borrowedBooks(0) {}

    string getStudentID() const { return studentID; }
    string getName() const { return name; }

    void borrowBook() { borrowedBooks++; }
    void returnBook() { if (borrowedBooks > 0) borrowedBooks--; }

    int getBorrowedBooks() const { return borrowedBooks; }
};

// �鼮��
class Book {
private:
    string bookID;    // �鼮���
    string title;     // ����
    bool isBorrowed;       // �Ƿ񱻽��

public:
    Book(string id, string t) : bookID(id), title(t), isBorrowed(false) {}

    string getBookID() const { return bookID; }
    string getTitle() const { return title; }

    bool borrow() {
        if (!isBorrowed) {
            isBorrowed = true;
            return true;
        }
        return false;
    }

    void returnBook() { isBorrowed = false; }

    bool checkBorrowed() const { return isBorrowed; }
};

// ͼ�����Ա��
class Librarian {
private:
    string librarianID;   // ����Ա���
    string name;          // ����

public:
    Librarian(string id, string n) : librarianID(id), name(n) {}

    void lendBook(Student &student, Book &book) {
        if (!book.checkBorrowed()) {
            book.borrow();
            student.borrowBook();
        }
    }

    // ����Ա����������
    void receiveBook(Student &student, Book &book) {
        if (book.checkBorrowed()) {
            book.returnBook();
            student.returnBook();
        }
    }
};
