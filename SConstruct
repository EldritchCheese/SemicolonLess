# -*- python -*-

debug = '-g'

env = Environment()
if debug:
    env.Append(CCFLAGS = Split(debug), LINKFLAGS = Split(debug))

env.Program('SLess.cc')
