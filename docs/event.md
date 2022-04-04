# Tridme Engine
### Event Handler

Untuk mendapatkan event, Tridme menggunakan fungsi GLFW ``glfwPollEvents();`` untuk mendapatkan input ke aplikasi. Pemrosesan event terjadi setiap sekali dalam satu frame setelah melakukan _buffer swapping_.

Cara kerja input handler dalam Tridme Engine adalah saat user menekan input