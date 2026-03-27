#include "gestioninteraction.h"

GestionInteraction::GestionInteraction() {
    // Initialisation si nécessaire
}

GestionInteraction::~GestionInteraction() {
    // Nettoyage si nécessaire
}

void GestionInteraction::ajouterInteraction(const Interaction& nouvelleInteraction) {
    listeInteractions.push_back(nouvelleInteraction);
}

void GestionInteraction::supprimerInteraction(const string& texte) {
    for (auto it = listeInteractions.begin(); it != listeInteractions.end(); ++it) {
        if (it->gettexte() == texte) {
            listeInteractions.erase(it);
            return;
        }
    }
}

Interaction* GestionInteraction::trouverInteraction(const string& texte) {
    for (auto& interaction : listeInteractions) {
        if (interaction.gettexte() == texte) {
            return &interaction;
        }
    }
    return nullptr;
}

void GestionInteraction::modifierInteraction(const string& texte, const Interaction& nouvelleInteraction) {
    for (auto& interaction : listeInteractions) {
        if (interaction.gettexte() == texte) {
            interaction = nouvelleInteraction;
            break;
        }
    }
}
const std::vector<Interaction>& GestionInteraction::getInteractions() const {
    return listeInteractions;
}
