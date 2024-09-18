using namespace std;
// 学生类
class Student {
private:
    string studentID;  // 学号
    string name;       // 姓名
    int borrowedBooks;      // 已借书籍数

public:
    Student(string id, string n) : studentID(id), name(n), borrowedBooks(0) {}

    string getStudentID() const { return studentID; }
    string getName() const { return name; }

    void borrowBook() { borrowedBooks++; }
    void returnBook() { if (borrowedBooks > 0) borrowedBooks--; }

    int getBorrowedBooks() const { return borrowedBooks; }
};

// 书籍类
class Book {
private:
    string bookID;    // 书籍编号
    string title;     // 书名
    bool isBorrowed;       // 是否被借出

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

// 图书管理员类
class Librarian {
private:
    string librarianID;   // 管理员编号
    string name;          // 姓名

public:
    Librarian(string id, string n) : librarianID(id), name(n) {}

    void lendBook(Student &student, Book &book) {
        if (!book.checkBorrowed()) {
            book.borrow();
            student.borrowBook();
        }
    }

    // 管理员操作：还书
    void receiveBook(Student &student, Book &book) {
        if (book.checkBorrowed()) {
            book.returnBook();
            student.returnBook();
        }
    }
};
