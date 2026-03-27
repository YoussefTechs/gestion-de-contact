#include "basededonnee.h"
#include <QtSql/QSqlDatabase>
#include <QDebug>
//#include <QtSql/QSqlQuery>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlRecord>
#include<QDate>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>

basededonnee::basededonnee(QObject *parent)
    : QObject(parent)
{
   // connexionBDD();
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home3/ic115194/Musique/Ennaji_Wassim_Choukri_Imane/CDAA_jalon1_VF/bdd.sqlite");

      if(!db.open())
      {
          qDebug() << "Pas de connexion BDD !";
      }
      else
      {
          qDebug() << "Connexion BDD ok";
      }
     exporterJson("/home3/ic115194/Musique/Ennaji_Wassim_Choukri_Imane/CDAA_jalon1_VF/export.json");

      connect(this, SIGNAL(baseDeDonneeModifiee()), this, SLOT(regenererJson()));




}
void basededonnee::exporterJson(const QString &nomFichier)
{
    QJsonObject databaseObject;

    // Exporter le tableau Contact
    QJsonArray contactsArray;
    QSqlQuery contactQuery;
    contactQuery.prepare("SELECT * FROM Contact");
    if (contactQuery.exec()) {
        while (contactQuery.next()) {
            QJsonObject contactObject;
            contactObject["idC"] = contactQuery.value("idC").toInt();
            contactObject["nom"] = contactQuery.value("nom").toString();
            contactObject["prenom"] = contactQuery.value("prenom").toString();
            contactObject["email"] = contactQuery.value("email").toString();
            contactObject["entreprise"] = contactQuery.value("entreprise").toString();
            contactObject["dateC"] = contactQuery.value("dateC").toString();
            contactObject["dateM"] = contactQuery.value("dateM").toString();
            contactObject["photo"] = contactQuery.value("photo").toString();
            contactObject["telephone"] = contactQuery.value("telephone").toString();
            contactsArray.append(contactObject);
        }
        databaseObject["Contact"] = contactsArray;
    } else {
        qDebug() << "Erreur lors de l'exportation du tableau Contact : " << contactQuery.lastError().text();
        return;
    }


    // Exporter le tableau Interaction
    QJsonArray interactionsArray;
    QSqlQuery interactionQuery;
    interactionQuery.prepare("SELECT * FROM Interaction");
    if (interactionQuery.exec()) {
        while (interactionQuery.next()) {
            QJsonObject interactionObject;
            interactionObject["idI"] = interactionQuery.value("idI").toInt();
            interactionObject["idC"] = interactionQuery.value("idC").toInt();
            interactionObject["contenu"] = interactionQuery.value("contenu").toString();
            interactionObject["dateInteraction"] = interactionQuery.value("dateInteraction").toString();
            interactionsArray.append(interactionObject);
        }
        databaseObject["Interaction"] = interactionsArray;
    } else {
        qDebug() << "Erreur lors de l'exportation du tableau Interaction : " << interactionQuery.lastError().text();
        return;
    }

    // Exporter le tableau Todo
    QJsonArray todoArray;
    QSqlQuery todoQuery;
    todoQuery.prepare("SELECT * FROM Todo");
    if (todoQuery.exec()) {
        while (todoQuery.next()) {
            QJsonObject todoObject;
            todoObject["idT"] = todoQuery.value("idT").toInt();
            todoObject["idI"] = todoQuery.value("idI").toInt();
            todoObject["tache"] = todoQuery.value("tache").toString();
            todoObject["dateTodo"] = todoQuery.value("dateTodo").toString();
            todoArray.append(todoObject);
        }
        databaseObject["Todo"] = todoArray;
    } else {
        qDebug() << "Erreur lors de l'exportation du tableau Todo : " << todoQuery.lastError().text();
        return;
    }

    // Créer le document JSON
    QJsonDocument jsonDocument(databaseObject);

    // Ouvrir un fichier pour l'écriture
    QFile file(nomFichier);
    if (file.open(QIODevice::WriteOnly)) {
        // Écrire le document JSON dans le fichier
        file.write(jsonDocument.toJson());
        file.close();
        qDebug() << "Export JSON réussi.";
    } else {
        qDebug() << "Erreur lors de l'ouverture du fichier pour l'export JSON.";
    }
}


void basededonnee::regenererJson()
{
    exporterJson("/home3/ic115194/Musique/Ennaji_Wassim_Choukri_Imane/CDAA_jalon1_VF/export.json");
}


basededonnee::~basededonnee()
{
    db.close();
}

QList<QString> basededonnee::getContacts()
{
    QList<QString> contacts;

    QSqlQuery query;
    query.prepare("SELECT * from Contact");
    query.exec();

    while(query.next())
    {
        QString contact = QString(query.value(1).toString() + " " + query.value(2).toString());
        contacts.append(contact);
    }

    return contacts;
}



QList<QString> basededonnee::searchContactsByNom(const QString &nom)
{
    QList<QString> contacts;

    QSqlQuery query;
    query.prepare("SELECT * FROM Contact WHERE nom = :nom");
    query.bindValue(":nom", nom);

    if (query.exec())
    {
        while (query.next())
        {
            QString c = QString(query.value("nom").toString() + " " + query.value("prenom").toString());
            contacts.append(c);
        }
    }
    else
    {
        qDebug() << "Erreur lors de la recherche par nom : " << query.lastError().text();
    }

    return contacts;
}

QList<QString> basededonnee::searchContactsByEntreprise(const QString &entreprise)
{
    QList<QString> contacts;

    QSqlQuery query;
    query.prepare("SELECT * FROM Contact WHERE entreprise = :entreprise");
    query.bindValue(":entreprise", entreprise);

    if (query.exec())
    {
        while (query.next())
        {
            QString c = QString(query.value("nom").toString() + " " + query.value("prenom").toString());
            contacts.append(c);
        }
    }
    else
    {
        qDebug() << "Erreur lors de la recherche par entreprise : " << query.lastError().text();
    }

    return contacts;
}

QList<QString> basededonnee::searchContactsByDate(const QString &date)
{
    QList<QString> contacts; // Liste pour stocker les noms complets des contacts trouvés

    // Traitement de la date pour supprimer le préfixe '0' si présent
    QString date1;
    string l1 = date.toStdString();
    string nl1 = "";

    if (l1[0] == '0')
    {
        for (__SIZE_TYPE__ i = 1; i < l1.size(); i++)
        {
            nl1 += l1[i];
        }
        date1 = QString::fromStdString(nl1);
    } else {
        date1 = date; // Utiliser la date telle quelle si elle ne commence pas par '0'
    }

    // Préparation de la requête SQL pour sélectionner les contacts par date
    QSqlQuery query;
    query.prepare("SELECT * FROM Contact WHERE dateC = :date1");
    query.bindValue(":date1", date1);

    // Exécution de la requête SQL
    if (query.exec())
    {
        // Parcours des résultats de la requête
        while (query.next())
        {
            // Construction du nom complet du contact
            QString c = QString(query.value("nom").toString() + " " + query.value("prenom").toString());
            contacts.append(c); // Ajout du nom complet à la liste
        }
    }
    else
    {
        // Affichage d'une erreur si la requête échoue
        qDebug() << "Erreur lors de la recherche par date : " << query.lastError().text();
    }

    // Retour de la liste de noms complets des contacts trouvés
    return contacts;
}

QList<QString> basededonnee::searchContactsByDateRange(const QString &date1, const QString &date2)
{
    QList<QString> contacts;

    QSqlQuery query;



    // Convertir les chaînes de date en objets QDate
    QDate dateDebut = QDate::fromString(date1, "d/MM/yyyy");
    QDate dateFin = QDate::fromString(date2, "d/MM/yyyy");

    // Formatage des dates dans le format attendu par la base de données (à adapter si nécessaire)
    QString dateDebutStr = dateDebut.toString("d/MM/yyyy");
    QString dateFinStr = dateFin.toString("d/MM/yyyy");



    query.prepare("SELECT * FROM Contact WHERE dateC BETWEEN :dateDebut AND :dateFin");
    query.bindValue(":dateDebut", dateDebutStr);
    query.bindValue(":dateFin", dateFinStr);

    if (query.exec())
    {
        while (query.next())
        {
            QString c = QString(query.value("nom").toString() + " " + query.value("prenom").toString());
            contacts.append(c);
        }
    }
    else
    {
        qDebug() << "Erreur lors de la recherche par plage de dates : " << query.lastError().text();
    }

    return contacts;
}




void basededonnee::ajoutContact(Contact *c)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Contact (nom,prenom,email,entreprise,dateC,dateM,photo,telephone) VALUES ( :n, :p, :m, :e, :dc, :dm, :ph, :t)");
    query.bindValue(":n", QString::fromStdString(c->getnom()));
    query.bindValue(":p", QString::fromStdString(c->getprenom()));
    query.bindValue(":m", QString::fromStdString(c->getmail()));
    query.bindValue(":e", QString::fromStdString(c->getentreprise()));
    query.bindValue(":dc", QString::fromStdString(c->ConvertDatec()));
    query.bindValue(":dm", QString::fromStdString(c->ConvertDatem()));
    query.bindValue(":ph", QString::fromStdString(c->getphoto()));
    query.bindValue(":t", QString::fromStdString(c->gettelephone()));
    query.exec();
//    if(query.exec()){qDebug()<<"requete marche";}

//    else{qDebug()<<"requete ne marche pas ";}
    emit baseDeDonneeModifiee();

}

void basededonnee::reception(string n,string p)
{
//    nom=n;
//    prenom=p;
    QString nom=QString::fromStdString(n);
    QString prenom=QString::fromStdString(p);
    QSqlQuery query;
    query.prepare("SELECT * FROM Contact WHERE nom = '" + nom + "' AND prenom = '" + prenom + "';");
    query.exec();
    while(query.next())
    {
        QString n= QString(query.value(1).toString());
        QString p= QString(query.value(2).toString());
        QString m= QString(query.value(3).toString());
        QString e= QString(query.value(4).toString());
        QString dc= QString(query.value(5).toString());
        QString dm= QString(query.value(6).toString());
        QString ph= QString(query.value(7).toString());
        QString t= QString(query.value(8).toString());

        c= new Contact(n.toStdString(),p.toStdString(),m.toStdString(),e.toStdString(),dc.toStdString(),dm.toStdString(),ph.toStdString(),t.toStdString());

    }

    list<Interaction *> li;
    list<list<tache*>> listTaches;

    QSqlQuery selectQuery;

    // Utilisation de requête paramétrée pour éviter les injections SQL
    selectQuery.prepare("SELECT idC FROM Contact WHERE nom = '" + nom + "' AND prenom = '" + prenom + "';");

    if (selectQuery.exec() && selectQuery.next()) {
        // Récupérer l'idC en tant que std::string
        QString idC = selectQuery.value("idC").toString();
        QSqlQuery query;

        // Sélectionner les interactions
        query.prepare("SELECT * FROM Interaction WHERE idC = :idC");
        query.bindValue(":idC", idC);

        if (query.exec()) {
            while (query.next()) {
                int idI = query.value(0).toInt();  // Récupérer l'ID d'interaction
                QString in = query.value(2).toString();
                QString din = query.value(3).toString();
                Interaction *I = new Interaction(in.toStdString(), din.toStdString());
                li.push_back(I);

                // Récupérer les tâches pour chaque interaction
                QSqlQuery tacheQuery;
                tacheQuery.prepare("SELECT * FROM Todo WHERE idI = :idI");
                tacheQuery.bindValue(":idI", idI);  // Utiliser l'ID d'interaction comme clé étrangère

                list<tache*> taches;
                if (tacheQuery.exec()) {
                    while (tacheQuery.next()) {
                        QString tacheText = tacheQuery.value(2).toString();
                        QString dateTache = tacheQuery.value(3).toString();
                        // Créer une nouvelle tâche avec la tâche et la date récupérées
                        tache *t = new tache(tacheText.toStdString(), dateTache.toStdString());
                        taches.push_back(t);
                    }
                } else {
                    qDebug() << "Erreur lors de la récupération des tâches : " << tacheQuery.lastError().text();
                }

                listTaches.push_back(taches);
            }

            // Émettre le signal avec la liste d'interactions et la liste des listes de tâches
            emit envoyerContact(c, li, listTaches);
        } else {
            qDebug() << "Erreur lors de la récupération des interactions : " << query.lastError().text();
        }
    } else {
        qDebug() << "Aucun contact trouvé pour les noms donnés.";
    }
}


void basededonnee::reciveE(QString N,QString P ,QString E,QString m,QString tele,QString photo)
{
    c1=new Contact();
    nom=c->getnom();
    prenom=c->getprenom();
    QString n=QString::fromStdString(nom);
    QString p=QString::fromStdString(prenom);
    QSqlQuery query;
    string ph=photo.toStdString();
    query.prepare("UPDATE Contact SET nom=:N,prenom=:P,email=:m,entreprise=:e,dateM=:dm,telephone=:tele,photo=:p WHERE nom = '" + n + "' AND prenom = '" + p + "';");
    query.bindValue(":N", N);
    query.bindValue(":P", P);
    query.bindValue(":m", m);
    query.bindValue(":e", E);
    query.bindValue(":dm", QString::fromStdString(c1->ConvertDatem()));
    query.bindValue(":tele", tele);
    query.bindValue(":p", photo);
    query.exec();
//    if(query.exec()){qDebug()<<"requete marche";}

//    else{qDebug()<<"requete ne marche pas ";}
    reception(N.toStdString(),P.toStdString());
    emit modifnomprenom();
    emit baseDeDonneeModifiee();

}




void basededonnee::recInteractionE(Interaction *I) //ajouter une interaction a la base de donnée
{

    nom=c->getnom();
    prenom=c->getprenom();
    QString nomW1=QString::fromStdString(nom);
    QString prenomW1=QString::fromStdString(prenom);
    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT idC FROM Contact WHERE nom = :nomW1 AND prenom = :prenomW1");
    selectQuery.bindValue(":nomW1", nomW1);
    selectQuery.bindValue(":prenomW1", prenomW1);

    if (selectQuery.exec() && selectQuery.next()) {
                   string idC = selectQuery.value("idC").toString().toStdString();
  // qDebug() << "ID du contact récupéré avec succès : " << QString::fromStdString(idC);
        // Requête d'insertion dans la table Interaction
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO Interaction (idC, contenu, dateInteraction) VALUES (:c, :t, :d)");
        insertQuery.bindValue(":c", QString::fromStdString(idC));
        insertQuery.bindValue(":t", QString::fromStdString(I->gettexte()));
        insertQuery.bindValue(":d", QString::fromStdString(I->getdateI()));
        if (insertQuery.exec()) {
            qDebug() << "Insertion réussie";
            QMessageBox msgBox;
            msgBox.setText("Intéraction ajoutée avec succes ,vous pouvez désormais ajouter une tâche");
            msgBox.exec();

        } else {
            qDebug() << "Erreur lors de l'insertion : " ;
        }
    } else
    {
    qDebug() << "Erreur lors de la récupération de l'ID du contact ";
    qDebug() << "Requête SQL : " << selectQuery.lastQuery();
    }
    emit baseDeDonneeModifiee();


}

void basededonnee::recTacheE(list<tache*> lt)
{
    QSqlQuery selectQuery(db);
    if (selectQuery.exec("SELECT idI FROM Interaction ORDER BY idI DESC LIMIT 1") && selectQuery.next()) {
        int dernierIdI = selectQuery.value(0).toInt();

        // Loop through the list of tasks and insert each one into the Todo table
        for (const tache* T : lt) {
            QSqlQuery insertQuery(db);
            insertQuery.prepare("INSERT INTO Todo (idI, tache, dateTodo) VALUES (:idI, :t, :d)");
            insertQuery.bindValue(":idI", dernierIdI);
            insertQuery.bindValue(":t", QString::fromStdString(T->getevenement()));
            insertQuery.bindValue(":d", QString::fromStdString(T->getdateT()));

            if (insertQuery.exec()) {
                qDebug() << "Insertion avec succès à la table Todo.";
            } else {
                qDebug() << "Erreur lors de l'ajout de l'enregistrement à la table Todo:" << insertQuery.lastError().text();
            }
        }

        QMessageBox msgBox;
        msgBox.setText("Tâches ajoutées, ajoutez une autre ou passez à une nouvelle interaction");
        msgBox.exec();
    } else {
        qDebug() << "Erreur lors de la récupération du dernier idI de la table Interaction:" << selectQuery.lastError().text();
    }
    emit baseDeDonneeModifiee();


}







void basededonnee::trouverNb()
{
    int nb=0; // Déclaration d'une variable entière pour stocker le nombre d'entrées

    QSqlQuery query; // Création d'une requête SQL
    query.prepare("SELECT COUNT (*) from Contact"); // Préparation de la requête pour compter les entrées dans la table "Contact"
    query.exec(); // Exécution de la requête

    // Vérification s'il y a un résultat à la requête
    if(query.next())
    {
        nb = query.value(0).toInt(); // Récupération du nombre d'entrées depuis la première colonne du résultat
    }

    emit envoyerNBC(nb); // Émission du nombre d'entrées via un signal nommé "NB"
}

void basededonnee::deleteCbd(Contact *c)
{
    nom = c->getnom();
    prenom = c->getprenom();
    QString nomW1 = QString::fromStdString(nom);
    QString prenomW1 = QString::fromStdString(prenom);

    QSqlDatabase::database().transaction(); // Début de la transaction

    QSqlQuery selectQuery;
    selectQuery.prepare("SELECT idC FROM Contact WHERE nom = :nomW1 AND prenom = :prenomW1");
    selectQuery.bindValue(":nomW1", nomW1);
    selectQuery.bindValue(":prenomW1", prenomW1);

    if (selectQuery.exec() && selectQuery.next()) {
        std::string idC = selectQuery.value("idC").toString().toStdString(); // Récupérer idC en tant que std::string

        QSqlQuery query;
        query.prepare("DELETE FROM Contact WHERE nom = :nomW1 AND prenom = :prenomW1");
        query.bindValue(":nomW1", nomW1);
        query.bindValue(":prenomW1", prenomW1);
        if (!query.exec()) {
            qDebug() << "Erreur lors de la suppression du contact : " << query.lastError().text();
            QSqlDatabase::database().rollback(); // Annuler la transaction en cas d'erreur
            return;
        }

        // Supprimer les tâches liées à l'idI dans la table Todo
        query.prepare("DELETE FROM Todo WHERE idI IN (SELECT idI FROM Interaction WHERE idC = :idC)");
        query.bindValue(":idC", QString::fromStdString(idC));
        if (!query.exec()) {
            qDebug() << "Erreur lors de la suppression des tâches : " << query.lastError().text();
            QSqlDatabase::database().rollback(); // Annuler la transaction en cas d'erreur
            return;
        }

        query.prepare("DELETE FROM Interaction WHERE idC = :idC");
        query.bindValue(":idC", QString::fromStdString(idC));
        if (!query.exec()) {
            qDebug() << "Erreur lors de la suppression des interactions : " << query.lastError().text();
            QSqlDatabase::database().rollback(); // Annuler la transaction en cas d'erreur
            return;
        }



        QSqlDatabase::database().commit(); // Fin de la transaction
        emit baseDeDonneeModifiee();

    } else {
        qDebug() << "Aucun contact trouvé pour suppression.";
        QSqlDatabase::database().rollback(); // Annuler la transaction car aucun contact trouvé
    }
}




