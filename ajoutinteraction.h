#ifndef AJOUTINTERACTION_H
#define AJOUTINTERACTION_H

#include <QWidget>
#include "interaction.h"

namespace Ui {
class AjoutInteraction;
}

class AjoutInteraction : public QWidget
{
    Q_OBJECT

public:
    explicit AjoutInteraction(QWidget *parent = nullptr);
    ~AjoutInteraction();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_CONTENU_clicked();







    void on_pushButton_6_clicked();

signals:
    void envoyerInteractionE(Interaction *);
    void envoyerTacheE(list<tache*> );
    void fermerparent();

private:
    Ui::AjoutInteraction *ui;
    Interaction *I;
    tache *T;


};

#endif // AJOUTINTERACTION_H
