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


    QString UserEnteredRegisterUsername = ui->RegisterUsernameLineEdit->text();
    QString UserEnteredRegisterPassword = ui->RegisterPasswordLineEdit->text();
    QString retypePassword = ui->RetypeRegisterPasswordLineEdit->text();
    QString UserEnteredYear = ui->YearLineEdit->text();


    if ((UserEnteredRegisterUsername.isEmpty()) or (UserEnteredRegisterPassword.isEmpty()) or (retypePassword.isEmpty()) or (UserEnteredYear.isEmpty())) {
        ui->ErrorCredentialsLabel->setVisible(true);
        return;
    }


    int year=UserEnteredYear.toInt();
    int RegisterAge = 2024-year;


    if (RegisterAge < 12) {
        ui->ErrorAgeLabel->setVisible(true);
        return;
    }

    // Check if the entered password is not equal the retyped password
    if (UserEnteredRegisterPassword != retypePassword) {
        ui->ErrorMatchingLabel->setVisible(true);
        return;
    }

    // Check if the entered username is already existing in the usernames array
    for (int i = 0; i < usersCount; ++i) {
        if (usernames[i] == UserEnteredRegisterUsername) {
            ui->ErrorExistingLabel->setVisible(true);
            return;
        }
    }

    // Add the new user to the global arrays
    usernames[usersCount-1] = UserEnteredRegisterUsername;
    passwords[usersCount-1] = UserEnteredRegisterPassword;
    ages[usersCount-1] = RegisterAge;
    usersCount++;



    hide();
    WelcomeWindow *welcomewindow = new WelcomeWindow(this, UserEnteredRegisterUsername, RegisterAge);
    welcomewindow->show();

}

