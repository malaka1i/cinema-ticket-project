#include "welcomewindow.h"
#include "ui_welcomewindow.h"

#include <QPixmap>
#include "mainwindow.h"

WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QPixmap pix ("C:\\Users\\Malak Ali\\Downloads\\Walker_Art_Ctr_bg2012cinema0709_008_LG.jpg");
        int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(pix.scaled(w,h, Qt::KeepAspectRatio));

    ui->hello->setText("Hello " + username + " "+ QString::number(age) + ", ");

}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButton_clicked()
{
    hide();
    MainWindow* loginWindow = new MainWindow(this);
    loginWindow->show();
}

