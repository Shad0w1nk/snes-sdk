#include "about.moc"
AboutWindow *aboutWindow;

AboutWindow::AboutWindow() {
  setObjectName("about-window");
  setWindowTitle("About bsnes ...");
  setGeometryString(&config().geometry.aboutWindow);
  application.windowList.append(this);

  layout = new QVBoxLayout;
  layout->setSizeConstraint(QLayout::SetFixedSize);
  layout->setMargin(Style::WindowMargin);
  layout->setSpacing(Style::WidgetSpacing);
  setLayout(layout);

  logo = new Logo;
  logo->setFixedSize(600, 106);
  layout->addWidget(logo);

  info = new QLabel(string() <<
    "<table width='100%'><tr>"
    "<td align='left'><b>Version: </b>" << bsnesVersion << "</td>"
    "<td align='center'><b>Author: </b>byuu</td>"
    "<td align='right'><b>Homepage: </b><a href='http://byuu.org'>http://byuu.org</a></td>"
    "</tr></table>"
  );
  layout->addWidget(info);
}

void AboutWindow::Logo::paintEvent(QPaintEvent*) {
  QPainter painter(this);
  QPixmap pixmap(":/logo.png");
  painter.drawPixmap(0, 0, pixmap);
}
