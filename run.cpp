#include <iostream>

using namespace std;

// Funktion för att omvandla tid till sekunder
int tidTillSekunder(int timmar, int minuter, int sekunder) {
    return timmar * 3600 + minuter * 60 + sekunder;
}

// Funktion för att omvandla sekunder till timmar, minuter och sekunder
void sekunderTillTid(int totalSekunder, int &timmar, int &minuter, int &sekunder) {
    timmar = totalSekunder / 3600;
    totalSekunder %= 3600;
    minuter = totalSekunder / 60;
    sekunder = totalSekunder % 60;
}

int main() {
    int timmar1, minuter1, sekunder1;
    int timmar2, minuter2, sekunder2;
    
    // Ta in input för det första loppet
    cout << "Ange tid för första loppet (tt mm ss): ";
    cin >> timmar1 >> minuter1 >> sekunder1;
    
    // Ta in input för det andra loppet
    cout << "Ange tid för andra loppet (tt mm ss): ";
    cin >> timmar2 >> minuter2 >> sekunder2;
    
    // Omvandla tiderna till sekunder
    int totalSekunderLopp1 = tidTillSekunder(timmar1, minuter1, sekunder1);
    int totalSekunderLopp2 = tidTillSekunder(timmar2, minuter2, sekunder2);
    
    // Summera totaltiden
    int totalSekunder = totalSekunderLopp1 + totalSekunderLopp2;
    
    // Variabler för att hålla den omvandlade totaltiden
    int totaltTimmar, totaltMinuter, totaltSekunder;
    
    // Omvandla totaltiden tillbaka till timmar, minuter och sekunder
    sekunderTillTid(totalSekunder, totaltTimmar, totaltMinuter, totaltSekunder);
    
    // Skriv ut resultatet
    cout << "Den totala tiden för löparen är: " 
         << totaltTimmar << " timmar, " 
         << totaltMinuter << " minuter, " 
         << totaltSekunder << " sekunder." << endl;
    
    return 0;
}
