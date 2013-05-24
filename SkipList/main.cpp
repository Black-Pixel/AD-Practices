#include <iostream>
#include "src/SkipList.h"

using namespace std;

int main()
{
    char choice = '0';
    SkipList skipList;

    while (choice != 'e') {
        cout << "||=======Skip-List======||" << endl;
        cout << "|| 1. Insert            ||" << endl;
        cout << "|| 2. Print             ||" << endl;
        cout << "|| 3. Search            ||" << endl;
        cout << "|| 4. Delete            ||" << endl;
        cout << "||----------------------||" << endl;
        cout << "|| e. Exit              ||" << endl;
        cout << "||======================||" << endl << endl;

        cin >> choice;

        if (choice == '1') {
            cout << "Insert value: ";
            int input;
            cin >> input;
            skipList.Insert(input);
            cout << endl;
        } else if (choice == '2') {
            skipList.Print();
        } else if (choice == '3') {
            cout << "Insert value: ";
            int input;
            cin >> input;
            if (skipList.Search(input)) {
                cout << endl << "Value found! :)" << endl;
            } else {
                cout << endl << "Value not found. :(" << endl;
            }
        } else if (choice == '4') {
            cout << "Insert value: ";
            int input;
            cin >> input;
            skipList.Delete(input);
            cout << endl;
        }
    }

    return 0;
}
