#include "playlistbrowserwidget.h"
#include "ui_playlistbrowserwidget.h"

PlaylistBrowserWidget::PlaylistBrowserWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlaylistBrowserWidget)
{
    ui->setupUi(this);
}

PlaylistBrowserWidget::~PlaylistBrowserWidget()
{
    delete ui;
}
