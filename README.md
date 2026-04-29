# Realtek RTL8188SU/RTL8191SU/RTL8192SU driver

## Introduction

This is "a" driver repository for the WIP rtl8192su for any interested developer.

To build the driver you will need to have a recent and compatible kernel source.
Currently, only kernels built from the latest wireless-testing.git are supported.
If you want to know more about wireless-testing.git then visit our
[wireless wiki's Git-Guide](http://wireless.kernel.org/en/developers/Documentation/git-guide).

## Contact

If you have any questions, reports or patches, you should write to <linux-wireless@vger.kernel.org>.

## Building the driver

### Standard build

just use the Makefile:

`make`

and then

`make load`

to load the module.

### Building for RTL8192SU (arm64 cross-compile)

To compile the RTL8192SU driver for a specific kernel source and architecture, use:

```
KSRC=<path-to-kernel-source> ARCH=<arch> make -f Makefile.r92su
```

| Argument | Description |
|----------|-------------|
| `KSRC` | Path to your Linux kernel source directory. Must point to a compatible kernel tree. |
| `ARCH` | Target architecture (e.g., `arm64`, `arm`, `x86`). |
| `clean` | Removes all build artifacts and generated files. Use `modules` instead to compile. |

**Example** — clean and build for arm64:

```
export KERNEL_SRC_DIR=/path/to/kernel/source
KSRC=$KERNEL_SRC_DIR ARCH=arm64 make -f Makefile.r92su clean
KSRC=$KERNEL_SRC_DIR ARCH=arm64 make -f Makefile.r92su modules
```
