FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    build-essential \
    gcc-14 g++-14 \
    cmake \
    gdb \
    git \
 && update-ca-certificates \
 && update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 100 \
 && update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 100 \
 && update-alternatives --set gcc /usr/bin/gcc-14 \
 && update-alternatives --set g++ /usr/bin/g++-14 \
 && apt-get clean && rm -rf /var/lib/apt/lists/*

