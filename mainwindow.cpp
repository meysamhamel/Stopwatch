/*
 * Authors:
 *   Meysam Hamel
 *   Eric Miramontes
 * Assignment:
 *   A5 Stopwatch
 */


#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize display
    this->setWindowTitle("Stopwatch");
    ui->minDisplay->display("00");
    ui->secDisplay->display("00");
    ui->hunDisplay->display("00");

    // Connect signals and slots between model and view
    connect(&stopwatchM, SIGNAL(currentTime(QString,QString,QString)), this, SLOT(updateDisplay(QString,QString,QString)));
    connect(this, SIGNAL(startClicked()), &stopwatchM, SLOT(startClock()));
    connect(this, SIGNAL(pauseClicked()), &stopwatchM, SLOT(pauseClock()));
    connect(this, SIGNAL(restartClicked()), &stopwatchM, SLOT(restartClock()));
    connect(this, SIGNAL(resetClicked()), &stopwatchM, SLOT(resetClock()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

// When this method is signaled the values in the lcd objects are updated.
void MainWindow::updateDisplay(QString min, QString sec, QString hun)
{
    ui->minDisplay->display(min);
    ui->secDisplay->display(sec);
    ui->hunDisplay->display(hun);
}

// Change text in start/pause button depending on what is currently displayed.
void MainWindow::on_startBut_clicked()
{
    if(ui->startBut->text() == "Start")
    {
        // Display "Pause" (stopwatch is running right now)
        ui->startBut->setText("Pause");
        emit startClicked(); // Start model
    }
    else if(ui->startBut->text() == "Pause")
    {
        // Display "Restart" (stopwatch has been paused)
        ui->startBut->setText("Restart");
        emit pauseClicked(); // Pause model
    }
    else
    {
        // Display "Pause" (stopwatch has been restarted)
        ui->startBut->setText("Pause");
        emit restartClicked(); // Restart model
    }
}

// When the stopwatch is reset, make sure text on start/pause button says "Start".
void MainWindow::on_resetBut_clicked()
{
    ui->startBut->setText("Start");
    emit resetClicked(); // Reset model.
}
