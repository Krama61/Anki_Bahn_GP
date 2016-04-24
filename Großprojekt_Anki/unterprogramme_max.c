/*
 * Copyright (c) 2014 Anki, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2000-2001  Qualcomm Incorporated
 *  Copyright (C) 2002-2003  Maxim Krasnyansky <maxk@qualcomm.com>
 *  Copyright (C) 2002-2010  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include <stdio.h>

#include "advertisement.h"
#include "anki_util.h"
#include "ankidrive.h"
#include "bluetooth.h"
#include "bluetooth_uuid.h"
#include "btio.h"
#include "common.h"
#include "display.h"
#include "eir.h"
#include "gattrib.h"
#include "hci.h"
#include "hci_lib.h"
#include "l2cap.h"
#include "log.h"
#include "protocol.h"
#include "sco.h"
#include "sdp.h"
#include "sdp_lib.h"
#include "uthash.h"
#include "utils.h"
#include "uuid.h"
#include "vehicle_gatt_profile.h"
#include "version.h"
#include "att.h"
#include "gatt.h"

//Muss eingebunden / Festgelegt werden damit set_speed Eins weiter unten Funktioniert

static GAttrib *attrib = NULL;

typedef struct anki_vehicle {
    struct gatt_char read_char;
    struct gatt_char write_char;
} anki_vehicle_t;

static anki_vehicle_t vehicle;

static enum state {
    STATE_DISCONNECTED,
    STATE_CONNECTING,
    STATE_CONNECTED
} conn_state;

#define error(fmt, arg...) \
    rl_printf(COLOR_RED "Error: " COLOR_OFF fmt, ## arg)

#define failed(fmt, arg...) \
    rl_printf(COLOR_RED "Command Failed: " COLOR_OFF fmt, ## arg)



//Eigentilche Funktion set_speed

static void set_speed(int inspeed, int inaccel)
{
        uint8_t *value;
        size_t plen;
        int handle;

        handle = vehicle.write_char.value_handle;

        int16_t speed = inspeed;
        int16_t accel = inaccel;

        // rl_printf("setting speed to %d (accel = %d)\n", speed, accel);

        anki_vehicle_msg_t msg;
        plen = anki_vehicle_msg_set_speed(&msg, speed, accel);
        value = (uint8_t *)&msg;

        gatt_write_char(attrib, handle, value, plen,
                                        NULL, NULL); // WICHTIG SENDEN????
}


int main1()
{
   // printl("Hello World!");
    set_speed(1000,1000);
}

