#include "formmodifcontact.h"
#include "ui_formmodifcontact.h"
#include<QMessageBox>

FormModifContact::FormModifContact(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormModifContact)
{
    ui->setupUi(this);
    ui->lineEdit_Tel->setPlaceholderText("0123456789");

}

FormModifContact::~FormModifContact()
{
    delete ui;
}

void FormModifContact::affichCm(Contact *c)
{
    this->c=c;
    ui->lineEditNom->setText(QString::fromStdString(c->getnom()));
    ui->lineEditPrenom->setText(QString::fromStdString(c->getprenom()));
    ui->lineEdit_Entr->setText(QString::fromStdString(c->getentreprise()));
    ui->lineEdit_Mail->setText(QString::fromStdString(c->getmail()));
    ui->lineEdit_Tel->setText(QString::fromStdString(c->gettelephone()));
    ui->lineEdit_DateC->setText(QString::fromStdString(c->getDateC()));

}
void FormModifContact::on_pushButtonParcourir_clicked()
{
    this -> nvpath =QFileDialog::getOpenFileName(this, "Photo", "//home");
    if(!nvpath.isEmpty())
        clicked=true;
    else
        clicked=false;}


void FormModifContact::on_pushButton_Enregistrer_clicked()
{
    if (
        !ui->lineEditNom->text().isEmpty() &&
        !ui->lineEditPrenom->text().isEmpty() &&
        !ui->lineEdit_Entr->text().isEmpty() &&
        !ui->lineEdit_Mail->text().isEmpty() &&
        !ui->lineEdit_Tel->text().isEmpty()
    )
    {
        // Vérifier que le numéro de téléphone est valide
        QString numeroTelephone = ui->lineEdit_Tel->text();
        QRegExp regex("\\d+"); // Expression régulière pour vérifier qu'il s'agit d'un nombre

        if (numeroTelephone.contains(regex) && numeroTelephone.length() == 10)
        {
            // Numéro de téléphone valide, émettre le signal de modification
            if (clicked)
                emit sendE(ui->lineEditNom->text(), ui->lineEditPrenom->text(), ui->lineEdit_Entr->text(), ui->lineEdit_Mail->text(), numeroTelephone, nvpath);
            else
                emit sendE(ui->lineEditNom->text(), ui->lineEditPrenom->text(), ui->lineEdit_Entr->text(), ui->lineEdit_Mail->text(), numeroTelephone, QString::fromStdString(c->getphoto()));

            this->close();

            QMessageBox msgBox;
            msgBox.setText("Votre contact a été modifié");
            msgBox.exec();
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


