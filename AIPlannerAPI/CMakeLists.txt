# Input
file(GLOB_RECURSE SOURCES "Sources/*")

# Dynamic library.
add_library (AIPlanner SHARED ${SOURCES})
# Include directories
target_include_directories(AIPlanner PUBLIC Include)

add_executable (AIPlannerExecutable ${SOURCES})
target_include_directories(AIPlanner PUBLIC Include)