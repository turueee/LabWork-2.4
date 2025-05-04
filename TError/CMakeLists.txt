file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h


include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../TString")

add_library(${errorlib} STATIC ${srcs}  ${hdrs})


