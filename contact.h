#ifndef CONTACT_H
#define CONTACT_H
#include<string>
#include "gestioninteraction.h" // Inclusion de GestionInteraction
#include "sdateAuto.h"
#include "date/date.h"
#include "date/chrono_io.h"

using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;

using namespace std;


class Contact
{
private:
    // atributs
    string nom;
    string prenom;
    string entreprise;
    string mail;
    string telephone;
    string photo;
    string dateC;
    string dateE;
    struct sdateAuto dateCreation;
    struct sdateAuto dateModi;
    GestionInteraction gestionInteractions;

public:
    //Constructeur
    Contact();
    Contact(const string &,const string &,const string &,const string &,const string &,const string &,const string &,const string &);
    // destructeur
    ~Contact();
    //accesseurs
    string getnom() const;
    string getprenom() const;
    string getentreprise() const;
    string getmail() const;
    string gettelephone() const;
    string getphoto() const;
    string getDateC() const;
    string getDateE() const;
    struct sdateAuto getDatecretion() const;
    struct sdateAuto getDatemodi()const;
    //list<Interaction> getlisteInter() const;
     const std::vector<Interaction>& getInteractions() const;
    //mutateurs
    void setnom(const string &);
    void setprenom(const string &);
    void setentreprise(const string &);
    void setmail(const string &);
    void settelephone(const string &);
    void setphoto(const string &);
    void setDateC(const string &);
    void setDateE(const string &);
    void setDatecreation();
    void setDatemodi();

    // fonction
    void ajouttache(const Interaction &,const tache &);
    void retirertache(const Interaction & ,const tache &);
    void ajouterInteraction(const Interaction &);
       void retirerInteraction(const string &); // Identifier l'interaction par un attribut unique
       Interaction* trouverInteraction(const string &);
       void modifierInteraction(const string &, const Interaction &);
    void modifierinteractiontachetex(const Interaction &,tache &,const string &);
    void modifierinteractiontachedate(const Interaction &,tache &,const string &);
    void modifierContact(const string & ,const string & );

    string ConvertDatec();
    string ConvertDatem();
    bool operator==(const Contact &) const;
    //fonction amie
    friend ostream & operator<<(ostream & ,const Contact &);

};

#endif // CONTACT_H
