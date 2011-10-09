#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lib/blinkenboxinstance/blinkenboxinstance.h"


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
    void button_goto();
    void button_poke();

    void update_console();


private:
    Ui::MainWindow *ui;
    BlinkenBoxInstance *bbi;

    byte inputByte();

    void update_led_row(QHBoxLayout *row, byte value);




};

#endif // MAINWINDOW_H
