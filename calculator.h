#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private:
    Ui::Calculator *ui;
private slots:
    void Numpressed();
        void Mathpressed();
        void Equalpressed();
        void SignChangepressed();
        void Clearpressed();
        void MemoryAddPressed();
        void MemoryGetPressed();
        void MemorySubtrPressed();
};
#endif // CALCULATOR_H
