#include "mylist.h"

int main()
{
    MyList list1, list2(2), list3(3, 6), list4(list3);
    cout << "List 1: " << list1 << "\nList 2: " << list2 << "\nList 3: " << list3 << "\nList 4: " << list4 << endl;
    if (list3 == list4)
        cout << "List 3 is equal to list 4\n";
    else
        cout << "List 3 isn't equal to list 4\n";
    cout << "Enter new list 1 and list 2:\n";
    cin >> list1 >> list2;
    cout << "New list 1: " << list1 << endl << "New list 2: " << list2 << endl;
    list3 = ++list1 + list2 -- + 7; 
    cout << "List 3: " << list3 << endl << "List 2: " << list2 << endl << "List 1: " << list1 << endl;
    if (list3.CheckExistencePerfectNumberGreaterThanMinimum())
        cout << "List 3 contains an element whose value is a perfect number greater than the minimum value of all the elements.";
    return 0;    
}