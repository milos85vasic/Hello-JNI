# Hello JNI
Small demo program that demonstrates binding C++ with Kotlin

## How to build and run

The following steps are executed on macOS:

- Clone project
- cd Native
- mkdir Build
- cd Build
- cmake ..
- make
- make install
- cd ../JVM
- gradle wrapper
- ./gradlew clean
- ./gradlew assemble
- cd Demo/build/libs
- java -jar -Djava.library.path=/usr/local/lib/Demo Demo.jar
