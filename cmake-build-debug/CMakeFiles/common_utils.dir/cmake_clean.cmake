file(REMOVE_RECURSE
  "libcommon_utils.pdb"
  "libcommon_utils.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/common_utils.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
