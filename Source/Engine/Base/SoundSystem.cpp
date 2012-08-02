/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  SoundSystem.h:  Sound Base class

  Copyright (c) 2001-2007, Hugh Bailey
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
      * Redistributions of source code must retain the above copyright
        notice, this list of conditions and the following disclaimer.
      * Redistributions in binary form must reproduce the above copyright
        notice, this list of conditions and the following disclaimer in the
        documentation and/or other materials provided with the distribution.
      * The name of Hugh Bailey may not be used to endorse or promote
        products derived from this software without specific prior written
        permission.

  THIS SOFTWARE IS PROVIDED BY HUGH BAILEY "AS IS" AND ANY
  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED.  IN NO EVENT SHALL HUGH BAILEY BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUISNESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

  Blah blah blah blah.  To the fricken' code already!
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


#include "Base.h"

DefineAbstractClass(SoundStream);
DefineAbstractClass(Sound);

DefineAbstractClass(SoundSystem);


Sound *SoundSystem::CreateSoundFromFile(TSTR lpFile, BOOL b3DSound)
{
    traceIn(SoundSystem::CreateSoundFromFile);

    XFile file;
    Sound *retSound = NULL;

    if(file.Open(lpFile, XFILE_READ, XFILE_OPENEXISTING))
    {
        DWORD dwFileSize = file.GetFileSize();
        LPBYTE lpData = (LPBYTE)Allocate(dwFileSize);
        file.Read(lpData, dwFileSize);

        retSound = SS->CreateSound(lpData, b3DSound);

        Free(lpData);
        file.Close();
    }
    else
        Log(TEXT("Could not create sound from file \"%s\""), lpFile);

    return retSound;

    traceOut;
}

