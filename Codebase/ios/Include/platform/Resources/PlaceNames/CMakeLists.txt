set(headers ${headers} platform/Resources/PlaceNames
)
set(currsources
  platform/Resources/PlaceNames/CMakeLists.txt
  platform/Resources/PlaceNames/PlaceNameCategory.h
  platform/Resources/PlaceNames/PlaceNameCategoryStyle.cpp
  platform/Resources/PlaceNames/PlaceNameCategoryStyle.h
  platform/Resources/PlaceNames/PlaceNameData.h
  platform/Resources/PlaceNames/PlaceNameIcons.h
  platform/Resources/PlaceNames/PlaceNameModel.cpp
  platform/Resources/PlaceNames/PlaceNameModel.h
  platform/Resources/PlaceNames/PlaceNameParser.cpp
  platform/Resources/PlaceNames/PlaceNameParser.h
  platform/Resources/PlaceNames/PlaceNames.h
  platform/Resources/PlaceNames/PlaceNamesBuilder.cpp
  platform/Resources/PlaceNames/PlaceNamesBuilder.h
  platform/Resources/PlaceNames/PlaceNamesBuilderOutput.cpp
  platform/Resources/PlaceNames/PlaceNamesBuilderOutput.h
  platform/Resources/PlaceNames/PlaceNamesCell.cpp
  platform/Resources/PlaceNames/PlaceNamesCell.h
  platform/Resources/PlaceNames/PlaceNamesController.cpp
  platform/Resources/PlaceNames/PlaceNamesController.h
  platform/Resources/PlaceNames/PlaceNamesControllerFactory.cpp
  platform/Resources/PlaceNames/PlaceNamesControllerFactory.h
  platform/Resources/PlaceNames/PlaceNamesMaterial.h
  platform/Resources/PlaceNames/PlaceNamesRepository.cpp
  platform/Resources/PlaceNames/PlaceNamesRepository.h
  platform/Resources/PlaceNames/PlaceNamesStreaming.cpp
  platform/Resources/PlaceNames/PlaceNamesStreaming.h
  platform/Resources/PlaceNames/PlaceNamesTransforms.cpp
  platform/Resources/PlaceNames/PlaceNamesTransforms.h
  platform/Resources/PlaceNames/PlaceNameView.cpp
  platform/Resources/PlaceNames/PlaceNameView.h
  platform/Resources/PlaceNames/PlaceNameViewBuilder.cpp
  platform/Resources/PlaceNames/PlaceNameViewBuilder.h
)
set(sources ${sources} ${currsources})
source_group(\\Resources\\PlaceNames FILES ${currsources})
