#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "ui_contactform.h"
#include <QMessageBox>
#include"QSqlQuery"
#include"basededonnee.h"
#include <QDebug>
#include "QSqlError"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bd =new basededonnee();
    remplirListWidget();
    int count = ui->listWidget->count();
     ui->NBRapreRech->setText(QString::number(count));
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::remplirListWidget()
{
    connect(this,SIGNAL(cherchNBC()),bd,SLOT(trouverNb()));
    connect(bd,SIGNAL(envoyerNBC(int)),this,SLOT(affichNb(int)));

    QList<QString> contacts = bd->getContacts();
    for (const QString& contact : contacts)
        {
            ui->listWidget->addItem(contact);
        }
    emit cherchNBC();
}

void MainWindow::affichNb(int total)//nb de contact
{
    ui->label_NBC->clear();
    ui->label_NBC->setText(QString::number(total));
}
void MainWindow::modifierListC()
{
    connect(this,SIGNAL(cherchNBC()),bd,SLOT(trouverNb()));
    connect(bd,SIGNAL(envoyerNBC(int)),this,SLOT(affichNb(int)));
    ui->listWidget->clear();
    remplirListWidget();
    int count = ui->listWidget->count();
    ui->NBRapreRech->setText(QString::number(count));
    emit cherchNBC();
}

void MainWindow::on_actionQuitter_triggered()
{
    QApplication::quit();
}



void MainWindow::on_radioButtonNom_clicked()
{
    ui->dateEdit->setEnabled(false);
    ui->lineEditNomEntr->setEnabled(true);
    clickedNom=true;
    clickedEntr=false;
    clickedDate=false;
    clicked2Date=false;


}


void MainWindow::on_radioButtonEntr_clicked()
{
    ui->dateEdit->setEnabled(false);
    ui->dateEditdebut->setEnabled(false);
    ui->dateEditfin->setEnabled(false);

    ui->lineEditNomEntr->setEnabled(true);
    clickedEntr=true;
    clickedNom=false;
    clickedDate=false;
    clicked2Date=false;


}


void MainWindow::on_radioButtonDate_clicked()
{
     ui->lineEditNomEntr->setEnabled(false);
     ui->dateEditdebut->setEnabled(false);
     ui->dateEditfin->setEnabled(false);

     ui->dateEdit->setEnabled(true);
     clickedDate=true;
     clickedEntr=false;
     clickedNom=false;
     clicked2Date=false;
}


void MainWindow::on_radioButton2Dates_clicked()
{
    ui->lineEditNomEntr->setEnabled(false);
    ui->dateEdit->setEnabled(false);
    ui->dateEditdebut->setEnabled(true);
    ui->dateEditfin->setEnabled(true);
    clicked2Date=true;
    clickedDate=false;
    clickedEntr=false;
    clickedNom=false;

}




void MainWindow::on_actionAjouter_contact_triggered()
{
    aj=new AjoutContact();
    aj->show();
    connect(aj,SIGNAL(enregistrerContact(Contact *)),bd,SLOT(ajoutContact(Contact*)));
    connect(aj,SIGNAL(majList()),this,SLOT(modifierListC()));//update de la liste

}


void MainWindow::on_listWidget_doubleClicked()
{
    fc=new FormContact();
    fc->show();
    connect(bd,SIGNAL(modifnomprenom()),this,SLOT(modifierListC()));

    //selection
    connect(this, SIGNAL(select(string,string)), bd, SLOT(reception(string,string)));
    //affichage
    connect(bd, SIGNAL(envoyerContact(Contact *,list<Interaction *>,list<list<tache*>>)),fc, SLOT(receiveContactf(Contact *,list<Interaction *>,list<list<tache*>>)));
    //modification
    connect(fc,SIGNAL(sendEbdd(QString,QString,QString,QString,QString,QString)),bd,SLOT(reciveE(QString,QString,QString,QString,QString,QString)));


    //suppression
    connect(fc,SIGNAL(deleteC(Contact *)),bd,SLOT(deleteCbd(Contact *)));
    connect(fc,SIGNAL(deleteC(Contact *)),this,SLOT(modifierListC()));

    //ajoutInteraction
    connect(fc, SIGNAL(envoyerInteractionEbdd(Interaction *)), bd, SLOT(recInteractionE(Interaction *)));
    connect(fc, SIGNAL(envoyerTacheEbdd(list<tache*>)), bd, SLOT(recTacheE(list<tache*>)));



//recupere le contact sélectionné
    string l=ui->listWidget->currentItem()->text().toStdString();
    string nomW="";
    string prenomW="";
    bool espaceRencontre = false;

     for (char c : l) {
         if (c != ' ' && !espaceRencontre) {
             nomW+= c;
         } else if (c == ' ') {
             espaceRencontre = true;
         } else {
             prenomW += c;
         }
     }

    emit select(nomW,prenomW);//envoyer le nom et prenom du contact selectionné via un signal à la classe basedonnee

}

void MainWindow::majRecherche()
{
    QString line = ui->lineEditNomEntr->text();

    ui->listWidget->clear(); // Effacer les éléments précédents

    if (clickedNom == true && !line.isEmpty())
     {
         QList<QString> contacts = bd->searchContactsByNom(line);
         for (const QString& contact : contacts)
         {
             ui->listWidget->addItem(contact);
         }
     }
     else if (clickedEntr == true && !line.isEmpty())
     {
         QList<QString> contacts = bd->searchContactsByEntreprise(line);
         for (const QString& contact : contacts)
         {
             ui->listWidget->addItem(contact);
         }
     }
     else if (clickedDate == true)
     {
         QString date = ui->dateEdit->text();
         QList<QString> contacts = bd->searchContactsByDate(date);
         for (const QString& contact : contacts)
         {
             ui->listWidget->addItem(contact);
         }
     }
     else if (clicked2Date == true)
     {
         QString date1 = ui->dateEditdebut->text();
         QString date2 = ui->dateEditfin->text();
         QList<QString> contacts = bd->searchContactsByDateRange(date1, date2);
         for (const QString& contact : contacts)
         {
             ui->listWidget->addItem(contact);
         }
     }

     int count = ui->listWidget->count();
     ui->NBRapreRech->setText(QString::number(count));


}

void MainWindow::on_pushButton_clicked()
{
    majRecherche();
    if(ui->listWidget->count()==0)
    {
        QMessageBox::information(this,"Information","Aucun contact ne correspond à cette recherche");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    ui->listWidget->clear();
    remplirListWidget();
    int count = ui->listWidget->count();
    ui->NBRapreRech->setText(QString::number(count));

}

