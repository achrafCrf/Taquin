/********************************************************************************
** Form generated from reading UI file 'taquin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAQUIN_H
#define UI_TAQUIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_taquin
{
public:
    QAction *infoQt;
    QAction *InfoTaquin;
    QAction *Original;
    QAction *NouvelPartie;
    QAction *Charger;
    QAction *Sauvegarder;
    QAction *Quitter;
    QAction *Foret;
    QAction *Arbre;
    QAction *Reseau;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuFond;
    QMenu *menuhelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *taquin)
    {
        if (taquin->objectName().isEmpty())
            taquin->setObjectName(QString::fromUtf8("taquin"));
        taquin->resize(454, 366);
        infoQt = new QAction(taquin);
        infoQt->setObjectName(QString::fromUtf8("infoQt"));
        InfoTaquin = new QAction(taquin);
        InfoTaquin->setObjectName(QString::fromUtf8("InfoTaquin"));
        Original = new QAction(taquin);
        Original->setObjectName(QString::fromUtf8("Original"));
        NouvelPartie = new QAction(taquin);
        NouvelPartie->setObjectName(QString::fromUtf8("NouvelPartie"));
        Charger = new QAction(taquin);
        Charger->setObjectName(QString::fromUtf8("Charger"));
        Sauvegarder = new QAction(taquin);
        Sauvegarder->setObjectName(QString::fromUtf8("Sauvegarder"));
        Quitter = new QAction(taquin);
        Quitter->setObjectName(QString::fromUtf8("Quitter"));
        Foret = new QAction(taquin);
        Foret->setObjectName(QString::fromUtf8("Foret"));
        Arbre = new QAction(taquin);
        Arbre->setObjectName(QString::fromUtf8("Arbre"));
        Reseau = new QAction(taquin);
        Reseau->setObjectName(QString::fromUtf8("Reseau"));
        centralwidget = new QWidget(taquin);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        taquin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(taquin);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 454, 30));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuFond = new QMenu(menubar);
        menuFond->setObjectName(QString::fromUtf8("menuFond"));
        menuhelp = new QMenu(menubar);
        menuhelp->setObjectName(QString::fromUtf8("menuhelp"));
        taquin->setMenuBar(menubar);
        statusbar = new QStatusBar(taquin);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        taquin->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuFond->menuAction());
        menubar->addAction(menuhelp->menuAction());
        menuFichier->addAction(NouvelPartie);
        menuFichier->addAction(Charger);
        menuFichier->addAction(Sauvegarder);
        menuFichier->addSeparator();
        menuFichier->addAction(Quitter);
        menuFond->addAction(Original);
        menuFond->addAction(Foret);
        menuFond->addAction(Arbre);
        menuFond->addAction(Reseau);
        menuhelp->addAction(infoQt);
        menuhelp->addAction(InfoTaquin);

        retranslateUi(taquin);

        QMetaObject::connectSlotsByName(taquin);
    } // setupUi

    void retranslateUi(QMainWindow *taquin)
    {
        taquin->setWindowTitle(QCoreApplication::translate("taquin", "taquin", nullptr));
        infoQt->setText(QCoreApplication::translate("taquin", "A propos de Qt", nullptr));
        InfoTaquin->setText(QCoreApplication::translate("taquin", "A propos de Taquin", nullptr));
        Original->setText(QCoreApplication::translate("taquin", "Original", nullptr));
        NouvelPartie->setText(QCoreApplication::translate("taquin", "Nouvel partie", nullptr));
#if QT_CONFIG(shortcut)
        NouvelPartie->setShortcut(QCoreApplication::translate("taquin", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        Charger->setText(QCoreApplication::translate("taquin", "Charger", nullptr));
#if QT_CONFIG(shortcut)
        Charger->setShortcut(QCoreApplication::translate("taquin", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        Sauvegarder->setText(QCoreApplication::translate("taquin", "Sauvegarder", nullptr));
#if QT_CONFIG(shortcut)
        Sauvegarder->setShortcut(QCoreApplication::translate("taquin", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        Quitter->setText(QCoreApplication::translate("taquin", "Quitter", nullptr));
#if QT_CONFIG(shortcut)
        Quitter->setShortcut(QCoreApplication::translate("taquin", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        Foret->setText(QCoreApplication::translate("taquin", "Foret", nullptr));
        Arbre->setText(QCoreApplication::translate("taquin", "Arbre", nullptr));
        Reseau->setText(QCoreApplication::translate("taquin", "Reseau", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("taquin", "Fichier", nullptr));
        menuFond->setTitle(QCoreApplication::translate("taquin", "Fond", nullptr));
        menuhelp->setTitle(QCoreApplication::translate("taquin", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class taquin: public Ui_taquin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAQUIN_H
