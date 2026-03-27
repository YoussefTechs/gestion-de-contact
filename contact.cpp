#include<iostream>
#include "contact.h"
using namespace std;
/**
 * @brief Contact::Contact Ce constructeur initialise les attributs de la classe "Contact" avec la valeur "NULL" et la date à zéro
 */
Contact::Contact()
{
    string d="11/03/2002";
    this->setnom("NULL");
    this->setprenom("NULL");
    this->setentreprise("NULL");
    this->setmail("NULL");
    this->settelephone("NULL");
    this->setphoto("NULL");
    this->setDatemodi();
    this->setDatecreation();
    this->setDateE(ConvertDatem());
    this->setDateC(ConvertDatec());
}
/**
 * @brief Contact::Contact Ce constructeur de la classe "Contact" permet d'initialiser une instance avec des valeurs spécifiques pour chaque attribut
 * @param [in] n : représente le nom (ou la chaîne de caractères) du contact.
 * @param [in] p : représente le prénom (ou la chaîne de caractères) du contact
 * @param [in] e : représente le nom de l'entreprise (ou la chaîne de caractères) associée au contact
 * @param [in] m : représente l'adresse e-mail (ou la chaîne de caractères) du contact.
 * @param [in] t : représente le numéro de téléphone (ou la chaîne de caractères) du contact.
 * @param [in] ph : représente un lien ou une référence à la photo associée au contact
 * @param [in] d : représente une référence à un objet de la classe "Date" qui est utilisé pour spécifier la date de création du contact
 */
Contact::Contact(const string &n, const string &p,  const string &m,const string &e,const string &d,const string &dm,const string &ph,const string &t)
{
    this->setnom(n);
    this->setprenom(p);
    this->setentreprise(e);
    this->setmail(m);
    this->settelephone(t);
    this->setphoto(ph);
    this->setDateC(d);
    this->setDateE(dm);
}
/**
 * @brief Contact::~Contact un destructeur par défaut de la classe "Contact".
 */
Contact::~Contact()
{

}
// accesseurs
/**
 * @brief Contact::getnom renvoie la valeur de l'attribut "nom". Elle est définie comme une fonction constante, ce qui signifie qu'elle ne peut pas modifier les membres de la classe.
 * @return une chaîne de caractères (string) qui représente le nom associée au contact.
 */
string Contact::getnom() const
{
    return this->nom;
}
/**
 * @brief Contact::getprenom getnom renvoie la valeur de l'attribut "prenom". Elle est définie comme une fonction constante, ce qui signifie qu'elle ne peut pas modifier les membres de la classe.
 * @return une chaîne de caractères (string) qui représente le prenom associée au contact.
 */
string Contact::getprenom() const
{
    return this->prenom;
}
/**
 * @brief Contact::getentreprise renvoie la valeur de l'attribut "entreprise". Elle est définie comme une fonction constante, ce qui signifie qu'elle ne peut pas modifier les membres de la classe.
 * @return une chaîne de caractères (string) qui représente le nom de l'entreprise associée au contact.
 */
string Contact::getentreprise() const
{
    return this->entreprise;
}
/**
 * @brief Contact::getmail renvoie la valeur de l'attribut "mail". Elle est définie comme une fonction constante, ce qui signifie qu'elle ne peut pas modifier les membres de la classe.
 * @return une chaîne de caractères (string) qui représente le mail associée au contact.
 */
string Contact::getmail() const
{
    return this->mail;
}
/**
 * @brief Contact::gettelephone renvoie la valeur de l'attribut "telephone". Elle est définie comme une fonction constante, ce qui signifie qu'elle ne peut pas modifier les membres de la classe.
 * @return une chaîne de caractères (string) qui représente le telephone associée au contact.
 */
string Contact::gettelephone() const
{
    return this->telephone;
}
/**
 * @brief Contact::getphoto renvoie la valeur de l'attribut "photo". Elle est définie comme une fonction constante, ce qui signifie qu'elle ne peut pas modifier les membres de la classe.
 * @return une chaîne de caractères (string) qui représente un lien ou une référence à la photo associée au contact
 */
string Contact::getphoto() const
{
    return this->photo;
}
/**
 * @brief Contact::getdateC renvoie la valeur de l'attribut "dateC". Elle est définie comme une fonction constante, ce qui signifie qu'elle ne peut pas modifier les membres de la classe.
 * @return l'objet "dateC", qui contient les informations sur la date, telles que le jour, le mois et l'année de création
 */
string Contact::getDateC() const
{
    return this->dateC;
}
string Contact::getDateE() const
{
    return this->dateE;
}
const std::vector<Interaction>& Contact::getInteractions() const {
    return gestionInteractions.getInteractions();  // Assurez-vous que cette méthode existe dans GestionInteraction
}

// mutateurs
/**
 * @brief Contact::setnom permet de modifier le nom associé au contact
 * @param [in] n : représente le nom (ou la chaîne de caractères) du contact.
 */
void Contact::setnom(const string &n)
{
    this->nom=n;
}
/**
 * @brief Contact::setprenom permet de modifier le prénom associé au contact.
 * @param [in] p : représente le prénom (ou la chaîne de caractères) du contact
 */
void Contact::setprenom(const string &p)
{
    this->prenom=p;
}
/**
 * @brief Contact::setentreprise permet de modifier le nom de l'entreprise associée au contact.
 * @param [in] e : représente le nom de l'entreprise (ou la chaîne de caractères) associée au contact
 */
void Contact::setentreprise(const string &e)
{
    this->entreprise=e;
}
/**
 * @brief Contact::setmail permet de modifier l'adresse e-mail associée au contact.
 * @param [in] m : représente l'adresse e-mail (ou la chaîne de caractères) du contact.
 */
void Contact::setmail(const string &m)
{
    this->mail=m;
}
/**
 * @brief Contact::settelephone permet de modifier le numéro de téléphone associé au contact.
 * @param [in] t : représente le numéro de téléphone (ou la chaîne de caractères) du contact.
 */
void Contact::settelephone(const string &t)
{
    this->telephone=t;
}
/**
 * @brief Contact::setphoto  permet de modifier la référence ou le lien vers la photo associée au contact.
 * @param [in] ph : représente un lien ou une référence à la photo associée au contact
 */
void Contact::setphoto(const string &ph)
{
    this->photo=ph;
}
/**
 * @brief Contact::setdateC Elle permet de modifier la date de création associée au contact en remplaçant l'objet "Date" existant par le nouvel objet "Date".
 * @param [in] d : représente une référence à un objet de la classe "Date" qui est utilisé pour spécifier la date de création du contact
 */
void Contact::setDateC(const string &date)
{
    this->dateC=date;
}
void Contact::setDateE(const string &d)
{
    this->dateE=d;
}
void Contact::setDatecreation()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this ->dateCreation.jour = ymd.day();
    this -> dateCreation.mois = ymd.month();
    this -> dateCreation.annee = ymd.year();
}
void Contact::setDatemodi()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this ->dateModi.jour = ymd.day();
    this -> dateModi.mois = ymd.month();
    this -> dateModi.annee = ymd.year();
}
// fonction
/**
 * @brief Contact::ajoutinteraction permet d'ajouter un objet de la classe "Interactions" à la liste (ou conteneur) d'interactions de l'objet "Contact".
 * @param [in ] I Il s'agit d'une référence constante à un objet de la classe "Interactions" qui est fournie en tant qu'entrée à la fonction.
 */
void Contact::ajouterInteraction(const Interaction &interaction) {
    gestionInteractions.ajouterInteraction(interaction);
}
void Contact::ajouttache(const Interaction &inter, const tache &t) {
    Interaction* interactionTrouvee = gestionInteractions.trouverInteraction(inter.gettexte());
    if (interactionTrouvee) {
        interactionTrouvee->getGestionTache().ajoutertache(t);
    }
}
/**
 * @brief Contact::retirerinteraction permet de retirer une instance d'interaction (représentée par l'objet I) de la liste des interactions stockées dans cet objet.
 * @param [in] I une référence constante vers un objet de la classe Interaction que nous souhaitons retirer de la liste d'interactions
 */
void Contact::retirerInteraction(const string &identifiant) {
    gestionInteractions.supprimerInteraction(identifiant);
}
/**
 * @brief Contact::retirertache permet de retirer une tâche "T" d'une interaction spécifique "I" dans une liste d'interactions.
 * @param [in] I représente une référence constante à un objet de la classe Interaction. Il s'agit de l'interaction spécifique à partir de laquelle nous souhaitons retirer une tâche.
 * @param [in] T représente une référence constante à un objet de la classe tache. Il s'agit de la tâche que nous souhaitons retirer de l'interaction spécifiée par I.
 */
void Contact::retirertache(const Interaction &inter, const tache &t) {
    Interaction* interactionTrouvee = gestionInteractions.trouverInteraction(inter.gettexte());
    if (interactionTrouvee) {
        interactionTrouvee->getGestionTache().supprimertache(t.getevenement()); // Remplacez getevenement par la méthode appropriée
    }
}

string Contact::ConvertDatec()
{
     return to_string(this->dateCreation.jour.operator unsigned int())+"/"+to_string(this->dateCreation.mois.operator unsigned int())+"/"+to_string(this->dateCreation.annee.operator int());
}
string Contact::ConvertDatem()
{
     return to_string(this->dateModi.jour.operator unsigned int())+"/"+to_string(this->dateModi.mois.operator unsigned int())+"/"+to_string(this->dateModi.annee.operator int());
}
/**
 * @brief Contact::operator == Cette fonction surchargée de l'opérateur "==" (égal) pour la classe "Contact" compare deux objets "Contact" pour déterminer s'ils sont égaux.
 * @param [in] c représente un autre objet de la classe "Contact" avec lequel l'objet actuel est comparé pour déterminer s'ils sont égaux.
 * @return
 */
bool Contact::operator==(const Contact &c) const
{
    if(this->getnom() == c.getnom())
        if(this->getprenom() == c.getprenom())
            if(this->getentreprise() == c.getentreprise())
                if(this->getmail() == c.getmail())
                    if(this->getphoto() == c.getphoto())
                        if(this->gettelephone() == c.gettelephone())
                            if (this->getDateC() == c.getDateC())
                                return true;
    return false;
}
// fonction amie
/**
 * @brief operator << Ceci est un opérateur de flux de sortie (<<) surchargé pour la classe "Contact". Il permet d'afficher les informations d'un objet "Contact" dans un flux de sortie.
 * @param [in/out] os variable de type "ostream" (flux de sortie) et est utilisée pour diriger la sortie des informations vers une destination, telle que la console ou un fichier.
 * @param [in] C une référence constante à un objet de la classe "Contact" qui représente le contact dont les informations doivent être affichées.
 * @return le flux de sortie après avoir écrit les informations du contact et de ses interactions.
 */
ostream & operator<<(ostream &os, const Contact &C) {
    os << C.getnom() << " " << C.getprenom() << "\n"
       << C.getentreprise() << "\n"
       << C.getmail() << "\n"
       << C.gettelephone() << "\n"
       << C.getphoto() << "\n"
       << C.getDateC() << "\n";

    int i = 1;
    const std::vector<Interaction>& interactions = C.getInteractions();
    for (const auto& it : interactions) {
        os << "Interactions N°" << i << ": " << it << "\n";
        ++i;
    }

    return os;
}

/**
 * @brief Contact::modifierContact permet de modifier certains attributs d'un objet "Contact" en fonction du type de modification spécifié par les paramètres "modif" et "nvmodif".
 * @param [in] modif Une chaîne de caractères (string) qui spécifie le type de modification à effectuer.
 * @param [in] nvmodif Une chaîne de caractères (string) qui spécifie la nouvelle valeur que vous souhaitez attribuer à l'attribut spécifié par "modif".
 */
void Contact::modifierContact(const string & modif ,const string & nvmodif )
{
    if(modif=="entreprise")
    {
       this->setentreprise(nvmodif);
    }
    if(modif=="mail")
    {
        this->setmail(nvmodif);
    }
    if(modif=="telephone")
    {
        this->settelephone(nvmodif);
    }
    if(modif=="photo")
    {
        this->setphoto(nvmodif);
    }
}
/**
 * @brief Contact::modifierinteractioneven permet de modifier le texte d'une interaction spécifique "I" dans une liste d'interactions en lui attribuant une nouvelle valeur
 * @param [i] I une référence à un objet de la classe Interaction
 * @param [in] nvmodif représente la nouvelle valeur ou le nouveau texte que nous souhaitons attribuer à une instance de la classe Interaction.
 */
void Contact::modifierInteraction(const string &identifiant, const Interaction &nouvelleInteraction) {
    gestionInteractions.modifierInteraction(identifiant, nouvelleInteraction);
}
/**
 * @brief Contact::modifierinteractiontachetex permet de modifier le texte d'une tâche spécifique "T" à l'intérieur d'une interaction spécifique "I" dans une liste d'interactions.
 * @param [in] I représente une référence constante à un objet de la classe Interaction. Il s'agit de l'interaction spécifique dans laquelle nous souhaitons modifier le texte d'une tâche.
 * @param [in] T représente une référence à un objet de la classe tache. Il s'agit de la tâche que nous souhaitons modifier à l'intérieur de l'interaction spécifiée par I.
 * @param [in] nvmodif représente une référence constante à une chaîne de caractères. Il s'agit du nouveau texte que nous souhaitons attribuer à la tâche T à l'intérieur de l'interaction I.
 */
void Contact::modifierinteractiontachetex(const Interaction &inter, tache &t, const string &nouveauTexte) {
    Interaction* interactionTrouvee = gestionInteractions.trouverInteraction(inter.gettexte());
    if (interactionTrouvee) {
        tache* tacheAModifier = interactionTrouvee->getGestionTache().trouvertache(t.getevenement());
        if (tacheAModifier) {
            interactionTrouvee->getGestionTache().modifiertache(t.getevenement(), tache(nouveauTexte, tacheAModifier->getdateT())); // Assurez-vous que les méthodes sont correctes
        }
    }
}
/**
 * @brief Contact::modifierinteractiontachedate permet de modifier la date d'une tâche spécifique "T" à l'intérieur d'une interaction spécifique "I" dans une liste d'interactions
 * @param [in] I représente une référence constante à un objet de la classe Interaction. Il s'agit de l'interaction spécifique dans laquelle nous souhaitons modifier la date d'une tâche.
 * @param [in] T représente une référence à un objet de la classe tache. Il s'agit de la tâche à l'intérieur de cette interaction que nous souhaitons modifier en termes de date.
 * @param [in] d représente une référence constante à un objet de la classe Date. Il s'agit de la nouvelle date que nous souhaitons attribuer à la tâche T à l'intérieur de l'interaction I.
 */
void Contact::modifierinteractiontachedate(const Interaction &inter, tache &t, const string &nouvelleDate) {
    Interaction* interactionTrouvee = gestionInteractions.trouverInteraction(inter.gettexte());
    if (interactionTrouvee) {
        tache* tacheAModifier = interactionTrouvee->getGestionTache().trouvertache(t.getevenement());
        if (tacheAModifier) {
            interactionTrouvee->getGestionTache().modifiertache(t.getevenement(), tache(tacheAModifier->getevenement(), nouvelleDate));
        }
    }
}
Interaction* Contact::trouverInteraction(const string &identifiant) {
    return gestionInteractions.trouverInteraction(identifiant);
}
