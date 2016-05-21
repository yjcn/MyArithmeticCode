#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stu_num->setText("2013012417");
    long double pa[]={0.21,0.22,0.24 ,0.13 ,0.11 ,0.01 ,0.02 ,0.02,0.02,0.02 }; //
    map<char,long double> stu_num;
    for(int i=0;i<10;i++)
    {
        stu_num[char(i+'0')]=pa[i];
    }
    num =new MyArithmeticCode(stu_num);
    map<char,long double> namemap;
    long double namechar[]={0.063,0.0105,0.023,0.035,0.105,0.0203,0.011,0.047,0.055,0.001,0.003,0.029,0.021,0.059,0.0654,0.0175,0.001,0.054,0.052,0.072,0.0203,0.008,0.012,0.002,0.012,0.001,0.2};
    for(int i=0;i<26;i++)
    {
        namemap[char(i+'a')]=namechar[i];
    }
    namemap[' ']=namechar[26];
    name =new MyArithmeticCode(namemap);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete num;
    delete name;   //删除指针
    num=NULL;
    name=NULL;
}

void MainWindow::on_code_clicked()
{
    QString temp;
    temp = ui->stu_num->text();
    QString temp2;
    if(ui->comboBox->currentIndex()==0)
    {
        temp2=QString::fromStdString(num->Code(temp.toStdString()));
    }
    if(ui->comboBox->currentIndex()==1)
    {
        temp2=QString::fromStdString(name->Code(temp.toStdString()));
    }
    ui->plainTextEdit->setPlainText(temp2);
    qDebug()<<temp2;
}

void MainWindow::on_decode_clicked()
{
    QString temp;
    temp=ui->plainTextEdit_2->toPlainText();
    qDebug()<<temp;
    QString temp2;
    if(ui->comboBox->currentIndex()==0)
    {
        temp2 =QString::fromStdString(num->Decode(temp.toStdString()));        
    }
    if(ui->comboBox->currentIndex()==1)
    {
        temp2 =QString::fromStdString(name->Decode(temp.toStdString()));
    }
    ui->result->setText(temp2);
    qDebug()<<"选择框"<<ui->comboBox->currentText();
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    qDebug()<<index;
    if(index==0)
    {
        ui->label->setText("学号");
        ui->stu_num->setText("2013012417");
    }
    if(index==1)
    {
        ui->label->setText("姓名");
        ui->stu_num->setText("yangjin");
    }
}
