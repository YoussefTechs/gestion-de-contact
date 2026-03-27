#include "tache.h"
#include<iostream>
using namespace std;
// constructeur
/**
 * @brief taches::taches le constructeur par défaut de la classe "tache".
 */
tache::tache()
{

}
/**
 * @brief taches::taches constructeur de la classe "taches" est utilisé pour créer une instance de la classe en spécifiant l'événement associé à la tâche et la date à laquelle cette tâche est planifiée.
 * @param [in] e Une chaîne de caractères (string) qui représente l'événement ou la description de la tâche.
 * @param [in] d Un objet de la classe "Date" qui représente la date à laquelle la tâche est planifiée.
 */
tache::tache(const string &e,const string &d)
{
    this->setevenement(e);
    this->setdateT(d);

}
// destructeur
/**
 * @brief taches::~taches le destructeur par défaut de la classe "tache".
 */
tache::~tache()
{

}
// accesseurs
/**
 * @brief taches::getevenement permet de récupérer la valeur de l'attribut "evenement" de l'objet "tache".La fonction est définie comme constante (const), ce qui signifie qu'elle ne modifie pas l'objet "tache" et peut être utilisée pour obtenir la valeur de l'événement ou de la description de la tâche sans la modifier.
 * @return une chaîne de caractères (string) qui représente l'événement ou la description de la tâche associée à cet objet "taches".
 */
string tache::getevenement() const
{
    return this->evenement;
}
/**
 * @brief taches::getdateT permet de récupérer l'objet "dateT", qui contient les informations sur la date, telles que le jour, le mois et l'année de la tâche. Cette fonction est utile pour obtenir la date de la tâche à partir de l'objet "taches" sans la modifier.
 * @return date de la tâche sous forme d'un objet "Date".
 */
string tache::getdateT()const
{
    return this->dateT;
}
// mutateurs
/**
 * @brief taches::setevenement permet de définir la valeur de l'attribut "evenement" de l'objet "taches" avec la valeur fournie en argument.
 * @param [in] e représente la nouvelle valeur de l'événement ou de la description que vous souhaitez attribuer à la tâche.
 */
void tache::setevenement(const string &e)
{
    this->evenement=e;
}
/**
 * @brief taches::setdateT permet de définir la date associée à la tâche en utilisant un objet de la classe "Date" passé en argument.
 * @param [in] d représente l'objet de la classe "Date" que vous souhaitez associer à la tâche en tant que nouvelle date de la tâche.
 */
void tache::setdateT( const string &d)
{
    this->dateT=d;
}
// fonction amie
/**
 * @brief operator << permet d'afficher une instance de la classe "taches" sous forme de chaîne de caractères formatée.
 * @param [in/out] os est un flux de sortie dans lequel nous souhaitons écrire les informations de l'objet "taches" "T".
 * @param [in] T est une référence constante à un objet de la classe "tache". Cet objet de la classe "tache" représente la tâche que nous souhaitons afficher à l'aide de cet opérateur de flux de sortie.
 * @return le flux de sortie "os" avec les informations de la tâche formatées comme vous l'avez défini dans la fonction.
 */
ostream & operator<<(ostream &os ,const tache &T)
{
    os<<"@todo "<<T.getevenement()<<" @date "<<T.getdateT();
    return os;
}
/**
 * @brief tache::operator == permet de comparer deux objets de cette classe pour déterminer s'ils sont égaux en fonction de certains critères.
 * @param [in] T représente une autre instance de la classe tache avec laquelle nous souhaitons comparer l'objet actuel pour déterminer s'ils sont égaux.
 * @return soit true soit false (faux), en fonction du résultat de la comparaison entre l'objet actuel de la classe tache pour lequel la fonction est appelée et l'objet T de la classe tache passé en paramètre.
 */
bool tache::operator==(const tache &T) const
{
    if(this->getevenement()==T.getevenement())
        if(this->getdateT()==T.getdateT())
            return true;
    return false;
}


