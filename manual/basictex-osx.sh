#!/usr/bin/env sh

# This script is essentially based on work of the project LaTeX3
# Source: https://github.com/latex3/latex3/

# This script is used for testing using Travis
# It is intended to work on their VM set up: OS X 10.11
# A minimal current TL is installed adding only the packages that are
# required

# See if there is a cached version of TL available
export PATH="/usr/local/texlive/2016basic/bin/universal-darwin":$PATH
if ! command -v latexmk > /dev/null; then

# Obtain BasicTeX with brew cask
brew cask install basictex

# Install a minimal system
sudo installer -pkg /usr/local/Caskroom/basictex/2016.1009/mactex-basictex-20161009.pkg -target /

# Updating the installation
sudo tlmgr update --self

fi

# Additional requirements for (u)pLaTeX, done with no dependencies to
# avoid large font payloads
sudo tlmgr install --no-depends ptex uptex ptex-base uptex-base ptex-fonts \
uptex-fonts platex uplatex

# Assuming a 'basic' font set up, metafont is required to avoid
# warnings with some packages and errors with others
sudo tlmgr install metafont mfware


# Set up graphics: nowadays split over a few places and requiring
# HO's bundle
sudo tlmgr install graphics graphics-cfg graphics-def oberdiek

# Contrib packages for testing
#
# The packages themselves are done with --no-depends to avoid
# picking up l3kernel, etc.
#
# fontspec comes first as other packages tested have it as a dep
sudo tlmgr install --no-depends fontspec
sudo tlmgr install ifluatex lm lualibs luaotfload

# Other contrib packages: done as a block to avoid multiple calls to tlmgr
# Dependencies other than the core l3build set up, metafont, fontspec and the
# 'graphics stack' (itself needed by fontspec) are listed below
sudo tlmgr install --no-depends \
siunitx       \
tlmgr install \
adobemapping  \
amsfonts      \
amsmath       \
biber         \
biblatex      \
ec            \
etoolbox      \
latexmk       \
lm-math       \
logreq        \
pgf           \
tools         \
ulem          \
units         \
url           \
xcolor        \
xstring       \
xunicode

# Keep no backups (not required, simply makes cache bigger)
sudo tlmgr option -- autobackup 0

# Update the TL install but add nothing new
sudo tlmgr update --self --all --no-auto-install
