#include "mainwindow.h"
#include <iostream>
#include <QApplication>
#include <QSoundEffect>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <arduinoparser.h>
#include <soundcontroller.h>

float volumes[7];

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SoundController controller( SoundController::C );



    QSerialPort serial;
    QString portName = "/dev/" + QSerialPortInfo::availablePorts().first().portName();
    std::cout << portName.toStdString() << std::endl;
    serial.setPortName( portName );
    serial.setBaudRate(9600);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if ( serial.open( QSerialPort::ReadOnly ) ) {
        std::cout << "Serial connection established" << std::endl;
        while ( true ) {
            while ( !serial.canReadLine() ) {
                serial.waitForReadyRead( -1 );
            }

            while ( serial.canReadLine() ) {
                std::string line = serial.readLine().toStdString();
                ArduinoParser::parse_volumes( line, volumes );
                controller.play_tones( volumes );
            }
        }
    } else {
        std::cout << "Serial connection could not be opened" << std::endl;
    }
    return a.exec();
}
