
#include <iostream>
#include "ScannerFunctions.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>


class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        scanButton = new QPushButton("Scan directory", this);
        layout->addWidget(scanButton);

        reportButton = new QPushButton("Report file", this);
        layout->addWidget(reportButton);

        clearButton = new QPushButton("Clear base", this);
        layout->addWidget(clearButton);

        connect(scanButton, &QPushButton::clicked, this, &MyWidget::scanClicked);
        connect(reportButton, &QPushButton::clicked, this, &MyWidget::reportClicked);
        connect(clearButton, &QPushButton::clicked, this, &MyWidget::clearClicked);

    }

private slots:

    void scanClicked() {
        QString filePath = QFileDialog::getExistingDirectory(this, "Выберите директорию", "",
                                                             QFileDialog::ShowDirsOnly);
        if (!filePath.isEmpty()) {
            AVBase Base("AVBase.txt");
            QString scanningResult = QString::fromStdString(ScanDirectory(filePath.toStdString(), Base));
            if (!scanningResult.isEmpty()) {
                QMessageBox::warning(this, "Scan finished", scanningResult);
            } else {
                QMessageBox::information(this, "Scan finished", "There is no malware files");
            }
        } else {
            QMessageBox::warning(this, "No Directory Entered", "You did not choose a directory!");
        }
    }

    void reportClicked() {
        QString password = QInputDialog::getText(this, "Access verification", "Enter administrator password:");
        if (password == "123456") {
            QMessageBox::information(this, "Access allowed", "Right password!");
            QString filePath = QFileDialog::getOpenFileName(this, "Choose File", "", "Все файлы (*.*)");
            if (!filePath.isEmpty()) {
                Signature newSignature(filePath.toStdString());
                newSignature.WriteToBase("AVBase.txt");
                QMessageBox::information(this, "File added", "File" + filePath + " was added to base.");
            } else {
                QMessageBox::warning(this, "No File Entered", "You did not choose a file!");
            }
        } else {
            QMessageBox::warning(this, "Access denied", "Wrong password!");
        }
    }

    void clearClicked() {
        QString password = QInputDialog::getText(this, "Access verification", "Enter administrator password:");
        if (password == "123456") {
            QMessageBox::information(this, "Access allowed", "Right password!");
            ClearBase("AVBase.txt");
            QMessageBox::information(this, "Clear base", "Base was cleared.");
        } else {
            QMessageBox::warning(this, "Access denied", "Wrong password!");
        }
    }

private:
    QPushButton *scanButton;
    QPushButton *reportButton;
    QPushButton *clearButton;

};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWidget widget;
    widget.resize(300, 100);
    widget.show();

    return app.exec();
}