#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Author {
protected:
    string name;
    bool contributed;
public:
    Author(string n, bool c) : name(n), contributed(c) {}
    string getName() {
        return name;
    }
    bool hasContributed() {
        return contributed;
    }
};

int main() {
    vector<Author> authors = {
        Author("Author1", true),
        Author("Author2", true),
        Author("Author3", true),
        Author("Author4", false),
        Author("Author5", true)
    };

    cout << "List of authors who contributed:" << endl;
    for (auto &author : authors) {
        if (author.hasContributed()) {
            cout << author.getName() << endl;
        }
    }

    cout << "\nList of authors who did not contribute:" << endl;
    for (auto &author : authors) {
        if (!author.hasContributed()) {
            cout << author.getName() << endl;
        }
    }

    return 0;
}
