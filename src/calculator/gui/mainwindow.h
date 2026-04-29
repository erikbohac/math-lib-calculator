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

/**
 * @class MainWindow
 * @brief Main window of the calculator application.
 *
 * This class handles the user interface logic and processes
 * input from both buttons and keyboard.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructs the main window.
     * @param parent Pointer to the parent widget.
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroys the main window.
     */
    ~MainWindow() override;

private slots:
    /**
     * @brief Handles numeric button presses (0–9).
     */
    void numberPressed();

    /**
     * @brief Handles operator button presses (+, -, *, /, etc.).
     */
    void operatorPressed();

    /**
     * @brief Toggles the sign of the current value (+/-).
     */
    void signPressed();

    /**
     * @brief Executes the calculation.
     */
    void calculatePressed();

    /**
     * @brief Deletes the current input or the last character.
     */
    void deletePressed();

    /**
     * @brief Displays the help dialog.
     */
    void helpPressed();

protected:
    /**
     * @brief Handles key press events.
     * @param event Pointer to the key event.
     */
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui; ///< Pointer to the user interface
};

#endif // MAINWINDOW_H
