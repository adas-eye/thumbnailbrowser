#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow){
            ui->setupUi(this);
            ui->listWidget ->setViewMode(QListView::IconMode);
            ui->listWidget ->setMovement(QListView::Static);
            connect(ui->All, SIGNAL(clicked()), this, SLOT(on_pushButton_checkAll()));
            connect(ui->Panda, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
            connect(ui->Pyramid, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
            connect(ui->Lotus, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
            connect(ui->Airplanes, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
            connect(ui->Strawberry, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
            connect(ui->listWidget,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this, SLOT(on_clickDialog(QListWidgetItem*)));
}
MainWindow::~MainWindow(){
    delete ui;
}

//randomizza la lista di elementi address e la carica nel listWidget
void MainWindow::Randomize(QStringList address){
     QListWidgetItem *lwi;
     std::string name;
     std::string indirizzo;
     int pos1;
     int pos2;
     ui->listWidget->clear();
    for (int i=0; i<address.size(); i++){
       for(int j=address.size(); j>0; j--){


             int rnd = rand()%j;

             QPixmap imm(address.at(rnd));
             QPixmap scaled = imm.scaled( QSize(120, 120),  Qt::IgnoreAspectRatio);
             QIcon ic(scaled);

                 indirizzo=address.at(rnd).toStdString();
                 pos1=indirizzo.find("dataset/")+8;
                 pos2=indirizzo.find("/image");
                 name=indirizzo.substr(pos1, pos2-pos1);

                 if (name=="airplaines"){
                     ui->listWidget ->addItem(lwi=new QListWidgetItem(ic, "airplaines"));
                     lwi->setTextAlignment(Qt::AlignCenter);
                     lwi->setWhatsThis(address.at(rnd));

                 }else  if (name=="panda"){
                     ui->listWidget ->addItem(lwi=new QListWidgetItem(ic, "panda"));
                     lwi->setTextAlignment(Qt::AlignCenter);
                     lwi->setWhatsThis(address.at(rnd));

                 }else  if (name=="pyramid"){
                     ui->listWidget ->addItem(lwi=new QListWidgetItem(ic, "pyramid"));
                     lwi->setTextAlignment(Qt::AlignCenter);
                     lwi->setWhatsThis(address.at(rnd));
                 }else  if (name=="lotus"){
                     ui->listWidget ->addItem(lwi=new QListWidgetItem(ic, "lotus"));
                     lwi->setTextAlignment(Qt::AlignCenter);
                     lwi->setWhatsThis(address.at(rnd));
                 }else  if (name=="strawberry"){
                     ui->listWidget ->addItem(lwi=new QListWidgetItem(ic, "strawberry"));
                     lwi->setTextAlignment(Qt::AlignCenter);
                     lwi->setWhatsThis(address.at(rnd));
                 }
                 address.removeAt(rnd); //viene rimosso l'elemento già inserito per non creare ridondanze


               }

    }

  address.clear(); //viene ripulita la lista address
}
    //


//crea uan lista di percorsi delle varie immagini associandovi il nome della cartella in cui sono presenti;
//nel caso il nome della cartella sia vuoto viene iterata tutta dataset e inserito il percorso ricevuto dall'iteratore, nel caso la stringa non sia
//vuota invece itera solo la cartella indicata in dir
void MainWindow::dirIt(QString dir){
    if (dir != ""){
    QDirIterator it("/home/riccardo/Scrivania/ThumbnailBrowser/Thumbnailbrowser/dataset/"+dir, QStringList() << "*.jpg", QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext()){
        it.next();
        address << it.filePath();
        }
    }
    else {
        QDirIterator it("/home/riccardo/Scrivania/ThumbnailBrowser/Thumbnailbrowser/dataset/", QStringList() << "*.jpg", QDir::Files, QDirIterator::Subdirectories);
        while (it.hasNext()){
        it.next();
        address << it.filePath();
         }
    }
     Randomize(address);
}


//se la checkbox All è clickata resetta la listWidget e seleziona tutte le altre e chiama allIterator, altrimenti le deseleziona tutte e resetta la
//lista
void MainWindow::on_pushButton_checkAll(){
    if(ui->All->isChecked()){
        ui->listWidget->clear();
        address.clear();
        dirIt("");
        ui->Airplanes->setChecked(true);
        ui->Lotus->setChecked(true);
        ui->Panda->setChecked(true);
        ui->Pyramid->setChecked(true);
        ui->Strawberry->setChecked(true);
    }
    else{
        ui->listWidget->clear();
        ui->Airplanes->setChecked(false);
        ui->Lotus->setChecked(false);
        ui->Panda->setChecked(false);
        ui->Pyramid->setChecked(false);
        ui->Strawberry->setChecked(false);
    }





}
//apre in una finestra l'immagine a grandezza originale dopo un doppio click
void MainWindow::on_clickDialog(QListWidgetItem* i){

    QLabel *l=new QLabel();
    QImage pix(i->whatsThis());
    l->setPixmap(QPixmap::fromImage(pix));
    l->setVisible(true);
    l->show();
}




//seleziona le immagini a seconda delle relative checkbox selezionate
void MainWindow::on_pushButton_clicked() {
    //clear
        ui->listWidget->clear();
        address.clear();
         //Airplanes
        if ((ui->Airplanes->isChecked())&&(ui->All->isChecked()==false)){
            dirIt("airplaines");
            //dirIt("");
        }
        else (ui->All->setChecked(false));
        //Lotus
        if ((ui->Lotus->isChecked())&&(ui->All->isChecked()==false)){
            dirIt("lotus");
          //  dirIt("");
        }
        else (ui->All->setChecked(false));
         //Panda
        if ((ui->Panda->isChecked())&&(ui->All->isChecked()==false)){
            dirIt("panda");
          //  dirIt("");
        }
        else (ui->All->setChecked(false));
          //Pyramid
        if ((ui->Pyramid->isChecked())&&(ui->All->isChecked()==false)){
             dirIt("pyramid");
            // dirIt("");
        }
        else (ui->All->setChecked(false));
          //Strawberry
        if ((ui->Strawberry->isChecked())&&(ui->All->isChecked()==false)){
             dirIt("strawberry");
            // dirIt("");
        }
        else (ui->All->setChecked(false));
        if ((ui->Strawberry->isChecked())&&(ui->Pyramid->isChecked())&&(ui->Panda->isChecked())&&(ui->Lotus->isChecked())&&(ui->Airplanes->isChecked()))
            ui->All->setChecked(true);
}

