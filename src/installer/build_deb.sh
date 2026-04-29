#!/bin/bash

set -e

PACKAGE_NAME="ivs-calculator"
VERSION="1.0"
ARCH="amd64"

PROJECT_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
PKG_DIR="$PROJECT_ROOT/installer/${PACKAGE_NAME}-deb"
DEB_FILE="$PROJECT_ROOT/installer/${PACKAGE_NAME}_${VERSION}_${ARCH}.deb"

echo "Cleaning old package files..."
rm -rf "$PKG_DIR"
rm -f "$DEB_FILE"

echo "Preparing package directory..."
mkdir -p "$PKG_DIR/DEBIAN"

echo "Installing application into package directory..."
cd "$PROJECT_ROOT"
make install DESTDIR="$PKG_DIR"

echo "Creating control file..."
cat > "$PKG_DIR/DEBIAN/control" <<EOF
Package: $PACKAGE_NAME
Version: $VERSION
Section: utils
Priority: optional
Architecture: $ARCH
Maintainer: IVS Team <team@example.com>
Depends: libqt6widgets6
Description: Calculator with custom mathematical library
 A simple calculator application created as a school project.
 The application uses its own mathematical library.
EOF

chmod 755 "$PKG_DIR/DEBIAN"
chmod 644 "$PKG_DIR/DEBIAN/control"

echo "Building .deb package..."
dpkg-deb --build "$PKG_DIR"
mv "${PKG_DIR}.deb" "$DEB_FILE"

echo "Package created:"
echo "$DEB_FILE"