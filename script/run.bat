@echo off
pushd .

if not exist build/tests/helloTest.exe (
	echo "helloTest.exe not exists!"
	popd
	exit(1)
)

cd build/tests

helloTest.exe

popd
