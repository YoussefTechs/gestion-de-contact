#ifndef GESTIONTACHE_H
#define GESTIONTACHE_H

#include <list>
#include "tache.h"

class GestionTache {
private:
    std::list<tache> listetaches;

public:
    GestionTache();
    ~GestionTache();

    void ajoutertache(const tache& nouvelleTache);
    void supprimertache(const string& evenement);
    tache* trouvertache(const string& evenement);
    void modifiertache(const string& evenement, const tache& nouvelleTache);
};

#endif // GESTIONTACHE_H
