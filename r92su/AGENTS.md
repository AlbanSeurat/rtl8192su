# AGENTS.md

## Project Overview
Linux kernel driver for the Realtek RTL8192SU wireless USB adapter.

## Build
```bash
make -C /lib/modules/$(uname -r)/build M=$(pwd) modules
sudo make -C /lib/modules/$(uname -r)/build M=$(pwd) modules_install
sudo modprobe r92su
```

## Architecture
```
├── main.c          - Driver entry/exit (usb_driver registration)
├── usb.c/h         - USB communication layer
├── hw.c/h          - Hardware initialization and register access
├── fw.c/h          - Firmware download and management
├── eeprom.c/h      - EEPROM read/configuration
├── cmd.c/h         - Command processing
├── rx.c/h          - Receive path
├── tx.c/h          - Transmit path
├── event.c/h       - Event handling
├── sta.c/h         - Station management
├── pwr.c/h         - Power management
├── debug.c/h       - Debug utilities
├── debugfs.c/h     - Debugfs interface (CONFIG_R92SU_DEBUGFS)
├── trace.c/h       - Kernel tracing (CONFIG_R92SU_TRACING)
├── crypto/         - Encryption: aes_ccm, tkip, wep, michael
├── api/            - Public API headers
├── core/           - Core functionality
├── usb/            - USB-specific headers
├── hw/             - Hardware-specific headers
├── fw/             - Firmware images
├── nvm/            - Non-volatile memory
├── rx/tx/sta/event/debug/ - Submodule directories
├── r92su.h         - Main driver header
├── def.h           - Definitions and macros
├── reg.h           - Register definitions
├── h2cc2h.h        - Host-to-chip command headers
└── Kconfig         - Kernel config options
```

## Coding Conventions
- Kernel driver style: follow `Documentation/process/coding-style.rst`
- Logging: use `netdev_dbg`, `netdev_info`, `netdev_err`, `pr_debug`
- Naming: `r92su_` prefix for exported symbols, `rtl92su_` for internal
- Error handling: check return values, use `goto` cleanup patterns
- Memory: use `kzalloc`/`kfree`, avoid stack allocations > page size
- Spinlocks: protect shared data, disable interrupts when needed
- No user-space interfaces except debugfs/netlink where appropriate

## Key Config Options (Kconfig)
- `CONFIG_R92SU` - Main driver
- `CONFIG_R92SU_DEBUGFS` - Debugfs interface
- `CONFIG_R92SU_TRACING` - Kernel tracing
