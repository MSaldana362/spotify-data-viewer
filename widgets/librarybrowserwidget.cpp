#include "librarybrowserwidget.h"
#include "ui_librarybrowserwidget.h"

LibraryBrowserWidget::LibraryBrowserWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LibraryBrowserWidget)
{
    ui->setupUi(this);

    QString filepath = "/home/jiji/Downloads/Spotify Data/Spotify Account Data/YourLibrary.json";
    _library.loadFile(filepath);

    _tracksModel = new LibraryTracksModel(this);
    _tracksModel->setTracks(_library.tracks());
    _tracksProxyModel = new QSortFilterProxyModel(this);
    _tracksProxyModel->setSourceModel(_tracksModel);

    _albumsModel = new LibraryAlbumsModel(this);
    _albumsModel->setAlbumns(_library.albums());
    _albumsProxyModel = new QSortFilterProxyModel(this);
    _albumsProxyModel->setSourceModel(_albumsModel);

    ui->tableTracks->setModel(_tracksProxyModel);
    ui->tableAlbums->setModel(_albumsProxyModel);

    // ui->tableTracks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableTracks->horizontalHeader()->setStretchLastSection(true);
    ui->tableTracks->setSortingEnabled(true);
    ui->tableTracks->sortByColumn(LibraryTracksModel::ArtistColumn, Qt::AscendingOrder);

    ui->tableAlbums->horizontalHeader()->setStretchLastSection(true);
    ui->tableAlbums->setSortingEnabled(true);
    ui->tableAlbums->sortByColumn(LibraryAlbumsModel::ArtistColumn, Qt::AscendingOrder);
}

LibraryBrowserWidget::~LibraryBrowserWidget()
{
    delete ui;
}
