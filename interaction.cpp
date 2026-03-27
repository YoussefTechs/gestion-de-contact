#include "interaction.h"
#include<iostream>
using namespace std;
// constructeur
/**
 * @brief Interactions::Interactions constructeur par défaut de la classe "Interaction".
 */
Interaction::Interaction() {
    setDateInteraction();
    settexte("null");
    setdateI(toStringDI());
}
/**
 * @brief Interactions::Interactions constructeur de la classe "Interaction" est utilisé pour créer une instance de la classe en spécifiant le texte de l'interaction et la date associée.
 * @param [in] t Une chaîne de caractères (string) qui représente le texte ou la description de l'interaction.
 * @param [in] d Un objet de la classe "Date" qui représente la date limite de l'interaction.
 */
Interaction::Interaction(const string &t, const string &d) {
    setDateInteraction();
    settexte(t);
    setdateI(d);
}
// destructeur
/**
 * @brief Interactions::~Interactions le destructeur par défaut de la classe "Interaction".
 */
Interaction::~Interaction()
{

}
// accesseurs
/**
 * @brief Interactions::gettexte fonction membre qui permet de récupérer la valeur de l'attribut "texte" de l'objet "Interaction". La fonction est définie comme constante (const), ce qui signifie qu'elle ne modifie pas l'objet "Interaction" et peut être utilisée pour obtenir la valeur du texte de l'interaction sans le modifier.
 * @return une chaîne de caractères (string) qui représente le texte ou la description de l'interaction
 */
string Interaction::gettexte() const
{
    return this->texte;
}
/**
 * @brief Interactions::getdateI fonction membre qui permet de récupérer la valeur de l'attribut "dateI" de l'objet "Interaction". La fonction est définie comme constante (const), ce qui signifie qu'elle ne modifie pas l'objet "Interaction" et peut être utilisée pour obtenir la date limite de l'interaction sans la modifier.
 * @return  l'objet "dateI", qui contient les informations sur la date, telles que le jour, le mois et l'année de l'interaction
 */
string Interaction::getdateI() const
{
    return this->dateI;
}

struct sdateAuto Interaction::getDateInteraction() const
{
    return this -> dateInteraction;
}
GestionTache& Interaction::getGestionTache() {
    return gestionTaches;
}
// mutateurs
/**
 * @brief Interactions::settexte permet de modifier le texte ou la description associée à l'interaction en remplaçant la valeur actuelle de l'attribut "texte" par la nouvelle valeur "t".
 * @param [in] t représente le texte ou la description que vous souhaitez attribuer à l'interaction.
 */
void Interaction::settexte(const string &t) {
    this->texte = t;
}

/**
 * @brief Interactions::setdateI permet de mettre à jour la date de l'interaction en remplaçant l'objet "Date" existant par le nouvel objet "Date" "d".
 * @param [in] d représente l'objet de la classe "Date" que vous souhaitez associer à l'interaction.
 */
void Interaction::setdateI(const string &d)
{
    this->dateI=d;
}

void Interaction::setDateInteraction()
{
    day_point dp = floor<days>(system_clock::now());
    auto ymd = year_month_day{dp};
    this -> dateInteraction.jour = ymd.day();
    this -> dateInteraction.mois = ymd.month();
    this -> dateInteraction.annee = ymd.year();
}
// fonction
/**
 * @brief Interactions::ajouttacheinter permet d'ajouter un objet de la classe "taches" à la liste d'objets "tache" associés à l'interaction de la classe "Interaction".
 * @param [in] T représente la tache a ajoutée.
 */
void Interaction::ajoutertache(const tache &T) {
    gestionTaches.ajoutertache(T);
}
/**
 * @brief Interaction::retirertache permet de retirer une tâche spécifique "T" de la liste de tâches (listetache) de l'objet Interaction.
 * @param [in] T représente la tache a supprimer.
 */
void Interaction::retirertache(const string &evenement) {
    gestionTaches.supprimertache(evenement);
}
/**
 * @brief operator << permet d'afficher les informations d'un objet "Interactions" ainsi que les informations des tâches associées à cette interaction.
 * @param [in/out] os représente un flux de sortie
 * @param [in] I représente l'objet que nous souhaitons afficher à l'aide de cet opérateur de flux de sortie
 * @return le flux de sortie après avoir écrit les informations d'interaction et de ses taches.
 */
ostream &operator<<(ostream &os, const Interaction &I) {
    os << I.gettexte() << "\t" << I.getdateI();
    // Vous pouvez également ajouter l'impression des tâches si nécessaire
    return os;
}
/**
 * @brief Interaction::operator == permet de comparer deux objets de cette classe pour déterminer s'ils sont égaux en fonction de certains critères.
 * @param [in] I représente un autre objet de la classe Interaction avec lequel vous souhaitez comparer l'objet actuel pour déterminer s'ils sont égaux.
 * @return soit true soit false, en fonction du résultat de la comparaison entre l'objet actuel pour lequel la fonction est appelée et l'objet I passé en paramètre.
 */
bool Interaction::operator==(const Interaction &I) const {
    return (texte == I.texte) && (dateI == I.dateI);
}
/**
 * @brief Interaction::modifiertache permet de modifier une tâche spécifique (T) en changeant l'événement associé à cette tâche par une nouvelle valeur
 * @param [in] T représente une référence à un objet de la classe tache. Il s'agit de la tâche spécifique que nous souhaitons modifier en termes d'événement (ou texte de l'événement).
 * @param [in] nvmodif représente une référence constante à une chaîne de caractères . Il s'agit de la nouvelle valeur (ou texte) que nous souhaitons attribuer à l'événement de la tâche T
 */
void Interaction::modifiertache(const string &evenement, const tache &nouvelleTache) {
    gestionTaches.modifiertache(evenement, nouvelleTache);
}
string Interaction::toStringDI()
{
    return to_string(this->dateInteraction.jour.operator unsigned int())+"/"+to_string(this->dateInteraction.mois.operator unsigned int())+"/"+to_string(this->dateInteraction.annee.operator int());
}
tache* Interaction::trouvertache(const string &evenement) {
    return gestionTaches.trouvertache(evenement);
}
