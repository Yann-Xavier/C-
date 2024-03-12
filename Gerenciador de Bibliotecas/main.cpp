#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <locale>

using namespace std;

struct Book {
    string title;
    string author;
    bool available;
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const string& title, const string& author) {
        books.push_back({title, author, true});
        cout << "Livro adicionado com sucesso!\n";
    }

    void borrowBook(int index) {
        if (index >= 0 && index < books.size()) {
            if (books[index].available) {
                books[index].available = false;
                cout << "Livro emprestado com sucesso!\n";
            } else {
                cout << "Livro já está emprestado.\n";
            }
        } else {
            cout << "Índice inválido!\n";
        }
    }

    void returnBook(int index) {
        if (index >= 0 && index < books.size()) {
            if (!books[index].available) {
                books[index].available = true;
                cout << "Livro devolvido com sucesso!\n";
            } else {
                cout << "Livro já está disponível.\n";
            }
        } else {
            cout << "Índice inválido!\n";
        }
    }

    void listBooks() {
        cout << "Lista de Livros:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << ". ";
            if (books[i].available)
                cout << "[Disponível] ";
            else
                cout << "[Emprestado] ";
            cout << books[i].title << " - " << books[i].author << endl;
        }
        cout << endl;
    }
};

int main() {
    setlocale (LC_ALL, "portuguese");
    Library library;
    int choice;
    string title, author;
    int index;

    do {
        cout << "=== Sistema de Gerenciamento de Biblioteca ===\n";
        cout << "1. Adicionar Livro\n";
        cout << "2. Emprestar Livro\n";
        cout << "3. Devolver Livro\n";
        cout << "4. Listar Livros\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Título do Livro: ";
                cin.ignore(); // Ignore newline character left in buffer
                getline(cin, title);
                cout << "Autor do Livro: ";
                getline(cin, author);
                library.addBook(title, author);
                break;
            case 2:
                cout << "Índice do Livro a ser emprestado: ";
                cin >> index;
                library.borrowBook(index - 1); // Adjusting for 0-based indexing
                break;
            case 3:
                cout << "Índice do Livro a ser devolvido: ";
                cin >> index;
                library.returnBook(index - 1); // Adjusting for 0-based indexing
                break;
            case 4:
                library.listBooks();
                break;
            case 0:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida!\n";
        }
    } while (choice != 0);

    return 0;
}

