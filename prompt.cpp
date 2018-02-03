#include "prompt.h"
#include "ui_prompt.h"

Prompt::Prompt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prompt)
{
    ui->setupUi(this);
}

Prompt::~Prompt()
{
    delete ui;
}

void Prompt::on_pushButton_clicked()
{
    system("reboot");
}

void Prompt::on_pushButton_2_clicked()
{
    QApplication::quit();
}
