{ pkgs }: {
	deps = [
		pkgs.htop
  pkgs.valgrind
  pkgs.clang_12
		pkgs.cmake
		pkgs.gdb
	];
}