#include "taquin.h"
#include "./ui_taquin.h"

taquin::taquin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::taquin)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(QDir::currentPath()+"/240px-15-puzzle.png"));
    ui->menuhelp->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogHelpButton));
    ui->infoQt->setIcon(QApplication::style()->standardIcon(QStyle::SP_MessageBoxInformation));
    ui->InfoTaquin->setIcon(QApplication::style()->standardIcon(QStyle::SP_MessageBoxInformation));
    connect(ui->Quitter,&QAction::triggered,this,&taquin::close);
    connect(ui->infoQt,&QAction::triggered,this,&taquin::afficherInfoQt);
    connect(ui->InfoTaquin,&QAction::triggered,this,&taquin::afficherInfoTaquin);
    connect(ui->Quitter,&QAction::triggered,this,&taquin::close);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    createTaquin(3);
}

taquin::~taquin()
{
    delete ui;
}
void taquin::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}
void taquin::createTaquin(int size)
{
    taquinG = new Game(this, size);
    setCentralWidget(taquinG);
    connect(ui->Foret,&QAction::triggered,taquinG,&Game::ChargerImage);
    connect(ui->Arbre,&QAction::triggered,taquinG,&Game::ChargerImage);
    connect(ui->Reseau,&QAction::triggered,taquinG,&Game::ChargerImage);
    connect(ui->Original,&QAction::triggered,taquinG,&Game::ChargerImage);
    connect(ui->Charger,&QAction::triggered,taquinG,&Game::ChargerUnFichier);
    connect(ui->NouvelPartie,&QAction::triggered,taquinG,&Game::SizeDialog);
    connect(ui->Sauvegarder,&QAction::triggered,taquinG,&Game::saveGame);

}

void taquin::afficherInfoQt()
{
    QMessageBox aboutQtBox;
    aboutQtBox.aboutQt(this);
}

void taquin::afficherInfoTaquin()
{
    QMessageBox aboutTaquin(this);
    aboutTaquin.setWindowTitle(tr("A propos de Taquin"));
    aboutTaquin.setWindowIcon(QIcon(QDir::currentPath()+"/240px-15-puzzle.png"));
    QPixmap logo(QDir::currentPath()+"/240px-15-puzzle.png");
    aboutTaquin.setIconPixmap(logo.scaled(60,60));
    aboutTaquin.setText(tr("Cette application a été créée par Mohamed Lyazid Boukhris pour le  projet Qt de L3 informatique."));
    aboutTaquin.exec();
}




