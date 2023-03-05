bin_PROGRAMS = time_is
time_is_SOURCES = src/main.cpp
noinst_LIBRARIES = libtime_now.a
libtime_now_a_SOURCES = src/time_now/time_now.cpp src/time_now/time_now.h
time_is_LDADD = libtime_now.a
time_is_CPPFLAGS = -Isrc -Isrc/time_now
