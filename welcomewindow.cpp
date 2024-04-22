#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"

WelcomeWindow::WelcomeWindow(QWidget *parent, QString username , int age )
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);
    QString greeting = "Hello " + username + " " + QString::number(age);
    ui->HelloLabel->setText(greeting);
    QPixmap pix (":/images/download.jpeg");
    int w =ui->ImageLabel->width();
    int h = ui->ImageLabel->height();
    ui->ImageLabel->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_LogoutButton_clicked()
{
    hide();
    LoginWindow* loginwindow=new LoginWindow(this);
    loginwindow->show();

}

