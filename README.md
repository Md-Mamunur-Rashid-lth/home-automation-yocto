# Home Automation System (Yocto + C++ + systemd)

This project demonstrates a multi-service embedded Linux system built using Yocto.

## Features

- Custom Yocto layer (`meta-homeautomation`)
- Multiple C++ services:
  - Temperature monitoring
  - Light control
  - Automation controller
  - REST API server
- systemd service integration
- CMake-based builds
- Journald logging

## Architecture

REST API → Controller → Services

## Structure

meta-homeautomation/
└── recipes-home/
    ├── temperature-service/
    ├── light-service/
    ├── automation-controller/
    └── rest-api/

## Build Instructions

```bash
source poky/oe-init-build-env
bitbake core-image-minimal
