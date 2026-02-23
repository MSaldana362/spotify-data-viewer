#ifndef SPOTIFYALBUM_H
#define SPOTIFYALBUM_H

#include <QJsonObject>
#include <QObject>

class SpotifyAlbum : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyAlbum(QObject *parent = nullptr);

    void fromLibraryJson(const QJsonObject& json);

    QString artist() const { return _artist; }
    QString name() const { return _name; }
    QString uri() const { return _uri; }

private:
    QString _artist;
    QString _name;
    QString _uri;

signals:
};

#endif // SPOTIFYALBUM_H
