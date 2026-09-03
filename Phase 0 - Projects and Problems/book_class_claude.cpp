#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

class Book{
private: 
    string title;
    string author;
    int id;
    bool available;
public: 
    Book(const string& bookTitle, const string& bookAuthor, int bookId)
        : title(bookTitle), author(bookAuthor), id(bookId), available(true) {}

    int getId() const{
        return id;
    }

    bool isAvailable() const{
        return available;
    }

    void borrowBook(){
        if(available){
            available = false;
            cout << "Book borrowed Successfully.\n";
        }else {
            cout << "This Book is already Borrowed.\n";
        }
    }

    void returnBook(){
        if(!available){
            available = true;
            cout << "Book Returned.\n";
        } else {
            cout << "This Book is already returned.\n";
        }
    }

    void displayBook() const{
        cout << "\nID : " << id << endl;
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;

        if(available){
            cout << "Status : Available.\n";
        } else {
            cout << "Status : Borrowed.\n";
        }
    }
};

// Reads an integer safely; clears cin's fail state and discards
// the bad input if the user types something that isn't a number.
bool readInt(int& value){
    cin >> value;
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }
    return true;
}

bool idExists(const vector<Book>& library, int id){
    for(const Book& book : library){
        if(book.getId() == id){
            return true;
        }
    }
    return false;
}

int main(){
    vector<Book> library;
    int choice;

    do{
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. EXIT\n";
        cout << "Enter your Choice : ";

        if(!readInt(choice)){
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if(choice == 1){
            string title,author;
            int id;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Enter Book Name : ";
            getline(cin,title);

            cout << "Enter Author : ";
            getline(cin, author);

            cout << "Enter Book ID : ";
            if(!readInt(id)){
                cout << "Invalid ID. Book not added.\n";
                continue;
            }

            if(idExists(library, id)){
                cout << "A book with this ID already exists. Book not added.\n";
                continue;
            }

            library.emplace_back(title, author, id);
            cout << "Book added successfully.\n";
        }

        else if(choice == 2){
            if(library.empty()){
                cout << "No Books in Library add some.\n";
            }else {
                for(const Book& book : library){
                    book.displayBook();
                }
            }
        }

        else if(choice == 3 || choice == 4 || choice == 5){
            int searchId;
            bool found = false;

            cout << "Enter Book ID : ";
            if(!readInt(searchId)){
                cout << "Invalid ID.\n";
                continue;
            }

            for(Book& book : library){
                if(book.getId() == searchId){
                    found = true;

                    if(choice == 3){
                        book.displayBook();
                    }else if(choice == 4){
                        book.borrowBook();
                    }else{
                        book.returnBook();
                    }

                    break;
                }
            }
            if(!found){
            cout << "Book not found.\n";
            }
        } 

        else if(choice == 6){
            cout << "Exiting.....\n";
        }   

        else{
            cout << "Invalid Choice. Try Again.\n";
        }
    } while(choice != 6);
    
    return 0;
}