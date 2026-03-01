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

    ui->tableTracks->setModel(_tracksProxyModel);
    // ui->tableTracks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableTracks->horizontalHeader()->setStretchLastSection(true);
    ui->tableTracks->setSortingEnabled(true);
    ui->tableTracks->sortByColumn(LibraryTracksModel::ArtistColumn, Qt::AscendingOrder);
}

LibraryBrowserWidget::~LibraryBrowserWidget()
{
    delete ui;
}
