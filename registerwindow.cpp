#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "users.h"
#include "welcomewindow.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->ErrorMatchingLabel->setVisible(false);
    ui->ErrorExistingLabel->setVisible(false);
    ui->ErrorCredentialsLabel->setVisible(false);
    ui->ErrorAgeLabel->setVisible(false);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_RegisterButton2_clicked()
{
    ui->ErrorMatchingLabel->setVisible(false);
    ui->ErrorExistingLabel->setVisible(false);
    ui->ErrorCredentialsLabel->setVisible(false);
    ui->ErrorAgeLabel->setVisible(false);

    bool matching=false;
    bool existing=false;
    bool credentials=false;
    bool ageError=false;
    QString UserEnteredRegisterUsername = ui->RegisterUsernameLineEdit->text();
    QString UserEnteredRegisterPassword = ui->RegisterPasswordLineEdit->text();
    QString retypePassword = ui->RetypeRegisterPasswordLineEdit->text();
    QString UserEnteredYear = ui->YearLineEdit->text();


    if ((UserEnteredRegisterUsername.isEmpty()) or (UserEnteredRegisterPassword.isEmpty()) or (retypePassword.isEmpty()) or (UserEnteredYear.isEmpty())) {
        credentials=true;
    }


    int year=UserEnteredYear.toInt();
    int RegisterAge = 2024-year;


    if (RegisterAge < 12) {
        ageError=true;
    }


    if (UserEnteredRegisterPassword != retypePassword) {
        matching=true;
    }


    for (int i = 0; i < usersCount; ++i) {
        if (usernames[i] == UserEnteredRegisterUsername) {
            existing=true;

        }
    }
    if((matching)||(existing)||(credentials)||(ageError)){
        if(matching)
            ui->ErrorMatchingLabel->setVisible(true);

        if(existing)
            ui->ErrorExistingLabel->setVisible(true);
        if(credentials){
            ui->ErrorCredentialsLabel->setVisible(true);
        }
        if(ageError){
            ui->ErrorAgeLabel->setVisible(true);
        }
        return;
    }


    usernames[usersCount-1] = UserEnteredRegisterUsername;
    passwords[usersCount-1] = UserEnteredRegisterPassword;
    ages[usersCount-1] = RegisterAge;
    usersCount++;



    hide();
    WelcomeWindow *welcomewindow = new WelcomeWindow(this, UserEnteredRegisterUsername, RegisterAge);
    welcomewindow->show();

}

