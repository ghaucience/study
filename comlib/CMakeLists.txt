add_library(comlib comlib.cxx)

install (TARGETS comlib DESTINATION bin)
install (FILES comlib.h DESTINATION	include)
