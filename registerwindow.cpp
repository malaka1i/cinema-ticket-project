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
    ui->label_6->setVisible(false);
    ui->label_3->setVisible(false);
    ui->groupBox_2->setVisible(false);
    ui->labelErrAllFields->setVisible(false);

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pushButtonRegister_clicked()
{
    hideErrors();
    bool errorsFound = false;

    // ---------- Fields' Retrieval -----------
    QString username = ui->label_6->text();
    QString password = ui->label_2->text();
    QString retype = ui->label_3->text();
    QString month = ui->comboBoxMonth->currentText();
    QString day = ui->label_4->text();
    QString year = ui->label_8->text();
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

    // ---------- Errors' Checking -----------
    // Check Username if existing
    for(int i = 0; i < usersCount; i++)
    {
        if (username == usernames[i])
        {
            ui->label_6->setVisible(true);
            errorsFound = true;
        }
    }
    // Check re-type password
    if (password != retype)
    {
        ui->label_3->setVisible(true);
        errorsFound = true;
    }
    // Check age
    int age = 2023 - year.toInt();
    if (age < 12)
    {
        ui->groupBox_2->setVisible(true);
        errorsFound = true;
    }
    // Check all fields are entered
    if (username == "" || password == "" || retype == ""
        || month == "" || day == "" || year == ""
        || (!male && !female) || (!userAccount && !adminAccount)
        || (!actionGenre && !comedyGenre && !romanceGenre
            && !dramaGenre && !horrorGenre && !otherGenre))
    {
        ui->labelErrAllFields->setVisible(true);
        errorsFound = true;
    }

    // ---------- Successful -----------
    if (!errorsFound)
    {
        // add new user
        usernames[usersCount] = username;
        passwords[usersCount] = password;
        ages[usersCount] = age;
        usersCount++;
        // go to the welcome page
        WelcomeWindow* welcomewindow = new WelcomeWindow(username, age);
        welcomewindow->show();
        this->close();
    }
}



