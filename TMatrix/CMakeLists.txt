 file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h

add_library(${matrixlib} STATIC ${srcs} ${hdrs})

target_link_libraries(${matrixlib} ${errorlib})
target_link_libraries(${matrixlib} ${vectorlib})
