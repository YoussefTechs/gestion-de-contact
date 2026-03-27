#ifndef AJOUTCONTACT_H
#define AJOUTCONTACT_H
#include "contact.h"
#include <QWidget>
#include <QFileDialog>

namespace Ui {
class AjoutContact;
}

class AjoutContact : public QWidget
{
    Q_OBJECT
    QString path;

public:
    explicit AjoutContact(QWidget *parent = nullptr);
    ~AjoutContact();

signals:
    void enregistrerContact(Contact *);
    void majList();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButtonParcourir_clicked();

    void on_pushButton_clicked();

private:
    Ui::AjoutContact *ui;
};

#endif // AJOUTCONTACT_H
