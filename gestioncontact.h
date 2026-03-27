#ifndef GESTIONCONTACT_H
#define GESTIONCONTACT_H
#include "contact.h"
#include<list>
#include<string>
using namespace std;
class GestionContact
{
private:
    list<Contact> listeContact;
public:
    GestionContact();
    // accesseurs
    list<Contact> getlisteContact() const;
    // fonction
    void ajoutContact(const Contact &);
    void retirerContact(const Contact &);
    void modifierContact(Contact & ,const string & ,const string & );
    void ajouterInteractionAuContact(Contact &, const Interaction &);
    void retirerInteractionDuContact(Contact &, const Interaction &); // Utiliser un identifiant ou un attribut unique pour l'interaction
    void ajouterTacheAInteraction(Contact &, const string &, const tache &); // Utiliser un identifiant ou un attribut unique pour l'interaction
    void retirerTacheDeInteraction(Contact &, const string &, const string &); // Identifiants pour l'interaction et la tâche
    void modifierContactIntereven(const Contact & , Interaction &,const string &);
    void modifierContactInterdate(const Contact &, Interaction &, const string &);
    void modifierContactTache(const Contact &, const Interaction & , tache &, const string &);
    string afficher();
    // fonction amie
    friend ostream & operator<<(ostream & ,const GestionContact &);
};

#endif // GESTIONCONTACT_H
