#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lib/blinkenbox/blinkenboxinstance.h"


#include <QHBoxLayout>

typedef unsigned char byte;


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void pressGoto();
    void pressPoke();
    void pressDeposit();
    void pressNext();
    void toggleRun(int state);



private:
    Ui::MainWindow *ui;
    BlinkenBoxInstance *bbi;
    int addr_;
    byte data_;


    void goto_address(int address);
    byte inputByte();
    void update_console();
    void update_led_row(QHBoxLayout *row, byte value);




};

#endif // MAINWINDOW_H
