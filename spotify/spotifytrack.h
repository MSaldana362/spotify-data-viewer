#ifndef SPOTIFYTRACK_H
#define SPOTIFYTRACK_H

#include <QJsonObject>
#include <QObject>

class SpotifyTrack : public QObject
{
    Q_OBJECT
public:
    explicit SpotifyTrack(QObject *parent = nullptr);

    void fromLibraryJson(const QJsonObject& json);
    void fromPlaylistJson(const QJsonObject& json);

    QString artist() const { return _artist; }
    QString album() const { return _album; }
    QString name() const { return _name; }
    QString uri() const { return _uri; }

private:
    QString _artist;
    QString _album;
    QString _name;
    QString _uri;

signals:
};

#endif // SPOTIFYTRACK_H
