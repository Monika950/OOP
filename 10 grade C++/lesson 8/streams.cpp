// stream - поток от данни
/*input and output streams
да имаш външна функция която за параметър да искаш прайвет полета и най- лесният начин е да вкараш функция в класа а искаш да подадеш обекта като параметър и за да не е метод на класа
za nestvane na klasove
sus friend promenqme scope-a
kato argument & - reference
kato durgo? & - adres*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Point2D
{
    double x, y;

protected:
    virtual vector<double> getParameters() const
    {
        vector<double> res;
        res.push_back(x);
        res.push_back(y);
        return res;
    } 
public:
    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double x) { this->x = x; }
    void setY(double x) { this->y = x; }

    friend ostream &operator<<(ostream &out, const Point2D p)
    {
        out << "(";

        vector<double> params = p.getParameters();

        // for(auto param: params) //auto автоматично към типа
        for (int i = 0; i << params.size(); i++)
        {
            out << params[i];
            if (i + 1 != params.size())
            {
            }
        }

        out << ")";
        return out;
    }

    friend istream &operator>>(istream &in, Point2D &p)
    {
        string line;
        getline(in, line);
        //cout << line << endl;

        //line.pop_back();
        line = line.substr(1, line.size() - 2);
        //cout << line << endl;

        stringstream ss(line);

        string x, y;
        getline(ss, x, ',');
        getline(ss, y, ',');

        string newLine = x + " " + y; // whitespace за да направим chain-vaneto
        stringstream nss(newLine);

        nss >> p.x >> p.y;

        return in;
    }
};

class Point3D : public Point2D
{
    double z;

protected:
    vector<double> getParameters() const override
    {
        vector<double> res = Point2D::getParameters();
        res.push_back(this->z);

        return res;
    }

public:
    double getZ() const { return z; }
    void setZ(double z) { this->z = z; }

    friend ostream &operator<<(ostream &out, const Point3D &p)
    {
        out << "(" << p.getX() << "," << p.getY() << "," << p.getZ() << ")";

        return out;
    }
};

int main()
{
    Point2D p;
    p.setX(0.1);
    p.setY(0.11);

    //cout<< p << endl; //operator<<(operator<<(cout,p),endl);
    // p<< cout;  //p.operator<<(cout);
    //cin>> p;
    cout<< "The point chosen is: " << p << endl;

    Point3D p2;
    //cin >> p;
    p2.setX(0.1);
    p2.setY(0.1);
    p2.setZ(0.1);
    cout << p2 << endl;

    return 0;
}