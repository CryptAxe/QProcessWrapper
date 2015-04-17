/*
 * This file exists as an example to demonstrate the use of this class.
 * The only files that you will need to include in your project are:
 * qprocesswrapper.cpp
 * qprocesswrapper.h
 *
 * This example will run whatever binary exists at the path specified
 * by the QString "binaryPath" with the arguments in "binaryArguments"
 *
 * ~CryptAxe
 */


#include <QCoreApplication>

#include "qprocesswrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString binaryPath = ""; // Set the binary to be launched
    QString binaryArguments = ""; // Set the arguments for the binary
    
    return a.exec();
}
