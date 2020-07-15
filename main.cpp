#include "skeleton.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QTextEdit>

Skeleton::Skeleton(QWidget *parent)
    : QMainWindow(parent) {

  QPixmap newpix("cursor.png");
  QPixmap openpix("shopping-cart.png");
  QPixmap quitpix("key.png");

  QAction *quit = new QAction("&Quit", this);

  QMenu *file;
  file = menuBar()->addMenu("&File");
  file->addAction(quit);

  connect(quit, &QAction::triggered, qApp, &QApplication::quit);

  QToolBar *toolbar = addToolBar("main toolbar");
  toolbar->addAction(QIcon(newpix), "New File");
  toolbar->addAction(QIcon(openpix), "Open File");
  toolbar->addSeparator();

  QAction *quit2 = toolbar->addAction(QIcon(quitpix), "Quit Application");
  connect(quit2, &QAction::triggered, qApp, &QApplication::quit);

  QTextEdit *edit = new QTextEdit(this); // создаём виджет QTextEdit
  setCentralWidget(edit); // помещаем созданный виджет в центр виджета QMainWindow

  statusBar()->showMessage("Ready"); // показываем в нижней панели приложения сообщение "Ready"
}
int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Skeleton window;

  window.resize(350, 250);
  window.setWindowTitle("Application skeleton");
  window.show();

  return app.exec();
}
