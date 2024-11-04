#include <iostream>
using namespace std;

class Car
{
public:
    string brand;
    string model;
    int year;
    double mileage;

    // Constructor
    Car(string brand, string model, int year, double mileage)
    {
        this->brand = brand;
        this->model = model;
        this->year = year;
        this->mileage = mileage;
    }

    void drive(double distance)
    {
        this->mileage += distance;
    }

    void display()
    {
        cout << "Brand: " << this->brand << endl;
        cout << "Model: " << this->model << endl;
        cout << "Year: " << this->year << endl;
        cout << "Mileage: " << this->mileage << endl;
    }

    int getYear()
    {
        return this->year;
    }

    double getMileage()
    {
        return this->mileage;
    }
};

int main()
{
    Car car1("Toyota", "Corolla", 2015, 10000);
    Car car2("Honda", "Civic", 2016, 20000);

    car1.display();
    car1.drive(100);
    car1.display();

    cout << "Year: " << car1.getYear() << endl;
    cout << "Mileage: " << car1.getMileage() << endl;

    return 0;
}
