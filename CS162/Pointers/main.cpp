#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

#define ForLoop(i, m, n) for (int i = m; i < n; ++i)

double max(double a, double b)
{
    return (a > b) ? a : b;
}

struct student
{
    char *name, *id;
    int year;
    float gpa;
};

char *ConvertString(char str[])
{
    char *res = new char[strlen(str) + 1];
    ForLoop(i, 0, strlen(str))
    {
        res[i] = str[i];
    }
    return res;
}

void inputStudent(istream &fin, student &s)
{
    char tS[101];

    fin.ignore();
    fin.get(tS, 101, ',');
    s.id = ConvertString(tS);

    fin.ignore();
    fin.get(tS, 101, ',');
    s.name = ConvertString(tS);

    fin.ignore();
    fin >> s.year;

    fin.ignore();
    fin >> s.gpa;
}

void outputStudent(ostream &fout, student &s)
{
    fout << s.id << ','
         << s.name << ','
         << s.year << ','
         << s.gpa << endl;
}

int main()
{
    int n;
    student *s;
    int maxGPA[4] = {-1, -1, -1, -1};

    ifstream fin("Data/StudentList.csv");
    if (fin.is_open())
    {
        char info[101];
        fin.get(info, 101, '\n');

        n = 0;
        ForLoop(i, 4, strlen(info))
        {
            if (info[i] == ')')
                break;

            n = n * 10 + int(info[i] - '0');
        }

        s = new student[n];
        ForLoop(i, 0, n)
        {
            inputStudent(fin, s[i]);
            maxGPA[s[i].year - 1] = max(maxGPA[s[i].year - 1], s[i].gpa);
        }
    }
    fin.close();

    ofstream fout("Data/HighestGPAList.csv");
    if (fout.is_open())
    {
        fout << "ID,Name,Year,GPA\n";

        ForLoop(y, 0, 4)
        {
            if (maxGPA[y] == -1)
                continue;

            ForLoop(i, 0, n)
            {
                if (s[i].year == y + 1 && s[i].gpa == maxGPA[y])
                    outputStudent(fout, s[i]);
            }
        }
    }
    fout.close();

    cout << "Done!\n";

    ForLoop(i, 0, n)
    {
        delete[] s[i].id;
        delete[] s[i].name;
    }
    delete[] s;
    return 0;
}