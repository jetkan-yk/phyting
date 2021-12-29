#include <bits/stdc++.h>

using namespace std;

class Car {
   protected:
    bool isSedan;
    string seats;

   public:
    Car(bool isSedan, string seats) {
        this->isSedan = isSedan;
        this->seats = seats;
    }

    bool getIsSedan() {
        return this->isSedan;
    }

    string getSeats() {
        return this->seats;
    }

    virtual string getMileage() = 0;

    void printCar(string name) {
        cout << "A " << name << " is " << (this->getIsSedan() ? "" : "not ")
             << "Sedan, is " << this->getSeats() << "-seater, and has a mileage of around "
             << getMileage() << ".\n";
    }
};

// Write your code here.

/**
*   WagonR class
**/
class WagonR : public Car {
   protected:
    int carMileage;

   public:
    WagonR(int carMileage) : Car(false, "4") {
        this->carMileage = carMileage;
    }

    string getMileage() {
        return to_string(this->carMileage) + " kmpl";
    }
};

/**
*   HondaCity class
**/
class HondaCity : public Car {
   protected:
    int carMileage;

   public:
    HondaCity(int carMileage) : Car(true, "4") {
        this->carMileage = carMileage;
    }

    string getMileage() {
        return to_string(this->carMileage) + " kmpl";
    }
};

/**
*   InnovaCrysta class
**/
class InnovaCrysta : public Car {
   protected:
    int carMileage;

   public:
    InnovaCrysta(int carMileage) : Car(false, "6") {
        this->carMileage = carMileage;
    }

    string getMileage() {
        return to_string(this->carMileage) + " kmpl";
    }
};

int main() {
    int carType, carMileage;
    cin >> carType >> carMileage;
    Car *pointer;
    if (carType == 0) {
        WagonR wagonR(carMileage);
        pointer = &wagonR;
        wagonR.printCar("WagonR");
    }

    if (carType == 1) {
        HondaCity hondaCity(carMileage);
        pointer = &hondaCity;
        hondaCity.printCar("HondaCity");
    }

    if (carType == 2) {
        InnovaCrysta innovaCrysta(carMileage);
        pointer = &innovaCrysta;
        innovaCrysta.printCar("InnovaCrysta");
    }
}