#include "toolbar.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>

Toolbar::Toolbar(QWidget *parent)
    : QMainWindow(parent) {

  QPixmap newpix("cursor.png");
  QPixmap openpix("shopping-cart.png");
  QPixmap quitpix("key.png");

  // Устанавливаем указатель на созданную панель инструментов
  QToolBar *toolbar = addToolBar("main toolbar");

  toolbar->addAction(QIcon(newpix), "New File"); // добавляем действие "New File" на панель инструментов
  toolbar->addAction(QIcon(openpix), "Open File"); // добавляем действие "Open File" на панель инструментов
  toolbar->addSeparator(); // добавляем разделитель на панель инструментов
  QAction *quit = toolbar->addAction(QIcon(quitpix), "Quit Application"); // добавляем действие "Quit" на панель инструментов

  connect(quit, &QAction::triggered, qApp, &QApplication::quit);
}
int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  Toolbar window;

  window.resize(300, 200);
  window.setWindowTitle("QToolBar");
  window.show();

  return app.exec();
}
