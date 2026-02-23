#ifndef SPOTIFYARTIST_H
#define SPOTIFYARTIST_H

#include <QJsonObject>
#include <QObject>

class SpotifyArtist : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyArtist(QObject *parent = nullptr);

    void fromLibraryJson(const QJsonObject& json);

    QString name() const { return _name; }
    QString uri() const { return _uri; }

private:
    QString _name;
    QString _uri;

signals:
};

#endif // SPOTIFYARTIST_H
