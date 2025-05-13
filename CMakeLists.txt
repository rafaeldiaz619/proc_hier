project(proc_hier C)

set(CMAKE_C_STANDARD 17)

set(CMAKE_C_FLAGS "-m64 -g -O0 -D_DEBUG -Wall")

set(PROC_HIER proc_hier.c)
set(iam iam.c)

add_executable(proc_hier ${PROC_HIER})
add_executable(iam ${iam})
