#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QListView>
#include <QListWidget>
#include <QWidget>
#include <QList>
#include <QHBoxLayout>
#include <QDirIterator>
#include<QDebug>
#include <QPushButton>
#include <QFileDialog>
#include <QAbstractButton>
#include <QString>
#include <QLabel>
#include <QMainWindow>
#include <iostream>
#include <algorithm>
#include <QUrlQuery>
#include <iostream>
#include <stdio.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QStringList address;








private slots:
    void on_pushButton_clicked();
    void on_pushButton_checkAll();
    void dirIt(QString a);
    void on_clickDialog(QListWidgetItem* i);
    void Randomize(QStringList address);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
