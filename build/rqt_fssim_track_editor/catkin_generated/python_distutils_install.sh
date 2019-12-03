#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/karenbarsegyan/BRTDriverless/src/fssim/fssim_rqt_plugins/rqt_fssim_track_editor"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/karenbarsegyan/BRTDriverless/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/karenbarsegyan/BRTDriverless/install/lib/python2.7/dist-packages:/home/karenbarsegyan/BRTDriverless/build/rqt_fssim_track_editor/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/karenbarsegyan/BRTDriverless/build/rqt_fssim_track_editor" \
    "/usr/bin/python" \
    "/home/karenbarsegyan/BRTDriverless/src/fssim/fssim_rqt_plugins/rqt_fssim_track_editor/setup.py" \
    build --build-base "/home/karenbarsegyan/BRTDriverless/build/rqt_fssim_track_editor" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/karenbarsegyan/BRTDriverless/install" --install-scripts="/home/karenbarsegyan/BRTDriverless/install/bin"
