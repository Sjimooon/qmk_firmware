# Quick Guide
[QMK documentation](https://docs.qmk.fm/)

## Keycodes
Call `sjimooon_process_record_user()` from `keymap.c` to use custom keycodes (see `custom_keycodes`) defined in [sjimooon.h](sjimooon.h).

```c
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return sjimooon_process_record_user(keycode, record);
}
```

### Danish Keycodes
- [keymap_danish.h](../../quantum/keymap_extras/keymap_danish.h)
- [sendstring_danish.h](../../quantum/keymap_extras/sendstring_danish.h)

## Keyboards
### ZSA Moonlander

### YMDK ID75
```
qmk compile -kb ymdk/id75
```

```
qmk flash -kb ymdk/id75
```
