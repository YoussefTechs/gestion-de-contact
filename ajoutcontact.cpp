#include "ajoutcontact.h"
#include "ui_ajoutcontact.h"
#include<QMessageBox>
AjoutContact::AjoutContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AjoutContact)
{
    ui->setupUi(this);
    ui->lineEditTEL->setPlaceholderText("0123456789");
}

AjoutContact::~AjoutContact()
{
    delete ui;
}

void AjoutContact::on_pushButton_2_clicked()
{

  this->close();


}


void AjoutContact::on_pushButtonParcourir_clicked()
{
     this->path =QFileDialog::getOpenFileName(this, "Photo", "//home");
}

void AjoutContact::on_pushButton_clicked()
{
    if (
        !ui->lineEditNOM->text().isEmpty() &&
        !ui->lineEditPRENOM->text().isEmpty() &&
        !ui->lineEditENTR->text().isEmpty() &&
        !ui->lineEditMAIL->text().isEmpty() &&
        !ui->lineEditTEL->text().isEmpty() &&
        !this->path.isEmpty()
    )
    {
        // Vérifier que le numéro de téléphone est valide
        QString numeroTelephone = ui->lineEditTEL->text();
        QRegExp regex("\\d+"); // Expression régulière pour vérifier qu'il s'agit d'un nombre

        if (numeroTelephone.contains(regex)&& numeroTelephone.length() == 10)
        {
            // Numéro de téléphone valide, créer et enregistrer le contact
            Contact *c = new Contact();
            c->setnom(ui->lineEditNOM->text().toStdString());
            c->setprenom(ui->lineEditPRENOM->text().toStdString());
            c->setmail(ui->lineEditMAIL->text().toStdString());
            c->setentreprise(ui->lineEditENTR->text().toStdString());
            c->setphoto(this->path.toStdString());
            c->settelephone(numeroTelephone.toStdString());

            emit enregistrerContact(c);
            emit majList();
            this->close();
        }
        else
        {
            // Numéro de téléphone invalide
            QMessageBox::warning(this, "Attention", "Numéro de téléphone invalide. Assurez-vous qu'il contient 10 chiffres.");
        }
    }
    else
    {
        QMessageBox::warning(this, "Attention", "Les champs ne sont pas tous remplis.");
    }
}


