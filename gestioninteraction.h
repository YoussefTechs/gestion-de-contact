#ifndef GESTIONINTERACTION_H
#define GESTIONINTERACTION_H

#include <vector>
#include "interaction.h"

class GestionInteraction {
private:
    std::vector<Interaction> listeInteractions;

public:
    GestionInteraction();
    ~GestionInteraction();
     const std::vector<Interaction>& getInteractions() const;
    void ajouterInteraction(const Interaction& nouvelleInteraction);
    void supprimerInteraction(const string& texte);
    Interaction* trouverInteraction(const string& texte);
    void modifierInteraction(const string& texte, const Interaction& nouvelleInteraction);
};

#endif // GESTIONINTERACTION_H
