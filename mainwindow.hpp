#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QComboBox>
#include <iostream>
#include <QKeyEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    void reset();

protected:
    void keyPressEvent(QKeyEvent *);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_HPP
