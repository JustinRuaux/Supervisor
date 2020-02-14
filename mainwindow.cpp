#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Connect
    QObject::connect(ui->UP, SIGNAL(pressed()), this, SLOT(goUp()));
    QObject::connect(ui->DOWN, SIGNAL(pressed()), this, SLOT(goDown()));
    QObject::connect(ui->RIGHT, SIGNAL(pressed()), this, SLOT(goRight()));
    QObject::connect(ui->LEFT, SIGNAL(pressed()), this, SLOT(goLeft()));
    QObject::connect(ui->Reset , SIGNAL(pressed()), this, SLOT(reset()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
        case Qt::Key_W :
            goUp();
            break;
        case Qt::Key_S :
            goDown();
            break;
        case Qt::Key_A :
            goLeft();
            break;
        case Qt::Key_D :
            goRight();
            break;
        case Qt::Key_R :
            reset();
            break;
        default :
            break;
    }
}

void MainWindow::goUp(){
    ui->Robot->move(ui->Robot->x(), ui->Robot->y() - 2);
}

void MainWindow::goDown(){
    ui->Robot->move(ui->Robot->x(), ui->Robot->y() + 2);
}

void MainWindow::goLeft(){
    ui->Robot->move(ui->Robot->x() - 2, ui->Robot->y());
}

void MainWindow::goRight(){
    ui->Robot->move(ui->Robot->x() + 2, ui->Robot->y());
}

void MainWindow::reset(){
    if(ui->Side_option->currentIndex() == 0)
        ui->Robot->move(370, 90);
    else
        ui->Robot->move(5, 90);
}



