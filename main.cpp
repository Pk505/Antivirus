

//int main() {
//    Signature testSignature("/home/vboxuser/TEST_FILESYSTEM/Directory/FILE1.py");
//   // Signature testSignature2("C:\\TEST FILE SYSTEM FOR ANTIVIRUS\\Directory 1\\File 1.3.exe");
//    //bool aa = testSignature == testSignature2;
//    ClearBase("AVBase.txt");
//    testSignature.WriteToBase("AVBase.txt");
//   // testSignature2.WriteToBase("AVBase.txt");
//    AVBase Base("AVBase.txt");
//    Base.Print();
//    ScanDirectory("/home/vboxuser/TEST_FILESYSTEM", Base);
//    return 0;
//}
#include <iostream>
#include "ScannerFunctions.h"
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
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
            }
            else{
                QMessageBox::information(this, "Scan finished", "There is no malware files");
            }
        } else {
            QMessageBox::warning(this, "No Directory Entered", "You did not choose a directory!");
        }
    }

    void reportClicked() {
        QString filePath = QFileDialog::getOpenFileName(this, "Choose File", "", "Все файлы (*.*)");

        if (!filePath.isEmpty()) {
            Signature newSignature(filePath.toStdString());
            newSignature.WriteToBase("AVBase.txt");
            QMessageBox::information(this, "File added", "File" + filePath + " was added to base.");
        } else {
            QMessageBox::warning(this, "No File Entered", "You did not choose a file!");
        }
    }

    void clearClicked() {
        ClearBase("AVBase.txt");
        QMessageBox::information(this, "Clear base", "Base was cleared.");
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