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
        lldb
    ];
    in
    {
      packages.default =
        pkgs.clangStdenv.mkDerivation {
            name = "main";
            srcs = [
                ./.
            ];
            buildInputs = packs;
        };
      }
    );
  }
