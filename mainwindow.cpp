#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bbi = new BlinkenBoxInstance();
    addr_ = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::pressGoto()
{
    goto_address(inputByte());
}

void MainWindow::pressPoke()
{
    byte *mem = (byte*)bbi->access_memory(addr_);
    *mem = inputByte();

    goto_address(addr_+1);
}

void MainWindow::pressNext()
{
    goto_address(addr_+1);
}

void MainWindow::pressDeposit()
{
    byte *mem = (byte*)bbi->access_memory(addr_);
    data_ = inputByte();
    *mem = data_;

    update_console();
}

void MainWindow::toggleRun(int state)
{
    if (state) {
      bbi->PC_ = addr_;
      bbi->run();
    }
}






void MainWindow::goto_address(int address)
{
    addr_ = address;
    byte *mem = (byte*)bbi->access_memory(addr_);
    data_ = *mem;

    update_console();
}


byte MainWindow::inputByte()
{
    byte high = ui->lcdNumber->value();
    byte low = ui->lcdNumber_2->value();
    return ((high & 0x0F) << 4) | (low & 0x0F);
}



void MainWindow::update_console()
{
    update_led_row(ui->led_row1, addr_ & 0xFF);
    update_led_row(ui->led_row2, data_ & 0xFF);

}


void MainWindow::update_led_row(QHBoxLayout *row, byte value)
{
    QPixmap pon = QPixmap(":images/assets/led_red_on.png");
    QPixmap poff = QPixmap(":images/assets/led_red_off.png");

    int i;
    for (i=0; i<8; i++) {
        QLabel *led = (QLabel*)row->itemAt(i)->widget();
        led->setPixmap( (value & (1<<(7-i))) ? pon : poff);
    }
}
