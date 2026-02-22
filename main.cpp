#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title;
    bool borrowed;
};

vector<Book> library;

void addBook() {
    Book b;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, b.title);
    b.borrowed = false;
    library.push_back(b);
    cout << "Book added!\n";
}

void showBooks() {
    if (library.empty()) {
        cout << "No books in library\n";
        return;
    }

    for (int i = 0; i < library.size(); i++) {
        cout << i+1 << ". " << library[i].title;
        if (library[i].borrowed) cout << " (Borrowed)";
        cout << endl;
    }
}

void borrowBook() {
    showBooks();
    cout << "Enter book number to borrow: ";
    int n; cin >> n;
    if (n>0 && n<=library.size()) {
        library[n-1].borrowed = true;
        cout << "Book borrowed\n";
    }
}

void returnBook() {
    showBooks();
    cout << "Enter book number to return: ";
    int n; cin >> n;
    if (n>0 && n<=library.size()) {
        library[n-1].borrowed = false;
        cout << "Book returned\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\nLibrary Menu\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) addBook();
        else if (choice == 2) showBooks();
        else if (choice == 3) borrowBook();
        else if (choice == 4) returnBook();
        else if (choice == 5) break;
    }
}
