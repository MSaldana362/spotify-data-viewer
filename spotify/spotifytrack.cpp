#include "spotifytrack.h"

SpotifyTrack::SpotifyTrack(QObject *parent)
    : QObject{parent}
{}

void SpotifyTrack::fromLibraryJson(const QJsonObject &json)
{
    _artist = json["artist"].toString();
    _album = json["album"].toString();
    _name = json["track"].toString();
    _uri = json["uri"].toString();
}

void SpotifyTrack::fromPlaylistJson(const QJsonObject &json)
{
    _artist = json["artistName"].toString();
    _album = json["albumName"].toString();
    _name = json["trackName"].toString();
    _uri = json["trackUri"].toString();
}
