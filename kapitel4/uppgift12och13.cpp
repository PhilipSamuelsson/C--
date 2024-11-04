#include <iostream>
#include <string>
using namespace std;

int subString(const string &t1, const string &t2)
{
    size_t found = t2.find(t1);

    if (found != string::npos)
    {
        return found;
    }
    else
    {
        return -1;
    }
}

int main()
{
    string t1 = "random word";
    string t2 = "This is a random word";

    int result = subString(t1, t2);
    cout << "This is the result: " << result << endl;
    return 0;
}