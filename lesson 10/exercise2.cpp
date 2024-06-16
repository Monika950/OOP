//ios:: ate - тръгва от където е курсора и override-va информация
//static - обвързан с класа, но не зависят от инстанцията му

//#pragma once //като header guard

#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <stdexcept>
#include <string>


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

    friend ostream &operator<<(ostream &out, const Point2D* p)
    {
        out << "(";

        vector<double> params = p->getParameters();

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
        cout << line << endl;

        line.pop_back();
        line = line.substr(1, line.size() - 2);
        cout << line << endl;

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

class File 
{
    fstream fs;
public:
    File(const string& path, ios_base::openmode mode)
        : fs(path, mode) // ако е така с конструктор с параметри създава файла и го отваря
    {
        //this->fs.open(path,flags);
        if(!fs.is_open())
        {
            throw runtime_error("Couldn't open file '"+ path + "'" );
        }
    }

    ~File()
    {
        this->fs.close();
    }

    fstream &getFilestream() 
    {
        return this->fs;
    }

};

class PointReader
{
    PointReader(){}  //  PointReader() = delete; долу
public:
    static Point2D readPoint2D(File &f) //не трябва да връщаме локална променлива, затова не референция 
    {
        Point2D res;
        f.getFilestream() >> res;

        return res;
    }
    static vector<Point2D> readPoints2D(File &f)
    {
        vector<Point2D> res;
        while(!f.getFilestream().eof())
        {
            res.push_back(PointReader::readPoint2D(f));
        }
        return res;
    }

    // PointReader getPointReader() 
    // {
    //     static PointReader* instance = new PointReader();
    //     return *instance;
    // }  да се инстанцира само веднъж

};

class PointWriter
{
    PointWriter() {} // PointWriter() = delete;

public:
    static void writePoinst2D(const vector<Point2D> &points, File &f)
    {

    }
    static void writePoint2D(Point2D &point, File &f)
    {
        f.getFilestream() << &point << endl;
    }
};



int main()
{
    File f("points.txt",ios::in); // без app няма да го създаде, а ще хвърля грешка
    File f2("points2d.txt", ios::out | ios::trunc);

    // Point2D point = PointReader::readPoint2D(f);
    // cout << point.getX()<< " "<<point.getY()<< endl;

    vector<Point2D> points = PointReader::readPoints2D(f);

    for (Point2D p : points)
    {
        cout<<p.getX() <<" "<<p.getY()<< endl;
        PointWriter::writePoint2D(p, f2);
    }

    return 0;
}


//gives an error