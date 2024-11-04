#include <iostream>
#include <iomanip>
using namespace std;

double calculateSalary(int year)
{
    if (year == 1)
    {
        return 15000;
    }
    else
    {
        return 1.04 * calculateSalary(year - 1) + 400;
    }
}

int main()
{
    int year;
    cout << "How many years have you worked? ";
    cin >> year;

    double salary = calculateSalary(year);
    cout << fixed << setprecision(2);
    cout << "Your salary is: " << salary << " SEK" << endl;

    return 0;
}