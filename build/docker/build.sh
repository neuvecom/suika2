#!/bin/bash

set -eu

# If "clean" is specified
if [ $# = 1 ]; then
	if [ $1 = "clean" ]; then
		echo Cleaning up...
		docker stop suika2-run || true
		docker rm suika2-run || true
		docker image rm suika2-dev || true
		rm -rf suika.exe suika-pro.exe suika-64.exe suika-capture.exe suika-arm64.exe suika-linux suika-linux-replay html suika.apk
		exit 0
	fi
fi

# Start
echo Starting builds...

# Build the suika2-dev image
echo Building the Docker image.
docker build -t suika2-dev --add-host archive.ubuntu.com:185.125.190.39 .

# Create an instance of suika2-dev
echo Running the Docker container.
docker run -d -it -v ${PWD%/*/*}:/workspace --name suika2-run suika2-dev

# Build the mingw target
echo Building the Windows binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/mingw && make"
docker cp suika2-run:/workspace/build/mingw/suika.exe suika.exe

# Build the mingw-pro target
echo Building the Windows Pro binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/mingw-pro && make"
docker cp suika2-run:/workspace/build/mingw/suika-pro.exe suika-pro.exe

# Build the mingw-64 target
echo Building the Windows 64-bit binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/mingw-64 && make"
docker cp suika2-run:/workspace/build/mingw/suika-64.exe suika-64.exe

# Build the mingw-capture target
echo Building the Windows Capture binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/mingw-capture && make"
docker cp suika2-run:/workspace/build/mingw/suika-capture.exe suika-capture.exe

# Build the mingw-replay target
echo Building the Windows Replay binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/mingw-replay && make"
docker cp suika2-run:/workspace/build/mingw/suika-replay.exe suika-replay.exe

# Build the mingw-arm64 target
echo Building the Windows Arm64 binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/mingw-arm64 && make"
docker cp suika2-run:/workspace/build/mingw/suika-arm64.exe suika-arm64.exe

# Build the linux-x86_64 target
echo Building the linux-x86_64 binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/linux-x86_64 && make"
docker cp suika2-run:/workspace/build/linux-x86_64/suika suika-linux

# Build the linux-x86_64-replay target
echo Building the linux-x86_64-replay binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/linux-x86_64-replay && make"
docker cp suika2-run:/workspace/build/linux-x86_64/suika-replay suika-linux-replay

# Build the Web target
echo Building the Web binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/emscripten && source /emsdk/emsdk_env.sh && make"
docker cp suika2-run:/workspace/build/emscripten/html ./

# Build the Android target
echo Building the Android binary.
docker exec -i suika2-run /bin/bash -c "cd /workspace/build/android && ./build-on-linux.sh"
docker cp suika2-run:/workspace/build/android/app/build/outputs/apk/debug/app-debug.apk suika.apk

# Trailer
echo Successfully finished the builds.
echo To cleanup, run ./build.sh clean