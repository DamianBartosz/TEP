#include "LotteryInstance.hpp"

LotteryInstance::LotteryInstance(int *wyniki, string date) {
    for (int i = 0; i < liczbaWynikow; i++) {
        this->wyniki[i] = wyniki[i];
        this->date = date;
    }
}

void LotteryInstance::print() {
    cout << "Data: " << date << endl;
    cout << "Wylosowane liczby: ";
    for (int i = 0; i < 6; i++){
        cout<<wyniki[i]<<" ";
    }
    cout<<endl;
}
