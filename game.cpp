    #include "game.h"

Game::Game(QWidget *parent,int size):QWidget(parent),m_size(size)
{
    // Layout pour les boutons sur la gauche
    qDebug()<<this->size();
    QPushButton *NouvellePartie = new QPushButton(tr("Nouvelle Partie"), this);
    connect(NouvellePartie,&QPushButton::clicked,this,&Game::SizeDialog);
    QPushButton *ChargerPartie = new QPushButton(tr("Charger une partie"), this);
    connect(ChargerPartie,&QPushButton::clicked,this,&Game::ChargerUnFichier);
    QPushButton *SauvegarderPartie = new QPushButton(tr("Sauvegarder une partie"), this);
    QLabel *labelCoup = new QLabel(tr("Nombre du coup:"), this);
    connect(SauvegarderPartie,&QPushButton::clicked,this,&Game::saveGame);
    numCoup = new QLabel("0", this);
    Image="";
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(labelCoup);
    hLayout->addWidget(numCoup);
    vLayout = new QVBoxLayout;
    vLayout->addWidget(NouvellePartie);
    vLayout->addWidget(ChargerPartie);
    vLayout->addWidget(SauvegarderPartie);
    vLayout->setSpacing(0);
    hLayout->setAlignment(Qt::AlignTop);
    vLayout->addLayout(hLayout);
    gridLayout=new QGridLayout;
    // Ajouter les layouts au layout principal
    mainLayout = new QHBoxLayout(this);
    mainLayout->addLayout(vLayout);
    peutJouer=false;
    changerSize(size,false);

}



void Game::shuffle() {
    peutJouer = true;

    // Crée un générateur de nombres aléatoires basé sur un état initial aléatoire
    QRandomGenerator generator(QRandomGenerator::securelySeeded());

    // Récupère les positions de tous les boutons
    QList<QPair<int, int>> positions;
    for (int row = 0; row < m_size; ++row) {
        for (int col = 0; col < m_size; ++col) {
            if (row != m_emptyRow || col != m_emptyCol) {
                positions.append(QPair<int, int>(row, col));
            }
        }
    }

    // Mélange les positions
    std::shuffle(positions.begin(), positions.end(), generator);

    // Déplace chaque bouton à sa nouvelle position
    for (int i = 0; i < positions.size(); ++i) {
        int row = positions[i].first;
        int col = positions[i].second;
        QWidget* widget1 = gridLayout->itemAtPosition(row, col)->widget();
        QWidget* widget2 = gridLayout->itemAtPosition(i / m_size, i % m_size)->widget();

        gridLayout->removeWidget(widget1);
        gridLayout->removeWidget(widget2);

        gridLayout->addWidget(widget1, i / m_size, i % m_size);
        gridLayout->addWidget(widget2, row, col);
    }

    // Mélange la position de la case vide
    int randomIndex = generator.bounded(positions.size());
    int row = positions[randomIndex].first;
    int col = positions[randomIndex].second;
    QWidget* widget1 = gridLayout->itemAtPosition(row, col)->widget();
    QWidget* widget2 = gridLayout->itemAtPosition(m_emptyRow, m_emptyCol)->widget();

    gridLayout->removeWidget(widget1);
    gridLayout->removeWidget(widget2);

    gridLayout->addWidget(widget1, m_emptyRow, m_emptyCol);
    gridLayout->addWidget(widget2, row, col);

    m_emptyCol = col;
    m_emptyRow = row;
}



void Game::move()
{
    //Verifier si le joueur peut jouer ou pas
    if(!peutJouer)
        return;
    //le button cliqué
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    int row, col;
    for (int r = 0, rEnd = gridLayout->rowCount(); r < rEnd; r++) {
            for (int c = 0, cEnd = gridLayout->columnCount(); c < cEnd; c++) {
                if (gridLayout->itemAtPosition(r, c)->widget() == button) {
                    row = r;
                    col = c;
                }
            }
    }
    if (!button) {
        return;
    }

    // verifier si le button cliquer est proche de la caseVide
    if (qAbs(row - m_emptyRow) + qAbs(col - m_emptyCol) != 1) {
        return;
    }

    numCoup->setText(QString::number(numCoup->text().toInt() + 1));
    QWidget* widget1 = gridLayout->itemAtPosition(row, col)->widget();
    QWidget* widget2 = gridLayout->itemAtPosition(m_emptyRow,m_emptyCol)->widget();

    gridLayout->removeWidget(widget1);
    gridLayout->removeWidget(widget2);

    gridLayout->addWidget(widget1, m_emptyRow, m_emptyCol);
    gridLayout->addWidget(widget2, row, col);

    m_emptyRow = row;
    m_emptyCol = col;


    // verifier si on a gagné
    if (isSolved()) {
        peutJouer=false;
        QString coup = numCoup->text();
        QMessageBox::information(this, tr("Fin !"), tr("Felicitations, vous avez gagne en %1 coups!").arg(coup).toLatin1().data());
    }
}


void Game::changerSize(int size,bool AvecShuffle)
{
    // Supprimer le layout de la grille de jeu
    if(refButton.size()!=0){
        mainLayout->removeItem(gridLayout);
        qDeleteAll(gridLayout->findChildren<QPushButton*>());
        delete gridLayout;
        gridLayout = new QGridLayout;
        for(int i=0;i<m_size*m_size;++i)
            delete refButton[i];
    }
    m_size = size;
    refButton.clear();
    std::vector<QPushButton*> Aux(size*size);
    // Réinitialiser le compteur de coups
    numCoup->setText("0");
    // Ajouter les boutons à la grille de jeu
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            QPushButton *button = new QPushButton(this);
            button->setFixedSize(100,100);
            button->setText(QString::number(row*size+col+1));
            button->setStyleSheet("background-color: blue;QPushButton { border: none; };color:white");
            gridLayout->addWidget(button, row, col);
            // generer dernier button
            if (row == size - 1 && col == size - 1) {
                button->setVisible(false);
                Aux[0] = button;
            } else {
                Aux[row * size + col + 1] = button;
            }
            connect(button, &QPushButton::clicked, this, &Game::move);
        }
        gridLayout->setRowStretch(row, 1);
    }




    // Mettre à jour la position de la case vide
    m_emptyRow = size - 1;
    m_emptyCol = size - 1;
    refButton=Aux;
    // Charger l'image si elle a été définie
    if (Image != "") {
        chargerImageByName(Image);
    }
     if(AvecShuffle)
         shuffle();
     // Ajouter la politique de taille à votre QWidget
     this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    mainLayout->insertLayout(0,gridLayout);
    adjustSize();
    qobject_cast<QMainWindow *>(parent())->adjustSize();

}






void Game::SizeDialog()
{
    QDialog * d=new QDialog(this);
    d->setWindowIcon(QIcon(QDir::currentPath()+"/240px-15-puzzle.png"));
    QLabel *text=new QLabel(d);
    text->setText(tr("taille du taquin"));
    QSpinBox *box=new QSpinBox(d);
    box->setMinimum(3);
    QVBoxLayout *v=new QVBoxLayout(d);
    QHBoxLayout *h=new QHBoxLayout;
    h->addWidget(text);h->addWidget(box);
    QDialogButtonBox * button=new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    v->addLayout(h);v->addWidget(button);
    connect(button,&QDialogButtonBox::accepted,this,&Game::AccepterDialog);
    connect(button, &QDialogButtonBox::rejected, d, &QDialog::reject);
    d->exec();

}

void Game::AccepterDialog()
{
        QDialogButtonBox *buttonBox = qobject_cast<QDialogButtonBox*>(sender());
        QDialog *dialog =qobject_cast<QDialog*>(buttonBox->parentWidget());
        QSpinBox *spinBox = dialog->findChild<QSpinBox*>();
        changerSize(spinBox->value());
        dialog->accept();
}


void Game::saveGame()
{
    QString filter = tr("Fichier du jeu (*.save)");
    // Emplacement du fichier
    QString path = QFileDialog::getSaveFileName(this, tr("Enregistrer le jeu"), QDir::currentPath(), filter);
    // Vérifier si l'utilisateur a annulé la boîte de dialogue
    if (path.isEmpty()) {
        return;
    }
    QFile NomFichier(path);
    if (NomFichier.open(QFile::WriteOnly | QIODevice::Text)) {
    // Écrire les informations du jeu dans le fichier
    QTextStream out(&NomFichier);
    out << m_size << " " << numCoup->text() << "\n";
    // Écrire l'ordre des boutons dans les lignes suivantes
    for (int row = 0; row < m_size; ++row) {
        for (int col = 0; col< m_size; ++col) {
            int k;
              for(k=0;k<m_size*m_size;++k){
                    if(qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget()) ==refButton[k])
                 break;
              }
                  out << k-1;
              if ((row*m_size+col + 1) % m_size == 0) {
                  out << "\n";
              }else
                  out<<" ";
    }
}
    NomFichier.close();
    }
}

    bool Game::isSolved() const
    {
        for (int row = 0; row < m_size; ++row) {
            for (int col = 0; col < m_size; ++col) {
                if (row == m_emptyRow && col == m_emptyCol) {
                    continue;
                }

                QPushButton *button = qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget());
                if (button != refButton[row * m_size + col + 1]) {
                    return false;
                }
            }
        }
        return true;
    }

    void Game::ChargerImage()
    {
        auto sender= qobject_cast<QAction*>(QObject::sender());
        QString FileName;
        if(sender->text()=="Arbre" || sender->text()=="Tree")
            FileName="arbre-papillons.jpg";
        else if(sender->text()=="Reseau" || sender->text()=="Network")
                FileName="reseau-informatique.jpeg";
            else if(sender->text()=="Foret" ||sender->text()=="Forest" )
                FileName="foret.jpg";
                else{
            ChargerOriginal();
            return;
        }
        Image=FileName;
        chargerImageByName(FileName);
    }

    void Game::ChargerOriginal()
    {
        for (int row = 0; row < m_size; ++row) {
            for (int col = 0; col< m_size; ++col) {
                int k;
                  for(k=1;k<m_size*m_size;++k){
                        if(qobject_cast<QPushButton*>(gridLayout->itemAtPosition(row, col)->widget()) ==refButton[k])
                     break;
                  }
                  if(k!=m_size*m_size){
                      refButton[k]->setIcon(QIcon());
                     refButton[k]->setText(QString::number(row*m_size+col+1));
                      refButton[k]->setStyleSheet("background-color: blue;color:white;QPushButton { border: none; }");
                  }
        }
    }
    }




    void Game::chargerImageByName(QString ImageName)
    {
        QImage sourceImage(QDir::currentPath() +"/"+ImageName);
        sourceImage = sourceImage.scaled(m_size*100, m_size*100);

        int tailleDeTuile = 100; // Taille des tuiles

        int num = 1;
        for (int row = 0; row < m_size; ++row) {
            for (int col = 0; col < m_size; ++col) {
                QPoint tileTopLeft(col * tailleDeTuile, row * tailleDeTuile);
                QImage tileImage = QImage(tailleDeTuile, tailleDeTuile, sourceImage.format());
                for (int y = 0; y < tailleDeTuile; ++y) {
                    const uchar *src = sourceImage.scanLine(tileTopLeft.y() + y) + 4 * tileTopLeft.x();
                    auto *dst = tileImage.scanLine(y);
                    memcpy(dst, src, 4 * tailleDeTuile);//je copie les données de pixels de la zone correspondante de la QImage source à la nouvelle QImage
                }
                QPushButton *button = refButton[num];
                button->setText("");
                ++num;
                QPixmap pixmap = QPixmap(tileImage.size());
                pixmap.fill(Qt::transparent);
                QPainter painter(&pixmap);
                painter.drawImage(0, 0, tileImage);
                button->setIcon(QIcon(pixmap));
                button->setIconSize(QSize(tailleDeTuile, tailleDeTuile));
                if (num == m_size * m_size)
                    break;
            }
        }
    }





    void Game::ChargerUnFichier()
    {
        peutJouer = true;

        QDialog warnning(this);
        warnning.setWindowTitle(tr("Charger une nouvelle partie?"));
        warnning.setWindowIcon(QIcon(QDir::currentPath() + "/240px-15-puzzle.png"));
        QVBoxLayout* layout = new QVBoxLayout(&warnning);
        QLabel* label = new QLabel(tr("Abandonner la partie actuelle pour en charger une nouvelle ?"));
        QHBoxLayout* buttonLayout = new QHBoxLayout;
        QPushButton* yesButton = new QPushButton(tr("Oui"));
        QPushButton* noButton = new QPushButton(tr("Non"));
        buttonLayout->addWidget(yesButton);
        buttonLayout->addWidget(noButton);
        layout->addWidget(label);
        layout->addLayout(buttonLayout);

        connect(yesButton, &QPushButton::clicked, this, &Game::onYesButtonClicked);
        connect(noButton, &QPushButton::clicked, this, &Game::onNoButtonClicked);

        warnning.exec();
    }

    void Game::onYesButtonClicked()
    {
        QDialog* dialog = qobject_cast<QDialog*>(sender()->parent());
        if (dialog) {
            dialog->close();
        }
        QString f=QFileDialog::getOpenFileName(this,tr("Sauvergarder une partie"),QDir::currentPath(),"Fichier du jeu (*.save)");
        QFile NomFichier(f);
    if (NomFichier.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QTextStream in(&NomFichier);

    // Lecture de la taille du jeu et du nombre de coups
    QString line = in.readLine();
    QStringList values = line.split(' ');
    if (values.size() != 2) {
        QMessageBox::warning(nullptr, tr("Erreur"), tr("Format de fichier invalide."));
        return;
    }
    int size = values[0].toInt();
    changerSize(size,false);
    numCoup->setText(QString::number(values[1].toInt()));

    // Lecture de l'ordre des boutons
    QVector<int> buttonOrder;
    for (int i = 0; i < size; i++) {
        line = in.readLine();
        values = line.split(' ');
//            qDebug()<<values.size()<<" "<<size;
        if (values.size() != size) {
            QMessageBox::warning(nullptr, tr("Erreur"), tr("Format de fichier invalide."));
            return;
        }
        for (int j = 0; j < size; j++) {
            buttonOrder.append(values[j].toInt());
        }
    }

    // Restauration de l'état du jeu
    for (int i = 0; i < size*size; i++) {
        int buttonIndex = buttonOrder[i]+1;
        QPushButton *firstButton=qobject_cast<QPushButton*>(gridLayout->itemAtPosition(i/m_size, i%m_size)->widget());
        QPushButton *secondButton=refButton[buttonIndex];
            int row, col;
            for (int r = 0, rEnd = gridLayout->rowCount(); r < rEnd; r++) {
                    for (int c = 0, cEnd = gridLayout->columnCount(); c < cEnd; c++) {
                        if (gridLayout->itemAtPosition(r, c)->widget() == secondButton) {
                            row = r;
                            col = c;
                        }
                    }
            }
            gridLayout->removeWidget(firstButton);
            gridLayout->removeWidget(secondButton);
            if(buttonOrder[i]+1==0){
                m_emptyCol=i%m_size;
                m_emptyRow=i/m_size;
            }
            gridLayout->addWidget(firstButton, row, col);
            gridLayout->addWidget(secondButton, i/m_size, i%m_size);
    }

    NomFichier.close();
    }
  }
    void Game::onNoButtonClicked()
    {
        // Ferme la fenêtre de dialogue
        QDialog* dialog = qobject_cast<QDialog*>(sender()->parent());
        if (dialog) {
            dialog->close();
        }
    }






