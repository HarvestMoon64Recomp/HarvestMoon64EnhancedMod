# HarvestMoon64EnhancedMod
Adds various quality-of-life improvements to Harvest Moon 64:
- Tool cycling: cycle through your equipped tools with a button shortcut.
- Time speed: Adjust clock speed in the config
- Music persistence: music keeps playing across transitions between maps and naming screens.
- Farm ranking screen: restores the farm ranking screen.
- Rain planting: crops sown while raining get automatically watered.
- Faster map loading
- Message box configuration: adjust text reveal speed and scroll speed, and toggle message box sound effects.
- Playable ocarina: once acquired, press D-Up to play.
### Tools

You'll need to install `clang` and `make` to build the mod.

* On Windows, using [Chocolatey](https://chocolatey.org/) to install both is recommended. The packages are `llvm` and `make`.
  * LLVM 19.1.0 does not support MIPS correctly for this workflow. LLVM/Clang 18.1.8 is recommended.
  * With Chocolatey, you can install that version with `--version 18.1.8`, or you can download the LLVM 18.1.8 release directly.
* On Linux, install `clang`, `make`, and `lld` through your distro's package manager.
  * On Debian/Ubuntu-based distros, the linker package is usually `lld`.
* On macOS, install `llvm` and `make` through Homebrew.
  * Apple Clang will not work because this build needs a MIPS target.

On Linux and macOS, make sure the `zip` utility is also installed.

You'll also need `RecompModTool` from the [N64Recomp](https://github.com/N64Recomp/N64Recomp) releases. You can also build it yourself from the N64Recomp repository.

### Building

* Run `make` to build the mod code.
  * You can pass a job count, such as `make -j8`, to build faster.
* Run `RecompModTool` with `mod.toml` as the first argument and the build directory as the second argument:

```sh
RecompModTool mod.toml build
```

This will produce the mod's `.nrm` file in the `build` folder.

On macOS, you may need to specify the Homebrew LLVM tools manually:

```sh
CC=/opt/homebrew/opt/llvm/bin/clang LD=/opt/homebrew/opt/llvm/bin/ld.lld make
```

### Updating Harvest Moon 64 symbols or headers

If the Harvest Moon 64 recomp/decompilation symbols change, the mod may need updated symbol files or headers.

General process:

* Build the matching Harvest Moon 64 ELF or symbol source used by the recomp project.
* Build [N64Recomp](https://github.com/N64Recomp/N64Recomp) and copy the `N64Recomp` executable to the root of this repository if needed.
* Generate or update the symbol files used by this mod.
* Update the corresponding headers and function names referenced by the mod source.
* Rebuild the mod.

If `RecompModTool` fails because a patched function does not exist in the original ROM, the function name may have changed. Find the function at the same address in the updated map or symbol file, then update the hook or patch name in the mod source.
