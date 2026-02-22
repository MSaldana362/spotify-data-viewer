#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "spotifylibrary.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString filepath = "/home/jiji/Downloads/Spotify Data/Spotify Account Data/YourLibrary.json";

    SpotifyLibrary library;
    library.loadFile(filepath);

    const auto tracks = library.tracks();

    qDebug() << "Total Tracks:" << tracks.count();

    qDebug() << "First:";
    qDebug() << "\t" << tracks.first()->album();
    qDebug() << "\t" << tracks.first()->artist();
    qDebug() << "\t" << tracks.first()->name();
    qDebug() << "\t" << tracks.first()->uri();

    qDebug() << "Last:";
    qDebug() << "\t" << tracks.last()->album();
    qDebug() << "\t" << tracks.last()->artist();
    qDebug() << "\t" << tracks.last()->name();
    qDebug() << "\t" << tracks.last()->uri();
}

MainWindow::~MainWindow()
{
    delete ui;
}
