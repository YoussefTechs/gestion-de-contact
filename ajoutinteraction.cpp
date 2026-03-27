#include "ajoutinteraction.h"
#include "ui_ajoutinteraction.h"
#include<QMessageBox>
#include <QTextStream>
#include<QDebug>
#include <QDate>
#include <QRegularExpression>


AjoutInteraction::AjoutInteraction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutInteraction)
{
    ui->setupUi(this);
    ui->textEditContenu->setPlaceholderText("@todo tache @date dd/MM/yyyy");



}


AjoutInteraction::~AjoutInteraction()
{
    delete ui;

}

void AjoutInteraction::on_pushButton_2_clicked()
{
    I=new Interaction();
    if(ui->lineEditInteractionTexte->text()!="")
    {
    I->settexte(ui->lineEditInteractionTexte->text().toStdString());
    emit envoyerInteractionE(I);




    ui->textEditContenu->setEnabled(true);
//    ui->dateEdit->setEnabled(true);
    ui->pushButton_CONTENU->setEnabled(true);
    ui->pushButton_AnnulerC->setEnabled(true);
    }
    else
    {
         QMessageBox::warning(this,"Attention","Le champ de l'intéraction est vide");    }


}


void AjoutInteraction::on_pushButton_5_clicked()
{
    ui->lineEditInteractionTexte->clear();
    ui->textEditContenu->clear();

}






void AjoutInteraction::on_pushButton_CONTENU_clicked()
{
    // Récupérer le contenu du QTextEdit
    QString content = ui->textEditContenu->toPlainText();

    // Vérifier si le QTextEdit est vide
    if (content.trimmed().isEmpty())
    {
        QMessageBox::information(this, "Contenu vide", "Il n'y a pas de tâches à traiter.");
        return;  // Pas de tâches à traiter
    }

    // Expressions régulières pour extraire les informations des lignes "@todo" et des dates
    QRegularExpression todoRegex("^@todo (.+?)(?:\\s+@date (.*))?$");
    QRegularExpression dateRegex("^\\d{2}/\\d{2}/\\d{4}$"); // Expression régulière pour la validation de la date

    // Liste pour stocker les objets de type tache*
    list<tache*> listeTaches;

    // Liste pour stocker les événements avec des dates invalides
    QStringList invalidDates;

    // Utiliser QTextStream pour lire le contenu ligne par ligne
    QTextStream stream(&content);
    while (!stream.atEnd())
    {
        QString line = stream.readLine();

        // Vérifier si la ligne commence par "@todo"
        if (!line.trimmed().startsWith("@todo"))
        {
            // Saute la ligne qui ne commence pas par un @todo
            continue;
        }

        // Extraire les informations de la ligne "@todo" en utilisant l'expression régulière
        QRegularExpressionMatch match = todoRegex.match(line);
        if (match.hasMatch())
        {
            QString evenement = match.captured(1);
            QString date = match.captured(2).trimmed(); // Utiliser la date actuelle si elle est vide

            // Valider le format de la date
            if (!date.isEmpty() && !dateRegex.match(date).hasMatch())
            {
                invalidDates.append(evenement);
                continue;
            }

            // Si la date est vide, utiliser la date actuelle
            if (date.isEmpty())
            {
                QDateTime currentDate = QDateTime::currentDateTime();
                date = currentDate.toString("dd/MM/yyyy");
            }

            // Créer un nouvel objet tache* et l'ajouter à la liste
            tache* myTask = new tache();
            myTask->setevenement(evenement.toStdString());
            myTask->setdateT(date.toStdString());
            listeTaches.push_back(myTask);
        }
    }

    // Afficher les dates invalides dans un QMessageBox
    if (!invalidDates.isEmpty()) {
        QString errorMessage = "Dates invalides pour les @todo suivants :\n";
        errorMessage += invalidDates.join("\n");
        QMessageBox::warning(this, "Dates invalides", errorMessage);
    }

    // Vérifier si la liste n'est pas vide avant d'émettre le signal
    if (!listeTaches.empty()) {
        // Faire quelque chose avec la liste de tâches (par exemple, les afficher ou les stocker)
        emit envoyerTacheE(listeTaches);
        ui->textEditContenu->clear();

        // Afficher les événements et les dates dans la console (QDebug)
        for (const tache* t : listeTaches)
        {
            qDebug() << "Événement : " << t->getevenement().c_str() << ", Date : " << t->getdateT().c_str();
        }
    }
    else {
        QMessageBox::information(this, "Liste vide", "Aucune tâche à traiter.");
    }
}



























//    T = new tache();

//    if (ui->textEditContenu->toPlainText().isEmpty()) {
//        QMessageBox::warning(this, "Attention", "Le champ du contenu de la tâche est vide ");
//    } else {
//        // Récupérer l'id de l'interaction à laquelle appartient cette tâche
//        QString idI = ui->lineEditInteractionTexte->text();

//        // Récupérer contenu et date de la tâche
//        T->setevenement(ui->textEditContenu->toPlainText().toStdString());

//        // Récupérer la date de l'interface
//        QDate selectedDate = ui->dateEdit->date();

//        // Vérifier si la date n'est pas dans le passé
//        QDate currentDate = QDate::currentDate();
//        if (selectedDate < currentDate) {
//            QMessageBox::warning(this, "Attention", "Impossible d'effectuer une tâche dans le passé.");
//        } else {
//            // Convertir la date en string et définir la date de la tâche
//            QString date = selectedDate.toString("dd/MM/yyyy");
//            T->setdateT(date.toStdString());

//            // Émettre le signal avec la tâche
//            emit envoyerTacheE(T);
//        }
//    }



//    ui->textEditContenu->clear();





void AjoutInteraction::on_pushButton_6_clicked()
{
        this->close();
         emit fermerparent();
}

