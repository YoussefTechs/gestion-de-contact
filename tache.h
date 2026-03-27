#ifndef TACHE_H
#define TACHE_H
#include<string>
//#include "date1.h"
using namespace std ;
class tache
{
private:
    string evenement;
    string dateT;
public:
    //constructeur
    tache();
    tache(const string &,const string &);
    //destructeur
    ~tache();
    //accesseurs
    string getevenement() const;
    string getdateT()const;
    //mutateurs
    void setevenement(const string &);
    void setdateT(const string &);
    //fonction
    bool operator==(const tache &) const;
    //fonction amie
    friend ostream & operator<<(ostream & ,const tache &);
};

#endif // TACHE_H
