#include <iostream>
#include <string>
#include <vector>
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

class Klub
{
private:
    vector<Klient> klienci;
    Id id;

public:
    string nazwa;
    string opis;

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
};


int main()
{
    Klient andrzej("Andrzej", "Jankowiak");
    Klient jan("Jan", "Kowalski");

    Klub klub1;
    Klub klub2("FitGym");

    klub1.czytaj_dane();
    klub2.czytaj_dane();

    cout << "----------------------------------------------------------" << endl;

    klub1.dodajKlienta(andrzej);
    klub1.dodajKlienta(jan);

    klub2.dodajKlienta(jan);

    klub1.wyswietl_wynik();
    cout << "----------------------------------------------------------" << endl;
    klub2.wyswietl_wynik();


    return 0;
}
