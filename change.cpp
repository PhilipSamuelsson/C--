#include <iostream>
using namespace std;

void calculate_change(int price, int payed)
{
    // Definiera sedlar och mynt
    int values[] = {1000, 500, 200, 100, 50, 20, 10, 5, 1};
    int change = payed - price;
    int size = sizeof(values) / sizeof(values[0]);

    if (change < 0)
    {
        cout << "Betalat belopp är inte tillräckligt. Du saknar " << -change << " kr." << endl;
        return;
    }

    cout << "Totalt växel att ge tillbaka: " << change << " kr." << endl;

    // Loop för att räkna antal sedlar och mynt
    for (int i = 0; i < size; i++)
    {
        int amount = change / values[i];
        if (amount > 0)
        {
            cout << amount << " st " << values[i] << "-kronors" << endl;
        }
        change %= values[i];
    }
}

int main()
{
    int price, payed;

    // Ta in pris och betalat belopp från användaren
    cout << "Ange priset på varan: ";
    cin >> price;

    cout << "Ange det betalda beloppet: ";
    cin >> payed;

    // Anropa funktionen för att beräkna växel
    calculate_change(price, payed);

    return 0;
}