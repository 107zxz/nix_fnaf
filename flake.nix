{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
    let
    pkgs = import nixpkgs {inherit system;};
    packs = with pkgs; [
        raylib
        glslang
        git
    ];
    in {
      packages.default =
        pkgs.llvmPackages_latest.stdenv.mkDerivation {
            name = "main";
            srcs = [
                ./.
            ];
            buildInputs = packs;

        };

      devShells.default =
        pkgs.mkShell {
            nativeBuildInputs = packs ++ [
                pkgs.clang-tools
                pkgs.clang
            ];


            # CPATH = nixpkgs.lib.makeSearchPathOutput "dev" "include" packs;
            # LIBCLANG_PATH = "${pkgs.llvmPackages_latest.libclang.lib}/lib";
            # BINDGEN_EXTRA_CLANG_ARGS = "-isystem ${pkgs.llvmPackages_latest.libclang.lib}/lib/clang/${nixpkgs.lib.getVersion pkgs.clang}/include";
            # PATH = "${pkgs.clang-tools}/bin:$PATH";
        };
      }
   );
  }
