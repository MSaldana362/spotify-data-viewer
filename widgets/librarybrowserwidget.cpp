#include "librarybrowserwidget.h"
#include "ui_librarybrowserwidget.h"

LibraryBrowserWidget::LibraryBrowserWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibraryBrowserWidget)
{
    ui->setupUi(this);

    _tracksModel = new LibraryTracksModel(this);
    ui->tableTracks->setModel(_tracksModel);
}

LibraryBrowserWidget::~LibraryBrowserWidget()
{
    delete ui;
}
