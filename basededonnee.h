#ifndef BASEDEDONNEE_H
#define BASEDEDONNEE_H
#include <QtSql/QSqlDatabase>
#include <QObject>
#include<QtSql/QSqlDatabase>

#include"contact.h"


class basededonnee : public QObject
{
    Q_OBJECT

private:
    QSqlDatabase db;
    Contact *c;
    Contact *c1;
    Interaction *I;



  string nom="";
   string prenom="";
   string idC="";


public:
    explicit basededonnee(QObject *parent = nullptr);
    ~basededonnee();
    QList<QString> getContacts();
    QList<QString> searchContactsByNom(const QString &);
    QList<QString> searchContactsByEntreprise(const QString &);
    QList<QString> searchContactsByDate(const QString &);
    QList<QString> searchContactsByDateRange(const QString &, const QString &);
    void exporterJson(const QString &);


signals:
    void envoyerNBC(int);
    void envoyerContact(Contact *,list<Interaction *>,list<list<tache*>>);
    void baseDeDonneeModifiee();
    void modifnomprenom();

public slots:
    void ajoutContact(Contact *);//ajouter un nouveau contact dans la base de donne
    void trouverNb();
    void reception(string,string);
    void deleteCbd(Contact *);
    void reciveE(QString,QString,QString,QString,QString,QString);
    void recInteractionE(Interaction *);
    void recTacheE(list<tache*>);
    void regenererJson();
    //void recIDC(string,string);


};

#endif // BASEDEDONNEE_H

