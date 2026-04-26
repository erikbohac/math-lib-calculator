#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui
{
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

	public:
		explicit MainWindow(QWidget *parent = nullptr);
		~MainWindow() override;

	private slots:
    	void numberPressed();    // Pro čísla 0-9
    	void operatorPressed();  // Pro +, -, *...
    	void signPressed();      // Pro +/-
    	void calculatePressed(); // Pro výpočet
		void deletePressed();    // Pro mazání
		void helpPressed();      // Pro Help

	protected:
    	void keyPressEvent(QKeyEvent *event) override;

	private:
		Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
