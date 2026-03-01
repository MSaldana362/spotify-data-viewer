#ifndef LIBRARYBROWSERWIDGET_H
#define LIBRARYBROWSERWIDGET_H

#include <QWidget>

#include "../spotify/spotifylibrary.h"
#include "../widgets/librarytracksmodel.h"

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
};

#endif // LIBRARYBROWSERWIDGET_H
