#include "iostream"
#include "clocale"
#include "library.hxx"

using namespace std;

void createBook(Library& library);
void borrowBook(Library& library);
void returnBook(Library& library);

int main() {

    setlocale(LC_ALL, "spanish");

    Library myLibrary = Library();

    char option;

    do {
        cout << "-------------------------------------------------" << endl;
        cout << "Ingresa una opcion:" << endl;
        cout << "  1 - Agregar un libro" << endl;
        cout << "  2 - Prestar un libro" << endl;
        cout << "  3 - Devolver un libro" << endl;
        cout << "  4 - Mostrar libros disponibles" << endl;
        cout << "  5 - Mostrar libros prestados" << endl;
        cout << endl;
        cout << "  6 - Salir" << endl;
        cout << endl;
        cout << endl;
        cout << "Opcion: ";
        cin >> option;
        cout << endl;
        cout << endl;

        switch (option) {
            case '1':
                createBook(myLibrary);
                break;
            case '2':
                borrowBook(myLibrary);
                break;
            case '3':
                returnBook(myLibrary);
                break;
            case '4':
                myLibrary.showAvailableBooks();
                break;
            case '5':
                myLibrary.showBorrowedBooks();
                break;
            case '6':
                cout << "En la buena :v" << endl;
                break;
            default:
                cout << "Opcion " << option << " invalida" << endl;
                break;
        }

        cout << endl;
    } while (option != '6');

    return 0;
}

void createBook(Library& library) {
    string name, author;
    int year, availableUnits;

    cout << "Titulo: ";
    cin >> name;
    cout << "Autor: ";
    cin >> author;
    cout << "Año: ";
    cin >> year;
    cout << "Cantidad: ";
    cin >> availableUnits;

    Book newBook = library.createBook(name, author, year, availableUnits);
    cout << "Nuevo libro creado con id: " << newBook.getId() << endl;
}

void borrowBook(Library& library) {
    string name, id;
    int bookId;

    cout << "Nombre: ";
    cin >> name;
    cout << "Identificación: ";
    cin >> id;
    cout << "ID del libro a solicitar: ";
    cin >> bookId;

    User newUser = User(name, id);

    library.borrowBook(bookId, newUser);
}

void returnBook(Library& library) {
    string name, id;
    int bookId;

    cout << "Nombre: ";
    cin >> name;
    cout << "Identificación: ";
    cin >> id;
    cout << "ID del libro a solicitar: ";
    cin >> bookId;

    User newUser = User(name, id);

    library.returnBook(bookId, newUser);
}

