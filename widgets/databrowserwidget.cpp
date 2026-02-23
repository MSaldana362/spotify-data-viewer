#include "databrowserwidget.h"
#include "ui_databrowserwidget.h"

DataBrowserWidget::DataBrowserWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DataBrowserWidget)
{
    ui->setupUi(this);
}

DataBrowserWidget::~DataBrowserWidget()
{
    delete ui;
}
