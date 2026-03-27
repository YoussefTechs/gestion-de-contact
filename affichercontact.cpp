#include "affichercontact.h"
#include "ui_affichercontact.h"
#include <QDate>

AfficherContact::AfficherContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AfficherContact)
{
    ui->setupUi(this);
    //receiveContact(nc);
}

AfficherContact::~AfficherContact()
{
    delete ui;
}

void AfficherContact::receiveContact(Contact *c, std::list<Interaction *> li,list<list<tache*>>llt)
{
    this->listTaches=llt;

    // Afficher les données du contact dans les line edits
    ui->lineEditNom->setText(QString::fromStdString(c->getnom()));
    ui->lineEditNom->setReadOnly(true);

    ui->lineEditPrenom->setText(QString::fromStdString(c->getprenom()));
    ui->lineEditPrenom->setReadOnly(true);

    ui->lineEditMail->setText(QString::fromStdString(c->getmail()));
    ui->lineEditMail->setReadOnly(true);

    ui->lineEditEntreprise->setText(QString::fromStdString(c->getentreprise()));
    ui->lineEditEntreprise->setReadOnly(true);

    ui->lineEditDC->setText(QString::fromStdString(c->getDateC()));
    ui->lineEditDC->setReadOnly(true);

    ui->lineEditDE->setText(QString::fromStdString(c->getDateE()));
    ui->lineEditDE->setReadOnly(true);

    ui->lineEditTel->setText(QString::fromStdString(c->gettelephone()));
    ui->lineEditTel->setReadOnly(true);


    // Afficher l'image du contact
    QString img = QString::fromStdString(c->getphoto());
    QPixmap originalPixmap(img);

    // Redimensionner l'image à la taille souhaitée
    int width = 140;  // Remplacez par la largeur souhaitée
    int height = 220; // Remplacez par la hauteur souhaitée
    QPixmap scaledPixmap = originalPixmap.scaled(width, height, Qt::KeepAspectRatio);

    QIcon ButtonIcon(scaledPixmap);
    ui->pushButtonPhoto->setIcon(ButtonIcon);
    ui->pushButtonPhoto->setIconSize(scaledPixmap.rect().size());



    // Effacer la liste actuelle dans QListWidget
    ui->listWidget->clear();

    // Afficher les éléments de la liste li dans QListWidget
    for (Interaction *interaction : li) {
        QString texteInteraction = QString::fromStdString(interaction->gettexte());
         QString dateInteraction = QString::fromStdString(interaction->getdateI()); // Remplacez getdate() par la fonction appropriée pour obtenir la date de l'interaction

                // Créer le texte complet de l'élément avec texte et date
                QString itemText = texteInteraction + " @date " + dateInteraction;
                ui->listWidget->addItem(itemText);
    }
    int nb = ui->listWidget->count();
    ui->nbI->setText(QString::number(nb));


}




void AfficherContact::on_listWidget_itemDoubleClicked()
{
    // Obtenir la position de l'élément cliqué
    int selectedItemIndex = ui->listWidget->currentRow();
    int cmpt=0;
    // Vérifier si l'indice est valide
    if (selectedItemIndex >= 0 && selectedItemIndex < static_cast<int>(listTaches.size())) {
        // Récupérer l'itérateur vers la liste interne correspondant à la position de l'interaction cliquée
        auto it = std::next(listTaches.begin(), selectedItemIndex);
        std::list<tache*>& tachesInterne = *it;  // Utiliser une référence pour éviter la copie

        // Afficher les tâches dans un QTextEdit
        ui->textEdit->clear();  // Effacer le contenu précédent

        for (const auto& tache : tachesInterne) {
            QString tacheText = "@todo " + QString::fromStdString(tache->getevenement());

               // Vérifier si la date de la tâche est égale à la date courante
               QDate currentDate = QDate::currentDate();
               QDate dateTache = QDate::fromString(QString::fromStdString(tache->getdateT()), "dd/MM/yyyy"); // Assurez-vous que le format de date est correct

               if (dateTache != currentDate) {
                   tacheText += " @date " + QString::fromStdString(tache->getdateT());
               } else {
                   tacheText += "  AJOURDHUI";
               }

            ui->textEdit->append(tacheText);
            cmpt++;
            ui->textEdit->setReadOnly(true);
        }
    }
    if (ui->textEdit->toPlainText().isEmpty())
    {
        ui->textEdit->setText("Cette intéraction n'a aucune tâche");
    }
    ui->nbT->setText(QString::number(cmpt));

}






