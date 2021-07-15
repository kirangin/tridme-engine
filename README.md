# Tridme Engine

Tridme Engine atau 3D Maker Engine adalah game engine berbasis code yang dibuat dengan C++ dan OpenGL. Tridme Engine (lebih mudah disebut "Tridme") menggunakan OpenGL dan Shader versi 3.3.

#### Cara Compile

1. Dapatkan source code

```bash
git clone https://github.com/naufaladrna08/tridme-engine.git
```

2. Install dependensi, yaitu build-essential (gcc, g++), xorg-dev, libglu1-mesa-dev

```bash
sudo apt install build-essential xorg-dev libglu1-mesa-dev
```

3. Mulai kompilasi dengan Makefile

| Perintah   | Fungsi                                                       |
| ---------- | ------------------------------------------------------------ |
| make lib   | Untuk membuat inti library.                                  |
| make test  | Untuk membuat test binary.                                   |
| make all   | Membuat inti dan test                                        |
| make clean | Untuk membersihkan atau menghapus file yang sudah digenerate oleh compiler. |

#### Bagian dalam Tridme

Tridme dibagi menjadi 2 bagian, yaitu inti dan window. Dalam inti, terdapat code untuk menghandle seluruh fungsi engine seperti membuat vertex buffer, membuat object (mesh), membuat shader, dll. Dalam window, terdapat code tampilan yang akan ditampilkan.