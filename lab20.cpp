#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 3, MIN = 10000, MAX = 99999;

class Chair {
private:
    int legs;
    double * prices;
    
public:
    Chair();
    Chair(int l, double p[SIZE]);

    void setLegs(int l)      { legs = l; }
    int getLegs()            { return legs; }

    void setPrices(double p1, double p2, double p3);
    double getAveragePrices();
    void print();
};

int main() {
    srand(time(0));
    cout << fixed << setprecision(2);

    Chair *chairPtr = new Chair;
    chairPtr->print();

    double prices[SIZE] = {525.25, 434.34, 252.52};
    Chair *livingChair = new Chair(3, prices);
    livingChair->print();
    delete livingChair;
    livingChair = nullptr;

    Chair *collection = new Chair[SIZE];
    for (int i = 0; i < SIZE; i++) {
        collection[i].print();
    }
    
    delete chairPtr;
    delete[] collection;

    return 0;
}

Chair::Chair() {
    prices = new double[SIZE];
    legs = (rand() % 2) + 3;
    for (int i = 0; i < SIZE; i++) {
        prices[i] = (rand() % (MAX-MIN+1) + MIN) / 100.0;
    }
}

Chair::Chair(int l, double p[SIZE]) {
    prices = new double[SIZE];
    legs = l;
    for (int i = 0; i < SIZE; i++) {
        prices[i] = p[i];
    }
}

void Chair::setPrices(double p1, double p2, double p3) { 
        prices[0] = p1; prices[1] = p2; prices[2] = p3; 
}

double Chair::getAveragePrices() {
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += prices[i];
    }
    return sum / SIZE;
}

void Chair::print() {
    cout << "CHAIR DATA - legs: " << legs << endl;
    cout << "Price history: " ;
    for (int i = 0; i < SIZE; i++) {
        cout << prices[i] << " ";
    }
    cout << endl << "Historical avg price: " << getAveragePrices();
    cout << endl << endl;
}
