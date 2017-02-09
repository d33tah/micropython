/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013-2015 Damien P. George
 * Copyright (c) 2016 Paul Sokolovsky
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <stdint.h>
#include <stdio.h>

#include "py/obj.h"
#include "py/runtime.h"

#include "user_interface.h"

#if MICROPY_PY_HELLO

STATIC mp_obj_t fun_wifi_send_pkt_freedom(mp_obj_t packet_buffer_obj) {
    mp_buffer_info_t src;
    mp_get_buffer_raise(packet_buffer_obj, &src, MP_BUFFER_READ);
    return mp_obj_new_int(wifi_send_pkt_freedom((uint8_t*)src.buf, src.len, 0));
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(fun_wifi_send_pkt_freedom_obj, fun_wifi_send_pkt_freedom);

STATIC const mp_rom_map_elem_t raw80211_module_globals_table[] = {
    { MP_ROM_QSTR(MP_QSTR___name__), MP_ROM_QSTR(MP_QSTR_raw80211) },
    { MP_OBJ_NEW_QSTR(MP_QSTR_send_packet), (mp_obj_t)&fun_wifi_send_pkt_freedom_obj },
};

STATIC MP_DEFINE_CONST_DICT(raw80211_module_globals, raw80211_module_globals_table);

const mp_obj_module_t mp_module_raw80211 = {
    .base = { &mp_type_module },
    .globals = (mp_obj_dict_t*)&raw80211_module_globals,
};

#endif // MICROPY_PY_HELLO
