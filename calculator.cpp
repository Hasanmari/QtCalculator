#include "calculator.h"
#include "ui_calculator.h"
double calcval = 0.0 ;
bool divTriger =false ;
bool multTriger =false ;
bool addTriger =false ;
bool subTriger =false ;
qint32 Memory ;
Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->Display->setText(QString::number(calcval));
    QPushButton *numbutton[10];
    for (int i = 0 ; i <10 ; ++i ){
        QString butname = "Button_" + QString::number(i);
        numbutton[i] = Calculator::findChild<QPushButton *>(butname);
        connect(numbutton[i],SIGNAL(released()),this ,SLOT(Numpressed()));
    }
    connect(ui->Add,SIGNAL(released()),this ,SLOT(Mathpressed()));
    connect(ui->Subtract,SIGNAL(released()),this ,SLOT(Mathpressed()));
    connect(ui->Devid,SIGNAL(released()),this ,SLOT(Mathpressed()));
    connect(ui->Multiply,SIGNAL(released()),this ,SLOT(Mathpressed()));
    connect(ui->Equal,SIGNAL(released()),this ,SLOT(Equalpressed()));
    connect(ui->Clear,SIGNAL(released()),this ,SLOT(Clearpressed()));
    connect(ui->Change_sign,SIGNAL(released()),this ,SLOT(SignChangepressed()));
    connect(ui->MemAdd,SIGNAL(released()),this ,SLOT(MemoryAddPressed()));
    connect(ui->MemGet,SIGNAL(released()),this ,SLOT(MemoryGetPressed()));
    connect(ui->subtract,SIGNAL(released()),this ,SLOT(MemorySubtrPressed()));
}

Calculator::~Calculator()
{
    delete ui;
}

//methods
void Calculator::Numpressed(){
 QPushButton *button = (QPushButton*)sender();
 QString butVal = button->text();
 QString displayval = ui->Display->text();
  if ((displayval.toDouble() == 0)||(displayval.toDouble() == 0.0))
      ui->Display->setText(butVal);
  else{
      QString newval = displayval+butVal;
      double dbnewval = newval.toDouble();
      ui->Display->setText(QString::number(dbnewval,'g',16));

}

}

void Calculator::Mathpressed(){
   divTriger = false ;
   multTriger= false ;
   addTriger= false;
   subTriger = false ;

   QString dispval = ui->Display->text();
   calcval = dispval.toDouble();
   QPushButton *Button = (QPushButton*) sender();
   QString butval = Button->text();
   if (QString::compare(butval,"/",Qt::CaseInsensitive)== 0){
       divTriger = true ;}
   else if (QString::compare(butval,"*",Qt::CaseInsensitive)== 0){
       multTriger = true ;}
   else if (QString::compare(butval,"+",Qt::CaseInsensitive)== 0){
       addTriger = true ;}
   else {
       subTriger = true ;}
   ui->Display->setText("");
}

void Calculator::Equalpressed(){
    double Sultion = 0.0 ;
    QString displayval = ui->Display->text();
    double dbdisplayval = displayval.toDouble();
    if (divTriger || multTriger || addTriger || subTriger){
        if (addTriger){
            Sultion = calcval+dbdisplayval ;
        }else if (subTriger){
            Sultion = calcval - dbdisplayval ;
        }else if(multTriger){
            Sultion = calcval * dbdisplayval ;
        }else {
            Sultion = calcval / dbdisplayval ;
    }
   }
    ui->Display->setText(QString::number(Sultion));
}

void Calculator::Clearpressed(){
    ui->Display->setText("0");
}

void Calculator::SignChangepressed(){
  qint32 valu = ui->Display->text().toInt() ;

 if (valu == 0 ) ui->Display->setText("0.0");

 valu += -valu*2 ;
  QString temp ;
  temp.setNum(valu);
  ui->Display->setText(temp);

}

void Calculator::MemoryAddPressed(){
 Memory+= ui->Display->text().toInt();

 Clearpressed();
}

void Calculator::MemoryGetPressed(){
 QString temp ;
 temp.setNum(Memory);
 ui->Display->setText(temp) ;
}

void Calculator::MemorySubtrPressed(){
 Memory -=ui->Display->text().toInt();
 Clearpressed();
}
