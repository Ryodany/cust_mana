from conans import ConanFile, CMake, tools

class CustomermanagementConan(ConanFile):
    name = "Customer Management"
    version = "1.0"
    license = "MIT"
    url = "https://github.com/Ryodany/cust_mana.git"
    description = "Customer Management sample project"
    settings = "os", "compiler", "build_type", "arch"
    default_options = "Core:shared=False"
    generators = "cmake"

    def source(self):
        self.run("git clone " + url)

    def build(self):
        cmake = CMake(self)
        cmake.configure(source_folder=".")
        cmake.build()

        # Explicit way:
        # self.run('cmake %s/hello %s'
        #          % (self.source_folder, cmake.command_line))
        # self.run("cmake --build . %s" % cmake.build_config)

    def package(self):
        self.copy("*.dll", dst="bin", src="bin")
        self.copy("*.so", dst="bin", src="bin")
        self.copy("*.a", dst="lib", src="bin")

    def package_info(self):
        self.cpp_info.includedirs = ['include']  # Ordered list of include paths
        self.cpp_info.libs = []  # The libs to link against
        self.cpp_info.libdirs = ['lib']  # Directories where libraries can be found
        self.cpp_info.resdirs = ['res']  # Directories where resources, data, etc can be found
        self.cpp_info.bindirs = ['bin']  # Directories where executables and shared libs can be found
        self.cpp_info.defines = ["CORE_DLL", "_CONSOLE ", "UNICODE", "_UNICODE"]  # preprocessor definitions
        self.cpp_info.cflags = []  # pure C flags
        self.cpp_info.cppflags = []  # C++ compilation flags
        self.cpp_info.sharedlinkflags = []  # linker flags
        self.cpp_info.exelinkflags = []  # linker flags


