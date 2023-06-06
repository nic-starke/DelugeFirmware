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

#include "Action.h"
#include "GeneralMemoryAllocator.h"
#include "functions.h"
#include <ClipInstance.h>
#include <ConsequenceClipInstanceChange.h>
#include <InstrumentClip.h>
#include <new>
#include <string.h>

ClipInstance::ClipInstance() {
  // TODO Auto-generated constructor stub
}

void ClipInstance::getColour(uint8_t* colour) {
  if (!clip || clip->isArrangementOnlyClip()) {
    memset(colour, 128, 3);
  } else {
    hueToRGB(defaultClipGroupColours[clip->section], colour);
  }
}

void ClipInstance::change(Action* action,
                          Output* output,
                          int32_t newPos,
                          int32_t newLength,
                          Clip*   newClip) {
  if (action) {
    void* consMemory = generalMemoryAllocator.alloc(sizeof(ConsequenceClipInstanceChange));

    if (consMemory) {
      ConsequenceClipInstanceChange* newConsequence =
          new (consMemory) ConsequenceClipInstanceChange(output, this, newPos, newLength, newClip);
      action->addConsequence(newConsequence);
    }
  }

  pos    = newPos;
  length = newLength;
  clip   = newClip;
}
