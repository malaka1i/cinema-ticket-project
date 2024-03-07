#include "registerwindow.h"
#include "ui_registerwindow.h"

#include "Users.h"
#include "welcomewindow.h"


RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    hideErrors();
}

void RegisterWindow::hideErrors()
{
    ui->labelErrUsername->setVisible(false);
    ui->labelErrRetype->setVisible(false);
    ui->label_7->setVisible(false);
    ui->labelErrAllFields->setVisible(false);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow:: on_pushButton_clicked()
{
    hideErrors();
    bool errorsFound = false;


    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();
    QString retype = ui->lineEditRetype->text();
    QString month = ui->comboBoxMonth->currentText();
    QString day = ui->lineEditDay->text();
    QString year = ui->lineEditYear->text();
    bool male = ui->radioButtonMale->isChecked();
    bool female = ui->radioButtonFemale->isChecked();
    bool userAccount = ui->radioButtonUser->isChecked();
    bool adminAccount = ui->radioButtonAdmin->isChecked();
    bool actionGenre = ui->checkBoxAction->isChecked();
    bool comedyGenre = ui->checkBoxComedy->isChecked();
    bool romanceGenre = ui->checkBoxRomance->isChecked();
    bool dramaGenre = ui->checkBoxDrama->isChecked();
    bool horrorGenre = ui->checkBoxHorror->isChecked();
    bool otherGenre = ui->checkBoxOtherGenre->isChecked();


    for(int i = 0; i < usersCount; i++)
    {
        if (username == usernames[i])
        {
            ui->labelErrUsername->setVisible(true);
            errorsFound = true;
        }
    }

    if (password != retype)
    {
        ui->labelErrRetype->setVisible(true);
        errorsFound = true;
    }

    int age = 2023 - year.toInt();
    if (age < 12)
    {
        ui->label_7->setVisible(true);
        errorsFound = true;
    }

    if (username == "" || password == "" || retype == ""
        || month == "" || day == "" || year == ""
        || (!male && !female) || (!userAccount && !adminAccount)
        || (!actionGenre && !comedyGenre && !romanceGenre
            && !dramaGenre && !horrorGenre && !otherGenre))
    {
        ui->labelErrAllFields->setVisible(true);
        errorsFound = true;
    }


    if (!errorsFound)
    {
        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = age;
        usersCount++;
        WelcomeWindow* welcomewindow = new WelcomeWindow(username, age);
        this->hide();
        welcomewindow->show();

    }


}








