#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "spotify/spotifylibrary.h"
#include "widgets/databrowserwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DataBrowserWidget* libraryDataWidget = new DataBrowserWidget(ui->tabLibrary);
    ui->tabLibrary->layout()->addWidget(libraryDataWidget);

    DataBrowserWidget* playlistsDataWidget = new DataBrowserWidget(ui->tabPlaylists);
    ui->tabPlaylists->layout()->addWidget(playlistsDataWidget);



    QString filepath = "/home/jiji/Downloads/Spotify Data/Spotify Account Data/YourLibrary.json";

    SpotifyLibrary library;
    library.loadFile(filepath);

    const auto tracks = library.tracks();
    const auto albums = library.albums();
    const auto artists = library.artists();

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

    qDebug() << "Total Albums:" << albums.count();

    qDebug() << "First:";
    qDebug() << "\t" << albums.first()->artist();
    qDebug() << "\t" << albums.first()->name();
    qDebug() << "\t" << albums.first()->uri();

    qDebug() << "Last:";
    qDebug() << "\t" << albums.last()->artist();
    qDebug() << "\t" << albums.last()->name();
    qDebug() << "\t" << albums.last()->uri();

    qDebug() << "Total Artists:" << artists.count();

    qDebug() << "First:";
    qDebug() << "\t" << artists.first()->name();
    qDebug() << "\t" << artists.first()->uri();

    qDebug() << "Last:";
    qDebug() << "\t" << artists.last()->name();
    qDebug() << "\t" << artists.last()->uri();
}

MainWindow::~MainWindow()
{
    delete ui;
}
