#include "gestioncontact.h"
#include<QString>
/**
 * @brief GestionContact::GestionContact le constructeur par défaut de la classe "GestionContact".
 */
GestionContact::GestionContact()
{

}
/**
 * @brief GestionContact::getlisteContact Cette fonction est utile pour obtenir la liste complète de contacts à partir de l'objet "GestionContact" sans la modifier.
 * @return la liste de contact telle qu'elle est actuellement stockée dans l'objet.
 */
list<Contact> GestionContact::getlisteContact() const
{
    return this->listeContact;
}
// fonction
/**
 * @brief GestionContact::ajoutContact permet d'ajouter un nouvel objet de la classe "Contact" à la liste de contacts de l'objet "GestionContact".
 * @param [in] C représente le contact que vous souhaitez ajouter à la liste de contacts de l'objet "GestionContact".
 */
void GestionContact::ajoutContact(const Contact &C)
{
    this->listeContact.push_back(C);
}
/**
 * @brief GestionContact::retirerContact permet de retirer un contact spécifique de la liste de contacts de l'objet "GestionContact".
 * @param C Il représente le contact que vous souhaitez retirer de la liste de contacts de l'objet "GestionContact".
 */
void GestionContact::retirerContact(const Contact &C)
{
    for (auto it = listeContact.begin(); it != listeContact.end(); )
    if ( *it==C )
    {
    it = listeContact.erase(it);
    }
    else
    ++it;
}
/**
 * @brief GestionContact::modifierContact permet de modifier un contact spécifique dans la liste de contacts de l'objet "GestionContact".
 * @param [in] C Un objet de la classe "Contact" qui représente le contact que vous souhaitez modifier.
 * @param [in] modif Une chaîne de caractères (string) qui spécifie ce que vous souhaitez modifier dans le contact (par exemple, "entreprise", "mail", "telephone", etc.).
 * @param [in] nvmodif Une chaîne de caractères (string) qui contient la nouvelle valeur que vous souhaitez attribuer à l'élément que vous modifiez.
 */
void GestionContact::modifierContact(Contact &C,const string &modif,const string &nvmodif)
{
    for (auto it =this->listeContact.begin(); it !=this->listeContact.end(); )
    {

    if ( *it==C )
    {
        it->modifierContact(modif,nvmodif);
        C=*it;
    }
    ++it;
    }
}
/**
 * @brief GestionContact::modifierContactIntereven permet de modifier un événement d'une interaction spécifique (I) à l'intérieur d'un contact spécifique (C) dans une liste de contacts.
 * @param [in] C représente une référence constante à un objet de la classe Contact. Il s'agit du contact spécifique que nous souhaitons modifier.
 * @param [in] I représente une référence à un objet de la classe Interaction. Il s'agit de l'interaction à l'intérieur du contact C que nous souhaitons modifier en termes d'événement.
 * @param [in] nvmodif représente une référence constante à une chaîne de caractères (std::string). Il s'agit de la nouvelle valeur (ou texte de l'événement) que nous souhaitons attribuer à l'événement de l'interaction I dans le contact C.
 */
void GestionContact::modifierContactIntereven(const Contact &contact, Interaction &inter, const string &nouvelEvenement) {
    for (auto &c : listeContact) {
        if (c == contact) {
            // Supposons que le texte de l'interaction est utilisé pour l'identifier
            Interaction* interaction = c.trouverInteraction(inter.gettexte());
            if (interaction) {
                interaction->settexte(nouvelEvenement);
                break;
            }
        }
    }
}
/**
 * @brief GestionContact::modifierContactInterdate permet de modifier la date d'une interaction spécifique (I) à l'intérieur d'un contact spécifique (C) dans une liste de contacts.
 * @param [in] C représente une référence constante à un objet de la classe Contact. Il s'agit du contact spécifique que nous souhaitons modifier.
 * @param [in] I représente une référence à un objet de la classe Interaction. Il s'agit de l'interaction au sein du contact C que nous souhaitons modifier en termes de date.
 * @param [in] d représente une référence constante à un objet de la classe Date. Il s'agit de la nouvelle date que nous souhaitons attribuer à l'interaction I dans le contact C.
 */
void GestionContact::modifierContactInterdate(const Contact &contact, Interaction &inter, const string &nouvelleDate) {
    for (auto &c : listeContact) {
        if (c == contact) {
            // Utilisation du texte pour identifier l'interaction
            Interaction* interaction = c.trouverInteraction(inter.gettexte());
            if (interaction) {
                interaction->setdateI(nouvelleDate);
                break;
            }
        }
    }
}
/**
 * @brief GestionContact::modifierContactTachetex permet de modifier le texte d'une tâche spécifique (T) à l'intérieur d'une interaction spécifique (I) dans un contact spécifique (C) dans une liste de contacts.
 * @param [in] C représente une référence constante à un objet de la classe Contact. Il s'agit du contact spécifique dans lequel nous souhaitons effectuer la modification.
 * @param [in] I représente une référence constante à un objet de la classe Interaction. Il s'agit de l'interaction spécifique au sein du contact C dans laquelle nous souhaitons effectuer la modification.
 * @param [in] T représente une référence à un objet de la classe tache. Il s'agit de la tâche spécifique que nous souhaitons modifier en termes de texte.
 * @param [in] nvmodif représente une référence constante à une chaîne de caractères (std::string). Il s'agit de la nouvelle valeur (ou texte de la tâche) que nous souhaitons attribuer à la tâche T dans l'interaction I.
 */
void GestionContact::modifierContactTache(const Contact &contact, const Interaction &inter, tache &t, const string &nouvelAttribut) {
    for (auto &c : listeContact) {
        if (c == contact) {
            // Utilisation du texte pour identifier l'interaction
            Interaction* interaction = c.trouverInteraction(inter.gettexte());
            if (interaction) {
                // Supposons que l'événement de la tâche est utilisé pour l'identifier
                tache* tacheAModifier = interaction->getGestionTache().trouvertache(t.getevenement());
                if (tacheAModifier) {
                    // Supposons que nouvelAttribut est un nouvel événement pour la tâche
                    tacheAModifier->setevenement(nouvelAttribut);
                    break;
                }
            }
        }
    }
}
/**
 * @brief operator << permet d'afficher les informations de tous les contacts contenus dans l'objet "GestionContact"
 * @param [in] os représente le flux de sortie où vous souhaitez afficher les informations des contacts.
 * @param [in] Gc une référence constante à l'objet de la classe "GestionContact" que vous souhaitez afficher.
 * @return le flux de sortie "os" après avoir écrit les informations de tous les contacts contenus dans l'objet "GestionContact" "Gc".
 */
ostream & operator<<(ostream &os ,const GestionContact &Gc)
{
        int i=1;
        for (auto it = Gc.listeContact.begin(); it != Gc.listeContact.end(); )
        {
            cout<<"Contact N°"<<i<<endl;
            os<<*it;
            ++it;
            ++i;
        }
        return os;
}
/**
 * @brief GestionContact::afficher représentant des informations de contact. Le code parcourt une liste de contacts ( listeContact) et génère une chaîne de caractères contenant les.cette fonction est utilisée dans l'interface graphique
 * @return une chaine de caractère qui contient les informations.
 */
string GestionContact::afficher()
{
    string s;
    QString p ;
     for (auto it = listeContact.begin(); it != listeContact.end(); )
     {
         s=s+it->getnom()+" "+it->getprenom() +" "+it->getentreprise()+" "+it->getmail()+" "+it->getphoto()+" "+it->gettelephone()+" "+ it->getDateC();

         ++it;
     }
     return s;
}
void GestionContact::ajouterInteractionAuContact(Contact &contact, const Interaction &interaction) {
    for (auto &c : listeContact) {
        if (c == contact) {  // Assurez-vous que l'opérateur == est bien défini pour Contact
            c.ajouterInteraction(interaction);
            break;
        }
    }
}

void GestionContact::retirerInteractionDuContact(Contact &contact, const Interaction &inter) {
    for (auto &c : listeContact) {
        if (c == contact) {
            // Utilisez le texte (ou tout autre attribut distinctif) de l'interaction pour l'identifier
            const string &identifiantInteraction = inter.gettexte();
            c.retirerInteraction(identifiantInteraction);
            break;
        }
    }
}


void GestionContact::ajouterTacheAInteraction(Contact &contact, const string &identifiantInteraction, const tache &t) {
    for (auto &c : listeContact) {
        if (c == contact) {
            Interaction* interaction = c.trouverInteraction(identifiantInteraction);
            if (interaction) {
                interaction->ajoutertache(t);
                break;
            }
        }
    }
}

void GestionContact::retirerTacheDeInteraction(Contact &contact, const string &identifiantInteraction, const string &identifiantTache) {
    for (auto &c : listeContact) {
        if (c == contact) {
            Interaction* interaction = c.trouverInteraction(identifiantInteraction);
            if (interaction) {
                interaction->retirertache(identifiantTache);
                break;
            }
        }
    }
}
