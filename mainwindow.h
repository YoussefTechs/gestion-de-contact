#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ajoutcontact.h"
#include <QMainWindow>
#include "formcontact.h"
#include"basededonnee.h"
#include "affichercontact.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void remplirListWidget();
    void majRecherche();


signals:
    void cherchNBC();//chercher le nombre de contact
    void select(string,string);

private slots:
    void on_actionQuitter_triggered();
    void on_radioButtonNom_clicked();

    void on_radioButtonEntr_clicked();

    void on_radioButtonDate_clicked();

    void on_actionAjouter_contact_triggered();

    void on_listWidget_doubleClicked();

    void on_radioButton2Dates_clicked();

    void affichNb(int);//afficher le nb de contact

    void modifierListC();


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    AjoutContact *aj;
    FormContact *fc;
    basededonnee  *bd;
    bool clickedNom=false;
    bool clickedEntr=false;
    bool clickedDate=false;
    bool clicked2Date=false;




};
#endif // MAINWINDOW_H
