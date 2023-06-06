/*
 * Copyright © 2018-2023 Synthstrom Audible Limited
 *
 * This file is part of The Synthstrom Audible Deluge Firmware.
 *
 * The Synthstrom Audible Deluge Firmware is free software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "MenuItemSampleLoopPoint.h"
#include "KeyboardScreen.h"
#include "MultisampleRange.h"
#include "Sample.h"
#include "SampleMarkerEditor.h"
#include "View.h"
#include "definitions.h"
#include "numericdriver.h"
#include "soundeditor.h"
#include "source.h"
#include "uart.h"
#include "uitimermanager.h"
#include <sound.h>

bool MenuItemSampleLoopPoint::isRelevant(Sound* sound, int whichThing) {

  Source* source = &sound->sources[whichThing];

  return (sound->getSynthMode() == SYNTH_MODE_SUBTRACTIVE && source->oscType == OSC_TYPE_SAMPLE);
}

int MenuItemSampleLoopPoint::checkPermissionToBeginSession(Sound*       sound,
                                                           int          whichThing,
                                                           MultiRange** currentRange) {

  if (!isRelevant(sound, whichThing)) { return MENU_PERMISSION_NO; }

  int permission = soundEditor.checkPermissionToBeginSessionForRangeSpecificParam(sound,
                                                                                  whichThing,
                                                                                  true,
                                                                                  currentRange);

  // Before going ahead, make sure a Sample is loaded
  if (permission == MENU_PERMISSION_YES) {
    if (!(*currentRange)->getAudioFileHolder()->audioFile) { permission = MENU_PERMISSION_NO; }
  }

  return permission;
}

void MenuItemSampleLoopPoint::beginSession(MenuItem* navigatedBackwardFrom) {

  if (getRootUI() == &keyboardScreen) {
    if (currentUIMode == UI_MODE_AUDITIONING) keyboardScreen.exitAuditionMode();
  }

  soundEditor.shouldGoUpOneLevelOnBegin = true;
  sampleMarkerEditor.markerType         = markerType;
  bool success = openUI(&sampleMarkerEditor); // Shouldn't be able to fail anymore
  if (!success) {
    // if (getCurrentUI() == &soundEditor) soundEditor.goUpOneLevel();
    uiTimerManager.unsetTimer(TIMER_SHORTCUT_BLINK);
  }
}
