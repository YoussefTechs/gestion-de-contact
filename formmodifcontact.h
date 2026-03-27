#ifndef FORMMODIFCONTACT_H
#define FORMMODIFCONTACT_H
#include"contact.h"
#include <QWidget>
#include <QFileDialog>

namespace Ui {
class FormModifContact;
}

class FormModifContact : public QWidget
{
    Q_OBJECT
   //QString path;

public:
    explicit FormModifContact(QWidget *parent = nullptr);
    ~FormModifContact();
signals:
    void sendE(QString,QString,QString,QString,QString,QString);
public slots:
    void affichCm(Contact *);

private slots:
    void on_pushButtonParcourir_clicked();

    void on_pushButton_Enregistrer_clicked();

private:
    Ui::FormModifContact *ui;
    QString nvpath;
    bool clicked=false;
    Contact *c;

};

#endif // FORMMODIFCONTACT_H
