#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

class student {
    string std_name;
    string std_id;
    int std_class;

public:
    void std_data(string name, string id, int Class) {
        std_name = name;
        std_id = id;
        std_class = Class;
    }

    void display() {
        cout << "Student Name: " << std_name << "  " << "ID: " << std_id << "  " << "Class: " << std_class <<  endl;
    }

    void read_from_file2(ifstream& file) {
        file >> std_name >> std_id >> std_class;
    }

    void write_in_file(ofstream& wfile) {
        wfile << std_name << " " << std_id << " " << std_class << endl;
    }
};

class book {
    string title;
    int book_code;

public:
    void book_data(string t, int p) {
        title = t;
        book_code = p;
    }

    void display() {
        cout << "Title: " << title << "  " << "Book code: " << book_code << "  " << endl;
    }

    void book_list() {
        cout << title << endl;
    }

    void read_from_file(ifstream& read_file) {
        read_file >> title >> book_code;
    }
};

void option() {
    int a = 0;
    cout << setw(40) << "Book Management System" << endl << endl;
    cout << __DATE__ << " " << __TIME__ << endl << endl;
    cout << setw(a) << "1. Add Books" << setw(49) << "(8) Book history" << endl;
    cout << setw(a) << "2. Book list" << setw(50) << "(9) Today history" << endl;
    cout << setw(a) << "3. View Books" << endl;
    cout << setw(25) << "(0) Exit" << setw(20) << "(i) Info" << endl << endl;
}

void student_data_entry() {
    const int maxStudents = 10; // Adjust as needed
    student student_obj[maxStudents];
    int n;
    int idx = 0;
    string name;
    string id;
    int Class;

    ifstream file("student_data.txt");
    while (!file.eof() && idx < maxStudents) {
        student_obj[idx].read_from_file2(file);
        idx++;
    }
    file.close();

    ofstream wfile("student_data.txt", ios::app);

    cout << "How many students: ";
    cin >> n;
    for (int i = 0; i < n && idx < maxStudents; i++) {
        cout << endl << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Student Id: ";
        getline(cin, id);
        cout << "Enter class: ";
        cin >> Class;
        student_obj[idx].std_data(name, id, Class);
        idx++;
    }



    wfile.close();
}

int main() {
    const int maxBooks = 50; // Adjust as needed
    book object[maxBooks];
    string z;
    int idx = 0;

    fstream in_file("book_data.txt");
    ifstream read_file("book_data.txt");
    while (!read_file.eof() && idx < maxBooks) {
        object[idx].read_from_file(read_file);
        idx++;
    }
    read_file.close();

    option();
    do {
        cout << "-->";
        cin >> z;
        cout << endl;
        if (z == "1") {
            int n;
            string t;
            int p;

            cout << "How many books: ";
            cin >> n;
            for (int i = 0; i < n && idx < maxBooks; i++) {
                cout << endl << "Enter Book title: ";
                cin.ignore();
                getline(cin, t);

                cout << "Enter Book Code: ";
                cin >> p;

                object[idx].book_data(t, p);
                idx++;
                in_file << t << " " << p << endl;

            }
        } else if (z == "2") {
            for (int i = 0; i < idx; i++) {
                cout << 1 + i << ". ";
                object[i].book_list();
            }
        } else if (z == "3") {
            for (int i = 0; i < idx; i++) {
                cout << "Book " << i + 1 << ":" << endl;
                object[i].display();
            }
        } else if (z == "0") {
            exit(0);
        } else if (z == "cls") {
            system("cls");
            option();
        } else if (z == "s") {
            student_data_entry();
        }
    } while (1);

    return 0;
}
