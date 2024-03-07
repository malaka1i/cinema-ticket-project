#include "welcomewindow.h"
#include "ui_welcomewindow.h"

#include <QPixmap>
#include "mainwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, QString username, int age)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QPixmap pix ("C:\Users\Malak Ali\Downloads\101d89b6cd5492080b4391d651cd527f.jpg");
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

