#ifndef SPOTIFYDATABROWSER_H
#define SPOTIFYDATABROWSER_H

#include <QWidget>

namespace Ui {
class SpotifyDataBrowser;
}

class SpotifyDataBrowser : public QWidget
{
    Q_OBJECT

public:
    explicit SpotifyDataBrowser(QWidget *parent = nullptr);
    ~SpotifyDataBrowser();

private:
    Ui::SpotifyDataBrowser *ui;
};

#endif // SPOTIFYDATABROWSER_H
