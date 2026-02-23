#ifndef DATABROWSERWIDGET_H
#define DATABROWSERWIDGET_H

#include <QWidget>

namespace Ui {
class DataBrowserWidget;
}

class DataBrowserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DataBrowserWidget(QWidget *parent = nullptr);
    ~DataBrowserWidget();

private:
    Ui::DataBrowserWidget *ui;
};

#endif // DATABROWSERWIDGET_H
