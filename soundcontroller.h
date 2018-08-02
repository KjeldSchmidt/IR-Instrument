#ifndef SOUNDCONTROLLER_H
#define SOUNDCONTROLLER_H

#include <QSoundEffect>

class SoundController {

public:
    enum Key{ C, D };

    Key key;

    SoundController( SoundController::Key key );
    void play_tones(float* volumes);


private:
    QSoundEffect effect1;
    QSoundEffect effect2;
    QSoundEffect effect3;
    QSoundEffect effect4;
    QSoundEffect effect5;
    QSoundEffect effect6;
    QSoundEffect effect7;

    void load_tones();


};

#endif // SOUNDCONTROLLER_H
