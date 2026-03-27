#ifndef AFFICHERCONTACT_H
#define AFFICHERCONTACT_H
#include "contact.h"
//#include"afficherinteraction.h"

#include <QWidget>

namespace Ui {
class AfficherContact;
}

class AfficherContact : public QWidget
{
    Q_OBJECT

public:
    explicit AfficherContact(QWidget *parent = nullptr);
    ~AfficherContact();

private:
    Ui::AfficherContact *ui;
    Contact * nc;
    list<list<tache*>> listTaches;
    bool clickedDate=false;


    //afficherInteraction *ai;
public slots:
    void receiveContact(Contact *,list<Interaction *>,list<list<tache*>>);

private slots:
    void on_listWidget_itemDoubleClicked();
};

#endif // AFFICHERCONTACT_H
