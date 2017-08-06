dnl run `autoreconf -i` to generate a configure script.
dnl Then run ./configure to generate a Makefile.
dnl Finally run make to generate the project.

AC_INIT([Tiny Sam], m4_esyscmd([./git-version-gen .tarball-version]), [sylvie.stucki@a3.epfl.ch], [tiny-sam], [lasig.epfl.ch/sambada])
AM_INIT_AUTOMAKE([foreign subdir-objects dist-zip])

AC_PROG_CXX

AC_CONFIG_FILES([Makefile])

# Check for presence of latexmk
AC_CHECK_PROG(LATEXMK, latexmk, latexmk)
if test -z "$LATEXMK"; then
	AC_MSG_WARN([Unable to create PDF version of the user manual.])
fi

AM_CONDITIONAL([HAVE_LATEXMK], test -n "$LATEXMK")

AC_OUTPUT
