# LHC CERN Data Audio Generator

## Project Overview
Sonifies LHC/CERN event data into real-time sound and 3D visualizations using openFrameworks on macOS.

## Build & Run
- macOS 11.5+ recommended
- openFrameworks 0.11+ (or project-pinned)
- Xcode + Command Line Tools

### Xcode
1. Open the Xcode project/workspace in this repo.
2. Select the correct target/config.
3. Build & Run.

### Make (if configured)
make
make RunRelease

## Architecture (typical)
- src/ofApp.* — app loop, rendering, input
- src/PathData.* — event/path parsing + data model
- src/SpectrumDrawer.* — spectrum rendering utilities
- src/LHCIgFileLoad.* — .ig event loader

## Audio Engine
- Additive synthesis (~512 oscillators)
- IFFT-based synthesis (4096-point FFT/IFFT pipeline)

## Controls
- Space: play/stop
- M: toggle engine mode
- C: screenshot
- G: info overlay
- Mouse drag: rotate

## Data Files
Examples: 4lepton, diphoton, dimuon-Jpsi (.ig)

## Config
- Project.xcconfig
- config.make
- addons.make

## Notes
- FMOD disabled (if applicable)
- macOS audio device auto-detection notes (if applicable)
