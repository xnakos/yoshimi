/*
    JackClient.h

    Copyright 2009-2011, Alan Calvert

    This file is part of yoshimi, which is free software: you can
    redistribute it and/or modify it under the terms of the GNU General
    Public License as published by the Free Software Foundation, either
    version 2 of the License, or (at your option) any later version.

    yoshimi is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with yoshimi.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef JACK_CLIENT_H
#define JACK_CLIENT_H

#include <string>

using namespace std;

#include "MusicIO/MusicClient.h"
#include "MusicIO/JackEngine.h"

class SynthEngine;

class JackClient : public MusicClient
{
    public:
        JackClient(SynthEngine *_synth) : MusicClient(_synth), jackEngine(_synth) { }
        ~JackClient() { Close(); }

        bool openAudio(void);
        bool openMidi(void);
        bool Start(void) { return jackEngine.Start(); }
        void Close(void) { jackEngine.Close(); }
        unsigned int getSamplerate(void) { return jackEngine.getSamplerate(); }
        int getBuffersize(void) { return jackEngine.getBuffersize(); }
        string audioClientName(void) { return jackEngine.clientName(); }
        string midiClientName(void) { return jackEngine.clientName(); }
        int audioClientId(void) { return jackEngine.clientId(); }
        int midiClientId(void) { return jackEngine.clientId(); }
        virtual void registerAudioPort(int portnum) { jackEngine.registerJackPort(portnum);}

    private:
        JackEngine jackEngine;
};

#endif
