#include "spotifydatabrowser.h"
#include "ui_spotifydatabrowser.h"

SpotifyDataBrowser::SpotifyDataBrowser(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SpotifyDataBrowser)
{
    ui->setupUi(this);
}

SpotifyDataBrowser::~SpotifyDataBrowser()
{
    delete ui;
}
