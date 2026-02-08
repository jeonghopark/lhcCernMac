# LHC CERN Data Audio Generator

![images/captureImage.png](images/captureImage.png)

An interactive audiovisual application that converts particle physics data from CERN's Large Hadron Collider (LHC) into sound and 3D visualizations.

## Requirements

- macOS 11.5+
- openFrameworks 0.11+
- C++23

## Features

- Sonification of CERN CMS detector event data (512 frequency bins, 44.1kHz)
- **Dual audio engine** with real-time switching:
  - **Additive Synthesis**: 512 independent sine oscillators with continuous phase tracking. Warm, harmonic tones.
  - **IFFT Synthesis**: 4096-point Inverse FFT with overlap-add. Frequency-mapped spectrum reconstruction with coherent phase accumulation. Textured, spectral character.
- Real-time 3D visualization of detector geometry (EB, EE, ES, HB, HE, HF) and particle trajectories
- Scrolling spectrogram display synchronized with audio playback
- Interactive controls: event navigation, auto-play, speed/volume adjustment
- Drag & drop support for loading .ig event files

## Controls

| Key | Action |
|-----|--------|
| Space | Play / Stop |
| M | Toggle audio engine (Additive / IFFT) |

Current audio engine mode is displayed at the bottom-left corner of the screen.

## Data

Event data is in CERN's iSpy `.ig` format (ZIP-compressed). Included datasets:

- **4lepton.ig** — Higgs boson candidate events: H → ZZ* → 4 leptons (4μ, 4e, 2e2μ), 3 events at 120-130 GeV
- **diphoton.ig** — Higgs boson candidate events: H → γγ, 10 events at 120-130 GeV
- **dimuon-Jpsi_0.ig** — J/ψ dimuon resonance events (~3.1 GeV)

Higgs candidate data from [CERN Open Data Record 300](http://opendata.cern.ch/record/300).
More .ig files at [CERN Open Data Record 301](http://opendata.cern.ch/record/301).

## Credits

Based on code from:
- Spectrum Generator: [https://github.com/dfeles/refreq](https://github.com/dfeles/refreq)
- ofxUnZip: [https://github.com/mazbox/ofxUnZip](https://github.com/mazbox/ofxUnZip)

## Author

A project by JeongHo Park
