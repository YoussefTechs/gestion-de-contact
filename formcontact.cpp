#include "formcontact.h"
#include "ui_formcontact.h"
#include <QMessageBox>

FormContact::FormContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormContact)
{
    ui->setupUi(this);
    //bd = new basededonnee();//instanciation de la classe basedonnee qui permet d'ouvrir la base de donnée

}

FormContact::~FormContact()
{
    delete ui;
}


void FormContact::on_pushButtonGerer_clicked()
{
    ui->pushButtonModifier->setEnabled(true);
    ui->pushButtonSupprimer->setEnabled(true);
    ui->pushButtonAjouteInter->setEnabled(true);



    connect(this,SIGNAL(supprimerC()),this,SLOT(deleteeC()));

}

void FormContact::receiveContactf(Contact *c,list<Interaction *>li,list<list<tache*>>llt)
{
    this->c=c;
    this->li=li;
    this->llt=llt;
}
void FormContact::on_pushButtonAfficher_clicked()
{
    afc=new AfficherContact();
    afc->show();
    connect(this, SIGNAL(AffichC(Contact *,list<Interaction *>,list<list<tache*>>)),afc, SLOT(receiveContact(Contact *,list<Interaction *>,list<list<tache*>>)));
    emit AffichC(c,li,llt);

}

void FormContact::deleteeC()
{
    emit deleteC(c);
    this->close();
}


void FormContact::on_pushButtonSupprimer_clicked()
{
    QMessageBox::StandardButton reply=QMessageBox::question(this,"Supprimer Contact ","Voulez-vous vraiment supprimer ce contact définitivement ?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
       // connect(ec,SIGNAL(suppriC()),this,SLOT(deleteeC()));

        emit supprimerC();
        this->close();
    }

}


void FormContact::on_pushButtonModifier_clicked()
{
    fmc=new FormModifContact();
    fmc->show();

    connect(this,SIGNAL(sendCedit(Contact *)),fmc,SLOT(affichCm(Contact *)));//envoie du contact a editContact
    connect(fmc,SIGNAL(sendE(QString,QString,QString,QString,QString,QString)),this,SLOT(reciveE(QString,QString,QString,QString,QString,QString)));

    emit sendCedit(c);



}

void FormContact::reciveE(QString nom,QString prenom,QString entreprise,QString email,QString telephone,QString photo)
{
    emit sendEbdd(nom,prenom,entreprise,email,telephone,photo);
}


void FormContact::on_pushButtonAjouteInter_clicked()
{
    ai=new AjoutInteraction();
    ai->show();
    connect(ai, SIGNAL(envoyerInteractionE(Interaction *)), this, SLOT(recInteractionE(Interaction *)));
    connect(ai, SIGNAL(envoyerTacheE(list<tache*>)), this, SLOT(recTacheE(list<tache*>)));

    connect(ai,SIGNAL(fermerparent()),this,SLOT(receiveFermer()));
}
void FormContact::receiveFermer()
{
    this->close();
}

void FormContact::recInteractionE(Interaction * i)
{
    emit envoyerInteractionEbdd(i);
}

void FormContact::recTacheE(list<tache*> tt)
{
    this->lt=tt;
    emit envoyerTacheEbdd(lt);
}
