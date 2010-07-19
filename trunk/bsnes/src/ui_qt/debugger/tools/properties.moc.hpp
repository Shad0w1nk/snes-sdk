class PropertiesWidget : public QWidget {
  Q_OBJECT

public:
  QVBoxLayout *layout;
  QTreeWidget *list;

  PropertiesWidget(SNES::ChipDebugger &object);

public slots:
  void refresh();

private:
  SNES::ChipDebugger &object;
};

class PropertiesViewer : public Window {
  Q_OBJECT

public:
  QVBoxLayout *layout;
  QTabWidget *tabWidget;
  QHBoxLayout *controlLayout;
  QCheckBox *autoUpdateBox;
  QPushButton *refreshButton;

  void autoUpdate();
  PropertiesViewer();

public slots:
  void refresh();
  void show();
};

extern PropertiesWidget *cpuPropertiesTab;
extern PropertiesWidget *smpPropertiesTab;
extern PropertiesWidget *ppuPropertiesTab;
extern PropertiesWidget *dspPropertiesTab;
extern PropertiesViewer *propertiesViewer;
