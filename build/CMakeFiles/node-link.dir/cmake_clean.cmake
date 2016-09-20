file(REMOVE_RECURSE
  "Release/node-link.pdb"
  "Release/node-link.node"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/node-link.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
