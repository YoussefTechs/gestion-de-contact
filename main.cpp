#include "mainwindow.h"
#include<gestioncontact.h>
#include <QApplication>
#include<basededonnee.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //basededonnee *bd=new basededonnee();
    MainWindow w;
    w.show();
         /**
         * Création d'objets de contacts, interactions et tâches avec des dates associées pour une gestion efficace des informations de contact
         */
//        Date1 d1(14,5,2023);
//        Date1 d2(02,6,2023);
//        Date1 d3(07,2,2023);
//        GestionContact gc;
//        Contact c1("Ennaji","Wassim","Nokia","ewassim@gmail.com","0715421478","Wassim.jpg",d1);
//        Contact c2("Choukri","Imane","Ikea","cimane@gmail.com","0612141518","Imane.jpg",d1);
//        Contact c3("Maupassant","Guy","Apple","mguy@gmail.com","0645589585","Guy.jpg",d2);
//        Contact c4("Victor","Hugo","Kfc","vhugo@gmail.com","0711559864","Hugo.jpg",d3);
//        Interaction i1("Rdv Aujourd'hui",d1);
//        Interaction i2("Livraison telephone",d3);
//        Interaction i3("Paiement",d2);
//        tache t1("reserver",d1);
//        tache t2("confirmer",d3);
//        tache t3("acheter",d2);
        /**
         * affichage du contact
         */
        //cout<<c1<<endl;
        //cout<<c2<<endl;
        /**
         * ajout des interactions a des contacts
         */
        //c1.ajoutinteraction(i1);
        //c1.ajoutinteraction(i2);
        //c2.ajoutinteraction(i3);
        /**
         * ajout des taches a des contacts
         */
        //c1.ajouttache(i1,t1);
        //c1.ajouttache(i1,t2);
        //c1.ajouttache(i2,t3);
        //c2.ajouttache(i3,t3);
        //c2.ajouttache(i3,t1);
        /**
         * affichage des contacts apres l'ajout des taches et des interaction
         */
        //cout<<c1<<endl;
        //cout<<c2<<endl;
        /**
         * modifier l'interaction et la tache d'un contact
         */
        //c1.modifierinteractioneven(i1,"reunion");
        //c1.modifierinteractiondate(i1,d3);
        //c1.modifierinteractiontachetex(i1,t1,"payer");
        //c1.modifierinteractiontachedate(i1,t1,d2);
        /**
         * l'affichage de ce contact après la modification
         */
          //cout<<c1<<endl;
        /**
         * ajout de tous les contact dans la liste contact
         */
          //gc.ajoutContact(c1);
          //gc.ajoutContact(c2);
          //gc.ajoutContact(c3);
          //gc.ajoutContact(c4);
          //gc.ajoutContact(c5);
        /**
         * affichege de la liste apres l'ajout
         */
          //cout<<gc<<endl;
        /**
         * retirer un contact de la liste
         */
          //gc.retirerContact(c4);
        /**
         * l'affichage de la liste apres la suppresion
         */
          //cout<<gc<<endl;
        /**
         * modifier un contact dans la liste
         */
           //gc.modifierContactInterdate(c1,i1,d3);
        /**
         * afficher apres la modification
         */
          //cout<<gc<<endl;

    return a.exec();
}
