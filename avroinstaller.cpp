#include "avroinstaller.h"
#include "ui_avroinstaller.h"
#include "prompt.h"
DWIDGET_USE_NAMESPACE
AvroInstaller::AvroInstaller(DMainWindow *parent) :
    QMainWindow(parent),
    ui(new Ui::AvroInstaller)
{
    ui->setupUi(this);
    ui->pushButton->hide();
    //ui->pushButton_2->hide();
}
QString password;
QString command;
AvroInstaller::~AvroInstaller()
{
    delete ui;
}

void AvroInstaller::on_pushButton_clicked()
{
    ui->pushButton->hide();
    //ui->pushButton_2->hide();
    ui->label->show();
    command = "echo '"+password+"' | sudo -S apt update && echo '"+password+"' | sudo -S apt install ibus ibus-m17n dconf-editor wget -y && cd $Home && echo 'export GTK_IM_MODULE=ibus' >> .bashrc && echo 'export XMODIFIERS=@im=ibus' >> .bashrc && echo 'export QT_IM_MODULE=ibus' >> .bashrc && echo 'ibus-daemon -drx' >> .bashrc && export GTK_IM_MODULE=ibus && export XMODIFIERS=@im=ibus && export QT_IM_MODULE=ibus && wget https://github.com/maateen/avro/releases/download/v2.1/avro_2.1-3_all.deb && echo '"+password+"' | sudo -S dpkg -i avro_2.1-3_all.deb && dconf write /desktop/ibus/general/enable-by-default true && dconf write /desktop/ibus/general/use-system-keyboard-layout true && wget --no-check-certificate https://fahadahammed.com/extras/fonts/font.sh -O font.sh;chmod +x font.sh;bash font.sh;rm font.sh && im-config -n ibus";
    system(command.toStdString().c_str());
    Prompt *prompt = new Prompt();
    prompt->show();
    ui->label->setText("                                   Installing avro please wait");
}

void AvroInstaller::on_pushButton_3_clicked()
{
    if(ui->textEdit->text() != ""){
    ui->pushButton->show();
    //ui->pushButton_2->show();
    ui->pushButton_3->hide();
    ui->label->hide();
    ui->textEdit->hide();
    password = ui->textEdit->text();
    }else{
        ui->label->setText("Password must not be empty. Please enter your root password.");
    }
}
