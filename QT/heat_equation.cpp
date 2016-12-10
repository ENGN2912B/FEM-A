#include <QtCore/QFile>
#include <QtCore/QTextStream>
#include "heat_equation.h"
#include "ui_heat_equation.h"
#include <QTextStream>


heat_equation::heat_equation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::heat_equation)
{
    ui->setupUi(this);
}

heat_equation::~heat_equation()
{
    delete ui;
}

void heat_equation::on_goButton_clicked()
{
    QTextStream out(stdout);
    QString dimension = ui->comboBox_dim->currentText();
    out<<"dimension out: "<<dimension<<endl;

    QString num_scheme = ui->comboBox_num_scheme->currentText();
    out<<"numerical scheme: "<<num_scheme<<endl;
    QString time_step = ui->time_step->text();
    out<<time_step<<endl;
    QString space_step = ui->space_step->text();
    out<<space_step<<endl;
    //QString space_step_y = ui->space_step_y->text();
    //out<<space_step_y<<endl;
    QString total_time = ui->total_time->text();
    out<<total_time<<endl;
    QString output_file_name = ui->output_file_name->text();
    out<<output_file_name<<endl;

    QString filename="C:\\Users\\Daegyoum\\Documents\\test4_Qt\\parameters.txt";
    QFile file( filename );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );
        stream << dimension<<' '<<num_scheme<<' '<<time_step<<' '<<space_step<<' '<<total_time<<' '<<output_file_name<< endl;
        //stream << dimension <<' '<<num_scheme<<' '<<time_step<<' '<<space_step_x<<' '<<space_step_y<<' '<<total_time<<' '<<output_file_name<< endl;
        //out<<output_file_name<<endl;
    }

}

void heat_equation::on_comboBox_dim_activated(const QString &arg1)
{
    //QTextStream out(stdout);
    //out<<"dimension: "<<arg1<<endl;
    if(arg1 =="3"){
        ui->comboBox_num_scheme->addItem("Euler");
    }
    else if(arg1 == "1" || arg1 == "2"){
        ui->comboBox_num_scheme->addItem("Euler");
        ui->comboBox_num_scheme->addItem("Backward-Euler");
        ui->comboBox_num_scheme->addItem("Crank-Nicolson");
        ui->comboBox_num_scheme->addItem("DuFort-Frankel");
        ui->comboBox_num_scheme->addItem("Finite-Element");
    }

}

