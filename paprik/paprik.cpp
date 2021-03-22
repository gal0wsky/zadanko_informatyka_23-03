#include <iostream>
#include <string>
using namespace std;

class Mieszkanie
{
private:
    int nrBudynku;
    int nrLokalu;

public:
    Mieszkanie()
    {
        this->nrBudynku = 0;
        this->nrLokalu = 0;
    }

    void setBudynek(int nr)
    {
        this->nrBudynku = nr;
    }

    void setLokal(int nr)
    {
        this->nrLokalu = nr;
    }

    int getBudynek()
    {
        return this->nrBudynku;
    }

    int getNr()
    {
        return this->nrLokalu;
    }
};

class Budynek
{
private:
    int nrBudynku;
    Mieszkanie mieszkania[10];

public:
    Budynek(int nr)
    {
        this->nrBudynku = nr;
    }

    void setNr(int nr)
    {
        this->nrBudynku = nr;
    }

    void addMieszkanie(Mieszkanie mieszkanie, int index)
    {
        this->mieszkania[index] = mieszkanie;
    }

    int getNr()
    {
        return this->nrBudynku;
    }

    Mieszkanie getMieszkanie(int index)
    {
        int mieszkaniaSize = (sizeof(this->mieszkania)/sizeof(*this->mieszkania));
        if (index <= mieszkaniaSize && index > 0)
            return this->mieszkania[index-1];
        else
        {
            Mieszkanie mieszkanie;
            return mieszkanie;
        }
    }
};

int main()
{
    Mieszkanie mieszkanie1, mieszkanie2;
    Budynek budynek(5); // ma 10 mieszkan

    budynek.setNr(15);

    mieszkanie1.setBudynek(budynek.getNr());
    mieszkanie2.setBudynek(69);

    mieszkanie1.getBudynek(); // <-- 5
    mieszkanie2.getBudynek(); // <-- 69

    budynek.getMieszkanie(2);

    for (int i=0; i<10; i++)
    {
        budynek.addMieszkanie(mieszkanie1, i);
    }

    Mieszkanie mojeMieszkanie = budynek.getMieszkanie(1); // <-- obiekt Mieszkanie
    Mieszkanie twojeMieszkanie = budynek.getMieszkanie(11); // <-- null == blad

    if (twojeMieszkanie.getNr() != 0)
        cout << "TAK" << endl;
    else
        cout << "NIE" << endl;

    // wypisze NIE, poniewaz null == false

    return 0;
}
