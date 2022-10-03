#include "dialog_cuuho.h"
#include "ui_dialog_cuuho.h"

Dialog_CuuHo::Dialog_CuuHo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CuuHo)
{
    ui->setupUi(this);
}

Dialog_CuuHo::~Dialog_CuuHo()
{
    delete ui;
}
