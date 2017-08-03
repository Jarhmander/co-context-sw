Cooperative context switch
==========================

Basic cooperative context switcher. It can be used as a basic building block for
higher level functionality like coroutines, exception handling and cooperative
multi-threading.

The scope of this project is intentionaly small: support a basic API (2
functions) accross a variety of platforms. The high-level functions can then be
portably implemented with only this tiny API as a dependency.
