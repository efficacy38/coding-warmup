{
  description = "A Nix-flake-based C/C++ development environment";
  # unstable(pined clangd) Nixpkgs
  inputs.nixpkgs.url = "github:NixOS/nixpkgs/staging-next-25.11";

  outputs =
    { self, ... }@inputs:

    let
      supportedSystems = [
        "x86_64-linux"
        "aarch64-linux"
        "x86_64-darwin"
        "aarch64-darwin"
      ];
      forEachSupportedSystem =
        f:
        inputs.nixpkgs.lib.genAttrs supportedSystems (
          system:
          f {
            pkgs = import inputs.nixpkgs { inherit system; };
          }
        );
    in
    {
      devShells = forEachSupportedSystem (
        { pkgs }:
        {
          default = pkgs.mkShellNoCC {
            packages = [
              # clang-tools comes first => wrapped clangd comes first in PATH
              pkgs.clang-tools
            ];
          };
        }
      );
    };
}
