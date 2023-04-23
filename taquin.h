#ifndef TAQUIN_H
#define TAQUIN_H

#include <QMainWindow>
#include<QApplication>
#include<QStyle>
#include<QMessageBox>
#include<QAction>
#include<QFileDialog>
#include<QSpinBox>
#include"game.h"
#include<QHBoxLayout>
#include<QSplitter>
#include<QSizePolicy>
#include<QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class taquin; }
QT_END_NAMESPACE

class taquin : public QMainWindow
{
    Q_OBJECT

public:
    taquin(QWidget *parent = nullptr);
    ~taquin();
    void createTaquin(int size);
protected:
    void resizeEvent(QResizeEvent *event);
public slots:
    void afficherInfoQt();
    void afficherInfoTaquin();
signals:
    void image(QString &);

private:
    Ui::taquin *ui;
    Game * taquinG;
};
#endif // TAQUIN_H
