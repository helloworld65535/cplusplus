#include <iostream>
#include <string>

namespace append_Test
{
    int main(void)
    {
        using namespace std;

        // The first member function
        // appending a C-string to a string
        string str1a("Hello ");
        cout << "The original string str1 is: " << str1a << endl;
        const char *cstr1a = "Out There ";
        cout << "The C-string cstr1a is: " << cstr1a << endl;
        str1a.append(cstr1a);
        cout << "Appending the C-string cstr1a to string str1 gives: "
             << str1a << "." << endl
             << endl;

        // The second member function
        // appending part of a C-string to a string
        string str1b("Hello ");
        cout << "The string str1b is: " << str1b << endl;
        const char *cstr1b = "Out There ";
        cout << "The C-string cstr1b is: " << cstr1b << endl;
        str1b.append(cstr1b, 3);
        cout << "Appending the 1st part of the C-string cstr1b "
             << "to string str1 gives: " << str1b << "."
             << endl
             << endl;

        // The third member function
        // appending part of one string to another
        string str1c("Hello "), str2c("Wide World ");
        cout << "The string str2c is: " << str2c << endl;
        str1c.append(str2c, 5, 5);
        cout << "The appended string str1 is: "
             << str1c << "." << endl
             << endl;

        // The fourth member function
        // appending one string to another in two ways,
        // comparing append and operator [ ]
        string str1d("Hello "), str2d("Wide "), str3d("World ");
        cout << "The  string str2d is: " << str2d << endl;
        str1d.append(str2d);
        cout << "The appended string str1d is: "
             << str1d << "." << endl;
        str1d += str3d;
        cout << "The doubly appended strig str1 is: "
             << str1d << "." << endl
             << endl;

        // The fifth member function
        // appending characters to a string
        string str1e("Hello ");
        str1e.append(4, '!');
        cout << "The string str1 appended with exclamations is: "
             << str1e << endl
             << endl;

        // The sixth member function
        // appending a range of one string to another
        string str1f("Hello "), str2f("Wide World ");
        cout << "The string str2f is: " << str2f << endl;
        str1f.append(str2f.begin() + 5, str2f.end() - 1);
        cout << "The appended string str1 is: "
             << str1f << "." << endl
             << endl;
        return 0;
    }
}
int main()
{
    append_Test::main();
    return 0;
}