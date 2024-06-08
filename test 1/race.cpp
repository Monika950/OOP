#include <iostream>
#include <string>
#include <cstring>
#include <exception>

using namespace std;

class Race
{
public:
    char *raceName;
    double *results;
    size_t numberOfResults;
    static int numberOfTotalRaces;

    Race()
        : raceName(strdup("")), results(new double[1]), numberOfResults(0)
    {
        numberOfTotalRaces++;
    }

    Race(const char *raceName, const double *results, size_t numberOfResults)
    {
        if (numberOfResults <= 0 || raceName == nullptr || results == nullptr)
            throw invalid_argument("Invalid arguments");
        this->raceName = strdup(raceName);
        this->numberOfResults = numberOfResults;
        this->results = new double[numberOfResults];
        for (size_t i = 0; i < numberOfResults; i++)
            this->results[i] = results[i];
        numberOfTotalRaces++;
    }

    Race(const Race &other)
    {
        this->raceName = strdup(other.raceName);
        this->numberOfResults = other.numberOfResults;
        this->results = new double[this->numberOfResults];
        for (size_t i = 0; i < this->numberOfResults; i++)
            this->results[i] = other.results[i];
        numberOfTotalRaces++;
    }

    ~Race()
    {
        delete[] raceName;
        delete[] results;
    }

    Race &operator=(const Race &other)
    {
        if (this != &other)
        {
            delete[] this->raceName;
            this->raceName = strdup(other.raceName);
            this->numberOfResults = other.numberOfResults;
            delete[] this->results;
            this->results = new double[this->numberOfResults];
            for (size_t i = 0; i < this->numberOfResults; i++)
                this->results[i] = other.results[i];
        }
        return *this;
    }

    static int getTotalRaces()
    {
        return numberOfTotalRaces;
    }

    void printRaceInformation() const
    {
        cout << getTotalRaces() << " " << raceName;
        double avgResult;
        for (size_t i = 0; i < numberOfResults; i++)
            avgResult += results[i];
        cout << " " << avgResult / numberOfResults << endl;
    }
};

int Race::numberOfTotalRaces = 0;

class Formula1Race : public Race
{
    string *teams;
    size_t numberOfTeams;

public:
    Formula1Race(const char *raceName, const double *results, size_t numberOfResults, const string *teams, size_t numberOfTeams)
        : Race(raceName, results, numberOfResults)
    {
        if (numberOfTeams <= 0 || teams == nullptr)
            throw invalid_argument("Invalid arguments");
        this->numberOfTeams = numberOfTeams;
        this->teams = new string[numberOfTeams];
        for (size_t i = 0; i < numberOfTeams; i++)
            this->teams[i] = teams[i];
    }

    Formula1Race(const Formula1Race &other)
        : Race(other)
    {
        this->numberOfTeams = other.numberOfTeams;
        this->teams = new string[this->numberOfTeams];
        for (size_t i = 0; i < this->numberOfTeams; i++)
            this->teams[i] = other.teams[i];
    }

    ~Formula1Race()
    {
        Race::~Race();
        delete[] teams;
    }

    Formula1Race &operator=(const Formula1Race &other)
    {
        if (this != &other)
        {
            delete[] teams;
            this->numberOfTeams = other.numberOfTeams;
            this->teams = new string[this->numberOfTeams];
            for (size_t i = 0; i < this->numberOfTeams; i++)
                this->teams[i] = other.teams[i];
        }
        return *this;
    }

    void printRaceInformation() const
    {
        Race::printRaceInformation();
        for (size_t i = 0; i < numberOfTeams; i++)
            cout << teams[i] << endl;
    }
};

int main()
{
    try
    {
        const double results[] = {1.5, 2.0, 1.8};
        const string teams[] = {"Team A", "Team B", "Team C"};

        Race race1("Race 1", results, 3);
        Race race2(race1);
        Race race3;
        race3 = race2;

        Formula1Race formula1Race1("Formula1 Race 1", results, 3, teams, 3);
        Formula1Race formula1Race2(formula1Race1);
        Formula1Race formula1Race3 = formula1Race2;

        cout << "Race 1 Information: " << endl;
        race1.printRaceInformation();

        cout << "\nRace 2 Information: " << endl;
        race2.printRaceInformation();

        cout << "\nRace 3 Information: " << endl;
        race3.printRaceInformation();

        cout << "\nFormula1 Race 1 Information: " << endl;
        formula1Race1.printRaceInformation();

        cout << "\nFormula1 Race 2 Information: " << endl;
        formula1Race2.printRaceInformation();

        cout << "\nFormula1 Race 3 Information: " << endl;
        formula1Race3.printRaceInformation();
    }
    catch (exception &e)
    {
        cout << e.what() << '\n';
    }

    return 0;
}
