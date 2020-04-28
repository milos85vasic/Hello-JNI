# Hello JNI
Small demo program that demonstrates binding C++ with Kotlin

## How to build and run

The following steps are executed on macOS:

- Make sure that Gradle is installed on your system and added to your system path
- Clone and cd into the directory where you have cloned the code
- `cd JVM`
- `gradle wrapper`
- `./gradlew assemble`
- `cd ../Native`
- `mkdir Build`
- `cd Build`
- `cmake ..`
- `make`
- `make install`
- `cd ../JVM`
- `gradle wrapper`
- `./gradlew clean`
- `./gradlew assemble`
- `cd Demo/build/libs`
- `java -jar -Djava.library.path=/usr/local/lib/Demo Demo.jar`
- Output: `Hello, young Padawan!`
