#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "engine/calculator_engine.h"
#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>
#include <QClipboard>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Display->setFocusPolicy(Qt::StrongFocus);
    ui->Display->setTextInteractionFlags(Qt::TextSelectableByMouse);

    // Propojím všechna číselná tlačítka na jeden slot

    for (int i = 0; i <= 9; ++i) {
        QString butName = "pushButton_" + QString::number(i);
        QPushButton *button = findChild<QPushButton *>(butName);
        if (button) {
            connect(button, &QPushButton::clicked, this, &MainWindow::numberPressed);
        }
    }

    connect(ui->pushButton_add, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_divide, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_dot, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_factorial, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_modulo, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_multiply, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_power, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_root, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_subtract, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_left, &QPushButton::clicked, this, &MainWindow::operatorPressed);
    connect(ui->pushButton_right, &QPushButton::clicked, this, &MainWindow::operatorPressed);

    connect(ui->pushButton_delete, &QPushButton::clicked, this, &MainWindow::deletePressed);
    connect(ui->pushButton_sign, &QPushButton::clicked, this, &MainWindow::signPressed);
    connect(ui->pushButton_calculate, &QPushButton::clicked, this, &MainWindow::calculatePressed);
    connect(ui->pushButton_help, &QPushButton::clicked, this, &MainWindow::helpPressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberPressed()
{
    // Zjistíme, které tlačítko nás zavolalo
    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();
    QString displayVal = ui->Display->text();

    if ((displayVal == "0") || (displayVal == "0.0")) {
        ui->Display->setText(butVal);
    } else {
        QString newVal = displayVal + butVal;
        ui->Display->setText(newVal);
    }
}

void MainWindow::operatorPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString displayVal = ui->Display->text();
    QString objName = button->objectName();
    QString opSymbol;

    // Mapování názvů tlačítek na symboly
    if (objName == "pushButton_power") opSymbol = "^";
    else if (objName == "pushButton_root") opSymbol = "√";
    else if (objName == "pushButton_factorial") opSymbol = "!";
    else if (objName == "pushButton_add") opSymbol = "+";
    else if (objName == "pushButton_subtract") opSymbol = "-";
    else if (objName == "pushButton_multiply") opSymbol = "*";
    else if (objName == "pushButton_divide") opSymbol = "/";
    else opSymbol = button->text(); // Záloha

    ui->Display->setText(displayVal + opSymbol);
}

void MainWindow::signPressed()
{
    QString text = ui->Display->text();
    if (text == "0" || text.isEmpty()) return;

    int lastOpIndex = -1;

    // Projdu text od konce a hledám poslední operátor
    for (int i = text.length() - 1; i >= 0; --i) {
        QChar c = text[i];

        // Pokud narazím na něco, co není číslo ani tečka, je to operátor
        if (!c.isDigit() && c != '.') {
            // Speciální logika pro mínus:
            // Musím poznat, jestli je to operátor nebo už existující znaménko
            if (c == '-') {
                // Pokud je před mínusem další operátor (nebo nic), je to znaménko
                if (i == 0 || (!text[i-1].isDigit() && text[i-1] != '!' && text[i-1] != ')')) {
                    lastOpIndex = i - 1; // Chceme měnit i s tímto znaménkem
                    break;
                }
            }
            lastOpIndex = i;
            break;
        }
    }

    // Rozdělím text na část před posledním číslem a na číslo samotné
    QString prefix = text.left(lastOpIndex + 1);
    QString lastNumber = text.mid(lastOpIndex + 1);

    if (lastNumber.isEmpty()) return; // Pokud za operátorem ještě není číslo

    // Změním znaménko u odseknutého čísla
    if (lastNumber.startsWith("-")) {
        lastNumber.remove(0, 1);
    } else {
        lastNumber.prepend("-");
    }

    ui->Display->setText(prefix + lastNumber);
}

void MainWindow::deletePressed()
{
    QString text = ui->Display->text();
    text.chop(1);  // smaže poslední znak
    ui->Display->setText(text);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // CTRL+C
    if (event->matches(QKeySequence::Copy)) {
        QApplication::clipboard()->setText(ui->Display->text());
        return;
    }

    // CTRL+V
    if (event->matches(QKeySequence::Paste)) {
        QString text = QApplication::clipboard()->text();
        ui->Display->setText(text);
        return;
    }

    // CTRL+X
    if (event->matches(QKeySequence::Cut)) {
        QApplication::clipboard()->setText(ui->Display->text());
        ui->Display->clear();
        return;
    }

    int key = event->key();

    // ČÍSLA 0–9
    if (key >= Qt::Key_0 && key <= Qt::Key_9) {
        QString butName = "pushButton_" + QString::number(key - Qt::Key_0);
        QPushButton *button = findChild<QPushButton *>(butName);
        if (button) button->click();
    }

    // NUMPAD (klávesnice vpravo)
    else if (key >= Qt::Key_0 && key <= Qt::Key_9) {
        QString butName = "pushButton_" + QString::number(key - Qt::Key_0);
        QPushButton *button = findChild<QPushButton *>(butName);
        if (button) button->click();
    }

    // OPERÁTORY
    else if (key == Qt::Key_Plus) {
        QPushButton *button = findChild<QPushButton *>("pushButton_add");
        if (button) button->click();
    }
    else if (key == Qt::Key_Minus) {
        QPushButton *button = findChild<QPushButton *>("pushButton_subtract");
        if (button) button->click();
    }
    else if (key == Qt::Key_Asterisk) {
        QPushButton *button = findChild<QPushButton *>("pushButton_multiply");
        if (button) button->click();
    }
    else if (key == Qt::Key_Slash) {
        QPushButton *button = findChild<QPushButton *>("pushButton_divide");
        if (button) button->click();
    }

    // ENTER = =
    else if (key == Qt::Key_Return || key == Qt::Key_Enter) {
        QPushButton *button = findChild<QPushButton *>("pushButton_calculate");
        if (button) button->click();
    }

    // BACKSPACE = mazání
    else if (key == Qt::Key_Backspace) {
        QPushButton *button = findChild<QPushButton *>("pushButton_delete");
        if (button) button->click();
    }

    // TEČKA
    else if (key == Qt::Key_Period || key == Qt::Key_Comma) {
        QPushButton *button = findChild<QPushButton *>("pushButton_dot");
        if (button) button->click();
    }
}

void MainWindow::helpPressed()
{
    QMessageBox::information(this, "Help",
        "Keyboard controls:\n"
        "0–9 for numbers\n"
        "+ - * / for operator\n"
        "= for result\n"
        "Root, power, modulo and factorial are accessible only through buttons");
}

void MainWindow::calculatePressed()
{
	std::string input = ui->Display->text().toStdString();

    try
    {
        double result = CalculatorEngine::evaluate(input);
        ui->Display->setText(QString::number(result));
    }
    catch (const std::exception& e)
    {
		QMessageBox::warning(this, "Processing Error", QString::fromUtf8(e.what()));
    }
}

