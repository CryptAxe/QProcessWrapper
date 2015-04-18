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
  std::cout << "starting\n";
  QCoreApplication a(argc, argv);

  QString binaryPath = "/home/cryptaxe/AtomicAlpha/ATOMIC/src/cpuminer/minerd"; // Set the binary to be launched
  QStringList binaryArguments;
  binaryArguments.push_back("-o");
  binaryArguments.push_back("54.77.145.190:9332");

  QProcessWrapper pWrapper(binaryPath, binaryArguments);

  return a.exec();
}
