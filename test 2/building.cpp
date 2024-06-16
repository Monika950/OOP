#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Place
{
    string tenantName;
    double area;
    int floor;

public:
    Place() : tenantName(""), area(0), floor(0) {}

    string getTenantName() const {
        return tenantName;
    }

    double getArea() const {
        return area;
    }

    int getFloor() const {
        return floor;
    }
   
    friend istream& operator>>(istream& in, Place& p) {
        in >> p.tenantName >> p.floor >> p.area;
        if (p.tenantName.empty() || p.area < 0 || p.floor < 0) {
            throw invalid_argument("Invalid input for Place");
        }
        return in;
    }
};


class Building
{
    string address;
    vector<Place> places;

public:
    // Building() {}
    // Building(const string &address, const vector<Place> &places) 
    // {
    //     if (places.size() <= 0) {
    //         throw invalid_argument("Places list size must be a positive number.");
    //     }
    //      if (address.empty()) {
    //         throw invalid_argument("Address cannot be an empty string.");
    //     }
    //     this->address = address;
    //     this->places = places;
    // }
    double calculateTotalArea() const
    {
        double totalArea=0;
        for(int i=0; i<places.size(); i++)
        {
            totalArea += places[i].getArea();
        }
        return totalArea;
    }

    double estimateReturn(unsigned months) const
    {
        return calculateTotalArea() * getPricePerMonth() * months;
    }

    double estimateNetReturn(unsigned months) const
    {
         return estimateReturn(months) - estimateExpenses(months);
    }

    friend istream &operator>>(istream &in, Building *b)
    {
        in >> b->address;
        if (b->address.empty()) {
            throw invalid_argument("Address cannot be an empty string.");
        }

        int numberOfPlaces;
        in >> numberOfPlaces;
        if (numberOfPlaces <= 0) {
            throw invalid_argument("Places list size must be a positive number.");
        }

        for (int i = 0; i < numberOfPlaces; ++i) {
            in >> b->places[i];
        }

        return in;
    }
    virtual double getPricePerMonth() const = 0;
    virtual double estimateExpenses(unsigned months) const = 0;
};

class House : public Building
{
public:
     House() {}
    // House(const string &address, const vector<Place> &places)
    //     : Building(address, places) {}
    double getPricePerMonth() const override
    {
        return 1000.0;
    }
    double estimateExpenses(unsigned months) const override
    {
        return 100.0 * months;
    }

};

class Office : public Building
{
public:
    Office() {}
    // Office(const string &address, const vector<Place> &places)
    //     : Building(address, places) {}
    double getPricePerMonth() const override
    {
        return 2000.0;
    }
    double estimateExpenses(unsigned months) const override
    {
        return 200.0 * months;
    }

};


int main() {
    ifstream fs("buildings.txt");

    if (!fs.is_open()) {
        cerr << "Failed to open file buildings.txt" << endl;
        return 0;
    }

//     12			// months
// House			// тип на сградата
// Simeonovo 41		// адрес на сградата
// 3			// брой местата в сградата
// George 1 55   		// Име, етаж и площ на мястото
// John 3 105
// Michael 0 40
// Office
// G.M. Dimitrov 102
// 1
// Will 10 200

    vector<Building *> buildings;
    string type;
    int months = 0;
    fs >> months;

    while (!fs.eof())
    {
        Building* building = nullptr;
        fs >> type;

        if (type == "House") {
            building = new House();
        } else if (type == "Office") {
            building = new Office();
        } else {
            cerr << "Invalid type: " << type << endl;
            continue;
        }

        try {
            fs >> building;
            buildings.push_back(building);
        } catch (const exception &e) {
            cerr << "Error reading building: " << e.what() << endl;
            delete building; 
        }
    }


    double totalIncome = 0;
    double totalNetIncome = 0;

    for (int i = 0; i < buildings.size(); i++) {
        totalIncome += buildings[i]->estimateReturn(months);
        totalNetIncome += buildings[i]->estimateNetReturn(months); 
    }

    fs.close();

    cout << "Total income: " << totalIncome << " USD" << endl;
    cout << "Total net income: " << totalNetIncome << " USD" << endl;

    for (int i = 0; i < buildings.size(); i++)
    {
        delete buildings[i];
    }

    return 0;
}







