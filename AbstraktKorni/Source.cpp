#include<iostream>
#include<vector>
using namespace std;

class Korni
{
public:
    virtual vector<double> rb(void) const = 0;
};

class l1 : public Korni
{
    double k, b;
public:
    void ink(double _k) { k = _k; }
    void inb(double _b) { b = _b; }
    l1(void) : k(0), b(0) { }
    l1(double _k, double _b) : k(_k), b(_b) { }
    virtual vector<double> rb(void) const override { return (fabs(b) < 1e-6 ?  vector<double>() :  vector<double>() = { -b / k }); }
};

class Yravnni : public Korni
{
    double a, b, c;
public:
    void setA(double _a) { a = _a; }
    void setB(double _b) { b = _b; }
    void setC(double _c) { c = _c; }
    Yravnni(void) : a(0), b(0), c(0) { }
    Yravnni(double _a, double _b, double _c) : a(_a), b(_b), c(_c) { }
    virtual vector<double> rb(void) const override
    {
        double D = b * b - 4 * a * c;
        return (D < 0 ?  vector<double>() : fabs(a) < 1e-6 ? l1(b, c).rb() :  vector<double>() = { (-b + sqrt(D)) / (2 * a), (-b - sqrt(D)) / (2 * a) });
    }
};

int main()
{
    Yravnni obj(2, -12, 6);
    for (auto a : obj.rb())
       cout << a << std::endl;

}