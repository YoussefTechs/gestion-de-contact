#ifndef INTERACTION_H
#define INTERACTION_H

#include<string>
#include "gestiontache.h" // Inclure GestionTache
#include "date/date.h"
#include "date/chrono_io.h"
#include "sdateAuto.h"

using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
using namespace std;

class Interaction {
private:
    string texte;
    string dateI = "";
    struct sdateAuto dateInteraction;

    GestionTache gestionTaches; // Remplacer list<tache> par GestionTache

public:
    Interaction();
    Interaction(const string &, const string &);
    ~Interaction();

    string gettexte() const;
    struct sdateAuto getDateInteraction() const;
    string getdateI() const;
    GestionTache& getGestionTache();
    void settexte(const string &);
      void setdateI(const string &);
      void setDateInteraction();
    // Nouvelles méthodes pour gérer les tâches via GestionTache
    void ajoutertache(const tache &);
    void retirertache(const string &); // Utiliser un attribut distinctif (ex: evenement)
    tache* trouvertache(const string &);
    void modifiertache(const string &, const tache &);

    string toStringDI();
    bool operator==(const Interaction &) const;
    friend ostream & operator<<(ostream &, const Interaction &);
};

#endif // INTERACTION_H
