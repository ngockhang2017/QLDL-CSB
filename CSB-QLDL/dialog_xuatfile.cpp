#include "dialog_xuatfile.h"
#include "ui_dialog_xuatfile.h"

Dialog_XuatFile::Dialog_XuatFile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_XuatFile)
{
    ui->setupUi(this);
}

Dialog_XuatFile::~Dialog_XuatFile()
{
    delete ui;
}

void Dialog_XuatFile::on_pushButton_clicked()  //ok click
{
    this->status = true;
    this->NgayDau = ui->dateEdit->date();
    this->NgayCuoi = ui->dateEdit_2->date();

    this->close();
}

void Dialog_XuatFile::on_pushButton_2_clicked()  //cacel click
{
    this->status = false;
    this->close();
}
