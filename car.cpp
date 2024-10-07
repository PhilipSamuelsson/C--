#include <iostream>
using namespace std;

int main() {
    int miles_year_ago;
    int miles_today;
    float avg_gas;
    int car_age; 

    cout << "Hur gammal är din bil?";
    cin >> car_age;
    
    if (car_age <= 5) {
        cout << "Du borde skaffa helförsäkring" << endl;
    }
    else if (car_age > 5 && car_age < 25) {
        cout << "Du borde skaffa halvförsäkring" << endl;
    }
    else if (car_age >= 25) {
        cout << "Du borde skaffa veteransbilsförsäkring" << endl;
    }

/*     
    cout << "How many miles did your car have one year ago? ";
    cin >> miles_year_ago;
    cout << "How many miles are on your car today? ";
    cin >> miles_today;
    cout << "Gas per mile? ";
    cin >> avg_gas;

    int yearly_miles = miles_today - miles_year_ago;
    float yearly_gas = avg_gas * yearly_miles;

    cout << "This many miles did you drive during the year: " << yearly_miles << endl;
    cout << "This much gas did you spend: " << yearly_gas << " liter" << endl;  */
    
    return 0;
}

