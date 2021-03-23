#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;

class Id
{
private:
    int id;

public:
    Id()
    {
        this->id = 0;
    }

    int increment()
    {
        ++id;
        return id;
    }

    int getId()
    {
        return this->id;
    }
};

class Klient
{
private:
    string imie;
    string nazwisko;

public:
    int id;

public:
    Klient()
    {
        this->imie = "default";
        this->nazwisko = "default";
        this->id = 0;
    }

    Klient(string imie, string nazwisko)
    {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->id = 0;
    }

    void czytaj_dane()
    {
        string imie, nazwisko;

        cout << "Podaj swoje imie: ";
        cin >> imie;

        cout << "Podaj swoje nazwisko: ";
        cin >> nazwisko;

        this->imie = imie;
        this->nazwisko = nazwisko;
    }

    void wyswietl_wynik()
    {
        cout << "Imie: " << this->imie << endl;
        cout << "Nazwisko: " << this->nazwisko << endl;
        cout << "ID: " << to_string(this->id) << endl;
    }

    string getImie()
    {
        return this->imie;
    }

    string getNazwisko()
    {
        return this->nazwisko;
    }

    int getId()
    {
        return this->id;
    }

    void setId(int id)
    {
        this->id = id;
    }
};


class Usluga
{
private:
    string nazwa;
    int cena;

public:
    Usluga()
    {
        this->nazwa = "";
        this->cena = 0;
    }

    Usluga(string nazwa, int cena)
    {
        if (cena > 0)
        {
            this->nazwa = nazwa;
            this->cena = cena;
        }
    }

    void changeCena(int nowaCena)
    {
        if (nowaCena > 0)
            this->cena = nowaCena;
    }

    int getCena()
    {
        return this->cena;
    }

    string getNazwa()
    {
        return this->nazwa;
    }

    map<string, int> get()
    {
        map<string, int> usluga;
        usluga[this->nazwa] = this->cena;
        return usluga;
    }
};


class Klub
{
private:
    vector<Klient> klienci;
    Id id;

public:
    string nazwa;
    string opis;
    vector<Usluga> uslugi;

public:
    Klub()
    {
        this->nazwa = "default";
        this->opis = "default";
    }

    Klub(string nazwa)
    {
        this->nazwa = nazwa;
    }

    void czytaj_dane()
    {
        string opis;

        cout << "Podaj opis dla klubu " << this->nazwa << ":" << endl;
        getline(cin, opis);

        this->opis = opis;
    }

    void wyswietl_wynik()
    {
        cout << "\t\t" << this->nazwa << endl;
        cout << "\t" << this->opis << endl;
        cout << endl;

        cout << "Oto nasze uslugi:" << endl;
        for (auto& usluga : this->uslugi)
        {
            cout << "-" << usluga.getNazwa() << " cena: " << usluga.getCena() << endl;
        }

        cout << endl;
        cout << "Oto klienci klubu " << this->nazwa << ":" << endl;

        for (Klient klient : this->klienci)
        {
            cout << klient.getImie() << "  " << klient.getNazwisko() << " ID: " << to_string(klient.getId()) << endl;
        }
        cout << endl;
    }

    void dodajKlienta(Klient klient)
    {
        klient.setId(this->id.increment());
        this->klienci.push_back(klient);
    }

    void dodajUsluge(Usluga * usluga)
    {
        this->uslugi.push_back(*usluga);
    }
};


int main()
{
    Klient andrzej("Andrzej", "Jankowiak");
    Klient jan("Jan", "Kowalski");

    Klub klub1;
    Klub klub2("FitGym");

    klub1.czytaj_dane();
    klub2.czytaj_dane();

    klub1.dodajUsluge(new Usluga("aerobik", 40));
    klub1.dodajUsluge(new Usluga("basen", 25));

    klub2.dodajUsluge(new Usluga("trening", 20));
    klub2.dodajUsluge(new Usluga("trener", 50));
    klub2.dodajUsluge(new Usluga("masaz", 30));

    cout << "----------------------------------------------------------" << endl;

    klub1.dodajKlienta(andrzej);
    klub1.dodajKlienta(jan);

    klub2.dodajKlienta(jan);

    klub1.wyswietl_wynik();
    cout << "----------------------------------------------------------" << endl;
    klub2.wyswietl_wynik();


    return 0;
}
