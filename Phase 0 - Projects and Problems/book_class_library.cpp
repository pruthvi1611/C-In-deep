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
    Book(string bookTitle, string bookAuthor, int bookId){
        title = bookTitle;
        author = bookAuthor;
        id = bookId;
        available = true;
    }

    int getId(){
        return id;
    }

    bool isAvailable(){
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

    void displayBook(){
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
int main(){
    vector<Book> library;
    int choice;

    do{
        cout << "\n--- Library Menu ---.\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Borrow Book\n";
        cout << "5. Return Book\n";
        cout << "6. EXIT\n";
        cout << "Enter your Choice : ";
        cin >> choice;

        if(choice == 1){
            string title,author;
            int id;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout << "Enter Book Name : ";
            getline(cin,title);

            cout << "Enter Author : ";
            getline(cin, author);

            cout << "Enter Book ID : ";
            cin >> id;

            library.push_back(Book(title, author, id));
            cout << "Book added successfully.\n";
        }

        else if(choice == 2){
            if(library.empty()){
                cout << "No Books in Library add some.\n";
            }else {
                for(Book& book : library){
                    book.displayBook();
                }
            }
        }

        else if(choice == 3 || choice == 4 || choice == 5){
            int searchId;
            bool found = false;

            cout << "Enter Book ID : ";
            cin >> searchId;

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