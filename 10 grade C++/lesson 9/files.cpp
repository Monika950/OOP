//overload - custom добавяне на функционалност, която да ни спести време
//overwrite vs overload - добавяш аргумент
//ctrl d - end-of-file
#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ifstream ifs; // only input
    ofstream ofs; // only output

    fstream fs; // read & write

    fs.open("tmp.txt", ios::in | ios::out | ios::trunc);

    if(!fs.is_open())
    {
        cerr << "Failed to open file" << endl;
    }

    cout << fs.tellp() << endl;
    fs << "Hello, world!" << endl;
    fs << "This is test!" << endl;
    //cout << fs.tellg() << endl;

    fs.seekg(ios::beg ); // fs.seekg(0)

    string line;
    while(!fs.eof())
    {   
        getline(fs,line);
        cout<< line << endl;
    }

    //fs >> line; //чете до първия whitespace 

    fs.close();

    return 0;
}