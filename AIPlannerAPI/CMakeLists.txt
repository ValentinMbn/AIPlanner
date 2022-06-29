# Input
file(GLOB_RECURSE SOURCES "Sources/*")

# Dynamic library.
add_library (AIPlanner SHARED ${SOURCES})
# Include directories
target_include_directories(AIPlanner PUBLIC Includes)

add_executable (AIPlannerExecutable ${SOURCES})
target_include_directories(AIPlannerExecutable PUBLIC Includes)

target_compile_features(AIPlanner PUBLIC cxx_std_17)