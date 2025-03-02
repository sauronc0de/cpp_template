FROM ubuntu:latest
RUN apt-get update -y
RUN apt-get upgrade -y
RUN apt-get install -y curl git

# C++ environment and SDL2
RUN apt-get install -y \
    gcc \
    g++ \
    gcc-multilib \
    g++-multilib \
    build-essential \
    xutils-dev \
    libsdl2-dev \
    libsdl2-gfx-dev \
    libsdl2-image-dev \
    libsdl2-mixer-dev \
    libsdl2-net-dev \
    libsdl2-ttf-dev \
    libreadline6-dev \
    libncurses5-dev \
    mingw-w64 \
    cmake

# Add clang compiler
RUN apt-get install -y clang

# Utilities
RUN apt-get update && apt-get install -y clang-format clangd lldb

# Install sudo and create a user
RUN apt-get update && apt-get install -y sudo
#👥 Create a non-root user 'sauroncode' with password '1234', grant sudo access without password
RUN useradd -m sauroncode && echo "sauroncode:1234" | chpasswd && adduser sauroncode sudo
RUN echo "%sudo ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

# Add user 'sauroncode' to plugdev and dialout groups for USB access
RUN sudo usermod -aG plugdev sauroncode && sudo usermod -aG dialout sauroncode

# Switch to 'sauroncode' user
USER sauroncode

# Set the working directory in the container
WORKDIR /workspace/template

ENV XDG_RUNTIME_DIR=/tmp