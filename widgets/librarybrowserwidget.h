#ifndef LIBRARYBROWSERWIDGET_H
#define LIBRARYBROWSERWIDGET_H

#include <QWidget>
#include <QSortFilterProxyModel>

#include "../spotify/spotifylibrary.h"
#include "../widgets/librarytracksmodel.h"
#include "../widgets/libraryalbumsmodel.h"

namespace Ui {
class LibraryBrowserWidget;
}

class LibraryBrowserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LibraryBrowserWidget(QWidget *parent = nullptr);
    ~LibraryBrowserWidget();

private:
    Ui::LibraryBrowserWidget *ui;

    SpotifyLibrary _library;

    LibraryTracksModel* _tracksModel;
    QSortFilterProxyModel* _tracksProxyModel;

    LibraryAlbumsModel* _albumsModel;
    QSortFilterProxyModel* _albumsProxyModel;
};

#endif // LIBRARYBROWSERWIDGET_H
