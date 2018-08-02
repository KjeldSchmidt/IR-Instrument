#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QSound>
#include <QSerialPort>
#include <QSerialPortInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    QSerialPort serial;
    serial.setPortName("/dev/ttyUSB0");
    serial.setBaudRate(9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if ( serial.open( QSerialPort::ReadOnly ) ) {
        while ( true ) {
            while (!serial.canReadLine() ) {
                serial.waitForReadyRead(-1);
            }

            while ( serial.canReadLine() ) {
                std::cout << serial.readLine().toStdString() << std::flush;
            }
        }
    } else {
        std::cout << "Serial connection could not be opened" << std::endl;
    }

    QSound::play(":/sounds/strings/D5.wav");

    return a.exec();
}
