#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bbi = new BlinkenBoxInstance();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::button_goto()
{
    byte input = inputByte();

    bbi->PC_ = input;

    update_console();
}

void MainWindow::button_poke()
{
}


byte MainWindow::inputByte()
{
    byte high = ui->lcdNumber->value();
    byte low = ui->lcdNumber_2->value();
    return ((high & 0x0F) << 4) | (low & 0x0F);
}



void MainWindow::update_console()
{
    QHBoxLayout *row0 = ui->led_row0_3;

    update_led_row(ui->led_row1, bbi->PC_ & 0xFF);
}


void MainWindow::update_led_row(QHBoxLayout *row, byte value)
{
    QPixmap pon = QPixmap(":images/assets/led_red_on.png");
    QPixmap poff = QPixmap(":images/assets/led_red_off.png");

    int i;
    for (i=0; i<8; i++) {
        QLabel *led = (QLabel*)row->itemAt(i)->widget();
        led->setPixmap( (value & (1<<(8-i))) ? pon : poff);
    }
}
