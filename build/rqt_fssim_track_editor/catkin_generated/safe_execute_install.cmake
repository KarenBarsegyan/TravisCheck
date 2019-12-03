execute_process(COMMAND "/home/karenbarsegyan/BRTDriverless/build/rqt_fssim_track_editor/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/karenbarsegyan/BRTDriverless/build/rqt_fssim_track_editor/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
