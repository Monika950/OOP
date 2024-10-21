#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Currency
{
    string name;
    double price;
    double amount;
public:
    Currency()
    : name(""), price(0), amount(0)
    {

    }

    string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    double getAmount() const {
        return amount;
    }

    friend istream &operator>>(istream &in, Currency &bet)
    {
        in >> bet.name >> bet.price >> bet.amount;
        return in;
    }
};

class Portfolio
{
protected:
    string name;
    vector<Currency> currencies;

  void validateName(const string &name) {
        if (name.empty()) {
            throw invalid_argument("Name cannot be an empty string.");
        }
    }

    void validateCurrenciesSize(const vector<Currency> &currencies) {
        if (currencies.size() <= 0) {
            throw invalid_argument("Currencies list size must be a positive number.");
        }
    }

public:
    Portfolio(){}
    Portfolio(const string &name, const vector<Currency> &currencies) {
        validateName(name);
        validateCurrenciesSize(currencies);
        this->name = name;
        this->currencies = currencies;
    }

    string getName() const {
        return name;
    }

    vector<Currency> getCurrencies() const {
        return currencies;
    }

    double calculateTotalPortfolioBalance() const
    {   
        double balance = 0;
        for(int i = 0; i < currencies.size(); i++)
        {
            balance+=currencies[i].getAmount() * currencies[i].getPrice();
        }
        return balance;
    }

    double estimateReturn() const
    {
        return calculateTotalPortfolioBalance()*getRisk();
    }

    double estimateReturnAfterTax() const
    {
        return estimateReturn() * (1 - getTax());
    }

    virtual double getTax() const = 0;
    virtual double getRisk() const = 0;

    friend istream &operator>>(istream &in, Portfolio *portfolio)
    {
        in >> portfolio->name;
        if (portfolio->name.empty()) {
            throw invalid_argument("Name cannot be an empty string.");
        }

        int numberOfCurrencies;
        in >> numberOfCurrencies;
        if (numberOfCurrencies <= 0) {
            throw invalid_argument("Currencies list size must be a positive number.");
        }

        portfolio->currencies.resize(numberOfCurrencies);
        for (int i = 0; i < numberOfCurrencies; ++i) {
            in >> portfolio->currencies[i];
        }
        
        return in;

    }
};

class CryptoPortfolio : public Portfolio
{
public:
    CryptoPortfolio() {}
    CryptoPortfolio(const string &name, const vector<Currency> &currencies)
        : Portfolio(name, currencies) {}

    double getTax() const 
    {
        return 0.10;
    }
    double getRisk() const 
    {
        return 10.00;
    }
};

class StocksPortfolio : public Portfolio
{
public:
    StocksPortfolio() {}
    StocksPortfolio(const string &name, const vector<Currency> &currencies)
        : Portfolio(name, currencies) {}

    double getTax() const override {
        return 0.00; 
    }

    double getRisk() const override {
        return 0.10; 
    }
};

int main()
{
    ifstream fs;

    fs.open("portfolios.txt", ios::in);

    if(!fs.is_open())
    {
        cerr << "Failed to open file" << endl;
    }

     vector<Portfolio *> arr;
    string type;

    while (!fs.eof()) {
        Portfolio* portfolio;
        if (type == "C") {
            portfolio = new CryptoPortfolio();
        } else if (type == "S") {
            portfolio = new StocksPortfolio();
        } else {
            cerr << "Unknown portfolio type: " << type << endl;
            continue;
        }

        try {
            fs >> portfolio;
            arr.push_back(portfolio);
        } catch (const exception &e) {
            cerr << "Error reading portfolio: " << e.what() << endl;
            delete portfolio; 
        }
    }

    fs.close();

    double totalIncome = 0;
    double totalNetIncome = 0;

    for (const auto &portfolio : arr) {
        totalIncome += portfolio->estimateReturn();
        totalNetIncome += portfolio->estimateReturnAfterTax();
        delete portfolio; 
    }

    cout << "Total income: " << totalIncome << " USD" << endl;
    cout << "Total net income: " << totalNetIncome << " USD" << endl;

    return 0;
}



#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class Currency
{
private:
    string name;
    double price;
    double amount;

public:
    Currency()
    {
        name = "";
        price = 0;
        amount = 0;
    }

    friend istream &operator>>(istream &in, Currency &currency)
    {
        in >> currency.name >> currency.price >> currency.amount;
        if (currency.name == "")
            throw "Invalid name";
        if (currency.price < 0)
            throw "Invalid price";
        if (currency.amount < 0)
            throw "Invalid amount";
        return in;
    }

    string getName() const
    {
        return name;
    }

    double getPrice() const
    {
        return price;
    }

    double getAmount() const
    {
        return amount;
    }
};

class Portfolio
{
private:
    vector<Currency> currencies;
    string name;

public:
    double calculateTotalPortfolioBalance() const
    {
        double total = 0;
        for (int i = 0; i < currencies.size(); i++)
        {
            total += currencies[i].getPrice() * currencies[i].getAmount();
        }
        return total;
    }

    double estimateReturn() const
    {
        return calculateTotalPortfolioBalance() * (getRisk() / 100);
    }

    double estimateReturnAfterTax() const
    {
        return estimateReturn() * ((100 - getTax()) / 100);
    }

    virtual double getTax() const = 0;
    virtual double getRisk() const = 0;

    friend istream &operator>>(istream &in, Portfolio &portfolio)
    {
        in >> portfolio.name;
        if (portfolio.name == "")
            throw "Invalid name";
        int n;
        in >> n;
        if (n <= 0)
            throw "Invalid number of currencies";
        for (int i = 0; i < n; i++)
        {
            Currency c;
            in >> c;
            portfolio.currencies.push_back(c);
        }
        return in;
    }

    vector<Currency> getCurrencies() const
    {
        return currencies;
    }

    string getName() const
    {
        return name;
    }
};

class CryptoPortfolio : public Portfolio
{
public:
    double getTax() const
    {
        return 10;
    }

    double getRisk() const
    {
        return 1000;
    }
};

class StocksPortfolio : public Portfolio
{
public:
    double getTax() const
    {
        return 0;
    }

    double getRisk() const
    {
        return 10;
    }
};

int main()
{
    vector<Portfolio *> arr;
    ifstream file("portfolios.txt");
    if (!file.is_open())
    {
        cout << "File not found" << endl;
        return 0;
    }
    // file format
    //     C            // тип на фиша - C - crypto, S - stock
    // MyPortfolio1        // име на портфолиото
    // 3            // брой на валутите в портфолиото
    // Bitcoin 70000 0.001   // Име, цена и количество на валутата
    // Ethereum 3700 2.5
    // Solana 180 22.5

    while (!file.eof())
    {
        string type;
        file >> type;

        Portfolio *portfolio = nullptr;
        if (type == "C")
        {
            portfolio = new CryptoPortfolio();
        }
        else if (type == "S")
        {
            portfolio = new StocksPortfolio();
        }
        else
        {
            cout << "Invalid type" << endl;
            continue;
        }

        try
        {
            file >> *portfolio;
            arr.push_back(portfolio);
        }
        catch (const char *err)
        {
            cout << err << endl;
            delete portfolio;
        }
    }

    double totalIncome = 0;
    double totalNetIncome = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        totalIncome += arr[i]->estimateReturn();
        totalNetIncome += arr[i]->estimateReturnAfterTax();
    }

    cout << "Total income: " << totalIncome << " USD" << endl;
    cout << "Total net income: " << totalNetIncome << " USD" << endl;
    file.close();

    for (int i = 0; i < arr.size(); i++)
    {
        delete arr[i];
    }

    return 0;
}