#include "gestiontache.h"

GestionTache::GestionTache() {
    // Initialisation si nécessaire
}

GestionTache::~GestionTache() {
    // Nettoyage si nécessaire
}

void GestionTache::ajoutertache(const tache& nouvelleTache) {
    listetaches.push_back(nouvelleTache);
}

void GestionTache::supprimertache(const string& evenement) {
    for (auto it = listetaches.begin(); it != listetaches.end(); ++it) {
        if (it->getevenement() == evenement) {
            listetaches.erase(it);
            return;
        }
    }
}

tache* GestionTache::trouvertache(const string& evenement) {
    for (auto& t : listetaches) {
        if (t.getevenement() == evenement) {
            return &t;
        }
    }
    return nullptr;
}

void GestionTache::modifiertache(const string& evenement, const tache& nouvelleTache) {
    for (auto& t : listetaches) {
        if (t.getevenement() == evenement) {
            t = nouvelleTache;
            break;
        }
    }
}
