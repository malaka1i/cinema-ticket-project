#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "users.h"
#include "welcomewindow.h"
#include "registerwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_3->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_login_button_clicked()
{
    QString username = ui->username_line_edit->text();
    QString password = ui->password_line_edit->text();
    bool sucessful_login = false;
    for(int i = 0; i < usersCount; i++)
    {
        if (username == usernames[i] && password == passwords[i])
        {
            sucessful_login=true;
            WelcomeWindow* WelcomeWindow = new WelcomeWindow(username, ages[i]);
            WelcomeWindow->show();
            this->close();
        }
    }

    if(!sucessful_login)
        ui->label_3->setVisible(true);

}
void MainWindow::on_pushButton_2_clicked()
{
    RegisterWindow* registerWindow = new RegisterWindow();
    registerWindow->show();
    this->close();
}


