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

    _artistsModel = new LibraryArtistsModel(this);
    _artistsModel->setArtists(_library.artists());
    _artistsProxyModel = new QSortFilterProxyModel(this);
    _artistsProxyModel->setSourceModel(_artistsModel);

    ui->tableTracks->setModel(_tracksProxyModel);
    ui->tableAlbums->setModel(_albumsProxyModel);
    ui->tableArtists->setModel(_artistsProxyModel);

    for (QTableView *table : this->findChildren<QTableView*>()) {
        table->horizontalHeader()->setStretchLastSection(true);
        table->setSortingEnabled(true);
    }

    ui->tableTracks->sortByColumn(LibraryTracksModel::ArtistColumn, Qt::AscendingOrder);
    ui->tableAlbums->sortByColumn(LibraryAlbumsModel::ArtistColumn, Qt::AscendingOrder);
    ui->tableArtists->sortByColumn(LibraryArtistsModel::ArtistColumn, Qt::AscendingOrder);
}

LibraryBrowserWidget::~LibraryBrowserWidget()
{
    delete ui;
}
