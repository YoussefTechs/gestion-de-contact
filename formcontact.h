#ifndef FORMCONTACT_H
#define FORMCONTACT_H
#include "affichercontact.h"
#include "formmodifcontact.h"
#include "ajoutinteraction.h"
#include "basededonnee.h"
#include "interaction.h"
#include <QWidget>

namespace Ui {
class FormContact;
}

class FormContact : public QWidget
{
    Q_OBJECT

public:
    explicit FormContact(QWidget *parent = nullptr);
    ~FormContact();

signals:
    void AffichC(Contact *,list<Interaction *>,list<list<tache*>>);
    void supprimerC();
    void deleteC(Contact *);
     void sendEbdd(QString,QString,QString,QString,QString,QString);
     void sendCedit(Contact *);
     void envoyerInteractionEbdd(Interaction *);
     void envoyerTacheEbdd(list<tache*>);


private slots:

    void on_pushButtonGerer_clicked();

    void on_pushButtonAfficher_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonAjouteInter_clicked();
    void receiveContactf(Contact *,list<Interaction *>,list<list<tache*>>);
    void deleteeC();
public slots:
    void reciveE(QString,QString,QString,QString,QString,QString);
    void recInteractionE(Interaction *);
    void recTacheE(list<tache*> );
       void receiveFermer();
private:
    Ui::FormContact *ui;
    AfficherContact *afc;
    FormModifContact *fmc;
    AjoutInteraction *ai;
   // basededonnee  *bd;
    Contact *c;
    list<Interaction *> li;
    list<list<tache*>> llt;
    list<tache *> lt;


};

#endif // FORMCONTACT_H
