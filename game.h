#pragma once
#include<QWidget>
#include<QPushButton>
#include<QMessageBox>
#include<QGridLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<cmath>
#include<QRandomGenerator>
#include<QApplication>
#include <iostream>
#include<QLabel>
#include<QString>
#include<string>
#include<utility>
#include<QFileDialog>
#include<QPainter>
#include<QPixmap>
#include<array>
#include<QGuiApplication>
#include<QScreen>
#include<QAction>
#include<vector>
#include<QSpinBox>
#include<QDialogButtonBox>
#include<QTextStream>
#include<QDebug>
#include <QIcon>
#include<QStyle>
#include<QSizePolicy>
#include <QMainWindow>
#include <QPixmap>
#include<QPainter>
class Game:public QWidget
{
    Q_OBJECT
public:
    Game(QWidget * parent=nullptr,int size=3);
    void shuffle();
    bool isSolved() const;
    void ChargerOriginal();
    QPushButton  * chercherButtonParNum(int num);
    void chargerImageByName(QString ImageName);


public slots:
    void move();
    void ChargerImage();
    void changerSize(int size,bool AvecShuffle=true);
    void SizeDialog();
    void AccepterDialog();
    void saveGame();
    void ChargerUnFichier();
    void onNoButtonClicked();
    void onYesButtonClicked();



private:
        int m_size;
        int m_emptyRow = 0;
        int m_emptyCol = 0;
        QString Image;
        QHBoxLayout *mainLayout;
        QVBoxLayout * vLayout;
        QLabel *numCoup;
        QGridLayout *gridLayout;
        std::vector<QPushButton*>refButton;
        bool peutJouer;
};



