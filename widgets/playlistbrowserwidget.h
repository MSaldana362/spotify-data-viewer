#ifndef PLAYLISTBROWSERWIDGET_H
#define PLAYLISTBROWSERWIDGET_H

#include <QWidget>

namespace Ui {
class PlaylistBrowserWidget;
}

class PlaylistBrowserWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlaylistBrowserWidget(QWidget *parent = nullptr);
    ~PlaylistBrowserWidget();

private:
    Ui::PlaylistBrowserWidget *ui;
};

#endif // PLAYLISTBROWSERWIDGET_H
