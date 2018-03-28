# RT - Generate images according to Raytracing protocol.
The final project of the first year in Unit Factory (42).

*Read this in other languages: [English](README.md), [Русский](README-ru.md).*

#### Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Authors](#authors)

## Features

- **New:** The faster `IPsec/XAuth ("Cisco IPsec")` mode is supported
- **New:** A pre-built <a href="https://github.com/hwdsl2/docker-ipsec-vpn-server" target="_blank">Docker image</a> of the VPN server is now available
- Fully automated IPsec VPN server setup, no user input needed
- Encapsulates all VPN traffic in UDP - does not need ESP protocol
- Can be directly used as "user-data" for a new Amazon EC2 instance
- Includes `sysctl.conf` optimizations for improved performance
- Tested with Ubuntu 16.04/14.04, Debian 9/8 and CentOS 7/6

## Requirements

Mac OS El Capitan
Mac OS Sierra
Mac OS High Sierra

## Installation

```bash
git clone https://github.com/andreyfaraponov/RayTracer.git ~/RT
cd ~/RT
make
```
## Authors

Vadim Kozlov
Andriy Faraponov
Pavlo Privalov
Andriy Nestor
