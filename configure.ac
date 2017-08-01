dnl run `autoreconf -i` to generate a configure script.
dnl Then run ./configure to generate a Makefile.
dnl Finally run make to generate the project.

AC_INIT([Tiny Sam], m4_esyscmd([./git-version-gen .tarball-version]), [sylvie.stucki@a3.epfl.ch], [tiny-sam], [lasig.epfl.ch/sambada])
AM_INIT_AUTOMAKE([foreign subdir-objects])

AC_PROG_CXX

AC_CONFIG_FILES([Makefile])

AC_OUTPUT
